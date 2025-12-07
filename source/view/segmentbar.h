#ifndef SEGMENTBAR_H
#define SEGMENTBAR_H

#include <QObject>

class SegmentBar : public QObject
{
    Q_OBJECT
public:
    explicit SegmentBar(QObject *parent = nullptr);

signals:
};

#endif // SEGMENTBAR_H
