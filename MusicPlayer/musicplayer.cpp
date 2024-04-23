#include "musicplayer.h"
#include <filesystem>
#include <iostream>
#include <unistd.h>
#include <string>
#include <QVector>
#include <QString>
#include <QDebug>
MusicPlayer::MusicPlayer(QObject *parent) : QObject{parent} {}

void MusicPlayer::findInMusicLibrary() {
    QVector<QString> songList;
    QVector<QString> songListFullPath;
    char* username = getlogin();
    std::string pathToDirectory = "/home/" + std::string(username) + "/Music";
    if (std::filesystem::exists(pathToDirectory) && std::filesystem::is_directory(pathToDirectory)) {
        for (const auto& entry : std::filesystem::directory_iterator(pathToDirectory)) {
            songList.append(QString::fromStdString(entry.path().filename()));
            songListFullPath.append(QString::fromStdString(entry.path()));
        }
        setSomeData(songList);
        musicLibraryChanged(songListFullPath);
    } else {
        std::filesystem::create_directory(pathToDirectory);
    }
}

QVector<QString> MusicPlayer::getMusicLibrary() {
    qDebug() << m_someData;
    return m_someData;
}
