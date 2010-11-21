#ifndef DIALER_H
#define DIALER_H

#include <QObject>

/**
 * @file
 * @author  Christoph Purrer <S1010455012@students.fh-hagenberg.at>
 * @author  Kathrin Probst <S0910629019@students.fh-hagenberg.at>
 * @version 0.1
 *
 * @section DESCRIPTION
 *
 * The time class represents the the dialer interface
 */
class Dialer : public QObject
{
    Q_OBJECT

public:

    /**
    * Constructor initializing the Dialer
    *
    * @param parent - reference to the parent QObject
    */
    explicit Dialer(QObject *parent = 0);


    Q_INVOKABLE void test();

signals:

public slots:

    /**
    *
    * @param number - the number to call
    **/
    bool callNumber(QString number);

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
};

#endif
