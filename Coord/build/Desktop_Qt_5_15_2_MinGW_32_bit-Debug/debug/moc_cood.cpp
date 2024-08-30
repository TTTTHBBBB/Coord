/****************************************************************************
** Meta object code from reading C++ file 'cood.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../cood.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cood.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cood_t {
    QByteArrayData data[14];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cood_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cood_t qt_meta_stringdata_Cood = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Cood"
QT_MOC_LITERAL(1, 5, 16), // "slot_flickwindow"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "str"
QT_MOC_LITERAL(4, 27, 9), // "FLICKTYPE"
QT_MOC_LITERAL(5, 37, 4), // "type"
QT_MOC_LITERAL(6, 42, 15), // "slot_Filecreate"
QT_MOC_LITERAL(7, 58, 13), // "CoordTreeNode"
QT_MOC_LITERAL(8, 72, 4), // "node"
QT_MOC_LITERAL(9, 77, 14), // "slot_FileExpor"
QT_MOC_LITERAL(10, 92, 4), // "path"
QT_MOC_LITERAL(11, 97, 11), // "Slot_broken"
QT_MOC_LITERAL(12, 109, 11), // "Slot_curved"
QT_MOC_LITERAL(13, 121, 11) // "Slot_column"

    },
    "Cood\0slot_flickwindow\0\0str\0FLICKTYPE\0"
    "type\0slot_Filecreate\0CoordTreeNode\0"
    "node\0slot_FileExpor\0path\0Slot_broken\0"
    "Slot_curved\0Slot_column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cood[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       9,    1,   52,    2, 0x0a /* Public */,
      11,    0,   55,    2, 0x0a /* Public */,
      12,    0,   56,    2, 0x0a /* Public */,
      13,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cood::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cood *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_flickwindow((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const FLICKTYPE(*)>(_a[2]))); break;
        case 1: _t->slot_Filecreate((*reinterpret_cast< const CoordTreeNode(*)>(_a[1]))); break;
        case 2: _t->slot_FileExpor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->Slot_broken(); break;
        case 4: _t->Slot_curved(); break;
        case 5: _t->Slot_column(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cood::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Cood.data,
    qt_meta_data_Cood,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cood::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cood::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cood.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Cood::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
