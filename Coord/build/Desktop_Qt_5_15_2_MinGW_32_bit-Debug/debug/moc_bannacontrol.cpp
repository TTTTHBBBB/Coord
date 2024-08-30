/****************************************************************************
** Meta object code from reading C++ file 'bannacontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../render/bannacontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bannacontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BannaControl_t {
    QByteArrayData data[8];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BannaControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BannaControl_t qt_meta_stringdata_BannaControl = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BannaControl"
QT_MOC_LITERAL(1, 13, 21), // "Signal_LanguageChange"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 9), // "FLICKTYPE"
QT_MOC_LITERAL(4, 46, 4), // "TYPE"
QT_MOC_LITERAL(5, 51, 21), // "Slot_changeImageTimer"
QT_MOC_LITERAL(6, 73, 19), // "Slot_pushButtonLeft"
QT_MOC_LITERAL(7, 93, 20) // "Slot_pushButtonRight"

    },
    "BannaControl\0Signal_LanguageChange\0\0"
    "FLICKTYPE\0TYPE\0Slot_changeImageTimer\0"
    "Slot_pushButtonLeft\0Slot_pushButtonRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BannaControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       1,    0,   42,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BannaControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BannaControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_LanguageChange((*reinterpret_cast< FLICKTYPE(*)>(_a[1]))); break;
        case 1: _t->Signal_LanguageChange(); break;
        case 2: _t->Slot_changeImageTimer(); break;
        case 3: _t->Slot_pushButtonLeft(); break;
        case 4: _t->Slot_pushButtonRight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BannaControl::*)(FLICKTYPE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BannaControl::Signal_LanguageChange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BannaControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_BannaControl.data,
    qt_meta_data_BannaControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BannaControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BannaControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BannaControl.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BannaControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void BannaControl::Signal_LanguageChange(FLICKTYPE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
