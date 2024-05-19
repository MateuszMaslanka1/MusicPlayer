#include "musicplayer.h"
#include <filesystem>
#include <unistd.h>
#include <string>
#include <QVector>
#include <QString>
#include <mpg123.h>
#include <QDebug>
#include <QSettings>

MusicPlayer::MusicPlayer(QObject *parent) : QObject{parent}, m_player(new QMediaPlayer(this)) {}

void MusicPlayer::findInMusicLibrary() {
    QVector<QString> songList;
    QVector<QString> songListFullPath;
    QVector<QString> songDurationTime;
    QVector<QString> songLenght;
    QSettings settings("PathToUserDirectory");

    char* username = getlogin();
    std::string pathToMusicDirectory = "/home/" + std::string(username) + "/Music";

    if (!std::filesystem::exists(pathToMusicDirectory) && !std::filesystem::is_directory(pathToMusicDirectory)) {
        std::filesystem::create_directory(pathToMusicDirectory);
        settings.setValue(QString::fromStdString(pathToMusicDirectory), QString::fromStdString(pathToMusicDirectory));
    } else if(!settings.contains(pathToMusicDirectory)) {
        settings.setValue(QString::fromStdString(pathToMusicDirectory), QString::fromStdString(pathToMusicDirectory));
    }
    QStringList allKeys = settings.allKeys();
    for (const QString &key : allKeys) {
        QString value = settings.value(key).toString();
        for (const auto& entry : std::filesystem::directory_iterator(value.toStdString())) {
            if (mpg123_init() != MPG123_OK) {
                qCritical() << "Błąd: Inicjalizacja mpg123.";
                return;
            }
            mpg123_handle* mh = mpg123_new(nullptr, nullptr);
            QString filePath = QString::fromStdString(entry.path());
            int err = mpg123_open(mh, filePath.toStdString().c_str());

            long rate;
            mpg123_getformat(mh, &rate, nullptr, nullptr);
            off_t length = mpg123_length(mh);

            double durationMinutes = (double)length / (rate * 60.0);
            int minutes = static_cast<int>(durationMinutes);
            int seconds = static_cast<int>((durationMinutes - minutes) * 60);

            songList.append(QString::fromStdString(entry.path().filename()));
            songListFullPath.append(QString::fromStdString(entry.path()));
            songDurationTime.append(songDurationTime);
            songLenght.append(QString::number(minutes) + ":" + QString::number(seconds));
            mpg123_close(mh);
            mpg123_delete(mh);
        }
        mpg123_exit();
    }

    setSomeData(songList);
    setPath(songListFullPath);
    setLenghtOfSong(songLenght);
    musicLibraryChanged(songListFullPath);
}

void MusicPlayer::getPathToDirectory(QString pathToDirectory) {
    qInfo() << pathToDirectory;
    QString cleanedPath = pathToDirectory;
    if (cleanedPath.startsWith("file://")) {
        cleanedPath = cleanedPath.mid(7);
    }
    QSettings settings("PathToUserDirectory");
    QStringList allKeys = settings.allKeys();
    bool valueExists = false;
    for (const QString &key : allKeys) {
        QString value = settings.value(key).toString();
        if (value == cleanedPath) {
            valueExists = true;
            qInfo() << "Wartość '" << cleanedPath << "' już istnieje w pliku konfiguracyjnym.";
            break;
        }
    }
    if (!valueExists) {
        settings.setValue(cleanedPath, cleanedPath);
        qInfo() << "Wartość '" << cleanedPath << "' została pomyślnie zapisana w pliku konfiguracyjnym.";
    }
}
