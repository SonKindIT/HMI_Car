#ifndef VehicleServices_H
#define VehicleServices_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include"../common/types/vehicletypes.h"

class VehicleServices : public QObject
{
    Q_OBJECT

private:

    //input from sensor
    Q_PROPERTY(qint16 speedCar READ speedCar WRITE setSpeedCar NOTIFY speedCarChanged FINAL)
    Q_PROPERTY(qint16 tempCar READ tempCar WRITE setTempCar NOTIFY tempCarChanged FINAL)
    Q_PROPERTY(qint16 batteryCar READ batteryCar WRITE setBatteryCar NOTIFY batteryCarChanged FINAL)
    Q_PROPERTY(qint16 fualCar READ fualCar WRITE setFualCar NOTIFY fualCarChanged FINAL)
    Q_PROPERTY(qint16 distCar READ distCar WRITE setDistCar NOTIFY distCarChanged FINAL)
    Q_PROPERTY(QDateTime currentDateTime READ currentDateTime WRITE setCurrentDateTime NOTIFY currentDateTimeChanged FINAL)
    Q_PROPERTY(bool absIndicator READ absIndicator WRITE setAbsIndicator NOTIFY absIndicatorChanged FINAL)
    Q_PROPERTY(bool parkBrakeIndicator READ parkBrakeIndicator WRITE setParkBrakeIndicator NOTIFY parkBrakeIndicatorChanged FINAL)
    Q_PROPERTY(bool errIndicator READ errIndicator WRITE setErrIndicator NOTIFY errIndicatorChanged FINAL)
    Q_PROPERTY(bool seatBeltIndicator READ seatBeltIndicator WRITE setSeatBeltIndicator NOTIFY seatBeltIndicatorChanged FINAL)
    Q_PROPERTY(VehicleTypes::Gear parkState READ parkState WRITE setParkState NOTIFY parkStateChanged FINAL)

    //output from HMI
    Q_PROPERTY(bool headLight READ headLight WRITE setHeadLight NOTIFY headLightChanged FINAL)
    Q_PROPERTY(bool rearFogLight READ rearFogLight WRITE setRearFogLight NOTIFY rearFogLightChanged FINAL)
    Q_PROPERTY(bool autoLight READ autoLight WRITE setAutoLight NOTIFY autoLightChanged FINAL)
    Q_PROPERTY(bool positionLight READ positionLight WRITE setPositionLight NOTIFY positionLightChanged FINAL)

    QTimer m_timerSample500ms;
    QTimer m_timerSample1000ms;
    QTimer m_timerDate;

    //help function prototype
    void setDummySpeedData();
    void setDummyTempData();
    void setDummyBatData();
    void setDummyFualData();
    void setDummyDistData();
    void setDummyIndicator();
    void setDummyParkState();

    qint16 m_speedCar;

    qint16 m_tempCar;

    qint16 m_batteryCar;

    qint16 m_fualCar;

    qint16 m_distCar;

    QDateTime m_currentDateTime;

    bool m_absIndicator;

    bool m_parkBrakeIndicator;

    bool m_errIndicator;

    bool m_seatBeltIndicator;

    bool m_headLight;

    bool m_rearFogLight;

    bool m_autoLight;

    bool m_positionLight;


    VehicleTypes::Gear m_parkState;

public:

    explicit VehicleServices(QObject *parent = nullptr);

    qint16 speedCar() const;
    void setSpeedCar(qint16 newSpeedCar);

    qint16 tempCar() const;
    void setTempCar(qint16 newTempCar);

    qint16 batteryCar() const;
    void setBatteryCar(qint16 newBatteryCar);

    qint16 fualCar() const;
    void setFualCar(qint16 newFualCar);

    qint16 distCar() const;
    void setDistCar(qint16 newDistCar);

    QDateTime currentDateTime() const;
    void setCurrentDateTime(const QDateTime &newCurrentDateTime);

    bool absIndicator() const;
    void setAbsIndicator(bool newAbsIndicator);

    bool parkBrakeIndicator() const;
    void setParkBrakeIndicator(bool newParkBrakeIndicator);

    bool errIndicator() const;
    void setErrIndicator(bool newErrIndicator);

    bool seatBeltIndicator() const;
    void setSeatBeltIndicator(bool newSeatBeltIndicator);

    bool headLight() const;
    void setHeadLight(bool newHeadLight);

    bool rearFogLight() const;
    void setRearFogLight(bool newRearFogLight);

    bool autoLight() const;
    void setAutoLight(bool newAutoLight);

    bool positionLight() const;
    void setPositionLight(bool newPositionLight);

    VehicleTypes::Gear parkState() const;
    void setParkState(VehicleTypes::Gear state);


signals:


    void speedCarChanged(qint16 speed);

    void tempCarChanged(qint16 temp);

    void batteryCarChanged(qint16 battery);

    void fualCarChanged(qint16 fuel);

    void distCarChanged(qint16 speed);

    void currentDateTimeChanged(QDateTime time);

    void absIndicatorChanged(bool absInd);

    void parkBrakeIndicatorChanged(bool parkBrakeInd);

    void errIndicatorChanged(bool errInd);

    void seatBeltIndicatorChanged(bool seatBeltInd);

    void parkStateChanged(VehicleTypes::Gear gearState);

    void headLightChanged(bool heagLightState);

    void rearFogLightChanged(bool rearFogLightState);

    void autoLightChanged(bool autoLightState);

    void positionLightChanged(bool positionLightState);

private slots:
    void setDummyData1000ms();
    void setDummyData500ms();

};

#endif // VehicleServices_H
