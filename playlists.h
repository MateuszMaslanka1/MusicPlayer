#ifndef PLAYLISTS_H
#define PLAYLISTS_H
#include "playlist.h"
#include <QObject>
#include <QSettings>
#include <QStringList>
#include <QList>
#include <./DecodeMusicData/decodemusicdata.h>

class Playlists : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Playlist*> playlistsNameAndSong READ playlistsNameAndSong WRITE setPlaylists NOTIFY playlistsChanged)
    Q_PROPERTY(QList<QStringList> songForPlayLists READ songForPlayLists WRITE setSongForPlayLists NOTIFY songForPlayListsChanged)

public:
    explicit Playlists(QObject *parent = nullptr);
    Q_INVOKABLE void addSongToPlayList(const QString &playListName, const QString &songName);
    Q_INVOKABLE void createPlayLists(const QString &playListName);
    Q_INVOKABLE void loadPlayLists();
    Q_INVOKABLE void deletePlayList(const QString &playListName);
    Q_INVOKABLE void removeSongFromPlayList(const QString &playListName, const QString &songName);
    DecodeMusicData decodeMusicData;

    QList<Playlist*> playlistsNameAndSong() const {
        return m_playlists;
    }

    QList<QStringList> songForPlayLists() const {
        return m_songForPlayLists;
    }

signals:
    void playlistsChanged();
    void songForPlayListsChanged();

public slots:
    void setPlaylists(const QList<Playlist*> &playlists) {
        m_playlists = playlists;
        emit playlistsChanged();
    }

    void setSongForPlayLists(const QList<QStringList> &playListsSong) {
        if (m_songForPlayLists != playListsSong) {
            m_songForPlayLists = playListsSong;
            emit songForPlayListsChanged();
        }
    }

private:
    QList<Playlist*> m_playlists;
    QList<QStringList> m_songForPlayLists;
    QSettings settings;
};

#endif // PLAYLISTS_H
