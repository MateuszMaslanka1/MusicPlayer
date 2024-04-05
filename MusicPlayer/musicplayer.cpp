#include "musicplayer.h"
#include <filesystem>
#include <iostream>
#include <unistd.h>

MusicPlayer::MusicPlayer(QObject *parent) : QObject{parent} {

}

std::string MusicPlayer::findMusicInDirectory() {
    char* username = getlogin();
    std::string sciezka_katalogu = "/home/" + std::string(username) + "/Music";

    if (std::filesystem::exists(sciezka_katalogu) && std::filesystem::is_directory(sciezka_katalogu)) {
        std::cout << "jes ok sciezka_katalogu" << std::endl;
    } else {
        std::cout << "nie jest ok sciezka_katalogu" << std::endl;
        std::filesystem::create_directory(sciezka_katalogu);
    }
    for (const auto& entry : std::filesystem::directory_iterator(sciezka_katalogu)) {
        std::cout << entry.path().filename() << std::endl;
    }
    return "";
}
