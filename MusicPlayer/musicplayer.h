#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
class MusicPlayer : public QObject
{
    Q_OBJECT
public:
    explicit MusicPlayer(QObject *parent = nullptr);
    std::string findMusicInDirectory ();

signals:
};

#endif // MUSICPLAYER_H
