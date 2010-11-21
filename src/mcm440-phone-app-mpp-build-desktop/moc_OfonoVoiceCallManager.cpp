/****************************************************************************
** Meta object code from reading C++ file 'OfonoVoiceCallManager.h'
**
** Created: Sun Nov 21 16:09:01 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mcm440-phone-app-mpp/srcgen/OfonoVoiceCallManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OfonoVoiceCallManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OrgOfonoVoiceCallManagerInterface[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      43,   35,   34,   34, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,   34,   81,   34, 0x0a,
     178,   35,  143,   34, 0x0a,
     231,   34,  200,   34, 0x0a,
     267,   34,  247,   34, 0x0a,
     279,   34,  247,   34, 0x0a,
     298,   34,  247,   34, 0x0a,
     318,  314,   81,   34, 0x0a,
     347,   34,  247,   34, 0x0a,
     366,  314,  247,   34, 0x0a,
     385,   34,  247,   34, 0x0a,
     397,   34,  247,   34, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OrgOfonoVoiceCallManagerInterface[] = {
    "OrgOfonoVoiceCallManagerInterface\0\0"
    "in0,in1\0PropertyChanged(QString,QDBusVariant)\0"
    "QDBusPendingReply<QList<QDBusObjectPath> >\0"
    "CreateMultiparty()\0"
    "QDBusPendingReply<QDBusObjectPath>\0"
    "Dial(QString,QString)\0"
    "QDBusPendingReply<QVariantMap>\0"
    "GetProperties()\0QDBusPendingReply<>\0"
    "HangupAll()\0HangupMultiparty()\0"
    "HoldAndAnswer()\0in0\0PrivateChat(QDBusObjectPath)\0"
    "ReleaseAndAnswer()\0SendTones(QString)\0"
    "SwapCalls()\0Transfer()\0"
};

const QMetaObject OrgOfonoVoiceCallManagerInterface::staticMetaObject = {
    { &QDBusAbstractInterface::staticMetaObject, qt_meta_stringdata_OrgOfonoVoiceCallManagerInterface,
      qt_meta_data_OrgOfonoVoiceCallManagerInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OrgOfonoVoiceCallManagerInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OrgOfonoVoiceCallManagerInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OrgOfonoVoiceCallManagerInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrgOfonoVoiceCallManagerInterface))
        return static_cast<void*>(const_cast< OrgOfonoVoiceCallManagerInterface*>(this));
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int OrgOfonoVoiceCallManagerInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: PropertyChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDBusVariant(*)>(_a[2]))); break;
        case 1: { QDBusPendingReply<QList<QDBusObjectPath> > _r = CreateMultiparty();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QList<QDBusObjectPath> >*>(_a[0]) = _r; }  break;
        case 2: { QDBusPendingReply<QDBusObjectPath> _r = Dial((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QDBusObjectPath>*>(_a[0]) = _r; }  break;
        case 3: { QDBusPendingReply<QVariantMap> _r = GetProperties();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QVariantMap>*>(_a[0]) = _r; }  break;
        case 4: { QDBusPendingReply<> _r = HangupAll();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 5: { QDBusPendingReply<> _r = HangupMultiparty();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 6: { QDBusPendingReply<> _r = HoldAndAnswer();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 7: { QDBusPendingReply<QList<QDBusObjectPath> > _r = PrivateChat((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QList<QDBusObjectPath> >*>(_a[0]) = _r; }  break;
        case 8: { QDBusPendingReply<> _r = ReleaseAndAnswer();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 9: { QDBusPendingReply<> _r = SendTones((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 10: { QDBusPendingReply<> _r = SwapCalls();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 11: { QDBusPendingReply<> _r = Transfer();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void OrgOfonoVoiceCallManagerInterface::PropertyChanged(const QString & _t1, const QDBusVariant & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
