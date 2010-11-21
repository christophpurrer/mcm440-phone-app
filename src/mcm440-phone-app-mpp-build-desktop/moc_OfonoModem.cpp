/****************************************************************************
** Meta object code from reading C++ file 'OfonoModem.h'
**
** Created: Sun Nov 21 15:38:06 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mcm440-phone-app-mpp/srcgen/OfonoModem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OfonoModem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OrgOfonoModemInterface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   24,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
     101,   23,   70,   23, 0x0a,
     137,   24,  117,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OrgOfonoModemInterface[] = {
    "OrgOfonoModemInterface\0\0in0,in1\0"
    "PropertyChanged(QString,QDBusVariant)\0"
    "QDBusPendingReply<QVariantMap>\0"
    "GetProperties()\0QDBusPendingReply<>\0"
    "SetProperty(QString,QDBusVariant)\0"
};

const QMetaObject OrgOfonoModemInterface::staticMetaObject = {
    { &QDBusAbstractInterface::staticMetaObject, qt_meta_stringdata_OrgOfonoModemInterface,
      qt_meta_data_OrgOfonoModemInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OrgOfonoModemInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OrgOfonoModemInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OrgOfonoModemInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrgOfonoModemInterface))
        return static_cast<void*>(const_cast< OrgOfonoModemInterface*>(this));
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int OrgOfonoModemInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: PropertyChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDBusVariant(*)>(_a[2]))); break;
        case 1: { QDBusPendingReply<QVariantMap> _r = GetProperties();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QVariantMap>*>(_a[0]) = _r; }  break;
        case 2: { QDBusPendingReply<> _r = SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDBusVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void OrgOfonoModemInterface::PropertyChanged(const QString & _t1, const QDBusVariant & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
