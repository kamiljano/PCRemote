/****************************************************************************
** Meta object code from reading C++ file 'server_plugin.h'
**
** Created: Thu Sep 27 18:56:11 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../server_plugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server_plugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Server_plugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      40,   14,   14,   14, 0x05,
      68,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Server_plugin[] = {
    "Server_plugin\0\0playerConnected(QString)\0"
    "playerDisconnected(QString)\0trackChanged()\0"
};

void Server_plugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Server_plugin *_t = static_cast<Server_plugin *>(_o);
        switch (_id) {
        case 0: _t->playerConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->playerDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->trackChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Server_plugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Server_plugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Server_plugin,
      qt_meta_data_Server_plugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Server_plugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Server_plugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Server_plugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Server_plugin))
        return static_cast<void*>(const_cast< Server_plugin*>(this));
    return QObject::qt_metacast(_clname);
}

int Server_plugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Server_plugin::playerConnected(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server_plugin::playerDisconnected(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server_plugin::trackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
