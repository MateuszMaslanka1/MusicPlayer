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
public:
    explicit PlaySong(QObject *parent = nullptr);
    void threadForPlaySound();
    std::string getSongDuration(const std::string& filePath);
    Q_INVOKABLE void playSound();

    QString second() const {
        return m_second;
    }

signals:
    void valueOfSecond();

public slots:
    void displayDuration(qint64 duration);

    void setSecondToSlider(QString value) {
        if (m_second != value) {
            m_second = value;
            emit valueOfSecond();
        }
    }

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QString m_second;

};

#endif // PLAYSONG_H
