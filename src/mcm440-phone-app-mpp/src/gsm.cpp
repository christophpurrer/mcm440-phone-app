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
 * @version 0.9
 *
 * @section DESCRIPTION
 *
 * gsm.h implementation
 */


// constructor
Gsm::Gsm(QObject *parent) : QObject(parent) {
    qDebug()<<"Gsm constructor";

    // initialize
    this->isModemTurnedOn=false;
    this->isDialing=false;

    this->ofonoModem = new OrgOfonoModemInterface("org.ofono", "/phonesim", QDBusConnection::systemBus());
    this->ofonoVoicecallManager = new OrgOfonoVoiceCallManagerInterface("org.ofono", "/phonesim", QDBusConnection::systemBus());

    // register to certain slots to get notified about events
    QObject::connect( this->ofonoVoicecallManager, SIGNAL(PropertyChanged(QString,QDBusVariant)), this, SLOT(voicecallManagerPropertyChanged(QString,QDBusVariant)));
}

// destructor
Gsm::~Gsm() {
    qDebug()<<"Gsm destructor";
    this->powerModemOff();
    delete(ofonoModem);
    delete(ofonoVoicecallManager);
}

// turns the modem on
bool Gsm::powerModemOn() {
    qDebug() << "Gsm powerModemOn";
    ofonoModem->SetProperty("Powered", QDBusVariant(true));
    emit this->modemPowerChanged("OFF");
    return true;
}

// shuts the modem down
bool Gsm::powerModemOff() {
    qDebug() << "Gsm powerModemOff";
    ofonoModem->SetProperty("Powered", QDBusVariant(false));
    emit this->modemPowerChanged("ON");
    return true;
}

// dials a number
bool Gsm::dialNumber(QString number) {
    qDebug() << "Gsm dialNumber" << number;
    this->isModemTurnedOn = this->getModemStatus();

    // qDebug() << "modemStatus" << this->isModemTurnedOn;
    if( this->isModemTurnedOn == false ){
        this->powerModemOn();
        this->isModemTurnedOn = this->getModemStatus();
    }

    // initialize a call
    if( this->isModemTurnedOn == true ){
        this->ofonoVoicecallManager->Dial(number, "default");
        emit outGoingCallChanged(number);

        this->isDialing=true;

        QDBusPendingReply<QDBusObjectPath> pendingReplys = this->ofonoVoicecallManager->Dial(number, "default");
        QDBusObjectPath dop = pendingReplys.value();
        this->currentOutgoingCall.append(dop.path());
        return true;

    }
    return false;
}

void Gsm::releaseAndAnswer()
{
    qDebug() << "Gsm releaseAndAnswer";
    this->ofonoVoicecallManager->ReleaseAndAnswer();
}

// hangup all phone calls
bool Gsm::hangupAll() {
    qDebug() << "Gsm hangupAll";
    ofonoVoicecallManager->HangupAll();
    this->currentOutgoingCall.clear();
    this->isDialing=false;
    return true;
}

// returns the modemStatus
bool Gsm::getModemStatus() {
    QMap<QString, QVariant> mapProperties = this->ofonoModem->GetProperties().value();
    QVariant powered = mapProperties.find("Powered").value();
    qDebug() << "Gsm getModemStatus: " << "" + powered.toString();
    return powered.value<bool>();
}

// handle inComing and outGoing calls
void Gsm::voicecallManagerPropertyChanged(const QString &name, const QDBusVariant &value) {
    qDebug() << "Gsm voicecallManagerPropertyChanged";
    const QVariant var = value.variant();
    const QDBusArgument arg = var.value<QDBusArgument>();
    QList<QString> calls;
    arg >> calls;
    qDebug() << "calls" << calls << ", length: " << calls.length();

    bool isInComingCall = false;
    if(name == "Calls") {
        for(int i = 0; i < calls.count(); i++)
        {
            if(calls[i] != this->currentOutgoingCall)
            {
                isInComingCall = true;
                break;
            }
        }

        // a.) inComingCall
        if( isInComingCall == true && this->isDialing==false ) {
            if( this->isModemTurnedOn==false ){
                this->powerModemOn();
                this->isModemTurnedOn = this->getModemStatus();
            }
            // default number from phone-sim
            emit inComingCallChanged("555000");
        }
        // b.) outgoingCall
        else {
            emit outGoingCallChanged("outGoingCall");
        }

        // c.) call has been terminated
        if ( calls.length() <= 0 ){
            emit endCallChanged("endCall");
        }
    }
}


// from Group-Project v3.pdf page 31 and following
// The Qt type QDbusArgument is used for marshalling and demarshalling.
// To get this type working with the stream operator << it’s necessary to implement the following function:
QDBusArgument &operator>>(QDBusArgument &arg, QList<QString> &calls)
{
    calls.empty();
    arg.beginArray();

    while(!arg.atEnd())
    {
        QDBusObjectPath opath;
        arg >> opath;
        calls.append(opath.path());
    }

    arg.endArray();
    return arg;
}
