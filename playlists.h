#ifndef PLAYLISTS_H
#define PLAYLISTS_H

#include <QObject>
#include <QSettings>
#include <QStringList>

class Playlists : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList playLists READ playLists WRITE setPlayLists NOTIFY playListsChanged)

public:
    explicit Playlists(QObject *parent = nullptr);
    Q_INVOKABLE void createPlayLists(const QString &playListName);
    Q_INVOKABLE void loadPlayLists();

    QStringList playLists() const {
        qInfo() << m_playLists;
        return m_playLists;
    }

signals:
    void playListsChanged();

public slots:
    void setPlayLists(const QStringList &playLists) {
        if (m_playLists != playLists) {
            m_playLists = playLists;
            emit playListsChanged();
        }
    }

private:
    QStringList m_playLists;
};

#endif // PLAYLISTS_H
