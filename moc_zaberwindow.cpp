/****************************************************************************
** Meta object code from reading C++ file 'zaberwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "zaberwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zaberwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ZaberWindow_t {
    QByteArrayData data[24];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZaberWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZaberWindow_t qt_meta_stringdata_ZaberWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ZaberWindow"
QT_MOC_LITERAL(1, 12, 13), // "connectToPort"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "std::string"
QT_MOC_LITERAL(4, 39, 8), // "portName"
QT_MOC_LITERAL(5, 48, 13), // "sendManualMsg"
QT_MOC_LITERAL(6, 62, 6), // "manMsg"
QT_MOC_LITERAL(7, 69, 13), // "sendUnitIndex"
QT_MOC_LITERAL(8, 83, 5), // "index"
QT_MOC_LITERAL(9, 89, 10), // "selectPort"
QT_MOC_LITERAL(10, 100, 8), // "motorMsg"
QT_MOC_LITERAL(11, 109, 12), // "std::string*"
QT_MOC_LITERAL(12, 122, 7), // "message"
QT_MOC_LITERAL(13, 130, 7), // "motorID"
QT_MOC_LITERAL(14, 138, 2), // "ID"
QT_MOC_LITERAL(15, 141, 10), // "prepManMsg"
QT_MOC_LITERAL(16, 152, 10), // "buttonHome"
QT_MOC_LITERAL(17, 163, 9), // "moveToPos"
QT_MOC_LITERAL(18, 173, 10), // "unitSelChd"
QT_MOC_LITERAL(19, 184, 4), // "unit"
QT_MOC_LITERAL(20, 189, 8), // "unitSend"
QT_MOC_LITERAL(21, 198, 6), // "stpFWD"
QT_MOC_LITERAL(22, 205, 6), // "stpBWD"
QT_MOC_LITERAL(23, 212, 18) // "externalUnitChange"

    },
    "ZaberWindow\0connectToPort\0\0std::string\0"
    "portName\0sendManualMsg\0manMsg\0"
    "sendUnitIndex\0index\0selectPort\0motorMsg\0"
    "std::string*\0message\0motorID\0ID\0"
    "prepManMsg\0buttonHome\0moveToPos\0"
    "unitSelChd\0unit\0unitSend\0stpFWD\0stpBWD\0"
    "externalUnitChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZaberWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x06 /* Public */,
       7,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   93,    2, 0x08 /* Private */,
      10,    1,   94,    2, 0x08 /* Private */,
      13,    1,   97,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    1,  103,    2, 0x08 /* Private */,
      20,    1,  106,    2, 0x08 /* Private */,
      21,    0,  109,    2, 0x08 /* Private */,
      22,    0,  110,    2, 0x08 /* Private */,
      23,    1,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void ZaberWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZaberWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectToPort((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->sendManualMsg((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->sendUnitIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->selectPort(); break;
        case 4: _t->motorMsg((*reinterpret_cast< std::string*(*)>(_a[1]))); break;
        case 5: _t->motorID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->prepManMsg(); break;
        case 7: _t->buttonHome(); break;
        case 8: _t->moveToPos(); break;
        case 9: _t->unitSelChd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->unitSend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->stpFWD(); break;
        case 12: _t->stpBWD(); break;
        case 13: _t->externalUnitChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZaberWindow::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZaberWindow::connectToPort)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZaberWindow::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZaberWindow::sendManualMsg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ZaberWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZaberWindow::sendUnitIndex)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ZaberWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_ZaberWindow.data,
    qt_meta_data_ZaberWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ZaberWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZaberWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZaberWindow.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int ZaberWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ZaberWindow::connectToPort(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZaberWindow::sendManualMsg(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ZaberWindow::sendUnitIndex(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE