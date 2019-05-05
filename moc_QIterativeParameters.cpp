/****************************************************************************
** Meta object code from reading C++ file 'QIterativeParameters.h'
**
** Created: Tue Jan 18 13:41:22 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QIterativeParameters.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QIterativeParameters.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QIterativeParameters[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   22,   21,   21, 0x05,
      48,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   71,   21,   21, 0x08,
     101,   71,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QIterativeParameters[] = {
    "QIterativeParameters\0\0,\0emitX0Value(int,double)\0"
    "emitErrorValue(double)\0,,\0"
    "setX0Value(int,int,double)\0"
    "setError(int,int,double)\0"
};

const QMetaObject QIterativeParameters::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QIterativeParameters,
      qt_meta_data_QIterativeParameters, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QIterativeParameters::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QIterativeParameters::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QIterativeParameters::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIterativeParameters))
        return static_cast<void*>(const_cast< QIterativeParameters*>(this));
    return QWidget::qt_metacast(_clname);
}

int QIterativeParameters::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: emitX0Value((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: emitErrorValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: setX0Value((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 3: setError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QIterativeParameters::emitX0Value(int _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QIterativeParameters::emitErrorValue(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
