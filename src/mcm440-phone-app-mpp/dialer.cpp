#include "dialer.h"
#include <QDebug>


/**
 * @file
 * @author  Christoph Purrer <S1010455012@students.fh-hagenberg.at>
 * @author  Kathrin Probst <S0910629019@students.fh-hagenberg.at>
 * @version 0.1
 *
 * @section DESCRIPTION
 *
 * dialer.h implementation
 */

Dialer::Dialer(QObject *parent) : QObject(parent) {
}

void Dialer::test() {
    qDebug("test");
}

bool Dialer::callNumber(QString number) {
    qDebug() << "calling" << number;
    return true;
}

bool Dialer::powerModemOn() {
    return true;
}

bool Dialer::powerModemOff() {
    return true;
}
