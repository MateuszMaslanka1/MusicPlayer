#ifndef PLAYSONG_H
#define PLAYSONG_H

#include <QObject>

class PlaySong : public QObject
{
    Q_OBJECT
public:
    explicit PlaySong(QObject *parent = nullptr);
    void threadForPlaySound();
    Q_INVOKABLE void playSound();

signals:
};

#endif // PLAYSONG_H
