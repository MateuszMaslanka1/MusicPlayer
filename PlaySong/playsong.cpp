#include "playsong.h"
#include <QDebug>
#include<QMediaMetaData>
PlaySong::PlaySong(QObject *parent) : QObject(parent), m_player(new QMediaPlayer(this)) {}
#include <QFileInfo>
QVector<QString> getMusicLibrary;

void PlaySong::setFirstSong() {
    firstSong = getMusicLibrary[0];
}

QString PlaySong::getFirstSong() {
    return firstSong;
}

void PlaySong::playSound(QString musicPath) {
    QAudioOutput *audioOutput = new QAudioOutput;
    qInfo() << musicPath;
    if (PlaySong::isPause && musicPath == firstSong) {
        m_player->pause();
        PlaySong::savePosition = m_player->position() / 1000;
        PlaySong::isPause = false;
    } else {
        firstSong = musicPath;
        m_player->setAudioOutput(audioOutput);
        connect(m_player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
            if (status == QMediaPlayer::LoadedMedia) {
                audioOutput->setVolume(10);
                qint64 durationInMillis = m_player->duration();
                int durationInSeconds = durationInMillis / 1000;

                QTime currentTime(0, 0, 0);
                emit setSecondToSlider(currentTime.addSecs(durationInSeconds).toString("mm:ss"));
                emit setSecondForShowOnLineAll(durationInSeconds);
                if (PlaySong::savePosition != 0) {
                    m_player->setPosition(PlaySong::savePosition * 1000);
                    PlaySong::savePosition = 0;
                }
                QString fileName = QFileInfo(firstSong).fileName();
                setSongName(fileName);
                m_player->play();
            }
        });
        connect(m_player, &QMediaPlayer::positionChanged, this, &PlaySong::displayDuration);
        m_player->setSource(QUrl::fromLocalFile(firstSong));
        PlaySong::isPause = true;
    }
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

void PlaySong::backMusic() {
    if (!getMusicLibrary.isEmpty()) {
        int currentIndex = getMusicLibrary.indexOf(firstSong);
        if (currentIndex != -1) {
            if (currentIndex > 0) {
                QString previousSong = getMusicLibrary[currentIndex - 1];
                playSound(previousSong);
            } else {
                QString lastSong = getMusicLibrary.last();
                playSound(lastSong);
            }
        }
    }
}

void PlaySong::nextMusic() {
    if (!getMusicLibrary.isEmpty()) {
        int currentIndex = getMusicLibrary.indexOf(firstSong);
        if (currentIndex != -1) {
            if (currentIndex < getMusicLibrary.size() - 1) {
                QString nextSong = getMusicLibrary[currentIndex + 1];
                playSound(nextSong);
            } else {
                QString firstSong = getMusicLibrary.first();
                playSound(firstSong);
            }
        }
    }
}
