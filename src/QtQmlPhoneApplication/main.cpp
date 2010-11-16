#include <QApplication>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QColor>
#include "ofono.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ofono *ofono = new Ofono();
    QDeclarativeView view;
    QDeclarativeContext *context = view.rootContext();
    context->setContextProperty("backgroundColor", QColor(Qt::yellow));

    view.rootContext()->setContextProperty("OfonoContext", ofono);
    view.setSource(QUrl::fromLocalFile("qml/QtQuickQML1.qml"));

    view.setSceneRect(0, 0, 240, 320);


    view.show();

    return a.exec();
}
