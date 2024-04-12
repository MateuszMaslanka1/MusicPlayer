#include "playsong.h"
#include <QDebug>

PlaySong::PlaySong(QObject *parent) : QObject(parent) {}

void PlaySong::playSound() {
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    player->setAudioOutput(audioOutput);

    connect(player, &QMediaPlayer::positionChanged, this, &PlaySong::displayDuration);

    connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::LoadedMedia) {
            audioOutput->setVolume(10);
            player->setPosition(30 * 1000);
            player->play();
        }
    });

    player->setSource(QUrl::fromLocalFile("/home/linux/Music/music.mp3"));
}

void PlaySong::displayDuration(qint64 duration) {
    QTime currentTime(0, (duration / 60000) % 60, (duration / 1000) % 60, (duration % 1000));

    qDebug() << "Czas odtwarzania: " << currentTime.toString("mm:ss");
}
