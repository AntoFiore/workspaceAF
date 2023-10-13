#include "PackegeSerive.h"
#include "FormPackage_0.h"
#include <QStandardItemModel>
namespace pkg{
PackegeSerive::PackegeSerive(QObject *parent)
    : QObject{parent}
{

}

QFrame *PackegeSerive::createPackege(qint16 idPkg)
{

    QFrame *pkg = nullptr;
    switch (idPkg) {
    case 0:
        pkg = new FormPackage_0;
        if (nullptr != pkg) {
            qobject_cast <FormPackage_0*> (pkg)->init();
        }
        break;

        break;
    default:
        break;
    }
    return pkg;

}

QStandardItemModel *PackegeSerive::get_Model(qint16 idPkg, QWidget *w)
{
    QStandardItemModel* model = nullptr;
    QVariant v = get_Data(data_model,idPkg,w);
    model = v.value<QStandardItemModel*> ();
    return model;
}

QString PackegeSerive::get_Package(qint16 idPkg, QWidget *w)
{
    QString pkg;
    QVariant v = get_Data(data_packege,idPkg,w);
    pkg=v.toString();
    return pkg;


}

void PackegeSerive::set_Package(qint16 idPkg, QString pkg, QWidget *w)
{

    set_Data (data_packege,idPkg,pkg,w);
}
QVariant PackegeSerive::set_Data(typeData_E type, qint16 idPkg, QVariant data, QWidget *w)
{

    if (nullptr != w ){
        switch (idPkg) {
        case 0:
            if (data_packege==type){
                QString pkg = data.toString();
                qobject_cast<FormPackage_0*>(w)->setPkg(pkg);
            }
            break;
        default:
            break;
        }
    }
}
QVariant PackegeSerive::get_Data(typeData_E type,qint16 idPkg, QWidget *w)
{
    QVariant data;
    if (nullptr != w ){

        switch (idPkg) {
        case 0:
            if (data_model==type){
                QStandardItemModel *model=qobject_cast<FormPackage_0*>(w)->model();
                data=QVariant::fromValue(model);
            } else if (data_packege==type){
                QString package =qobject_cast<FormPackage_0*>(w)->pkg();
                data=package;
            }
            break;
        default:
            break;
        }
    }
    return data;








    //    QStandardItemModel  *m;
    //    QVariant v = QVariant::fromValue(m);
    //     QStandardItemModel* vv=v.value<QStandardItemModel*> ();


}



}
