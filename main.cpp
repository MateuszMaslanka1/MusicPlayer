#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <future>
#include <string>
#include <QDebug>

void playSound(const std::string& filePath) {
    // Skonstruuj polecenie mpg123
    std::string command = "mpg123 ";
    command += filePath;

    // Wywołaj polecenie mpg123 za pomocą funkcji systemowej
    qDebug() << "Starting sound playback...";
    system(command.c_str());
    qDebug() << "Sound playback finished.";
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/MusicPlayer/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    const std::string filePath = "/home/linux/Downloads/music.mp3"; // Upewnij się, że podajesz poprawną ścieżkę i format pliku dźwiękowego

    // Uruchom nowy wątek, aby odtworzyć dźwięk
     std::future<void> soundFuture = std::async(std::launch::async, playSound, filePath);
    return app.exec();
}
