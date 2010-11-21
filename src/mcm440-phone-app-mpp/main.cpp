#include <QApplication>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QVariant>
#include <ofono.h>

/**
 * main.cpp starts the phone application by setting the QDeclarative context
 * and invoking the *.qml files
 **/
int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QDeclarativeView view;
    view.rootContext()->setContextProperty("OfonoContext", new Ofono());
    view.setSource(QUrl::fromLocalFile("qml/Dialer.qml"));
    view.show();

    return a.exec();
}
