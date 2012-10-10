/****************************************************************************
** Meta object code from reading C++ file 'plugin_winamp.h'
**
** Created: Wed Oct 10 21:01:19 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plugin_winamp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plugin_winamp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Waiter[] = {

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

static const char qt_meta_stringdata_Waiter[] = {
    "Waiter\0"
};

void Waiter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Waiter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Waiter::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Waiter,
      qt_meta_data_Waiter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Waiter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Waiter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Waiter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Waiter))
        return static_cast<void*>(const_cast< Waiter*>(this));
    return QThread::qt_metacast(_clname);
}

int Waiter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_Plugin_winamp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      36,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Plugin_winamp[] = {
    "Plugin_winamp\0\0winampDetectedSlot()\0"
    "winampGoneSlot()\0"
};

void Plugin_winamp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Plugin_winamp *_t = static_cast<Plugin_winamp *>(_o);
        switch (_id) {
        case 0: _t->winampDetectedSlot(); break;
        case 1: _t->winampGoneSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Plugin_winamp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Plugin_winamp::staticMetaObject = {
    { &ServerMediaPlugin::staticMetaObject, qt_meta_stringdata_Plugin_winamp,
      qt_meta_data_Plugin_winamp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Plugin_winamp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Plugin_winamp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Plugin_winamp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Plugin_winamp))
        return static_cast<void*>(const_cast< Plugin_winamp*>(this));
    return ServerMediaPlugin::qt_metacast(_clname);
}

int Plugin_winamp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ServerMediaPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
