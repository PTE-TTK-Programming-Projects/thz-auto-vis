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
    QByteArrayData data[11];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScopeWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScopeWindow_t qt_meta_stringdata_ScopeWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ScopeWindow"
QT_MOC_LITERAL(1, 12, 10), // "showStatus"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "std::string"
QT_MOC_LITERAL(4, 36, 6), // "status"
QT_MOC_LITERAL(5, 43, 19), // "showMeasurementData"
QT_MOC_LITERAL(6, 63, 8), // "int32_t*"
QT_MOC_LITERAL(7, 72, 10), // "bufferSize"
QT_MOC_LITERAL(8, 83, 8), // "int16_t*"
QT_MOC_LITERAL(9, 92, 6), // "buffer"
QT_MOC_LITERAL(10, 99, 9) // "resetZoom"

    },
    "ScopeWindow\0showStatus\0\0std::string\0"
    "status\0showMeasurementData\0int32_t*\0"
    "bufferSize\0int16_t*\0buffer\0resetZoom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScopeWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       5,    2,   32,    2, 0x08 /* Private */,
      10,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void,

       0        // eod
};

void ScopeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScopeWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showStatus((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->showMeasurementData((*reinterpret_cast< int32_t*(*)>(_a[1])),(*reinterpret_cast< int16_t*(*)>(_a[2]))); break;
        case 2: _t->resetZoom(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScopeWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
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
    return QWidget::qt_metacast(_clname);
}

int ScopeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE