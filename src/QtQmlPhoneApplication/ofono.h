#ifndef OFONO_H
#define OFONO_H

#include <QObject>

class Ofono : public QObject
{
    Q_OBJECT
public:
    explicit Ofono(QObject *parent = 0);
//    Q_INVOKABLE void setPowerOff();

signals:

public slots:
    bool setPowerOn();
};

#endif // OFONO_H
