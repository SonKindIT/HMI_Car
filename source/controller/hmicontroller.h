#ifndef HMICONTROLLER_H
#define HMICONTROLLER_H

#include <QObject>
#include <QDateTime>
#include"../model/appmodel.h"
#include"../../service/vehicleservices.h"

class HmiController : public QObject
{
    Q_OBJECT

public:
    explicit HmiController(AppModel *model, QObject *parent = nullptr);

signals:


private:
    AppModel *m_model;
    VehicleServices m_appService;

public slots:
    void SetModelDateTime(QDateTime curDateTime);
};

#endif // HMICONTROLLER_H
