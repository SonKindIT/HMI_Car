#ifndef HMICONTROLLER_H
#define HMICONTROLLER_H

#include <QObject>

class HmiController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint16 currentBat READ currentBat WRITE setCurrentBat NOTIFY currentBatChanged FINAL)
    Q_PROPERTY(qint16 currentSpeed READ currentSpeed WRITE setCurrentSpeed NOTIFY currentSpeedChanged FINAL)
    Q_PROPERTY(qint16 currentTemp READ currentTemp WRITE setCurrentTemp NOTIFY currentTempChanged FINAL)

public:
    explicit HmiController(QObject *parent = nullptr);

    qint16 currentBat() const;
    void setCurrentBat(qint16 newCurrentBat);

    qint16 currentTemp() const;
    void setCurrentTemp(qint16 newCurrentTemp);

    qint16 currentSpeed() const;
    void setCurrentSpeed(qint16 newCurrentSpeed);

signals:
    void currentBatChanged(qint16 battery);
    void currentTempChanged(qint16 temp);

    void currentSpeedChanged(qint16 speed);

private:
    qint16 m_currentBat;
    qint16 m_currentTemp;
    qint16 m_currentSpeed;
};

#endif // HMICONTROLLER_H
