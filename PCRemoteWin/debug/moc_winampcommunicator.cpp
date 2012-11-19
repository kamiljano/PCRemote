/****************************************************************************
** Meta object code from reading C++ file 'winampcommunicator.h'
**
** Created: Sat Nov 17 23:52:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PlayerCommunicators/winampcommunicator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'winampcommunicator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WinampCommunicator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_WinampCommunicator[] = {
    "WinampCommunicator\0"
};

void WinampCommunicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData WinampCommunicator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WinampCommunicator::staticMetaObject = {
    { &ServerMediaPlugin::staticMetaObject, qt_meta_stringdata_WinampCommunicator,
      qt_meta_data_WinampCommunicator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WinampCommunicator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WinampCommunicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WinampCommunicator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WinampCommunicator))
        return static_cast<void*>(const_cast< WinampCommunicator*>(this));
    return ServerMediaPlugin::qt_metacast(_clname);
}

int WinampCommunicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ServerMediaPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
