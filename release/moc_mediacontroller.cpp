/****************************************************************************
** Meta object code from reading C++ file 'mediacontroller.h'
**
** Created: Sat Mar 2 06:57:58 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PCRemoteWin/Widgets/mediacontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediacontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MediaController[] = {

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
      17,   16,   16,   16, 0x09,
      24,   16,   16,   16, 0x09,
      31,   16,   16,   16, 0x09,
      42,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MediaController[] = {
    "MediaController\0\0Play()\0Next()\0"
    "Previous()\0LoadLogo()\0"
};

void MediaController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MediaController *_t = static_cast<MediaController *>(_o);
        switch (_id) {
        case 0: _t->Play(); break;
        case 1: _t->Next(); break;
        case 2: _t->Previous(); break;
        case 3: _t->LoadLogo(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MediaController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MediaController::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MediaController,
      qt_meta_data_MediaController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MediaController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MediaController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MediaController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MediaController))
        return static_cast<void*>(const_cast< MediaController*>(this));
    return QWidget::qt_metacast(_clname);
}

int MediaController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
