/****************************************************************************
** Meta object code from reading C++ file 'interface_control.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "interface_control.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interface_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_interface_control[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      45,   18,   18,   18, 0x08,
      71,   18,   18,   18, 0x08,
      97,   18,   18,   18, 0x08,
     123,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_interface_control[] = {
    "interface_control\0\0on_pushButton_4_clicked()\0"
    "on_pushButton_2_pressed()\0"
    "on_pushButton_5_pressed()\0"
    "on_pushButton_3_pressed()\0"
    "on_pushButton_6_pressed()\0"
};

void interface_control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        interface_control *_t = static_cast<interface_control *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_4_clicked(); break;
        case 1: _t->on_pushButton_2_pressed(); break;
        case 2: _t->on_pushButton_5_pressed(); break;
        case 3: _t->on_pushButton_3_pressed(); break;
        case 4: _t->on_pushButton_6_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData interface_control::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject interface_control::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_interface_control,
      qt_meta_data_interface_control, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &interface_control::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *interface_control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *interface_control::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_interface_control))
        return static_cast<void*>(const_cast< interface_control*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int interface_control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
