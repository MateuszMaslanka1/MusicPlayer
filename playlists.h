#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include <QObject>
#include <QSettings>
#include <QStringList>
#include <QList>
class Playlists : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList playLists READ playLists WRITE setPlayLists NOTIFY playListsChanged)
    Q_PROPERTY(QStringList songForPlayLists READ songForPlayLists WRITE setSongForPlayLists NOTIFY songForPlayListsChanged)

public:
    explicit Playlists(QObject *parent = nullptr);
    Q_INVOKABLE void addSongToPlayList(const QString &playListName, const QString &songName);
    Q_INVOKABLE void createPlayLists(const QString &playListName);
    Q_INVOKABLE void loadPlayLists();

    QStringList playLists() const {
        return m_playLists;
    }

    QStringList songForPlayLists() const {
        return m_songForPlayLists;
    }

signals:
    void playListsChanged();
    void songForPlayListsChanged();

public slots:
    void setPlayLists(const QStringList &playLists) {
        if (m_playLists != playLists) {
            m_playLists = playLists;
            emit playListsChanged();
        }
    }

    void setSongForPlayLists(const QStringList &playListsSong) {
        if (m_songForPlayLists != playListsSong) {
            m_songForPlayLists = playListsSong;
            emit songForPlayListsChanged();
        }
    }

private:
    QStringList m_playLists;
    QStringList m_songForPlayLists;
    QSettings settings;
};

#endif // PLAYLISTS_H
