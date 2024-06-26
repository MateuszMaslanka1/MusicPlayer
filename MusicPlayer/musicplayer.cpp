#include "musicplayer.h"
#include <filesystem>
#include <unistd.h>
#include <string>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QSettings>
#include <QMediaPlayer>
#include <QPointer>
#include <QEventLoop>

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
            QString filePath = QString::fromStdString(entry.path());
            songLenght.append(decodeMusicData.getSongData(filePath));
            songList.append(QString::fromStdString(entry.path().filename()));
            songListFullPath.append(QString::fromStdString(entry.path()));
        }
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
        MusicPlayer::findInMusicLibrary();
    }

}
