/****************************************************************************
** Meta object code from reading C++ file 'editionimagewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../projet/editionimagewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editionimagewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditionImageWindow_t {
    QByteArrayData data[15];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditionImageWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditionImageWindow_t qt_meta_stringdata_EditionImageWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "EditionImageWindow"
QT_MOC_LITERAL(1, 19, 18), // "on_btn_img_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "on_resize_btn_clicked"
QT_MOC_LITERAL(4, 61, 19), // "on_zoom_btn_clicked"
QT_MOC_LITERAL(5, 81, 26), // "on_zoomSlider_valueChanged"
QT_MOC_LITERAL(6, 108, 5), // "value"
QT_MOC_LITERAL(7, 114, 20), // "on_reset_btn_clicked"
QT_MOC_LITERAL(8, 135, 19), // "on_crop_btn_clicked"
QT_MOC_LITERAL(9, 155, 15), // "mousePressEvent"
QT_MOC_LITERAL(10, 171, 12), // "QMouseEvent*"
QT_MOC_LITERAL(11, 184, 5), // "event"
QT_MOC_LITERAL(12, 190, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(13, 208, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(14, 223, 22) // "on_pivoter_btn_clicked"

    },
    "EditionImageWindow\0on_btn_img_clicked\0"
    "\0on_resize_btn_clicked\0on_zoom_btn_clicked\0"
    "on_zoomSlider_valueChanged\0value\0"
    "on_reset_btn_clicked\0on_crop_btn_clicked\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "mouseReleaseEvent\0mouseMoveEvent\0"
    "on_pivoter_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditionImageWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,
      13,    1,   78,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

       0        // eod
};

void EditionImageWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditionImageWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_img_clicked(); break;
        case 1: _t->on_resize_btn_clicked(); break;
        case 2: _t->on_zoom_btn_clicked(); break;
        case 3: _t->on_zoomSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_reset_btn_clicked(); break;
        case 5: _t->on_crop_btn_clicked(); break;
        case 6: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: _t->on_pivoter_btn_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EditionImageWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_EditionImageWindow.data,
    qt_meta_data_EditionImageWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EditionImageWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditionImageWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditionImageWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int EditionImageWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
