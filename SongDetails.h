#ifndef SONGDETAILS_H
#define SONGDETAILS_H
#include <QObject>
#include <QString>

class SongDetails : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString songName READ songName CONSTANT)
    Q_PROPERTY(QVector<QString> songTime READ songTime CONSTANT)

public:
    SongDetails(const QString &songName, const QVector<QString> &songTime, QObject *parent = nullptr)
        : QObject(parent), m_songName(songName), m_songTime(songTime) {}

    QString songName() const { return m_songName; }
    QVector<QString> songTime() const { return m_songTime; }

private:
    QString m_songName;
    QVector<QString> m_songTime;
};
#endif // SONGDETAILS_H
