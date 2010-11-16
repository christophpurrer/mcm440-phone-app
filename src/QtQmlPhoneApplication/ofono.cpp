#include "ofono.h"
#include <QDebug>

Ofono::Ofono(QObject *parent) :
        QObject(parent)
{
}

//void Ofono::setPowerOff() {

//}

bool Ofono::setPowerOn() {
    qDebug("powerOn");
    return true;
}
