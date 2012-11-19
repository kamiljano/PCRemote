/****************************************************************************
** Meta object code from reading C++ file 'ServerMediaPlugin.h'
**
** Created: Sat Nov 17 23:52:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../export/ServerMediaPlugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerMediaPlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerMediaPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      33,   18,   18,   18, 0x05,
      51,   18,   18,   18, 0x05,
      87,   18,   18,   18, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ServerMediaPlugin[] = {
    "ServerMediaPlugin\0\0trackPaused()\0"
    "newTrack(QString)\0playerConnected(ServerMediaPlugin*)\0"
    "playerDisconnected(ServerMediaPlugin*)\0"
};

void ServerMediaPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ServerMediaPlugin *_t = static_cast<ServerMediaPlugin *>(_o);
        switch (_id) {
        case 0: _t->trackPaused(); break;
        case 1: _t->newTrack((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->playerConnected((*reinterpret_cast< ServerMediaPlugin*(*)>(_a[1]))); break;
        case 3: _t->playerDisconnected((*reinterpret_cast< ServerMediaPlugin*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ServerMediaPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ServerMediaPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServerMediaPlugin,
      qt_meta_data_ServerMediaPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerMediaPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerMediaPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerMediaPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerMediaPlugin))
        return static_cast<void*>(const_cast< ServerMediaPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int ServerMediaPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ServerMediaPlugin::trackPaused()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ServerMediaPlugin::newTrack(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ServerMediaPlugin::playerConnected(ServerMediaPlugin * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ServerMediaPlugin::playerDisconnected(ServerMediaPlugin * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
