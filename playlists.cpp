#include "playlists.h"
#include "SongDetails.h"

Playlists::Playlists(QObject *parent) : QObject{parent} {}

void Playlists::createPlayLists(const QString &playListName) {
    QSettings settings("playLists");
    QStringList emptyList;
    settings.setValue(playListName, emptyList);
    Playlists::loadPlayLists();
}

void Playlists::loadPlayLists() {
    QSettings settings("playLists");
    QStringList keys = settings.allKeys();
    QList<QStringList> songTimeAndName;
    QList<Playlist*> playlists;
    QList<SongDetails*> songDetails;
    foreach (const QString &key, keys) {
        songDetails.clear();
        QList<QString> songs = settings.value(key).toStringList();
        foreach (const QString &song, songs) {
            songDetails.append(new SongDetails(song,decodeMusicData.getSongData(song)));
        };
        playlists.append(new Playlist(key, songDetails));
    }
    setPlaylists(playlists);
}

void Playlists::addSongToPlayList(const QString &playListName, const QString &songName) {
    QSettings settings("playLists");
    QStringList songs = settings.value(playListName).toStringList();
    if (!songs.contains(songName)) {
        songs.append(songName);
        settings.setValue(playListName, songs);
        Playlists::loadPlayLists();
    }
}

void Playlists::deletePlayList(const QString &playListName) {
    QSettings settings("playLists");
    if (settings.contains(playListName)) {
        settings.remove(playListName);
    }
    Playlists::loadPlayLists();
}

void Playlists::removeSongFromPlayList(const QString &songName, const QString &playListName) {
    QSettings settings("playLists");
    QStringList songs = settings.value(playListName).toStringList();
    if (songs.contains(songName)) {
        songs.removeAll(songName);
        settings.setValue(playListName, songs);
    }
    Playlists::loadPlayLists();
}
