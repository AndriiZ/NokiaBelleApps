/****************************************************************************
** Meta object code from reading C++ file 'symbianutils.h'
**
** Created: Fri 25. Jul 17:46:38 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/symbianutils.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'symbianutils.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SymbianUtils[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x02,
      42,   28,   13,   13, 0x02,
      80,   76,   13,   13, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_SymbianUtils[] = {
    "SymbianUtils\0\0minimizeApp()\0title,message\0"
    "showNotification(QString,QString)\0url\0"
    "openDefaultBrowser(QUrl)\0"
};

const QMetaObject SymbianUtils::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SymbianUtils,
      qt_meta_data_SymbianUtils, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SymbianUtils::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SymbianUtils::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SymbianUtils::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SymbianUtils))
        return static_cast<void*>(const_cast< SymbianUtils*>(this));
    return QObject::qt_metacast(_clname);
}

int SymbianUtils::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: minimizeApp(); break;
        case 1: showNotification((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: openDefaultBrowser((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
