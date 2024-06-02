#ifndef DECODEMUSICDATA_H
#define DECODEMUSICDATA_H

#include <QObject>

class DecodeMusicData : public QObject
{
    Q_OBJECT
public:
    explicit DecodeMusicData(QObject *parent = nullptr);

signals:
};

#endif // DECODEMUSICDATA_H
