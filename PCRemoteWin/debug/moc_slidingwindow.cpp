/****************************************************************************
** Meta object code from reading C++ file 'slidingwindow.h'
**
** Created: Wed Nov 14 20:15:21 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../slidingwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'slidingwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SlidingWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      22,   14,   14,   14, 0x0a,
      29,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SlidingWindow[] = {
    "SlidingWindow\0\0Show()\0Hide()\0killWindow()\0"
};

void SlidingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SlidingWindow *_t = static_cast<SlidingWindow *>(_o);
        switch (_id) {
        case 0: _t->Show(); break;
        case 1: _t->Hide(); break;
        case 2: _t->killWindow(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SlidingWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SlidingWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SlidingWindow,
      qt_meta_data_SlidingWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SlidingWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SlidingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SlidingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SlidingWindow))
        return static_cast<void*>(const_cast< SlidingWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SlidingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
