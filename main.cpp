#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include "./MusicPlayer/musicplayer.h"
#include "./PlaySong/playsong.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<PlaySong>("PlaySong",1,0,"PlaySong");

    QQmlApplicationEngine engine;
    MusicPlayer musicPlayer;
    musicPlayer.findInMusicLibrary();
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
