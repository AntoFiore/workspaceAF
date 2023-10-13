#ifndef PACKEGESERIVE_H
#define PACKEGESERIVE_H

#include <QObject>
#include <QFrame>
#include <QStandardItemModel>
namespace pkg{
class PackegeSerive : public QObject
{
    Q_OBJECT
public:
    explicit PackegeSerive(QObject *parent = nullptr);
    enum  typeData_E{ data_model, data_packege};



    static QFrame * createPackege (qint16 idPkg);
    static QStandardItemModel * get_Model (qint16 idPkg, QWidget *w) ;
    static QString get_Package(qint16 idPkg, QWidget *w) ;
    static void set_Package(qint16 idPkg,QString pkg ,QWidget *w) ;

signals:
private:
    static QVariant get_Data(typeData_E type, qint16 idPkg, QWidget *w);
    static QVariant set_Data(typeData_E type, qint16 idPkg, QVariant data,QWidget *w);



};
}

#endif // PACKEGESERIVE_H
