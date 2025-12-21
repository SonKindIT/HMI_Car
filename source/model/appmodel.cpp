#include "appmodel.h"
#include<QDebug>

AppModel::AppModel(QObject *parent)
    : QObject(parent)
    , m_curSpeed(0)
    , m_curTemp(0)
    , m_curBattery(0)
    , m_curFualCar(0)
    , m_curDistCar(0)
    , m_curDateTime(QDateTime::currentDateTime())
    , m_curAbsInd(false)
    , m_curParkBrakeInd(false)
    , m_curErrInd(false)
    , m_curSeatBeltInd(false)
    , m_curParkState(VehicleTypes::Gear::P)
    , m_curHeadLight(false)
    , m_rearFogLight(false)
    , m_autoLight(false)
    , m_positionLight(false)
    , m_curDate(QDateTime::currentDateTime().date().toString("dd/MM/yyyy"))
    , m_curTime(QDateTime::currentDateTime().time().toString("HH:mm:ss"))
{}

qint16 AppModel::curSpeed() const
{
    return m_curSpeed;
}

void AppModel::setCurSpeed(qint16 newCurSpeed)
{
    // qDebug() << "AppModel::setCurSpeed = " << newCurSpeed << Qt::endl;
    if (m_curSpeed == newCurSpeed)
        return;
    m_curSpeed = newCurSpeed;
    emit curSpeedChanged();
}

qint16 AppModel::curTemp() const
{
    return m_curTemp;
}

void AppModel::setCurTemp(qint16 newCurTemp)
{
    if (m_curTemp == newCurTemp)
        return;
    m_curTemp = newCurTemp;
    emit curTempChanged();
}

qint16 AppModel::curBattery() const
{
    return m_curBattery;
}

void AppModel::setCurBattery(qint16 newCurBattery)
{
    if (m_curBattery == newCurBattery)
        return;
    m_curBattery = newCurBattery;
    emit curBatteryChanged();
}

qint16 AppModel::curFualCar() const
{
    return m_curFualCar;
}

void AppModel::setCurFualCar(qint16 newCurFualCar)
{
    if (m_curFualCar == newCurFualCar)
        return;
    m_curFualCar = newCurFualCar;
    emit curFualCarChanged();
}

qint16 AppModel::curDistCar() const
{
    return m_curDistCar;
}

void AppModel::setCurDistCar(qint16 newCurDistCar)
{
    if (m_curDistCar == newCurDistCar)
        return;
    m_curDistCar = newCurDistCar;
    emit curDistCarChanged();
}

QDateTime AppModel::currentDateTime() const
{
    return m_curDateTime;
}

void AppModel::setCurrentDateTime(const QDateTime &newCurDateTime)
{
    if (m_curDateTime == newCurDateTime)
        return;
    m_curDateTime = newCurDateTime;
    emit currentDateTimeChanged();
}

bool AppModel::curAbsInd() const
{
    return m_curAbsInd;
}

void AppModel::setCurAbsInd(bool newCurAbsInd)
{
    if (m_curAbsInd == newCurAbsInd)
        return;
    m_curAbsInd = newCurAbsInd;
    emit curAbsIndChanged();
}

bool AppModel::curParkBrakeInd() const
{
    return m_curParkBrakeInd;
}

void AppModel::setCurParkBrakeInd(bool newCurParkBrakeInd)
{
    if (m_curParkBrakeInd == newCurParkBrakeInd)
        return;
    m_curParkBrakeInd = newCurParkBrakeInd;
    emit curParkBrakeIndChanged();
}

bool AppModel::curErrInd() const
{
    return m_curErrInd;
}

void AppModel::setCurErrInd(bool newCurErrInd)
{
    if (m_curErrInd == newCurErrInd)
        return;
    m_curErrInd = newCurErrInd;
    emit curErrIndChanged();
}

bool AppModel::curSeatBeltInd() const
{
    return m_curSeatBeltInd;
}

void AppModel::setCurSeatBeltInd(bool newCurSeatBeltInd)
{
    if (m_curSeatBeltInd == newCurSeatBeltInd)
        return;
    m_curSeatBeltInd = newCurSeatBeltInd;
    emit curSeatBeltIndChanged();
}

VehicleTypes::Gear AppModel::curParkState() const
{
    return m_curParkState;
}

void AppModel::setCurParkState(const VehicleTypes::Gear &newCurParkState)
{
    if (m_curParkState == newCurParkState)
        return;
    m_curParkState = newCurParkState;
    emit curParkStateChanged();
}

bool AppModel::curHeadLight() const
{
    return m_curHeadLight;
}

void AppModel::setCurHeadLight(bool newCurHeadLight)
{
    if (m_curHeadLight == newCurHeadLight)
        return;
    m_curHeadLight = newCurHeadLight;
    emit curHeadLightChanged();
}

bool AppModel::rearFogLight() const
{
    return m_rearFogLight;
}

void AppModel::setRearFogLight(bool newRearFogLight)
{
    if (m_rearFogLight == newRearFogLight)
        return;
    m_rearFogLight = newRearFogLight;
    emit rearFogLightChanged();
}

bool AppModel::autoLight() const
{
    return m_autoLight;
}

void AppModel::setAutoLight(bool newAutoLight)
{
    if (m_autoLight == newAutoLight)
        return;
    m_autoLight = newAutoLight;
    emit autoLightChanged();
}

bool AppModel::positionLight() const
{
    return m_positionLight;
}

void AppModel::setPositionLight(bool newPositionLight)
{
    if (m_positionLight == newPositionLight)
        return;
    m_positionLight = newPositionLight;
    emit positionLightChanged();
}

QString AppModel::curDate() const
{
    return m_curDate;
}

void AppModel::setCurDate(const QString &newCurDate)
{
    if (m_curDate == newCurDate)
        return;
    m_curDate = newCurDate;
    emit curDateChanged();
}

QString AppModel::curTime() const
{
    return m_curTime;
}

void AppModel::setcurTime(const QString &newCurTime)
{
    if (m_curTime == newCurTime)
        return;
    m_curTime = newCurTime;
    emit curTimeChanged();
}
