#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QMediaPlayer>
#include "./DecodeMusicData/decodemusicdata.h"
class MusicPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> someData READ someData WRITE setSomeData NOTIFY someDataChanged)
    Q_PROPERTY(QVector<QString> path READ path WRITE setPath NOTIFY somePathChanged)
    Q_PROPERTY(QVector<QString> songLenght READ songLenght WRITE setLenghtOfSong NOTIFY songLenghtChanged)

public:
    explicit MusicPlayer(QObject *parent = nullptr);

    void findInMusicLibrary();
    Q_INVOKABLE void getPathToDirectory(QString pathToDirectory);
    QVector<QString>getMusicLibrary();
    DecodeMusicData decodeMusicData;

    QVector<QString> songLenght() const {
        return m_songLenght;
    }
    QVector<QString> someData() const {
        return m_someData;
    }

    QVector<QString> path() const {
        return m_somePath;
    }

signals:
    void someDataChanged();
    void songLenghtChanged();
    void musicLibraryChanged(const QVector<QString> &musicLibrary);
    void somePathChanged();

public slots:
    void setLenghtOfSong(const QVector<QString> &songLenght) {
        if (m_songLenght != songLenght) {
            m_songLenght = songLenght;
            emit songLenghtChanged();
        }
    }

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
    QVector<QString> m_songLenght;
    QMediaPlayer *m_player;
};

#endif // MUSICPLAYER_H
