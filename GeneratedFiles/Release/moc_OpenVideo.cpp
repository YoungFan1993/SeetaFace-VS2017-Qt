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
    QByteArrayData data[25];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenVideo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenVideo_t qt_meta_stringdata_OpenVideo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "OpenVideo"
QT_MOC_LITERAL(1, 10, 10), // "mainSignal"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "str"
QT_MOC_LITERAL(4, 26, 11), // "VideoSignal"
QT_MOC_LITERAL(5, 38, 5), // "image"
QT_MOC_LITERAL(6, 44, 4), // "flag"
QT_MOC_LITERAL(7, 49, 13), // "OpenVideoFile"
QT_MOC_LITERAL(8, 63, 10), // "OpenCamera"
QT_MOC_LITERAL(9, 74, 11), // "CloseCamera"
QT_MOC_LITERAL(10, 86, 10), // "ScreenShot"
QT_MOC_LITERAL(11, 97, 3), // "REC"
QT_MOC_LITERAL(12, 101, 6), // "EndREC"
QT_MOC_LITERAL(13, 108, 22), // "FaceDetectionAlignment"
QT_MOC_LITERAL(14, 131, 10), // "InputImage"
QT_MOC_LITERAL(15, 142, 22), // "FaceRecognitionProcess"
QT_MOC_LITERAL(16, 165, 9), // "nextFrame"
QT_MOC_LITERAL(17, 175, 25), // "nextSeetaFaceProcessFrame"
QT_MOC_LITERAL(18, 201, 18), // "currentDateAndTime"
QT_MOC_LITERAL(19, 220, 11), // "CloseWindow"
QT_MOC_LITERAL(20, 232, 25), // "getRecognitionInformation"
QT_MOC_LITERAL(21, 258, 16), // "gallery_face_num"
QT_MOC_LITERAL(22, 275, 14), // "probe_face_num"
QT_MOC_LITERAL(23, 290, 3), // "sim"
QT_MOC_LITERAL(24, 294, 6) // "NoFace"

    },
    "OpenVideo\0mainSignal\0\0str\0VideoSignal\0"
    "image\0flag\0OpenVideoFile\0OpenCamera\0"
    "CloseCamera\0ScreenShot\0REC\0EndREC\0"
    "FaceDetectionAlignment\0InputImage\0"
    "FaceRecognitionProcess\0nextFrame\0"
    "nextSeetaFaceProcessFrame\0currentDateAndTime\0"
    "CloseWindow\0getRecognitionInformation\0"
    "gallery_face_num\0probe_face_num\0sim\0"
    "NoFace"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenVideo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    2,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  107,    2, 0x0a /* Public */,
       8,    0,  108,    2, 0x0a /* Public */,
       9,    0,  109,    2, 0x0a /* Public */,
      10,    0,  110,    2, 0x0a /* Public */,
      11,    0,  111,    2, 0x0a /* Public */,
      12,    0,  112,    2, 0x0a /* Public */,
      13,    0,  113,    2, 0x0a /* Public */,
      14,    0,  114,    2, 0x0a /* Public */,
      15,    0,  115,    2, 0x0a /* Public */,
      16,    0,  116,    2, 0x0a /* Public */,
      17,    0,  117,    2, 0x0a /* Public */,
      18,    0,  118,    2, 0x0a /* Public */,
      19,    0,  119,    2, 0x0a /* Public */,
      20,    4,  120,    2, 0x0a /* Public */,
      24,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QImage, QMetaType::Bool,    5,    6,

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
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QImage, QMetaType::Float,   21,   22,    5,   23,
    QMetaType::Void,

       0        // eod
};

void OpenVideo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OpenVideo *_t = static_cast<OpenVideo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mainSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->VideoSignal((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->OpenVideoFile(); break;
        case 3: _t->OpenCamera(); break;
        case 4: _t->CloseCamera(); break;
        case 5: _t->ScreenShot(); break;
        case 6: _t->REC(); break;
        case 7: _t->EndREC(); break;
        case 8: _t->FaceDetectionAlignment(); break;
        case 9: _t->InputImage(); break;
        case 10: _t->FaceRecognitionProcess(); break;
        case 11: _t->nextFrame(); break;
        case 12: _t->nextSeetaFaceProcessFrame(); break;
        case 13: _t->currentDateAndTime(); break;
        case 14: _t->CloseWindow(); break;
        case 15: _t->getRecognitionInformation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QImage(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 16: _t->NoFace(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (OpenVideo::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenVideo::mainSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (OpenVideo::*_t)(QImage , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenVideo::VideoSignal)) {
                *result = 1;
                return;
            }
        }
    }
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void OpenVideo::mainSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OpenVideo::VideoSignal(QImage _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
