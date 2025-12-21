#ifndef VEHICLETYPES_H
#define VEHICLETYPES_H

#include <QObject>

class VehicleTypes: public QObject
{
    Q_OBJECT

public:
    enum class Gear{
        P,
        R,
        N,
        D
    };
    Q_ENUM(Gear)
};

#endif // VEHICLETYPES_H
