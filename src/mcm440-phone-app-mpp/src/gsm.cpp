#include <QDebug>
#include <QList>
#include <QMap>
#include <QString>
#include <QVariantMap>
#include <QDBusArgument>
#include <QDBusConnection>
#include <QDBusPendingReply>
#include <QDBusVariant>

#include "srcgen/OfonoVoiceCallManager.h"
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

OrgOfonoModemInterface ofonoModem("org.ofono", "/phonesim0", QDBusConnection::systemBus());
OrgOfonoVoiceCallManagerInterface ofonoVoicecallManager("org.ofono", "/phonesim0", QDBusConnection::systemBus());

Gsm::Gsm(QObject *parent) : QObject(parent) {
    this->isConnected=false;

    qDebug()<<"start";

    QObject::connect( &ofonoModem, SIGNAL(PropertyChanged(QString,QDBusVariant)), this, SLOT(propertyChanged(QString,QDBusVariant)));
}

void Gsm::test() {
    qDebug("test");
}

bool Gsm::dialNumber(QString number) {
    qDebug() << "callNumber" << number;
    this->isConnected = this->getModemStatus();
    qDebug() << "modemStatus" << this->isConnected;
    if( this->isConnected==true ){
        ofonoVoicecallManager.Dial(number, "default");
        return true;
    }
    else {
        return false;
    }
}

bool Gsm::powerModemOn() {
    qDebug() << "powerModemOn";
    ofonoModem.SetProperty("Powered", QDBusVariant(true));
    //this->isConnected = true;
    return true;
}

bool Gsm::powerModemOff() {
    qDebug() << "powerModemOff";
    ofonoModem.SetProperty("Powered", QDBusVariant(false));
    //this->isConnected = false;
    return true;
}

bool Gsm::getModemStatus() {
    //    OrgOfonoModemInterface ofono("org.ofono", "/phonesim", QDBusConnection::systemBus());
    //    QDBusPendingReply<QVariantMap> properties = ofono.GetProperties();
    QMap<QString, QVariant> mapProperties = ofonoModem.GetProperties().value();

    qDebug() << mapProperties;
    qDebug() << mapProperties.contains("Powered");

    QVariant powered = mapProperties.find("Powered").value();
    qDebug() << "" + powered.toString();
    return powered.value<bool>();
}

void Gsm::propertyChanged(const QString &name, const QDBusVariant &value) {

    qDebug() << "propertyChanged2";

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
