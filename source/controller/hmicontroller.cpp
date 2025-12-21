#include "hmicontroller.h"

HmiController::HmiController(AppModel *model, QObject *parent)
    : QObject{parent},
    m_appService(this),
    m_model(model)
{
    connect(&m_appService, &VehicleServices::currentDateTimeChanged, this, &HmiController::SetModelDateTime);

    connect(&m_appService, &VehicleServices::speedCarChanged, m_model, &AppModel::setCurSpeed);
    connect(&m_appService, &VehicleServices::tempCarChanged, m_model, &AppModel::setCurTemp);
    connect(&m_appService, &VehicleServices::batteryCarChanged, m_model, &AppModel::setCurBattery);
    connect(&m_appService, &VehicleServices::fualCarChanged, m_model, &AppModel::setCurFualCar);
    connect(&m_appService, &VehicleServices::distCarChanged, m_model, &AppModel::setCurDistCar);
    connect(&m_appService, &VehicleServices::absIndicatorChanged, m_model, &AppModel::setCurAbsInd);
    connect(&m_appService, &VehicleServices::parkBrakeIndicatorChanged, m_model, &AppModel::setCurParkBrakeInd);
    connect(&m_appService, &VehicleServices::errIndicatorChanged, m_model, &AppModel::setCurErrInd);
    connect(&m_appService, &VehicleServices::seatBeltIndicatorChanged, m_model, &AppModel::setCurSeatBeltInd);
    connect(&m_appService, &VehicleServices::parkStateChanged, m_model, &AppModel::setCurParkState);
}

void HmiController::SetModelDateTime(QDateTime curDateTime)
{
    m_model->setCurDate(curDateTime.date().toString("dd/MM/yyyy"));
    m_model->setcurTime(curDateTime.time().toString("HH:mm:ss"));
}


