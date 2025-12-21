#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "./source/view/radialbar.h"
#include "./source/view/segmentbar.h"
#include "./source/controller/hmicontroller.h"
#include "./source/model/appmodel.h"
#include "./common/types/vehicletypes.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    AppModel hmiModel;
    HmiController controller(&hmiModel);
    qmlRegisterType<RadialBar>("CustomControls", 1, 0, "RadialBar");
    qmlRegisterType<SegmentBar>("CustomControls", 1, 0, "SegmentBar");
    qmlRegisterType<VehicleTypes>("CommonType", 1, 0, "VehicleTypes");

    engine.rootContext()->setContextProperty("hmiModel", &hmiModel);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("CarHmi", "Main");

    return app.exec();
}
