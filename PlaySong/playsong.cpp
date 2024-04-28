#include "playsong.h"
#include <QDebug>
PlaySong::PlaySong(QObject *parent) : QObject(parent), m_player(new QMediaPlayer(this)) {}

QVector<QString> getMusicLibrary;

void PlaySong::playSound(QString musicPath) {
    QAudioOutput *audioOutput = new QAudioOutput;
    if (musicPath == "") {
        musicPath = getMusicLibrary[0];
    }

    m_player->setAudioOutput(audioOutput);
    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::LoadedMedia) {
            audioOutput->setVolume(10);
            qint64 durationInMillis = m_player->duration();
            int durationInSeconds = durationInMillis / 1000;
            QTime currentTime(0, 0, 0);
            emit setSecondToSlider(currentTime.addSecs(durationInSeconds).toString("mm:ss"));
            emit setSecondForShowOnLineAll(durationInSeconds);
            m_player->play();
        }
    });
    qInfo() << musicPath;
    connect(m_player, &QMediaPlayer::positionChanged, this, &PlaySong::displayDuration);
    m_player->setSource(QUrl::fromLocalFile(musicPath));
}

void PlaySong::displayDuration(qint64 duration) {
    qint64 durationInSeconds = duration / 1000;
    QTime currentTime(0, 0, 0);
    QString formattedTime = currentTime.addSecs(durationInSeconds).toString("mm:ss");
    emit setSecondOnStart(formattedTime);
    emit setSecondForShowOnLine(durationInSeconds);
}

void PlaySong::updateMusicLibrary(const QVector<QString> &musicLibrary) {
    getMusicLibrary = musicLibrary;
}

void PlaySong::setPosition(qint64 position) {
    qInfo() << position;
    if (!m_player) {
        qWarning() << "Player is not initialized!";
        return;
    }

    QMediaPlayer::MediaStatus mediaStatus = m_player->mediaStatus();

    if (mediaStatus == QMediaPlayer::LoadedMedia || mediaStatus == QMediaPlayer::BufferedMedia) {
        qint64 setPositionStop = position * 1000;
        m_player->setPosition(setPositionStop);
    } else {
        connect(m_player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus newStatus) {
            if (newStatus == QMediaPlayer::LoadedMedia || newStatus == QMediaPlayer::BufferedMedia) {
                qint64 setPosition = position * 1000;
                m_player->setPosition(setPosition);
                disconnect(m_player, &QMediaPlayer::mediaStatusChanged, this, nullptr);
            }
        });
    }
}
