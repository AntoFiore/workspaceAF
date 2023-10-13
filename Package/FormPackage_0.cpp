#include "FormPackage_0.h"
#include "ui_FormPackage_0.h"
#include "Define.h"
#include <QDebug>
FormPackage_0::FormPackage_0(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FormPackage_0)
{
    ui->setupUi(this);


}

bool FormPackage_0::init()
{
    bool ret = true;
    m_idPkg=0;
    for (int idx = 0 ; idx < 256;idx ++){

        ui->comboBox_NID_Pkg_0->addItem(QString::number(idx));
    }
    for (int idx = 0 ; idx < 54;idx ++){

        ui->comboBox_NID_VBCMK_Pkg_0->addItem(QString::number(idx));
    }

    m_model = new QStandardItemModel (0,1);
    return ret;
}

QString FormPackage_0::pkg()
{
    QString package;
    package= QString::number(m_idPkg);
    package+=INTERNAL_FIELD_SEPARATOR_PKG+ui->comboBox_NID_Pkg_0->currentText();
    package+=INTERNAL_FIELD_SEPARATOR_PKG+ui->comboBox_NID_VBCMK_Pkg_0->currentText();
    return package;

}

void FormPackage_0::setPkg(const QString &newPkg)
{

    QStringList fileds = newPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
    if (fileds.size() > 2){
         ui->comboBox_NID_Pkg_0->setCurrentText(fileds [1]);
         ui->comboBox_NID_VBCMK_Pkg_0->setCurrentText(fileds[2]);
    }
}

bool FormPackage_0::isValid()
{

    bool isValid = true;
    return isValid;
}

FormPackage_0::~FormPackage_0()
{
    delete ui;
}

QStandardItemModel *FormPackage_0::model() const
{



    while (m_model->rowCount() > 0)
    {
        m_model->removeRow(0);
    }

    QStandardItem *item = new QStandardItem (QString ("NID_PACKET = %1").arg(ui->comboBox_NID_Pkg_0->currentText()));
    item->setEditable(false);
    item->setToolTip(item->text());
    m_model->setItem(0,0,item);

    item = new QStandardItem (QString ("NID_VBCMK = %1").arg(ui->comboBox_NID_VBCMK_Pkg_0->currentText()));
    item->setEditable(false);
    item->setToolTip(item->text());
    m_model->setItem(1,0,item);

    return m_model;
}

