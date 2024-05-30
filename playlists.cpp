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
    QList<QStringList> songForPlayLists;

    foreach (const QString &key, keys) {
        QStringList songs = settings.value(key).toStringList();
        qInfo() << "Playlist:" << key << "Songs:" << songs;
        playLists.append(key);
        songForPlayLists.append(songs);
    }
    setPlayLists(playLists);
    // qInfo() << songForPlayLists;
    setSongForPlayLists(songForPlayLists);
}

void Playlists::addSongToPlayList(const QString &playListName, const QString &songName) {
    QSettings settings("playLists");
    QStringList songs = settings.value(playListName).toStringList();
    if (!songs.contains(songName)) {
        songs.append(songName);
        settings.setValue(playListName, songs);
    } else {
        qInfo() << "Song" << songName << "already exists in playlist" << playListName;
    }
}

void Playlists::deletePlayList(const QString &playListName) {
    QSettings settings("playLists");
    if (settings.contains(playListName)) {
        settings.remove(playListName);
        qInfo() << "Deleted playlist" << playListName;
    } else {
        qInfo() << "Playlist" << playListName << "does not exist";
    }
}

void Playlists::removeSongFromPlayList(const QString &playListName, const QString &songName) {
    // QSettings settings("playLists");
    // QStringList songs = settings.value(playListName).toStringList();
      qInfo() << playListName;
    // if (songs.contains(songName)) {
    //     // songs.removeAll(songName);
    //     // settings.setValue(playListName, songs);
    //     qInfo() << "Removed song" << songName << "from playlist" << playListName;
    // } else {
    //     qInfo() << "Song" << songName << "not found in playlist" << playListName;
    // }
}
