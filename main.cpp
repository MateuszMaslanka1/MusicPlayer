#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include "./MusicPlayer/musicplayer.h"
#include "./PlaySong/playsong.h"
#include "./playlists.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<PlaySong>("PlaySong",1,0,"PlaySong");
    qmlRegisterType<Playlists>("Playlists",1,0,"Playlists");

    QQmlApplicationEngine engine;
    MusicPlayer musicPlayer;
    PlaySong playSong;
    Playlists playLists;

    QObject::connect(&musicPlayer, &MusicPlayer::musicLibraryChanged, &playSong, &PlaySong::updateMusicLibrary);

    musicPlayer.findInMusicLibrary();
    // playLists.loadPlayLists();

    engine.rootContext()->setContextProperty("musicPlayer", &musicPlayer);

    const QUrl url(u"qrc:/MusicPlayer/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
