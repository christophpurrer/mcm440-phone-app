#ifndef GSM_H
#define GSM_H

#include <QObject>
#include <QString>
#include <QDBusVariant>
#include "srcgen/OfonoVoiceCallManager.h"
#include "srcgen/OfonoModem.h"

/**
 * @file
 * @author  Christoph Purrer <S1010455012@students.fh-hagenberg.at>
 * @author  Kathrin Probst <S0910629019@students.fh-hagenberg.at>
 * @version 0.9
 *
 * @section DESCRIPTION
 *
 * The Gsm class represents the the dialer interface
 */
class Gsm : public QObject
{
    Q_OBJECT

private:
    // properties
    OrgOfonoModemInterface *ofonoModem;
    OrgOfonoVoiceCallManagerInterface *ofonoVoicecallManager;

    bool isModemTurnedOn;
    bool isDialing;

    QDBusPendingReply<QDBusObjectPath> currentCalls;
    QString currentOutgoingCall;

    // methods
    /**
    *
    * @param bool - the current modem status
    **/
    bool getModemStatus();

public:
    /**
    * Constructor initializing the Gsm instance
    *
    * @param parent - reference to the parent QObject
    */
    explicit Gsm(QObject *parent = 0);

    /**
    * Destructor destroys the Gsm instance
    *
    **/
    ~Gsm();


signals:
    // signals of the suffix 'Changed' ...
    void modemPowerChanged(QString onOff);
    void inComingCallChanged(QString number);
    void outGoingCallChanged(QString number);
    void endCallChanged(QString number);

public slots:    
    /**
    *
    * turns the GSM modem on
    **/
    bool powerModemOn();

    /**
    *
    * turns the GSM modem off
    **/
    bool powerModemOff();

    /**
    *
    * @param number - the number to call
    **/
    bool dialNumber(QString number);

    /**
    *
    * terminates all phone calls
    **/
    bool hangupAll();

    /**
    *
    *
    **/
    void releaseAndAnswer();

    /**
    *
    * Qt Slot for a D-Bus Signal to get notified about voicecallManager changes
    **/
    void voicecallManagerPropertyChanged(const QString &name, const QDBusVariant &value);
};
#endif
