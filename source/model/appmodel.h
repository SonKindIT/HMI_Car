#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QDateTime>
#include "../../common/types/vehicletypes.h"

class AppModel : public QObject
{
    Q_OBJECT
private:
    Q_PROPERTY(qint16 curSpeed READ curSpeed WRITE setCurSpeed NOTIFY curSpeedChanged FINAL)
    Q_PROPERTY(qint16 curTemp READ curTemp WRITE setCurTemp NOTIFY curTempChanged FINAL)
    Q_PROPERTY(qint16 curBattery READ curBattery WRITE setCurBattery NOTIFY curBatteryChanged FINAL)
    Q_PROPERTY(qint16 curFualCar READ curFualCar WRITE setCurFualCar NOTIFY curFualCarChanged FINAL)
    Q_PROPERTY(qint16 curDistCar READ curDistCar WRITE setCurDistCar NOTIFY curDistCarChanged FINAL)
    Q_PROPERTY(QDateTime curDateTime READ currentDateTime WRITE setCurrentDateTime NOTIFY currentDateTimeChanged FINAL)
    Q_PROPERTY(bool curAbsInd READ curAbsInd WRITE setCurAbsInd NOTIFY curAbsIndChanged FINAL)
    Q_PROPERTY(bool curParkBrakeInd READ curParkBrakeInd WRITE setCurParkBrakeInd NOTIFY curParkBrakeIndChanged FINAL)
    Q_PROPERTY(bool curErrInd READ curErrInd WRITE setCurErrInd NOTIFY curErrIndChanged FINAL)
    Q_PROPERTY(bool curSeatBeltInd READ curSeatBeltInd WRITE setCurSeatBeltInd NOTIFY curSeatBeltIndChanged FINAL)
    Q_PROPERTY(VehicleTypes::Gear curParkState READ curParkState WRITE setCurParkState NOTIFY curParkStateChanged FINAL)
    Q_PROPERTY(QString curDate READ curDate WRITE setCurDate NOTIFY curDateChanged FINAL)
    Q_PROPERTY(QString curTime READ curTime WRITE setcurTime NOTIFY curTimeChanged FINAL)

    Q_PROPERTY(bool curHeadLight READ curHeadLight WRITE setCurHeadLight NOTIFY curHeadLightChanged FINAL)
    Q_PROPERTY(bool rearFogLight READ rearFogLight WRITE setRearFogLight NOTIFY rearFogLightChanged FINAL)
    Q_PROPERTY(bool autoLight READ autoLight WRITE setAutoLight NOTIFY autoLightChanged FINAL)
    Q_PROPERTY(bool positionLight READ positionLight WRITE setPositionLight NOTIFY positionLightChanged FINAL)


    qint16 m_curSpeed;

    qint16 m_curTemp;

    qint16 m_curBattery;

    qint16 m_curFualCar;

    qint16 m_curDistCar;

    QDateTime m_curDateTime;

    bool m_curAbsInd;

    bool m_curParkBrakeInd;

    bool m_curErrInd;

    bool m_curSeatBeltInd;

    VehicleTypes::Gear m_curParkState;

    bool m_curHeadLight;

    bool m_rearFogLight;

    bool m_autoLight;

    bool m_positionLight;

    QString m_curDate;

    QString m_curTime;

public:
    explicit AppModel(QObject *parent = nullptr);
    qint16 curSpeed() const;
    void setCurSpeed(qint16 newCurSpeed);
    qint16 curTemp() const;
    void setCurTemp(qint16 newCurTemp);

    qint16 curBattery() const;
    void setCurBattery(qint16 newCurBattery);

    qint16 curFualCar() const;
    void setCurFualCar(qint16 newCurFualCar);

    qint16 curDistCar() const;
    void setCurDistCar(qint16 newCurDistCar);

    QDateTime currentDateTime() const;
    void setCurrentDateTime(const QDateTime &newCurDateTime);

    bool curAbsInd() const;
    void setCurAbsInd(bool newCurAbsInd);

    bool curParkBrakeInd() const;
    void setCurParkBrakeInd(bool newCurParkBrakeInd);

    bool curErrInd() const;
    void setCurErrInd(bool newCurErrInd);

    bool curSeatBeltInd() const;
    void setCurSeatBeltInd(bool newCurSeatBeltInd);

    VehicleTypes::Gear curParkState() const;
    void setCurParkState(const VehicleTypes::Gear &newCurParkState);

    bool curHeadLight() const;
    void setCurHeadLight(bool newCurHeadLight);

    bool rearFogLight() const;
    void setRearFogLight(bool newRearFogLight);

    bool autoLight() const;
    void setAutoLight(bool newAutoLight);

    bool positionLight() const;
    void setPositionLight(bool newPositionLight);

    QString curDate() const;
    void setCurDate(const QString &newCurDate);

    QString curTime() const;
    void setcurTime(const QString &newCurTime);

signals:
    void curSpeedChanged();
    void curTempChanged();
    void curBatteryChanged();
    void curFualCarChanged();
    void curDistCarChanged();
    void currentDateTimeChanged();
    void curAbsIndChanged();
    void curParkBrakeIndChanged();
    void curErrIndChanged();
    void curSeatBeltIndChanged();
    void curParkStateChanged();
    void curHeadLightChanged();
    void rearFogLightChanged();
    void autoLightChanged();
    void positionLightChanged();
    void curDateChanged();
    void curTimeChanged();
};

#endif // APPMODEL_H
