#ifndef DECODEMUSICDATA_H
#define DECODEMUSICDATA_H

#include <QObject>

class DecodeMusicData : public QObject
{
    Q_OBJECT
public:
    explicit DecodeMusicData(QObject *parent = nullptr);
    QVector<QString> getSongData(QString filePath);

signals:
};

#endif // DECODEMUSICDATA_H
