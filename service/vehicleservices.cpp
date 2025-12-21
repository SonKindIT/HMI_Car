#include "vehicleservices.h"
#include<QDebug>

#define MAX_SPEED 300
#define MAX_TEMP 212
#define MAX_BAT 100
#define MAX_FUAL 200
#define MAX_DISTANCE 999



VehicleServices::VehicleServices(QObject *parent)
    : QObject{parent}
{
    m_speedCar = 0;
    m_tempCar = 0;
    m_batteryCar = 0;
    m_fualCar = 0;
    m_distCar = 0;
    m_absIndicator = true;
    m_parkBrakeIndicator = true;
    m_errIndicator = false;
    m_seatBeltIndicator = false;
    m_parkState = VehicleTypes::Gear::P;

    m_headLight = true;
    m_rearFogLight = true;
    m_autoLight = true;
    m_positionLight = true;

    connect(&m_timerSample1000ms, &QTimer::timeout, this, &VehicleServices::setDummyData1000ms);
    connect(&m_timerSample500ms, &QTimer::timeout, this, &VehicleServices::setDummyData500ms);
    connect(&m_timerDate, &QTimer::timeout, this, [=](){
        setCurrentDateTime(QDateTime::currentDateTime());
        setDummyParkState();
    });

    m_timerSample500ms.start(100);
    m_timerSample1000ms.start(200);
    m_timerDate.start(1000);
}


void VehicleServices::setDummyData1000ms()
{
    setDummyFualData();
    setDummyIndicator();
}

void VehicleServices::setDummyData500ms()
{
    setDummySpeedData();
    setDummyTempData();
    setDummyBatData();
    setDummyDistData();
}

void VehicleServices::setDummySpeedData()
{
    qint16 speed = speedCar();
    if(speed >= MAX_SPEED)
        speed = 0;
    else
        speed+=2;
    setSpeedCar(speed);
}

void VehicleServices::setDummyTempData()
{
    qint16 temp = tempCar();
    if(temp >= MAX_TEMP)
        temp = 0;
    else
        temp += 1;
    setTempCar(temp);
}

void VehicleServices::setDummyBatData()
{
    qint16 bat = batteryCar();
    if(bat >= MAX_BAT)
        bat = 0;
    else
        bat += 1;
    setBatteryCar(bat);
}

void VehicleServices::setDummyFualData()
{
    qint16 fuel = fualCar();
    if(fuel >= MAX_FUAL)
        fuel = 0;
    else
        fuel += 1;

    setFualCar(fuel);
}

void VehicleServices::setDummyDistData()
{
    qint16 dist = distCar();
    if(dist >= MAX_DISTANCE)
        dist = 0;
    else
        dist += 20;

    setDistCar(dist);
}

void VehicleServices::setDummyIndicator()
{
    bool curState;
    curState = absIndicator();
    setAbsIndicator(!curState);

    curState = parkBrakeIndicator();
    setParkBrakeIndicator(!curState);

    curState = errIndicator();
    setErrIndicator(!curState);

    curState = seatBeltIndicator();
    setSeatBeltIndicator(!curState);
}

void VehicleServices::setDummyParkState()
{
    switch (parkState()) {
    case VehicleTypes::Gear::P: setParkState(VehicleTypes::Gear::R); break;
    case VehicleTypes::Gear::R: setParkState(VehicleTypes::Gear::N); break;
    case VehicleTypes::Gear::N: setParkState(VehicleTypes::Gear::D); break;
    case VehicleTypes::Gear::D: setParkState(VehicleTypes::Gear::P); break;
    }
}

qint16 VehicleServices::speedCar() const
{
    return m_speedCar;
}

void VehicleServices::setSpeedCar(qint16 newSpeedCar)
{
    // qDebug() << "ehicleServices::setSpeedCar" << newSpeedCar << Qt::endl;
    if (m_speedCar == newSpeedCar)
        return;
    m_speedCar = newSpeedCar;
    emit speedCarChanged(m_speedCar);
}


qint16 VehicleServices::tempCar() const
{
    return m_tempCar;
}

void VehicleServices::setTempCar(qint16 newTempCar)
{
    if (m_tempCar == newTempCar)
        return;
    m_tempCar = newTempCar;
    emit tempCarChanged(m_tempCar);
}

qint16 VehicleServices::batteryCar() const
{
    return m_batteryCar;
}

void VehicleServices::setBatteryCar(qint16 newBatteryCar)
{
    if (m_batteryCar == newBatteryCar)
        return;
    m_batteryCar = newBatteryCar;
    emit batteryCarChanged(m_batteryCar);
}

qint16 VehicleServices::fualCar() const
{
    return m_fualCar;
}

void VehicleServices::setFualCar(qint16 newFualCar)
{
    if (m_fualCar == newFualCar)
        return;
    m_fualCar = newFualCar;
    emit fualCarChanged(m_fualCar);
}

qint16 VehicleServices::distCar() const
{
    return m_distCar;
}

void VehicleServices::setDistCar(qint16 newDistCar)
{
    if (m_distCar == newDistCar)
        return;
    m_distCar = newDistCar;
    emit distCarChanged(m_distCar);
}

QDateTime VehicleServices::currentDateTime() const
{
    return m_currentDateTime;
}

void VehicleServices::setCurrentDateTime(const QDateTime &newCurrentDateTime)
{
    if (m_currentDateTime == newCurrentDateTime)
        return;
    m_currentDateTime = newCurrentDateTime;
    emit currentDateTimeChanged(m_currentDateTime);
}

bool VehicleServices::absIndicator() const
{
    return m_absIndicator;
}

void VehicleServices::setAbsIndicator(bool newAbsIndicator)
{
    if (m_absIndicator == newAbsIndicator)
        return;
    m_absIndicator = newAbsIndicator;
    emit absIndicatorChanged(m_absIndicator);
}

bool VehicleServices::parkBrakeIndicator() const
{
    return m_parkBrakeIndicator;
}

void VehicleServices::setParkBrakeIndicator(bool newParkBrakeIndicator)
{
    if (m_parkBrakeIndicator == newParkBrakeIndicator)
        return;
    m_parkBrakeIndicator = newParkBrakeIndicator;
    emit parkBrakeIndicatorChanged(m_parkBrakeIndicator);
}

bool VehicleServices::errIndicator() const
{
    return m_errIndicator;
}

void VehicleServices::setErrIndicator(bool newErrIndicator)
{
    if (m_errIndicator == newErrIndicator)
        return;
    m_errIndicator = newErrIndicator;
    emit errIndicatorChanged(m_errIndicator);
}

bool VehicleServices::seatBeltIndicator() const
{
    return m_seatBeltIndicator;
}

void VehicleServices::setSeatBeltIndicator(bool newSeatBeltIndicator)
{
    if (m_seatBeltIndicator == newSeatBeltIndicator)
        return;
    m_seatBeltIndicator = newSeatBeltIndicator;
    emit seatBeltIndicatorChanged(m_seatBeltIndicator);
}



bool VehicleServices::headLight() const
{
    return m_headLight;
}

void VehicleServices::setHeadLight(bool newHeadLight)
{
    if (m_headLight == newHeadLight)
        return;
    m_headLight = newHeadLight;
    emit headLightChanged(m_headLight);
}

bool VehicleServices::rearFogLight() const
{
    return m_rearFogLight;
}

void VehicleServices::setRearFogLight(bool newRearFogLight)
{
    if (m_rearFogLight == newRearFogLight)
        return;
    m_rearFogLight = newRearFogLight;
    emit rearFogLightChanged(m_rearFogLight);
}

bool VehicleServices::autoLight() const
{
    return m_autoLight;
}

void VehicleServices::setAutoLight(bool newAutoLight)
{
    if (m_autoLight == newAutoLight)
        return;
    m_autoLight = newAutoLight;
    emit autoLightChanged(m_autoLight);
}

bool VehicleServices::positionLight() const
{
    return m_positionLight;
}

void VehicleServices::setPositionLight(bool newPositionLight)
{
    if (m_positionLight == newPositionLight)
        return;
    m_positionLight = newPositionLight;
    emit positionLightChanged(m_positionLight);
}

void VehicleServices::setParkState(VehicleTypes::VehicleTypes::Gear newState)
{
    if(newState == m_parkState)
        return;
    m_parkState = newState;
    emit parkStateChanged(m_parkState);
}

VehicleTypes::VehicleTypes::Gear VehicleServices::parkState() const
{
    return m_parkState;
}
