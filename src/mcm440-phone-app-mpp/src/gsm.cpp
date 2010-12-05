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
 * @author  Alexander Moosbrugger <S10104550111@students.fh-hagenberg.at>
 * @version 0.1
 *
 * @section DESCRIPTION
 *
 * gsm.h implementation
 */

OrgOfonoModemInterface ofonoModem("org.ofono", "/phonesim0", QDBusConnection::systemBus());
OrgOfonoVoiceCallManagerInterface ofonoVoicecallManager("org.ofono", "/phonesim0", QDBusConnection::systemBus());

// constructor
Gsm::Gsm(QObject *parent) : QObject(parent) {
    this->isConnected=false;

    qDebug()<<"start";

    // register to certain slots to get notified about events
    QObject::connect( &ofonoModem, SIGNAL(PropertyChanged(QString,QDBusVariant)), this, SLOT(modemPropertyChanged(QString,QDBusVariant)));
    QObject::connect( &ofonoVoicecallManager, SIGNAL(PropertyChanged(QString,QDBusVariant)), this, SLOT(voicecallManagerPropertyChanged(QString,QDBusVariant)));
}

// turns the modem on
bool Gsm::powerModemOn() {
    qDebug() << "powerModemOn";
    ofonoModem.SetProperty("Powered", QDBusVariant(true));
    return true;
}

// shuts the modem down
bool Gsm::powerModemOff() {
    qDebug() << "powerModemOff";
    ofonoModem.SetProperty("Powered", QDBusVariant(false));
    return true;
}

// dials a number
bool Gsm::dialNumber(QString number) {
    // qDebug() << "callNumber" << number;
    this->isConnected = this->getModemStatus();
    // qDebug() << "modemStatus" << this->isConnected;
    if( this->isConnected==true ){
        ofonoVoicecallManager.Dial(number, "default");
        this->outgoingCall(number);
        return true;
    }
    else {
        return false;
    }
}

// hangup all phone calls
bool Gsm::hangupAll() {
    ofonoVoicecallManager.HangupAll();
    return true;
}

// returns the modemStatus
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

void Gsm::modemPropertyChanged(const QString &name, const QDBusVariant &value) {
    qDebug() << "modemPropertyChanged";
    const QVariant var = value.variant();
    const QDBusArgument arg = var.value<QDBusArgument>();
    QList<QString> values;
    arg >> values;
    qDebug() << values;

    if(name == "Calls") {
    }
    else if(name == "Features") {
    }
    else if(name == "Interfaces") {
    }
    else if(name == "Manufactorer") {
    }
    else if(name == "Model") {
    }
    else if(name == "Online") {
    }
    else if(name == "Powered") {
    }
    else if(name == "Revision") {
    }
    else if(name == "Serial") {
    }
}

void Gsm::voicecallManagerPropertyChanged(const QString &name, const QDBusVariant &value) {
    qDebug() << "voicecallManagerPropertyChanged";
    const QVariant var = value.variant();
    const QDBusArgument arg = var.value<QDBusArgument>();
    QList<QString> values;
    arg >> values;
    //qDebug() << "values" << values << " ,length: " << values.length();

    //qDebug() << "Befehl: " << name;

    if(name == "Calls") {
        if ( values.length() > 0 ){
            this->outgoingCall("outGoingCall");
        }
        else {
            this->endCall("endCall");
        }

    }
}
