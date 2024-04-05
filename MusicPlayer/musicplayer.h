#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
class MusicPlayer : public QObject
{
    Q_OBJECT
    // Q_PROPERTY(int workload READ value WRITE setValue NOTIFY progress)
public:
    explicit MusicPlayer(QObject *parent = nullptr);
public:
    std::string findMusicInDirectory ();

signals:
};

#endif // MUSICPLAYER_H
