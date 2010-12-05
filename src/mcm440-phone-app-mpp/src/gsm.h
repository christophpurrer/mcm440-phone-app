#ifndef GSM_H
#define GSM_H

#include <QObject>
#include <QString>
#include <QDBusVariant>

/**
 * @file
 * @author  Christoph Purrer <S1010455012@students.fh-hagenberg.at>
 * @author  Kathrin Probst <S0910629019@students.fh-hagenberg.at>
 * @version 0.2
 *
 * @section DESCRIPTION
 *
 * The Gsm class represents the the dialer interface
 */
class Gsm : public QObject
{
    Q_OBJECT

private:
    bool isConnected;

public:
    /**
    * Constructor initializing the Gsm
    *
    * @param parent - reference to the parent QObject
    */
    explicit Gsm(QObject *parent = 0);

    /**
    *
    * @param bool - the current modem status
    **/
    Q_INVOKABLE bool getModemStatus();

signals:
    void powerOn();
    void powerOff();
    void incomingCall(QString id);
    void outgoingCall(QString id);
    void endCall(QString id);

public slots:    
    /**
    *
    * turns the GSM moden on
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
    * Qt Slot for a D-Bus Signal to get notified about modem changes
    **/
    void modemPropertyChanged(const QString &name, const QDBusVariant &value);

    /**
    *
    * Qt Slot for a D-Bus Signal to get notified about voicecallManager changes
    **/
    void voicecallManagerPropertyChanged(const QString &name, const QDBusVariant &value);
};
#endif
