#ifndef GSM_H
#define GSM_H

#include <QObject>
#include <QString>
#include <QDBusVariant>

/**
 * @file
 * @author  Christoph Purrer <S1010455012@students.fh-hagenberg.at>
 * @author  Kathrin Probst <S0910629019@students.fh-hagenberg.at>
 * @version 0.1
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


    Q_INVOKABLE void test();

    /**
    *
    * @param bool - the current modem status
    **/
    Q_INVOKABLE bool getModemStatus();

signals:

public slots:

    /**
    *
    * @param number - the number to call
    **/
    bool dialNumber(QString number);

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
