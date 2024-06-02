// Playlist.h
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QString>
#include <QStringList>

class Playlist : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QStringList songs READ songs CONSTANT)

public:
    Playlist(const QString &name, const QStringList &songs, QObject *parent = nullptr)
        : QObject(parent), m_name(name), m_songs(songs) {}

    QString name() const { return m_name; }
    QStringList songs() const { return m_songs; }

private:
    QString m_name;
    QStringList m_songs;
};

#endif // PLAYLIST_H
