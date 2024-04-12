#ifndef PLAYSONG_H
#define PLAYSONG_H
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QMediaPlayer>
#include <QAudioOutput>

class PlaySong : public QObject
{
    Q_OBJECT
public:
    explicit PlaySong(QObject *parent = nullptr);
    void threadForPlaySound();
    std::string getSongDuration(const std::string& filePath);
    Q_INVOKABLE void playSound();

signals:

public slots:
    void displayDuration(qint64 duration);

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

};

#endif // PLAYSONG_H
