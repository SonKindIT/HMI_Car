#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "./source/view/radialbar.h"
#include "./source/view/segmentbar.h"
#include "./source/controller/hmicontroller.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    HmiController controller;


    qmlRegisterType<RadialBar>("CustomControls", 1, 0, "RadialBar");
    qmlRegisterType<SegmentBar>("CustomControls", 1, 0, "SegmentBar");

    engine.rootContext()->setContextProperty("Controller", &controller);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("CarHmi", "Main");

    return app.exec();
}
