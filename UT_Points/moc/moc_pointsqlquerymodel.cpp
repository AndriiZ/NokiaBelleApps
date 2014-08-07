/****************************************************************************
** Meta object code from reading C++ file 'pointsqlquerymodel.h'
**
** Created: Thu 7. Aug 01:00:38 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pointsqlquerymodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pointsqlquerymodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PointSqlQueryModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      29,   20,   19,   19, 0x02,
      66,   60,   19,   19, 0x22,
      84,   60,   19,   19, 0x02,
     124,  113,  104,   19, 0x02,
     166,  146,   19,   19, 0x02,
     201,  196,   19,   19, 0x02,
     229,  224,  104,   19, 0x02,
     254,   19,  249,   19, 0x02,
     263,   19,   19,   19, 0x02,
     272,   19,   19,   19, 0x02,
     307,  289,  282,   19, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_PointSqlQueryModel[] = {
    "PointSqlQueryModel\0\0query,db\0"
    "setQuery(QString,QSqlDatabase)\0query\0"
    "setQuery(QString)\0setQuery(QSqlQuery)\0"
    "QVariant\0index,role\0data(QModelIndex,int)\0"
    "lat,lng,maxDistance\0refresh(double,double,double)\0"
    "city\0refreshSearch(QString)\0role\0"
    "datasingle(QString)\0bool\0openDB()\0"
    "initDB()\0closeDB()\0double\0lat,lng,lat2,lng2\0"
    "distance(double,double,double,double)\0"
};

const QMetaObject PointSqlQueryModel::staticMetaObject = {
    { &QSqlQueryModel::staticMetaObject, qt_meta_stringdata_PointSqlQueryModel,
      qt_meta_data_PointSqlQueryModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PointSqlQueryModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PointSqlQueryModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PointSqlQueryModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PointSqlQueryModel))
        return static_cast<void*>(const_cast< PointSqlQueryModel*>(this));
    return QSqlQueryModel::qt_metacast(_clname);
}

int PointSqlQueryModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 4: refresh((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 5: refreshSearch((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: { QVariant _r = datasingle((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 7: { bool _r = openDB();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: initDB(); break;
        case 9: closeDB(); break;
        case 10: { double _r = distance((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
