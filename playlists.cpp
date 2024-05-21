#include "playlists.h"

Playlists::Playlists(QObject *parent) : QObject{parent} {}

void Playlists::createPlayLists(const QString &playListName) {
    QSettings settings("playLists");
    QStringList emptyList;
    settings.setValue(playListName, emptyList);
    qInfo() << "Created playlist" << playListName;
}

void Playlists::loadPlayLists() {
    QSettings settings("playLists");
    QStringList keys = settings.allKeys();
    QStringList playLists;

    foreach (const QString &key, keys) {
        QStringList songs = settings.value(key).toStringList();
        qInfo() << "Playlist:" << key << "Songs:" << songs;
        playLists.append(key);
    }
    setPlayLists(playLists);

}

void Playlists::addSongToPlayList(const QString &playListName, const QString &songName) {
    QSettings settings("playLists");
    QStringList songs = settings.value(playListName).toStringList();
    if (!songs.contains(songName)) {
        songs.append(songName);
        settings.setValue(playListName, songs);
        qInfo() << "Added song" << songName << "to playlist" << playListName;
    } else {
        qInfo() << "Song" << songName << "already exists in playlist" << playListName;
    }
}
