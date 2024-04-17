#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QVector>
#include <QString>

class MusicPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> someData READ someData WRITE setSomeData NOTIFY someDataChanged)

public:
    explicit MusicPlayer(QObject *parent = nullptr);

    void findInMusicLibrary();
    QVector<QString>getMusicLibrary();
    QVector<QString> someData() const {
        return m_someData;
    }

signals:
    void someDataChanged();
    void musicLibraryChanged(const QVector<QString> &musicLibrary);

public slots:
    void setSomeData(const QVector<QString> &songList) {
        if (m_someData != songList) {
            m_someData = songList;
            emit someDataChanged();
        }
    }

private:
    QVector<QString> m_someData;
};

#endif // MUSICPLAYER_H
