/****************************************************************************
** Meta object code from reading C++ file 'notepadwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/notepadwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notepadwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_notepadWindow_t {
    QByteArrayData data[21];
    char stringdata[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_notepadWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_notepadWindow_t qt_meta_stringdata_notepadWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "notepadWindow"
QT_MOC_LITERAL(1, 14, 14), // "onSokConnected"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "onSokDisconnected"
QT_MOC_LITERAL(4, 48, 14), // "onSokReadyRead"
QT_MOC_LITERAL(5, 63, 17), // "onSokDisplayError"
QT_MOC_LITERAL(6, 81, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(7, 110, 11), // "socketError"
QT_MOC_LITERAL(8, 122, 28), // "on_connectDisConnect_clicked"
QT_MOC_LITERAL(9, 151, 27), // "on_files_currentTextChanged"
QT_MOC_LITERAL(10, 179, 11), // "currentText"
QT_MOC_LITERAL(11, 191, 28), // "on_plainTextEdit_textChanged"
QT_MOC_LITERAL(12, 220, 26), // "on_files_currentRowChanged"
QT_MOC_LITERAL(13, 247, 10), // "currentRow"
QT_MOC_LITERAL(14, 258, 38), // "on_plainTextEdit_cursorPositi..."
QT_MOC_LITERAL(15, 297, 4), // "send"
QT_MOC_LITERAL(16, 302, 14), // "keyPressEventT"
QT_MOC_LITERAL(17, 317, 10), // "QKeyEvent*"
QT_MOC_LITERAL(18, 328, 1), // "e"
QT_MOC_LITERAL(19, 330, 5), // "saveB"
QT_MOC_LITERAL(20, 336, 4) // "save"

    },
    "notepadWindow\0onSokConnected\0\0"
    "onSokDisconnected\0onSokReadyRead\0"
    "onSokDisplayError\0QAbstractSocket::SocketError\0"
    "socketError\0on_connectDisConnect_clicked\0"
    "on_files_currentTextChanged\0currentText\0"
    "on_plainTextEdit_textChanged\0"
    "on_files_currentRowChanged\0currentRow\0"
    "on_plainTextEdit_cursorPositionChanged\0"
    "send\0keyPressEventT\0QKeyEvent*\0e\0saveB\0"
    "save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_notepadWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    1,   86,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    1,   90,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    1,   95,    2, 0x0a /* Public */,
      19,    0,   98,    2, 0x0a /* Public */,
      20,    0,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void notepadWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        notepadWindow *_t = static_cast<notepadWindow *>(_o);
        switch (_id) {
        case 0: _t->onSokConnected(); break;
        case 1: _t->onSokDisconnected(); break;
        case 2: _t->onSokReadyRead(); break;
        case 3: _t->onSokDisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->on_connectDisConnect_clicked(); break;
        case 5: _t->on_files_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_plainTextEdit_textChanged(); break;
        case 7: _t->on_files_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_plainTextEdit_cursorPositionChanged(); break;
        case 9: _t->send(); break;
        case 10: _t->keyPressEventT((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 11: _t->saveB(); break;
        case 12: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject notepadWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_notepadWindow.data,
      qt_meta_data_notepadWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *notepadWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *notepadWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_notepadWindow.stringdata))
        return static_cast<void*>(const_cast< notepadWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int notepadWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
