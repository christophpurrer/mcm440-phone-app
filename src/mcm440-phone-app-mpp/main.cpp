#include <QApplication>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QVariant>
#include "src/gsm.h"

/**
 * @file
 * @author  Christoph Purrer <S1010455012@students.fh-hagenberg.at>
 * @author  Kathrin Probst <S0910629019@students.fh-hagenberg.at>
 * @version 0.1
 *
 * @section DESCRIPTION
 *
 * main.cpp starts the phone application by setting the QDeclarative context
 * and invoking the *.qml files
 */

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    QDeclarativeView view;

    Gsm *gsm = new Gsm();
    //gsm->powerModemOn();

    view.rootContext()->setContextProperty("OfonoContext", gsm);
    // view.setSource(QUrl::fromLocalFile("qml/PhoneAppMain.qml"));
    view.setSource(QUrl("qrc:/qml/PhoneAppMain.qml"));
    view.show();

    return a.exec();
}
