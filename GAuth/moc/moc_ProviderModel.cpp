/****************************************************************************
** Meta object code from reading C++ file 'ProviderModel.h'
**
** Created: Thu 31. Jul 21:32:30 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ProviderModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProviderModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProviderSqlQueryModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      32,   23,   22,   22, 0x02,
      69,   63,   22,   22, 0x22,
      87,   63,   22,   22, 0x02,
     127,  116,  107,   22, 0x02,
     149,   22,   22,   22, 0x02,
     164,  159,  107,   22, 0x02,
     189,   22,  184,   22, 0x02,
     198,   22,   22,   22, 0x02,
     207,   22,   22,   22, 0x02,
     230,  217,  184,   22, 0x02,
     286,  262,  184,   22, 0x02,
     333,  322,  184,   22, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_ProviderSqlQueryModel[] = {
    "ProviderSqlQueryModel\0\0query,db\0"
    "setQuery(QString,QSqlDatabase)\0query\0"
    "setQuery(QString)\0setQuery(QSqlQuery)\0"
    "QVariant\0index,role\0data(QModelIndex,int)\0"
    "refresh()\0role\0datasingle(QString)\0"
    "bool\0openDB()\0initDB()\0closeDB()\0"
    "title,secret\0insertProvider(QString,QString)\0"
    "title,secret,providerid\0"
    "updateProvider(QString,QString,int)\0"
    "providerid\0deleteProvider(int)\0"
};

const QMetaObject ProviderSqlQueryModel::staticMetaObject = {
    { &QSqlQueryModel::staticMetaObject, qt_meta_stringdata_ProviderSqlQueryModel,
      qt_meta_data_ProviderSqlQueryModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProviderSqlQueryModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProviderSqlQueryModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProviderSqlQueryModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProviderSqlQueryModel))
        return static_cast<void*>(const_cast< ProviderSqlQueryModel*>(this));
    return QSqlQueryModel::qt_metacast(_clname);
}

int ProviderSqlQueryModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlQueryModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setQuery((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QSqlDatabase(*)>(_a[2]))); break;
        case 1: setQuery((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: setQuery((*reinterpret_cast< const QSqlQuery(*)>(_a[1]))); break;
        case 3: { QVariant _r = data((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 4: refresh(); break;
        case 5: { QVariant _r = datasingle((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 6: { bool _r = openDB();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: initDB(); break;
        case 8: closeDB(); break;
        case 9: { bool _r = insertProvider((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = updateProvider((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = deleteProvider((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
