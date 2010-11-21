#include "ofono.h"
#include <QDebug>

Ofono::Ofono(QObject *parent) : QObject(parent)
{
}

void Ofono::call(QString number) {
    qDebug() << "calling" << number;
}

void Ofono::test() {
    qDebug("test");
}
