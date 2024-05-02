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
    QByteArrayData data[31];
    char stringdata0[335];
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
QT_MOC_LITERAL(12, 132, 10), // "scopeReady"
QT_MOC_LITERAL(13, 143, 13), // "singleMeasure"
QT_MOC_LITERAL(14, 157, 9), // "nextRound"
QT_MOC_LITERAL(15, 167, 10), // "showStatus"
QT_MOC_LITERAL(16, 178, 11), // "std::string"
QT_MOC_LITERAL(17, 190, 6), // "status"
QT_MOC_LITERAL(18, 197, 19), // "showMeasurementData"
QT_MOC_LITERAL(19, 217, 8), // "int32_t*"
QT_MOC_LITERAL(20, 226, 10), // "bufferSize"
QT_MOC_LITERAL(21, 237, 8), // "int16_t*"
QT_MOC_LITERAL(22, 246, 6), // "buffer"
QT_MOC_LITERAL(23, 253, 9), // "resetZoom"
QT_MOC_LITERAL(24, 263, 11), // "liveRequest"
QT_MOC_LITERAL(25, 275, 6), // "isLive"
QT_MOC_LITERAL(26, 282, 9), // "sendSetup"
QT_MOC_LITERAL(27, 292, 8), // "sendTime"
QT_MOC_LITERAL(28, 301, 9), // "sendRatio"
QT_MOC_LITERAL(29, 311, 11), // "stepMeasure"
QT_MOC_LITERAL(30, 323, 11) // "stopMeasure"

    },
    "ScopeWindow\0chartingFinished\0\0"
    "setScopeChannel\0couplingIDX\0sensIDX\0"
    "setTriggerThreshold\0int16_t\0divisor\0"
    "setTimeBase\0uint32_t\0timeBase\0scopeReady\0"
    "singleMeasure\0nextRound\0showStatus\0"
    "std::string\0status\0showMeasurementData\0"
    "int32_t*\0bufferSize\0int16_t*\0buffer\0"
    "resetZoom\0liveRequest\0isLive\0sendSetup\0"
    "sendTime\0sendRatio\0stepMeasure\0"
    "stopMeasure"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScopeWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    2,   95,    2, 0x06 /* Public */,
       6,    1,  100,    2, 0x06 /* Public */,
       9,    1,  103,    2, 0x06 /* Public */,
      12,    0,  106,    2, 0x06 /* Public */,
      13,    0,  107,    2, 0x06 /* Public */,
      14,    0,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  109,    2, 0x08 /* Private */,
      18,    2,  112,    2, 0x08 /* Private */,
      23,    0,  117,    2, 0x08 /* Private */,
      24,    1,  118,    2, 0x08 /* Private */,
      26,    0,  121,    2, 0x08 /* Private */,
      27,    0,  122,    2, 0x08 /* Private */,
      28,    0,  123,    2, 0x08 /* Private */,
      29,    0,  124,    2, 0x0a /* Public */,
      30,    0,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 21,   20,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void,
    QMetaType::Void,
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
        case 4: _t->scopeReady(); break;
        case 5: _t->singleMeasure(); break;
        case 6: _t->nextRound(); break;
        case 7: _t->showStatus((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 8: _t->showMeasurementData((*reinterpret_cast< int32_t*(*)>(_a[1])),(*reinterpret_cast< int16_t*(*)>(_a[2]))); break;
        case 9: _t->resetZoom(); break;
        case 10: _t->liveRequest((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->sendSetup(); break;
        case 12: _t->sendTime(); break;
        case 13: _t->sendRatio(); break;
        case 14: _t->stepMeasure(); break;
        case 15: _t->stopMeasure(); break;
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
        {
            using _t = void (ScopeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScopeWindow::scopeReady)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ScopeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScopeWindow::singleMeasure)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ScopeWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScopeWindow::nextRound)) {
                *result = 6;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
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

// SIGNAL 4
void ScopeWindow::scopeReady()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ScopeWindow::singleMeasure()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ScopeWindow::nextRound()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
