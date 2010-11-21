/****************************************************************************
** Meta object code from reading C++ file 'OfonoSimManager.h'
**
** Created: Sun Nov 21 16:09:00 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mcm440-phone-app-mpp/srcgen/OfonoSimManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OfonoSimManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OrgOfonoSimManagerInterface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      37,   29,   28,   28, 0x05,

 // slots: signature, parameters, type, tag, flags
     107,   95,   75,   28, 0x0a,
     142,   29,   75,   28, 0x0a,
     199,   28,  168,   28, 0x0a,
     215,   29,   75,   28, 0x0a,
     240,   95,   75,   28, 0x0a,
     274,   29,   75,   28, 0x0a,
     308,   29,   75,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OrgOfonoSimManagerInterface[] = {
    "OrgOfonoSimManagerInterface\0\0in0,in1\0"
    "PropertyChanged(QString,QDBusVariant)\0"
    "QDBusPendingReply<>\0in0,in1,in2\0"
    "ChangePin(QString,QString,QString)\0"
    "EnterPin(QString,QString)\0"
    "QDBusPendingReply<QVariantMap>\0"
    "GetProperties()\0LockPin(QString,QString)\0"
    "ResetPin(QString,QString,QString)\0"
    "SetProperty(QString,QDBusVariant)\0"
    "UnlockPin(QString,QString)\0"
};

const QMetaObject OrgOfonoSimManagerInterface::staticMetaObject = {
    { &QDBusAbstractInterface::staticMetaObject, qt_meta_stringdata_OrgOfonoSimManagerInterface,
      qt_meta_data_OrgOfonoSimManagerInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OrgOfonoSimManagerInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OrgOfonoSimManagerInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OrgOfonoSimManagerInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrgOfonoSimManagerInterface))
        return static_cast<void*>(const_cast< OrgOfonoSimManagerInterface*>(this));
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int OrgOfonoSimManagerInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: PropertyChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDBusVariant(*)>(_a[2]))); break;
        case 1: { QDBusPendingReply<> _r = ChangePin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 2: { QDBusPendingReply<> _r = EnterPin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 3: { QDBusPendingReply<QVariantMap> _r = GetProperties();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QVariantMap>*>(_a[0]) = _r; }  break;
        case 4: { QDBusPendingReply<> _r = LockPin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 5: { QDBusPendingReply<> _r = ResetPin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 6: { QDBusPendingReply<> _r = SetProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDBusVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 7: { QDBusPendingReply<> _r = UnlockPin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void OrgOfonoSimManagerInterface::PropertyChanged(const QString & _t1, const QDBusVariant & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
