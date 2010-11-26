/****************************************************************************
** Meta object code from reading C++ file 'gsm.h'
**
** Created: Fri Nov 26 10:11:00 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/gsm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gsm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gsm[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   10,    5,    4, 0x0a,
      37,    4,    5,    4, 0x0a,
      52,    4,    5,    4, 0x0a,
      79,   68,    4,    4, 0x0a,

 // methods: signature, parameters, type, tag, flags
     117,    4,    4,    4, 0x02,
     124,    4,    5,    4, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_Gsm[] = {
    "Gsm\0\0bool\0number\0dialNumber(QString)\0"
    "powerModemOn()\0powerModemOff()\0"
    "name,value\0propertyChanged(QString,QDBusVariant)\0"
    "test()\0getModemStatus()\0"
};

const QMetaObject Gsm::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Gsm,
      qt_meta_data_Gsm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gsm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gsm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gsm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gsm))
        return static_cast<void*>(const_cast< Gsm*>(this));
    return QObject::qt_metacast(_clname);
}

int Gsm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = dialNumber((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = powerModemOn();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = powerModemOff();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: propertyChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDBusVariant(*)>(_a[2]))); break;
        case 4: test(); break;
        case 5: { bool _r = getModemStatus();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
