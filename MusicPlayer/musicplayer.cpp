#include "musicplayer.h"
#include <cstdlib>

MusicPlayer::MusicPlayer(QObject *parent) : QObject{parent} {

}

std::string MusicPlayer::findMusicInDirectory() {
    return "";
}
