/****************************************************************************
** Meta object code from reading C++ file 'collapseanimation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../collapseanimation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'collapseanimation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CollapseAnimation_t {
    QByteArrayData data[22];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CollapseAnimation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CollapseAnimation_t qt_meta_stringdata_CollapseAnimation = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CollapseAnimation"
QT_MOC_LITERAL(1, 18, 18), // "signal_FlickWindow"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 3), // "str"
QT_MOC_LITERAL(4, 42, 9), // "FLICKTYPE"
QT_MOC_LITERAL(5, 52, 4), // "type"
QT_MOC_LITERAL(6, 57, 17), // "signal_Filecreate"
QT_MOC_LITERAL(7, 75, 13), // "CoordTreeNode"
QT_MOC_LITERAL(8, 89, 4), // "node"
QT_MOC_LITERAL(9, 94, 16), // "signal_FileExpor"
QT_MOC_LITERAL(10, 111, 4), // "path"
QT_MOC_LITERAL(11, 116, 13), // "Signal_broken"
QT_MOC_LITERAL(12, 130, 13), // "Signal_curved"
QT_MOC_LITERAL(13, 144, 13), // "Signal_column"
QT_MOC_LITERAL(14, 158, 10), // "toggleFold"
QT_MOC_LITERAL(15, 169, 13), // "COLLSPSESTAUS"
QT_MOC_LITERAL(16, 183, 16), // "slot_FlickWindow"
QT_MOC_LITERAL(17, 200, 15), // "slot_Filecreate"
QT_MOC_LITERAL(18, 216, 14), // "slot_FileExpor"
QT_MOC_LITERAL(19, 231, 11), // "Slot_broken"
QT_MOC_LITERAL(20, 243, 11), // "Slot_curved"
QT_MOC_LITERAL(21, 255, 11) // "Slot_column"

    },
    "CollapseAnimation\0signal_FlickWindow\0"
    "\0str\0FLICKTYPE\0type\0signal_Filecreate\0"
    "CoordTreeNode\0node\0signal_FileExpor\0"
    "path\0Signal_broken\0Signal_curved\0"
    "Signal_column\0toggleFold\0COLLSPSESTAUS\0"
    "slot_FlickWindow\0slot_Filecreate\0"
    "slot_FileExpor\0Slot_broken\0Slot_curved\0"
    "Slot_column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CollapseAnimation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       6,    1,   84,    2, 0x06 /* Public */,
       9,    1,   87,    2, 0x06 /* Public */,
      11,    0,   90,    2, 0x06 /* Public */,
      12,    0,   91,    2, 0x06 /* Public */,
      13,    0,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   93,    2, 0x0a /* Public */,
      16,    2,   96,    2, 0x0a /* Public */,
      17,    1,  101,    2, 0x0a /* Public */,
      18,    1,  104,    2, 0x0a /* Public */,
      19,    0,  107,    2, 0x0a /* Public */,
      20,    0,  108,    2, 0x0a /* Public */,
      21,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CollapseAnimation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CollapseAnimation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_FlickWindow((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const FLICKTYPE(*)>(_a[2]))); break;
        case 1: _t->signal_Filecreate((*reinterpret_cast< const CoordTreeNode(*)>(_a[1]))); break;
        case 2: _t->signal_FileExpor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->Signal_broken(); break;
        case 4: _t->Signal_curved(); break;
        case 5: _t->Signal_column(); break;
        case 6: _t->toggleFold((*reinterpret_cast< COLLSPSESTAUS(*)>(_a[1]))); break;
        case 7: _t->slot_FlickWindow((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const FLICKTYPE(*)>(_a[2]))); break;
        case 8: _t->slot_Filecreate((*reinterpret_cast< const CoordTreeNode(*)>(_a[1]))); break;
        case 9: _t->slot_FileExpor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->Slot_broken(); break;
        case 11: _t->Slot_curved(); break;
        case 12: _t->Slot_column(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CollapseAnimation::*)(const QString , const FLICKTYPE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CollapseAnimation::signal_FlickWindow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CollapseAnimation::*)(const CoordTreeNode & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CollapseAnimation::signal_Filecreate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CollapseAnimation::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CollapseAnimation::signal_FileExpor)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CollapseAnimation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CollapseAnimation::Signal_broken)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CollapseAnimation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CollapseAnimation::Signal_curved)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CollapseAnimation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CollapseAnimation::Signal_column)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CollapseAnimation::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_CollapseAnimation.data,
    qt_meta_data_CollapseAnimation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CollapseAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CollapseAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CollapseAnimation.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int CollapseAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CollapseAnimation::signal_FlickWindow(const QString _t1, const FLICKTYPE _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CollapseAnimation::signal_Filecreate(const CoordTreeNode & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CollapseAnimation::signal_FileExpor(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CollapseAnimation::Signal_broken()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CollapseAnimation::Signal_curved()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CollapseAnimation::Signal_column()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
