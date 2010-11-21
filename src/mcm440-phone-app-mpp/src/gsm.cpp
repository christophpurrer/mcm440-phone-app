#include <QDebug>
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
    qDebug() << "calling" << number;
    return true;
}

bool Gsm::powerModemOn() {
    return true;
}

bool Gsm::powerModemOff() {
    return true;
}
