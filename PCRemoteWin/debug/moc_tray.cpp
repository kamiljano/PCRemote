/****************************************************************************
** Meta object code from reading C++ file 'tray.h'
**
** Created: Sun Oct 14 09:40:37 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tray.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tray[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,    6,    5,    5, 0x0a,
      57,    5,    5,    5, 0x0a,
      71,    5,    5,    5, 0x0a,
      88,    5,    5,    5, 0x0a,
     108,  105,    5,    5, 0x0a,
     137,    5,    5,    5, 0x0a,
     152,    5,    5,    5, 0x0a,
     167,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tray[] = {
    "Tray\0\0reason\0activate(QSystemTrayIcon::ActivationReason)\0"
    "exitClicked()\0optionsClicked()\0"
    "getInfoClicked()\0cv\0setClientsView(ClientsView*)\0"
    "aboutClicked()\0adHocClicked()\0"
    "closeAdHocClicked()\0"
};

void Tray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Tray *_t = static_cast<Tray *>(_o);
        switch (_id) {
        case 0: _t->activate((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 1: _t->exitClicked(); break;
        case 2: _t->optionsClicked(); break;
        case 3: _t->getInfoClicked(); break;
        case 4: _t->setClientsView((*reinterpret_cast< ClientsView*(*)>(_a[1]))); break;
        case 5: _t->aboutClicked(); break;
        case 6: _t->adHocClicked(); break;
        case 7: _t->closeAdHocClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tray::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tray::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tray,
      qt_meta_data_Tray, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tray::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tray::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tray))
        return static_cast<void*>(const_cast< Tray*>(this));
    return QObject::qt_metacast(_clname);
}

int Tray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
