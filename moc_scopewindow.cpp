/****************************************************************************
** Meta object code from reading C++ file 'scopewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "scopewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scopewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScopeWindow_t {
    QByteArrayData data[26];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScopeWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScopeWindow_t qt_meta_stringdata_ScopeWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ScopeWindow"
QT_MOC_LITERAL(1, 12, 16), // "chartingFinished"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "setScopeChannel"
QT_MOC_LITERAL(4, 46, 11), // "couplingIDX"
QT_MOC_LITERAL(5, 58, 7), // "sensIDX"
QT_MOC_LITERAL(6, 66, 19), // "setTriggerThreshold"
QT_MOC_LITERAL(7, 86, 7), // "int16_t"
QT_MOC_LITERAL(8, 94, 7), // "divisor"
QT_MOC_LITERAL(9, 102, 11), // "setTimeBase"
QT_MOC_LITERAL(10, 114, 8), // "uint32_t"
QT_MOC_LITERAL(11, 123, 8), // "timeBase"
QT_MOC_LITERAL(12, 132, 10), // "showStatus"
QT_MOC_LITERAL(13, 143, 11), // "std::string"
QT_MOC_LITERAL(14, 155, 6), // "status"
QT_MOC_LITERAL(15, 162, 19), // "showMeasurementData"
QT_MOC_LITERAL(16, 182, 8), // "int32_t*"
QT_MOC_LITERAL(17, 191, 10), // "bufferSize"
QT_MOC_LITERAL(18, 202, 8), // "int16_t*"
QT_MOC_LITERAL(19, 211, 6), // "buffer"
QT_MOC_LITERAL(20, 218, 9), // "resetZoom"
QT_MOC_LITERAL(21, 228, 11), // "liveRequest"
QT_MOC_LITERAL(22, 240, 6), // "isLive"
QT_MOC_LITERAL(23, 247, 9), // "sendSetup"
QT_MOC_LITERAL(24, 257, 8), // "sendTime"
QT_MOC_LITERAL(25, 266, 9) // "sendRatio"

    },
    "ScopeWindow\0chartingFinished\0\0"
    "setScopeChannel\0couplingIDX\0sensIDX\0"
    "setTriggerThreshold\0int16_t\0divisor\0"
    "setTimeBase\0uint32_t\0timeBase\0showStatus\0"
    "std::string\0status\0showMeasurementData\0"
    "int32_t*\0bufferSize\0int16_t*\0buffer\0"
    "resetZoom\0liveRequest\0isLive\0sendSetup\0"
    "sendTime\0sendRatio"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScopeWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    2,   70,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       9,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   81,    2, 0x08 /* Private */,
      15,    2,   84,    2, 0x08 /* Private */,
      20,    0,   89,    2, 0x08 /* Private */,
      21,    1,   90,    2, 0x08 /* Private */,
      23,    0,   93,    2, 0x08 /* Private */,
      24,    0,   94,    2, 0x08 /* Private */,
      25,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 18,   17,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScopeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScopeWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->chartingFinished(); break;
        case 1: _t->setScopeChannel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setTriggerThreshold((*reinterpret_cast< int16_t(*)>(_a[1]))); break;
        case 3: _t->setTimeBase((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 4: _t->showStatus((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 5: _t->showMeasurementData((*reinterpret_cast< int32_t*(*)>(_a[1])),(*reinterpret_cast< int16_t*(*)>(_a[2]))); break;
        case 6: _t->resetZoom(); break;
        case 7: _t->liveRequest((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->sendSetup(); break;
        case 9: _t->sendTime(); break;
        case 10: _t->sendRatio(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScopeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScopeWindow::chartingFinished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScopeWindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScopeWindow::setScopeChannel)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ScopeWindow::*)(int16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScopeWindow::setTriggerThreshold)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ScopeWindow::*)(uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScopeWindow::setTimeBase)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScopeWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_ScopeWindow.data,
    qt_meta_data_ScopeWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScopeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScopeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScopeWindow.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int ScopeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ScopeWindow::chartingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ScopeWindow::setScopeChannel(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScopeWindow::setTriggerThreshold(int16_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ScopeWindow::setTimeBase(uint32_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
