#ifndef PLAYSONG_H
#define PLAYSONG_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <mpg123.h>
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
    Q_PROPERTY(QString songName READ songName WRITE setSongName NOTIFY setSongNameChanged)
    Q_PROPERTY(bool isPauseToView READ isPauseToView WRITE setIsPause NOTIFY setIsPauseChanged)

public:
    int savePosition = 0;
    bool isPause = false;
    bool isPlayLists = false;
    QString nextSong;
    QString playlistName = "";
    Q_INVOKABLE void setFirstSong();
    explicit PlaySong(QObject *parent = nullptr);
    void threadForPlaySound();
    std::string getSongDuration(const std::string& filePath);
    Q_INVOKABLE void playSound(QString musicPath);
    Q_INVOKABLE void getPlaylist(QString playlistName, bool isMUsicLibrary);
    Q_INVOKABLE void setPosition(qint64 position);
    Q_INVOKABLE void nextMusic();
    Q_INVOKABLE void backMusic();
    QString getFirstSong() const;

    bool isPauseToView() const {
        return m_isPauseToView;
    }

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

    QString songName() const {
        return m_songName;
    }


signals:
    void valueOfSecond();
    void valueOfSecondStart();
    void valueOfSecondForShowOnLine();
    void valueOfSecondForShowOnLineAll();
    void firstSongChanged();
    void setSongNameChanged();
    void setIsPauseChanged();

public slots:
    QString getFirstSong();
    void displayDuration(qint64 duration);
    void updateMusicLibrary(const QVector<QString> &musicLibrary);

    void setSongName(QString value) {
        if (m_songName != value) {
            m_songName = value;
            emit setSongNameChanged();
        }
    }

    void setIsPause(bool value) {
        if (m_isPauseToView != value) {
            m_isPauseToView = value;
            emit setIsPauseChanged();
        }
    }

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
    QString m_songName;
    qint64 m_secondForShowOnLine;
    qint64 m_secondForShowOnLineAll;
    QString firstSong;
    QVector<QString> m_getMusicLibrary;
    bool m_isPauseToView;
};

#endif // PLAYSONG_H
