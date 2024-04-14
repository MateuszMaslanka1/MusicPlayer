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
    Q_PROPERTY(int totalDurationInSeconds READ totalDurationInSeconds NOTIFY totalDurationInSecondsChanged) // Dodany sygnał dla całkowitej długości utworu
public:
    explicit PlaySong(QObject *parent = nullptr);
    void threadForPlaySound();
    std::string getSongDuration(const std::string& filePath);
    Q_INVOKABLE void playSound();

    QString second() const {
        return m_second;
    }

    QString secondStart() const {
        return m_secondStart;
    }

    int totalDurationInSeconds() const {
        return m_totalDurationInSeconds;
    }

signals:
    void valueOfSecond();
    void valueOfSecondStart();
    void totalDurationInSecondsChanged(int totalDurationInSeconds); // Deklaracja sygnału dla całkowitej długości utworu

public slots:
    void displayDuration(qint64 duration);

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

    void onTotalDurationChanged(int totalDurationInSeconds) {
        if (m_totalDurationInSeconds != totalDurationInSeconds) {
            m_totalDurationInSeconds = totalDurationInSeconds;
            emit totalDurationInSecondsChanged(m_totalDurationInSeconds);
        }
    }

private:
    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;
    QString m_second;
    QString m_secondStart;
    int m_totalDurationInSeconds;
    int m_positionInSeconds;
};

#endif // PLAYSONG_H
