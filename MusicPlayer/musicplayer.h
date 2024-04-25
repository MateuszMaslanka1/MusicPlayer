#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QVector>
#include <QString>

class MusicPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> someData READ someData WRITE setSomeData NOTIFY someDataChanged)
    Q_PROPERTY(QVector<QString> path READ path WRITE setPath NOTIFY somePathChanged)
public:
    explicit MusicPlayer(QObject *parent = nullptr);

    void findInMusicLibrary();
    QVector<QString>getMusicLibrary();
    QVector<QString> someData() const {
        return m_someData;
    }

    QVector<QString> path() const {
        return m_somePath;
    }

signals:
    void someDataChanged();
    void musicLibraryChanged(const QVector<QString> &musicLibrary);
    void somePathChanged();

public slots:
    void setSomeData(const QVector<QString> &songList) {
        if (m_someData != songList) {
            m_someData = songList;
            emit someDataChanged();
        }
    }

    void setPath(const QVector<QString> &path) {
        if (m_somePath != path) {
            m_somePath = path;
            emit somePathChanged();
        }
    }

private:
    QVector<QString> m_someData;
    QVector<QString> m_somePath;
};

#endif // MUSICPLAYER_H
