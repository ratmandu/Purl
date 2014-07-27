#include <QApplication>
#include <QQmlApplicationEngine>

#include "patterngrid.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<PatternGrid>("PatternGrid", 1, 0, "PatternGrid");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
