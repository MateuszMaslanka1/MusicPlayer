#ifndef PLAYSONG_H
#define PLAYSONG_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QMediaPlayer>
#include <QAudioOutput>

class PlaySong : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString second READ second WRITE setSecondToSlider NOTIFY valueOfSecond)
    Q_PROPERTY(QString secondStart READ secondStart WRITE setSecondOnStart NOTIFY valueOfSecondStart)
    Q_PROPERTY(qint64 secondForShowOnLine READ secondForShowOnLine WRITE setSecondForShowOnLine NOTIFY valueOfSecondForShowOnLine)
    Q_PROPERTY(qint64 secondForShowOnLineAll READ secondForShowOnLineAll WRITE setSecondForShowOnLineAll NOTIFY valueOfSecondForShowOnLineAll)
    Q_PROPERTY(QString firstSong READ getFirstSong NOTIFY firstSongChanged)

public:
    int savePosition = 0;
    bool isPause = false;
    Q_INVOKABLE void setFirstSong();
    explicit PlaySong(QObject *parent = nullptr);
    void threadForPlaySound();
    std::string getSongDuration(const std::string& filePath);
    Q_INVOKABLE void playSound(QString musicPath);
    Q_INVOKABLE void setPosition(qint64 position);
    QString getFirstSong() const;


    QString second() const {
        return m_second;
    }

    qint64 secondForShowOnLine() const {
        return m_secondForShowOnLine;
    }

    qint64 secondForShowOnLineAll() const {
        return m_secondForShowOnLineAll;
    }

    QString secondStart() const {
        return m_secondStart;
    }

signals:
    void valueOfSecond();
    void valueOfSecondStart();
    void valueOfSecondForShowOnLine();
    void valueOfSecondForShowOnLineAll();
    void firstSongChanged();

public slots:
    QString getFirstSong();
    void displayDuration(qint64 duration);
    void updateMusicLibrary(const QVector<QString> &musicLibrary);
    qint64 setSecondForShowOnLineAll(qint64 value) {
        if (m_secondForShowOnLineAll != value) {
            m_secondForShowOnLineAll = value;
            emit valueOfSecondForShowOnLineAll();
        }
    }

    qint64 setSecondForShowOnLine(qint64 value) {
        if (m_secondForShowOnLine != value) {
            m_secondForShowOnLine = value;
            emit valueOfSecondForShowOnLine();
        }
    }

    void setSecondToSlider(QString value) {
        if (m_second != value) {
            m_second = value;
            emit valueOfSecond();
        }
    }

    void setSecondOnStart(QString value) {
        if (m_secondStart != value) {
            m_secondStart = value;
            emit valueOfSecondStart();
        }
    }

private:
    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;
    QString m_second;
    QString m_secondStart;
    qint64 m_secondForShowOnLine;
    qint64 m_secondForShowOnLineAll;
    QString firstSong;
    QVector<QString> m_getMusicLibrary;
};

#endif // PLAYSONG_H
