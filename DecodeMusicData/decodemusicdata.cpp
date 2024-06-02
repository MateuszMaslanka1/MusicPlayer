#include "decodemusicdata.h"
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QUrl>
#include <QDebug>
#include <QPointer>
#include <QEventLoop>

DecodeMusicData::DecodeMusicData(QObject *parent)
    : QObject{parent}
{}

QVector<QString> DecodeMusicData::getSongData(QString filePath) {
    QVector<QString> songLenght;
    QMediaPlayer tempPlayer;
    tempPlayer.setSource(QUrl::fromLocalFile(filePath));
    QEventLoop loop;
    connect(&tempPlayer, &QMediaPlayer::mediaStatusChanged, &loop, &QEventLoop::quit);
    tempPlayer.play();
    loop.exec();
    int duration = tempPlayer.duration();
    int seconds = (duration / 1000) % 60;
    int minutes = (duration / (1000 * 60)) % 60;

    songLenght.append(QString::number(minutes) + ":" + QString::number(seconds));
    return songLenght;
}
