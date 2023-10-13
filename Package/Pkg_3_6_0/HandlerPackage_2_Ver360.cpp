#include "HandlerPackage_2_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_2_Ver360::HandlerPackage_2_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_versionVar=nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg=2;
}

bool HandlerPackage_2_Ver360::creteView()
{

    qDebug () << "HandlerPackage_2_Ver360::creteView();";
    bool ret = false;
    if (nullptr != m_layOutPkg){


        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 2 - " + QString(BASELINE_3_6_0));
        m_layOutPkg->addWidget(m_titlePkg, 0, 0);

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);
        connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_2_Ver360::saveData );


        m_qDirVar =  new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_2_Ver360::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg;
        m_lenPkgVar->set_L_PACKET(30, 30);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_2_Ver360::saveData );

        m_versionVar =  new package::GraphicVariablePkg;
        m_versionVar->set_M_VERSION();
        m_VariableVect.push_back(m_versionVar);
        connect (m_versionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_2_Ver360::saveData );

        if (m_isReload) {
            loadPkg();
        }
        this->showVariable();
        ret=saveData();
    }
    return ret;

}

bool HandlerPackage_2_Ver360::saveData()
{
    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_versionVar->valueOfVariable();

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;


    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;

}

void HandlerPackage_2_Ver360::deleteView()
{

    HandlerPackage::deleteView();
    // deleteLater();
}

void HandlerPackage_2_Ver360::loadPkg()
{

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        if (dataList.size() == 4 ){

            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
            m_versionVar->setDefaultValue( dataList.at(3).toInt() );
        }
    }



}
}
