#include "GraphicEditBalise.h"
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include "GraphicViewPackage.h"
#include "PackegeSerive.h"
#include <QDateTime>
#include "Define.h"
namespace hndcommand{

GraphicEditBalise::GraphicEditBalise(QObject *parent)
    : QObject{parent}
{

    m_keyPkt=-1;
    m_formPkgWidget=nullptr;
    m_mainWin_Ptr=nullptr;
}

bool GraphicEditBalise::init(Ui::MainWindow *mainWin_Ptr)
{
    bool ret =true;
    qDebug () << "Init GraphicEditBalise";
    if ( mainWin_Ptr == nullptr){
        qDebug () << "GraphicEditBalise -- Invalid pointer to MainWindow";
        ret= false;
    } else {
        m_mainWin_Ptr = mainWin_Ptr;
    }
    m_currentIdPkg=-1;
    m_isUpdatePkg=false;

    m_EditPkgFrame = new QFrame (m_mainWin_Ptr->tabWidget_Commands);
    m_editGridLayout = new QGridLayout;
   m_EditPkgFrame->setLayout(m_editGridLayout);
   m_mainWin_Ptr->scrollArea_EditPkgBalise->setWidget(m_EditPkgFrame);

    connect (m_mainWin_Ptr->pushButton_ApplylEditBaslise,&QPushButton::clicked,[this](){

        auto mainPageBalise = m_mainWin_Ptr->stackedWidget_ContainerBalise->widget(0);
        m_mainWin_Ptr->stackedWidget_ContainerBalise->setCurrentWidget(mainPageBalise);

        if (nullptr != m_formPkgWidget ) {

            QStandardItemModel * model= pkg::PackegeSerive::get_Model(m_currentIdPkg,m_formPkgWidget);
            QString pkg = pkg::PackegeSerive::get_Package(m_currentIdPkg,m_formPkgWidget);
            removeFormPkgWidget();
            //new packege
            if ( ! m_isUpdatePkg ){
                 m_keyPkt = QDateTime::currentSecsSinceEpoch();
            }
            emit addNewOrUpdatePackage_SG (model ,pkg,m_currentIdPkg ,m_keyPkt);
             m_currentIdPkg=-1;
             m_isUpdatePkg=false;
        }
    } );

    connect (m_mainWin_Ptr->pushButton_CancelEditBaslise,&QPushButton::clicked,[this](){
        removeFormPkgWidget();
        auto mainPageBalise = m_mainWin_Ptr->stackedWidget_ContainerBalise->widget(0);
        m_mainWin_Ptr->stackedWidget_ContainerBalise->setCurrentWidget(mainPageBalise);
        m_currentIdPkg=-1;
        m_isUpdatePkg=false;
    });

    return ret;

}

void GraphicEditBalise::setFormPkgWidget(QWidget  *w)
{

    if (nullptr != w ) {
        m_formPkgWidget=w;
        m_editGridLayout->addWidget(w);
    }
}

void GraphicEditBalise::removeFormPkgWidget()
{
    if (m_formPkgWidget != nullptr){
       m_formPkgWidget->deleteLater();
       m_formPkgWidget=nullptr;
    }
}
void GraphicEditBalise::handlePackageFromTable(QString listPkg){

    QStringList pkgs = listPkg.split(INTERNAL_SEPARATOR_PKG);
    qint16 sizePkgs= pkgs.size();
    if (sizePkgs) {

        for (int idx =0 ; idx < sizePkgs;idx++){

            QStringList pkg= pkgs[idx].split(INTERNAL_FIELD_SEPARATOR_PKG);
            if (pkg.size()) {
                QString idPkg =pkg[0];
                qDebug () << "idPkg="<<idPkg;
                QWidget *w = pkg::PackegeSerive::createPackege(idPkg.toLongLong());
                if (nullptr != w) {
                     pkg::PackegeSerive::set_Package(idPkg.toLongLong(),pkgs[idx],w);
                     QStandardItemModel * model= pkg::PackegeSerive::get_Model(idPkg.toLongLong(),w);
                      qint64 keyPkt = QDateTime::currentSecsSinceEpoch();
                      w->deleteLater();
                     emit addNewOrUpdatePackage_SG (model ,pkgs[idx] ,idPkg.toLongLong() ,keyPkt+idx);
                }

            }
        }
    }
}

quint16 GraphicEditBalise::currentIdPkg() const
{
    return m_currentIdPkg;
}

void GraphicEditBalise::setCurrentIdPkg(quint16 newCurrentIdPkg)
{
    m_currentIdPkg = newCurrentIdPkg;
}

qint64 GraphicEditBalise::keyPkt() const
{
    return m_keyPkt;
}

void GraphicEditBalise::setKeyPkt(qint64 newKeyPkt)
{
    m_keyPkt = newKeyPkt;
}

bool GraphicEditBalise::isUpdatePkg() const
{
    return m_isUpdatePkg;
}

void GraphicEditBalise::setIsUpdatePkg(bool newIsUpdatePkg)
{
    m_isUpdatePkg = newIsUpdatePkg;
}
}
