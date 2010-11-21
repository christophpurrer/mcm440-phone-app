#include <QDebug>
#include <QList>
#include <QMap>
#include <QString>
#include <QVariantMap>
#include <QDBusArgument>
#include <QDBusConnection>
#include <QDBusPendingReply>
#include <QDBusVariant>

#include "srcgen/OfonoModem.h"
#include "src/gsm.h"

/**
 * @file
 * @author  Christoph Purrer <S1010455012@students.fh-hagenberg.at>
 * @author  Kathrin Probst <S0910629019@students.fh-hagenberg.at>
 * @version 0.1
 *
 * @section DESCRIPTION
 *
 * gsm.h implementation
 */

Gsm::Gsm(QObject *parent) : QObject(parent) {
}

void Gsm::test() {
    qDebug("test");
}

bool Gsm::callNumber(QString number) {
    qDebug() << "callNumber" << number;
    return true;
}

bool Gsm::powerModemOn() {
    qDebug() << "powerModemOn";
    OrgOfonoModemInterface ofono("org.ofono", "/phonesim", QDBusConnection::systemBus());
    ofono.SetProperty("Powered", QDBusVariant(true));
    return true;
}

bool Gsm::powerModemOff() {
    qDebug() << "powerModemOff";
    OrgOfonoModemInterface ofono("org.ofono", "/phonesim", QDBusConnection::systemBus());
    ofono.SetProperty("Powered", QDBusVariant(false));
    return true;
}

bool Gsm::getModemStatus() {
    OrgOfonoModemInterface ofono("org.ofono", "/phonesim", QDBusConnection::systemBus());
    //    QDBusPendingReply<QVariantMap> properties = ofono.GetProperties();
    QMap<QString, QVariant> mapProperties = ofono.GetProperties().value();

    qDebug() << mapProperties;
    qDebug() << mapProperties.contains("Powered");

    QVariant powered = mapProperties.find("Powered").value();
    qDebug() << "" + powered.toString();
    return powered.value<bool>();
}

void Gsm::propertyChanged(const QString &name, const QDBusVariant &value) {
    if(name == "Calls") {
        const QVariant var = value.variant();
        const QDBusArgument arg = var.value<QDBusArgument>();
        QList<QString> calls;
        arg >> calls;
        qDebug() << calls;
    }
    else if(name == "Powered") {
        const QVariant var = value.variant();
        const QDBusArgument arg = var.value<QDBusArgument>();
        QList<QString> calls;
        arg >> calls;
        qDebug() << calls;
    }
}
