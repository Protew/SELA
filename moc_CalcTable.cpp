/****************************************************************************
** Meta object code from reading C++ file 'CalcTable.h'
**
** Created: Tue Jan 18 13:41:21 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CalcTable.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalcTable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CalcTable[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      30,   10,   10,   10, 0x0a,
      43,   10,   10,   10, 0x0a,
      53,   51,   10,   10, 0x0a,
      76,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CalcTable[] = {
    "CalcTable\0\0methodChanged(int)\0"
    "doCalcStep()\0setX0()\0,\0setX0Value(int,double)\0"
    "setError(double)\0"
};

const QMetaObject CalcTable::staticMetaObject = {
    { &QTextBrowser::staticMetaObject, qt_meta_stringdata_CalcTable,
      qt_meta_data_CalcTable, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CalcTable::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CalcTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CalcTable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CalcTable))
        return static_cast<void*>(const_cast< CalcTable*>(this));
    return QTextBrowser::qt_metacast(_clname);
}

int CalcTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextBrowser::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: methodChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: doCalcStep(); break;
        case 2: setX0(); break;
        case 3: setX0Value((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: setError((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
