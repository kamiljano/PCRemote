/****************************************************************************
** Meta object code from reading C++ file 'tcpcommunicator.h'
**
** Created: Thu Sep 27 18:03:45 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../communicators/tcpcommunicator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpcommunicator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpCommunicator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      29,   16,   16,   16, 0x08,
      44,   16,   16,   16, 0x08,
      54,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpCommunicator[] = {
    "TcpCommunicator\0\0addClient()\0"
    "removeClient()\0process()\0processUDP()\0"
};

void TcpCommunicator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpCommunicator *_t = static_cast<TcpCommunicator *>(_o);
        switch (_id) {
        case 0: _t->addClient(); break;
        case 1: _t->removeClient(); break;
        case 2: _t->process(); break;
        case 3: _t->processUDP(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TcpCommunicator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TcpCommunicator::staticMetaObject = {
    { &AbstractCommunicator::staticMetaObject, qt_meta_stringdata_TcpCommunicator,
      qt_meta_data_TcpCommunicator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpCommunicator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpCommunicator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpCommunicator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpCommunicator))
        return static_cast<void*>(const_cast< TcpCommunicator*>(this));
    return AbstractCommunicator::qt_metacast(_clname);
}

int TcpCommunicator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCommunicator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
