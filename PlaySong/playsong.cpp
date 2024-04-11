#include "playsong.h"
#include <QDebug>
#include <thread>
PlaySong::PlaySong(QObject *parent)
    : QObject{parent}
{}

void PlaySong::threadForPlaySound() {
    const std::string filePath = "/home/linux/Music/music.mp3";
    std::string command = "mpg123 ";
    command += filePath;

    qDebug() << "Starting sound playback...";
    system(command.c_str());
    qDebug() << "Sound playback finished.";
}

void PlaySong::playSound() {
    std::thread (&PlaySong::threadForPlaySound, this).detach();
}


