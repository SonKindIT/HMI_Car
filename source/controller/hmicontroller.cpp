#include "hmicontroller.h"
#include "../view/radialbar.h"
#include <QTimer>

HmiController::HmiController(QObject *parent):
    QObject{parent},
    m_currentBat(0),
    m_currentTemp(0),
    m_currentSpeed(0)
{
    //Dummy Data
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=](){
        m_currentBat++;
        if(m_currentBat > 100)
            m_currentBat = 0;

        m_currentSpeed+=5;
        if(m_currentSpeed > 160)
            m_currentSpeed = 0;

        m_currentTemp+=2;
        if(m_currentTemp > 150)
            m_currentTemp = 0;

        emit currentSpeedChanged(m_currentSpeed);
        emit currentBatChanged(m_currentBat);
        emit currentTempChanged(m_currentTemp);


    });
    timer->start(100);
}

qint16 HmiController::currentBat() const
{
    return m_currentBat;
}

void HmiController::setCurrentBat(qint16 newCurrentBat)
{
    if (m_currentBat == newCurrentBat)
        return;
    m_currentBat = newCurrentBat;
    emit currentBatChanged(m_currentBat);
}

qint16 HmiController::currentTemp() const
{
    return m_currentTemp;
}

void HmiController::setCurrentTemp(qint16 newCurrentTemp)
{
    if (m_currentTemp == newCurrentTemp)
        return;
    m_currentTemp = newCurrentTemp;
    emit currentTempChanged(newCurrentTemp);
}

qint16 HmiController::currentSpeed() const
{
    return m_currentSpeed;
}

void HmiController::setCurrentSpeed(qint16 newCurrentSpeed)
{
    if (m_currentSpeed == newCurrentSpeed)
        return;
    m_currentSpeed = newCurrentSpeed;
    emit currentSpeedChanged(newCurrentSpeed);
}
