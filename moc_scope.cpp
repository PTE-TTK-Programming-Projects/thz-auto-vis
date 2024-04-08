/****************************************************************************
** Meta object code from reading C++ file 'scope.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "scope.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scope.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PicoScope_t {
    QByteArrayData data[25];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PicoScope_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PicoScope_t qt_meta_stringdata_PicoScope = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PicoScope"
QT_MOC_LITERAL(1, 10, 10), // "sendStatus"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "std::string"
QT_MOC_LITERAL(4, 34, 6), // "status"
QT_MOC_LITERAL(5, 41, 12), // "finishSignal"
QT_MOC_LITERAL(6, 54, 15), // "sendMeasurement"
QT_MOC_LITERAL(7, 70, 8), // "int32_t*"
QT_MOC_LITERAL(8, 79, 12), // "bufferLength"
QT_MOC_LITERAL(9, 92, 8), // "int16_t*"
QT_MOC_LITERAL(10, 101, 6), // "buffer"
QT_MOC_LITERAL(11, 108, 12), // "retrieveData"
QT_MOC_LITERAL(12, 121, 9), // "getStatus"
QT_MOC_LITERAL(13, 131, 7), // "measure"
QT_MOC_LITERAL(14, 139, 15), // "setScopeChannel"
QT_MOC_LITERAL(15, 155, 11), // "couplingIDX"
QT_MOC_LITERAL(16, 167, 7), // "sensIDX"
QT_MOC_LITERAL(17, 175, 13), // "setTimeWindow"
QT_MOC_LITERAL(18, 189, 8), // "uint32_t"
QT_MOC_LITERAL(19, 198, 8), // "timeBase"
QT_MOC_LITERAL(20, 207, 15), // "setTriggerRatio"
QT_MOC_LITERAL(21, 223, 7), // "int16_t"
QT_MOC_LITERAL(22, 231, 7), // "divisor"
QT_MOC_LITERAL(23, 239, 10), // "setAvgRqst"
QT_MOC_LITERAL(24, 250, 14) // "lineEditString"

    },
    "PicoScope\0sendStatus\0\0std::string\0"
    "status\0finishSignal\0sendMeasurement\0"
    "int32_t*\0bufferLength\0int16_t*\0buffer\0"
    "retrieveData\0getStatus\0measure\0"
    "setScopeChannel\0couplingIDX\0sensIDX\0"
    "setTimeWindow\0uint32_t\0timeBase\0"
    "setTriggerRatio\0int16_t\0divisor\0"
    "setAvgRqst\0lineEditString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PicoScope[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    2,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x0a /* Public */,
      13,    0,   75,    2, 0x0a /* Public */,
      14,    2,   76,    2, 0x0a /* Public */,
      17,    1,   81,    2, 0x0a /* Public */,
      20,    1,   84,    2, 0x0a /* Public */,
      23,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9,    8,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::QString,   24,

       0        // eod
};

void PicoScope::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PicoScope *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendStatus((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->finishSignal(); break;
        case 2: _t->sendMeasurement((*reinterpret_cast< int32_t*(*)>(_a[1])),(*reinterpret_cast< int16_t*(*)>(_a[2]))); break;
        case 3: _t->retrieveData(); break;
        case 4: _t->getStatus(); break;
        case 5: _t->measure(); break;
        case 6: _t->setScopeChannel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->setTimeWindow((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 8: _t->setTriggerRatio((*reinterpret_cast< int16_t(*)>(_a[1]))); break;
        case 9: _t->setAvgRqst((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PicoScope::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicoScope::sendStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PicoScope::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicoScope::finishSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PicoScope::*)(int32_t * , int16_t * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PicoScope::sendMeasurement)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PicoScope::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PicoScope.data,
    qt_meta_data_PicoScope,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PicoScope::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PicoScope::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PicoScope.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PicoScope::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PicoScope::sendStatus(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PicoScope::finishSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PicoScope::sendMeasurement(int32_t * _t1, int16_t * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
