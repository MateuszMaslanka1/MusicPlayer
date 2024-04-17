#include "playsong.h"
#include <QDebug>

PlaySong::PlaySong(QObject *parent) : QObject(parent)  {}

void PlaySong::playSound() {
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    player->setAudioOutput(audioOutput);

    connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::LoadedMedia) {
            audioOutput->setVolume(10);
            qint64 durationInMillis = player->duration();
            int durationInSeconds = durationInMillis / 1000;
            qDebug() << "Długość utworu w sekundach: " << durationInSeconds;

            QTime currentTime(0, 0, 0);
            emit setSecondToSlider(currentTime.addSecs(durationInSeconds).toString("mm:ss"));
            emit setSecondForShowOnLineAll(durationInSeconds);
            player->play();
        }
    });

    connect(player, &QMediaPlayer::positionChanged, this, &PlaySong::displayDuration);

    player->setSource(QUrl::fromLocalFile("/home/linux/Music/music.mp3"));
}

void PlaySong::displayDuration(qint64 duration) {
    qint64 durationInSeconds = duration / 1000;
    QTime currentTime(0, 0, 0);
    QString formattedTime = currentTime.addSecs(durationInSeconds).toString("mm:ss");
    emit setSecondOnStart(formattedTime);
    emit setSecondForShowOnLine(durationInSeconds);
}

void PlaySong::updateMusicLibrary(const QVector<QString> &musicLibrary) {
    // Tutaj możesz zrobić, co zechcesz z listą utworów, na przykład wyświetlić ją
    qDebug() << "Nowa lista utworów:" << musicLibrary;
}
