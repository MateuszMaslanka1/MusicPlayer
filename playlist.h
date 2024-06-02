// Playlist.h
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "SongDetails.h"

class Playlist : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QList<SongDetails*> songs READ songs CONSTANT)

public:
    Playlist(const QString &name, const QList<SongDetails*> &songs, QObject *parent = nullptr)
        : QObject(parent), m_name(name), m_songs(songs) {}

    QString name() const { return m_name; }
    QList<SongDetails*> songs() const { return m_songs; }

private:
    QString m_name;
    QList<SongDetails*> m_songs;
};

#endif // PLAYLIST_H
