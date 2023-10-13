#include "GraphicViewPackage.h"
#include "ui_GraphicViewPackage.h"
#include <QDebug>
GraphicViewPackage::GraphicViewPackage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::GraphicViewPackage)
{
    ui->setupUi(this);
    m_model=nullptr;
    m_currentIdPkg=-1;
    m_keyPkt=-1;
}

bool GraphicViewPackage::init()
{

    bool retVal = true;
    connect (ui->pushButton_Update_PackageGrView,&QPushButton::clicked,[this]() {
        qDebug () << "Update GraphicPackage";
        emit updateMe_SG(m_keyPkt);

    });
    connect (ui->pushButton_Remove_PackageGrView,&QPushButton::clicked,[this]() {
        qDebug () << "Remove GraphicPackage";
         emit deleteMe_SG(m_keyPkt);
    });



  ///  connect( ui->)

    return  true;;
}

GraphicViewPackage::~GraphicViewPackage()
{
    if (nullptr != m_model){
        delete m_model;
    }
    delete ui;
}

void GraphicViewPackage::setModel(QStandardItemModel *newModel)
{
    m_model = newModel;
    ui->treeView_PackageView->setModel(m_model);
}


qint64 GraphicViewPackage::keyPkt() const
{
    return m_keyPkt;
}

void GraphicViewPackage::setKeyPkt(qint64 newKeyPkt)
{
    m_keyPkt = newKeyPkt;
}



quint32 GraphicViewPackage::currentIdPkg() const
{
    return m_currentIdPkg;
}

void GraphicViewPackage::setCurrentIdPkg(quint32 newCurrentIdPkg)
{
    m_currentIdPkg = newCurrentIdPkg;
    QString namePackage = QString ("PacketN.%1").arg(QString::number(m_currentIdPkg));
    ui->label_NamePackageGrView->setText(namePackage);
}

QString GraphicViewPackage::getPackage()
{
    return m_pkg;
}

const QString &GraphicViewPackage::pkg() const
{
    return m_pkg;
}

void GraphicViewPackage::setPkg(const QString &newPkg)
{
    m_pkg = newPkg;
}
