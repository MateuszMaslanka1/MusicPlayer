#include "playlists.h"

Playlists::Playlists(QObject *parent) : QObject{parent} {}



void Playlists::createPlayLists(const QString &playListName) {
    QSettings settings("playLists");
    settings.setValue(playListName, playListName);
    qInfo() << playListName;
}

void Playlists::loadPlayLists() {
    QSettings settings("playLists");
    QStringList keys = settings.allKeys();
    QStringList playLists;

    foreach (const QString &key, keys) {
        qInfo() << settings.value(key).toString();
        playLists.append(settings.value(key).toString());
    }
    setPlayLists(playLists);
}
