#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include <QObject>
#include <QSettings>

class Playlists : public QObject
{
    Q_OBJECT
public:
    explicit Playlists(QObject *parent = nullptr);
    Q_INVOKABLE void createPlayLists(const QString &playListName);
    Q_INVOKABLE QStringList loadPlayLists();

signals:
    void playListsLoaded(const QStringList &playLists);

public slots:
};

#endif // PLAYLISTS_H
