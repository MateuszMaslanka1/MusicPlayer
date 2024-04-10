#include "musicplayer.h"
#include <filesystem>
#include <iostream>
#include <unistd.h>
#include <string>
#include <QVector>
#include <QString>
// MusicPlayer::MusicPlayer(QObject *parent) : QObject{parent} {

// }

void MusicPlayer::findInMusicLibrary() {
    QVector<QString> songList;
    char* username = getlogin();
    std::string pathToDirectory = "/home/" + std::string(username) + "/Music";
    if (std::filesystem::exists(pathToDirectory) && std::filesystem::is_directory(pathToDirectory)) {
        for (const auto& entry : std::filesystem::directory_iterator(pathToDirectory)) {
            std::cout << entry.path().filename() << std::endl;
            songList.append(QString::fromStdString(entry.path().filename()));
        }
        setSomeData(songList);
    } else {
        std::filesystem::create_directory(pathToDirectory);
    }
}
