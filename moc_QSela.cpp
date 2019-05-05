/****************************************************************************
** Meta object code from reading C++ file 'QSela.h'
**
** Created: Tue Jan 18 13:41:23 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QSela.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSela.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSela[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    7,    6,    6, 0x0a,
      42,    7,    6,    6, 0x0a,
      74,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSela[] = {
    "QSela\0\0,,\0setMatrixAValue(int,int,double)\0"
    "setMatrixBValue(int,int,double)\0"
    "showOutput()\0"
};

const QMetaObject QSela::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_QSela,
      qt_meta_data_QSela, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSela::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSela::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSela::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSela))
        return static_cast<void*>(const_cast< QSela*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int QSela::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setMatrixAValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 1: setMatrixBValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: showOutput(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
