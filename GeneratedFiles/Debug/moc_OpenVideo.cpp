/****************************************************************************
** Meta object code from reading C++ file 'OpenVideo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OpenVideo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenVideo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OpenVideo_t {
    QByteArrayData data[16];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenVideo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenVideo_t qt_meta_stringdata_OpenVideo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "OpenVideo"
QT_MOC_LITERAL(1, 10, 13), // "OpenVideoFile"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "OpenCamera"
QT_MOC_LITERAL(4, 36, 11), // "CloseCamera"
QT_MOC_LITERAL(5, 48, 10), // "ScreenShot"
QT_MOC_LITERAL(6, 59, 3), // "REC"
QT_MOC_LITERAL(7, 63, 6), // "EndREC"
QT_MOC_LITERAL(8, 70, 22), // "FaceDetectionAlignment"
QT_MOC_LITERAL(9, 93, 10), // "InputImage"
QT_MOC_LITERAL(10, 104, 15), // "FaceRecognition"
QT_MOC_LITERAL(11, 120, 9), // "nextFrame"
QT_MOC_LITERAL(12, 130, 25), // "nextSeetaFaceProcessFrame"
QT_MOC_LITERAL(13, 156, 19), // "nextFaceRecognition"
QT_MOC_LITERAL(14, 176, 18), // "currentDateAndTime"
QT_MOC_LITERAL(15, 195, 11) // "CloseWindow"

    },
    "OpenVideo\0OpenVideoFile\0\0OpenCamera\0"
    "CloseCamera\0ScreenShot\0REC\0EndREC\0"
    "FaceDetectionAlignment\0InputImage\0"
    "FaceRecognition\0nextFrame\0"
    "nextSeetaFaceProcessFrame\0nextFaceRecognition\0"
    "currentDateAndTime\0CloseWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenVideo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OpenVideo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OpenVideo *_t = static_cast<OpenVideo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OpenVideoFile(); break;
        case 1: _t->OpenCamera(); break;
        case 2: _t->CloseCamera(); break;
        case 3: _t->ScreenShot(); break;
        case 4: _t->REC(); break;
        case 5: _t->EndREC(); break;
        case 6: _t->FaceDetectionAlignment(); break;
        case 7: _t->InputImage(); break;
        case 8: _t->FaceRecognition(); break;
        case 9: _t->nextFrame(); break;
        case 10: _t->nextSeetaFaceProcessFrame(); break;
        case 11: _t->nextFaceRecognition(); break;
        case 12: _t->currentDateAndTime(); break;
        case 13: _t->CloseWindow(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OpenVideo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OpenVideo.data,
      qt_meta_data_OpenVideo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OpenVideo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenVideo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenVideo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OpenVideo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
