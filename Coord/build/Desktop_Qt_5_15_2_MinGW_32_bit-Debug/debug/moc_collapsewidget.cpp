/****************************************************************************
** Meta object code from reading C++ file 'collapsewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../collapsewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'collapsewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CollapseWidget_t {
    QByteArrayData data[11];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CollapseWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CollapseWidget_t qt_meta_stringdata_CollapseWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CollapseWidget"
QT_MOC_LITERAL(1, 15, 17), // "signal_btnClicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "COLLSPSESTAUS"
QT_MOC_LITERAL(4, 48, 4), // "type"
QT_MOC_LITERAL(5, 53, 17), // "drawShowAnimation"
QT_MOC_LITERAL(6, 71, 20), // "drawDisplayAnimation"
QT_MOC_LITERAL(7, 92, 8), // "showLine"
QT_MOC_LITERAL(8, 101, 10), // "cancelLine"
QT_MOC_LITERAL(9, 112, 6), // "radius"
QT_MOC_LITERAL(10, 119, 12) // "cancleRadius"

    },
    "CollapseWidget\0signal_btnClicked\0\0"
    "COLLSPSESTAUS\0type\0drawShowAnimation\0"
    "drawDisplayAnimation\0showLine\0cancelLine\0"
    "radius\0cancleRadius"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CollapseWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       4,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08 /* Private */,
       6,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QReal, 0x00095003,
       8, QMetaType::QReal, 0x00095003,
       9, QMetaType::QReal, 0x00095103,
      10, QMetaType::QReal, 0x00095003,

       0        // eod
};

void CollapseWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CollapseWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_btnClicked((*reinterpret_cast< COLLSPSESTAUS(*)>(_a[1]))); break;
        case 1: _t->drawShowAnimation(); break;
        case 2: _t->drawDisplayAnimation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CollapseWidget::*)(COLLSPSESTAUS );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CollapseWidget::signal_btnClicked)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CollapseWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getshowLine(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->getcancelLine(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->getRadius(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = _t->getcancleRadius(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CollapseWidget *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setshowLine(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setcancelLine(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setRadius(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->setcancleRadius(*reinterpret_cast< qreal*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CollapseWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_CollapseWidget.data,
    qt_meta_data_CollapseWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CollapseWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CollapseWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CollapseWidget.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int CollapseWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CollapseWidget::signal_btnClicked(COLLSPSESTAUS _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
