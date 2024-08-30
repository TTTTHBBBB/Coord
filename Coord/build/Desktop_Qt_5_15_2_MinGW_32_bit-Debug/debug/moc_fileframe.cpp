/****************************************************************************
** Meta object code from reading C++ file 'fileframe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CoordData/fileframe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileFrame_t {
    QByteArrayData data[14];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileFrame_t qt_meta_stringdata_FileFrame = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FileFrame"
QT_MOC_LITERAL(1, 10, 18), // "signal_FlickWindow"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "str"
QT_MOC_LITERAL(4, 34, 9), // "FLICKTYPE"
QT_MOC_LITERAL(5, 44, 4), // "type"
QT_MOC_LITERAL(6, 49, 17), // "signal_Filecreate"
QT_MOC_LITERAL(7, 67, 13), // "CoordTreeNode"
QT_MOC_LITERAL(8, 81, 4), // "node"
QT_MOC_LITERAL(9, 86, 16), // "signal_FileExpor"
QT_MOC_LITERAL(10, 103, 4), // "path"
QT_MOC_LITERAL(11, 108, 13), // "slot_FileOpen"
QT_MOC_LITERAL(12, 122, 14), // "slot_FileExpor"
QT_MOC_LITERAL(13, 137, 15) // "slot_Filecreate"

    },
    "FileFrame\0signal_FlickWindow\0\0str\0"
    "FLICKTYPE\0type\0signal_Filecreate\0"
    "CoordTreeNode\0node\0signal_FileExpor\0"
    "path\0slot_FileOpen\0slot_FileExpor\0"
    "slot_Filecreate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileFrame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,
       9,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   55,    2, 0x08 /* Private */,
      12,    0,   56,    2, 0x08 /* Private */,
      13,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void FileFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_FlickWindow((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const FLICKTYPE(*)>(_a[2]))); break;
        case 1: _t->signal_Filecreate((*reinterpret_cast< const CoordTreeNode(*)>(_a[1]))); break;
        case 2: _t->signal_FileExpor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->slot_FileOpen(); break;
        case 4: _t->slot_FileExpor(); break;
        case 5: _t->slot_Filecreate((*reinterpret_cast< const CoordTreeNode(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileFrame::*)(const QString , const FLICKTYPE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileFrame::signal_FlickWindow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileFrame::*)(const CoordTreeNode & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileFrame::signal_Filecreate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileFrame::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileFrame::signal_FileExpor)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FileFrame.data,
    qt_meta_data_FileFrame,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileFrame.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FileFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FileFrame::signal_FlickWindow(const QString _t1, const FLICKTYPE _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileFrame::signal_Filecreate(const CoordTreeNode & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileFrame::signal_FileExpor(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
