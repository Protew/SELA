/****************************************************************************
** Meta object code from reading C++ file 'QOutputViewer.h'
**
** Created: Tue Jan 18 13:41:22 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QOutputViewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QOutputViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QOutputViewer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      25,   14,   14,   14, 0x0a,
      32,   14,   14,   14, 0x0a,
      39,   14,   14,   14, 0x0a,
      48,   14,   14,   14, 0x0a,
      61,   14,   14,   14, 0x0a,
      75,   14,   14,   14, 0x0a,
      89,   14,   14,   14, 0x0a,
     103,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QOutputViewer[] = {
    "QOutputViewer\0\0setSela()\0setA()\0setB()\0"
    "setDet()\0setInverse()\0setTranpose()\0"
    "setCofactor()\0setIdentity()\0setDiagonal()\0"
};

const QMetaObject QOutputViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QOutputViewer,
      qt_meta_data_QOutputViewer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QOutputViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QOutputViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QOutputViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QOutputViewer))
        return static_cast<void*>(const_cast< QOutputViewer*>(this));
    return QWidget::qt_metacast(_clname);
}

int QOutputViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setSela(); break;
        case 1: setA(); break;
        case 2: setB(); break;
        case 3: setDet(); break;
        case 4: setInverse(); break;
        case 5: setTranpose(); break;
        case 6: setCofactor(); break;
        case 7: setIdentity(); break;
        case 8: setDiagonal(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
