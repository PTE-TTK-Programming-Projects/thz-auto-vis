/****************************************************************************
** Meta object code from reading C++ file 'zabermotor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "zabermotor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zabermotor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ZaberDevice_t {
    QByteArrayData data[16];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZaberDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZaberDevice_t qt_meta_stringdata_ZaberDevice = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ZaberDevice"
QT_MOC_LITERAL(1, 12, 10), // "motorReady"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "motorBusy"
QT_MOC_LITERAL(4, 34, 9), // "motorSent"
QT_MOC_LITERAL(5, 44, 12), // "std::string*"
QT_MOC_LITERAL(6, 57, 3), // "msg"
QT_MOC_LITERAL(7, 61, 9), // "motorIDed"
QT_MOC_LITERAL(8, 71, 2), // "ID"
QT_MOC_LITERAL(9, 74, 16), // "startSerialTimer"
QT_MOC_LITERAL(10, 91, 10), // "readSerial"
QT_MOC_LITERAL(11, 102, 11), // "connectName"
QT_MOC_LITERAL(12, 114, 11), // "std::string"
QT_MOC_LITERAL(13, 126, 8), // "portName"
QT_MOC_LITERAL(14, 135, 11), // "sendToMotor"
QT_MOC_LITERAL(15, 147, 7) // "message"

    },
    "ZaberDevice\0motorReady\0\0motorBusy\0"
    "motorSent\0std::string*\0msg\0motorIDed\0"
    "ID\0startSerialTimer\0readSerial\0"
    "connectName\0std::string\0portName\0"
    "sendToMotor\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZaberDevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,
       7,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,
      11,    1,   64,    2, 0x0a /* Public */,
      14,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   15,

       0        // eod
};

void ZaberDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZaberDevice *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->motorReady(); break;
        case 1: _t->motorBusy(); break;
        case 2: _t->motorSent((*reinterpret_cast< std::string*(*)>(_a[1]))); break;
        case 3: _t->motorIDed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->startSerialTimer(); break;
        case 5: _t->readSerial(); break;
        case 6: _t->connectName((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 7: _t->sendToMotor((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZaberDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZaberDevice::motorReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZaberDevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZaberDevice::motorBusy)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ZaberDevice::*)(std::string * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZaberDevice::motorSent)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ZaberDevice::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZaberDevice::motorIDed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ZaberDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QSerialPort::staticMetaObject>(),
    qt_meta_stringdata_ZaberDevice.data,
    qt_meta_data_ZaberDevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ZaberDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZaberDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZaberDevice.stringdata0))
        return static_cast<void*>(this);
    return QSerialPort::qt_metacast(_clname);
}

int ZaberDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ZaberDevice::motorReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ZaberDevice::motorBusy()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ZaberDevice::motorSent(std::string * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ZaberDevice::motorIDed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
