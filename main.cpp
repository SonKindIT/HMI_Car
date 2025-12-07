#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "./source/view/radialbar.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<RadialBar>("CustomControls", 1, 0, "RadialBar");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("CarHmi", "Main");

    return app.exec();
}
