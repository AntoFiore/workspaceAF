#include "HandlerPackage_65_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_65_Ver340::HandlerPackage_65_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;

    m_qScaleVar=nullptr;
    m_nidTSRVar=nullptr;
    m_dTSRVar=nullptr;
    m_lTSRVar=nullptr;
    m_qFrontVar=nullptr;
    m_vTSRVar=nullptr;

    m_row = 0;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg = 65;
}

bool HandlerPackage_65_Ver340::creteView()
{

    qDebug () << "HandlerPackage_5_Ver340::creteView();";

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 65 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);

        m_qDirVar =  new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_65_Ver340::saveData );

        m_lenPkgVar = new package::GraphicVariablePkg;
        m_lenPkgVar->set_L_PACKET(71,71);
        m_VariableVect.push_back(m_lenPkgVar);

        m_qScaleVar = new package::GraphicVariablePkg;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_65_Ver340::saveData );

        m_nidTSRVar = new package::GraphicVariablePkg;
        m_nidTSRVar->set_NID_TSR();
        m_VariableVect.push_back(m_nidTSRVar);
        connect (m_nidTSRVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_65_Ver340::saveData );

        m_dTSRVar = new package::GraphicVariablePkg;
        m_dTSRVar->set_D_TSR();
        m_VariableVect.push_back(m_dTSRVar);
        connect (m_dTSRVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_65_Ver340::saveData );

        m_lTSRVar = new package::GraphicVariablePkg;
        m_lTSRVar->set_L_TSR();
        m_VariableVect.push_back(m_lTSRVar);
        connect (m_lTSRVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_65_Ver340::saveData );

        m_qFrontVar = new package::GraphicVariablePkg;
        m_qFrontVar->set_Q_FRONT();
        m_VariableVect.push_back(m_qFrontVar);
        connect (m_qFrontVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_65_Ver340::saveData );

        m_vTSRVar = new package::GraphicVariablePkg;
        m_vTSRVar->set_Q_FRONT();
        m_VariableVect.push_back(m_vTSRVar);
        connect (m_vTSRVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_65_Ver340::saveData );


        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);

    }
    if (m_isReload) {
        loadPkg();
    }

    showVariable();


    return true;

}


void HandlerPackage_65_Ver340::showVariable()
{
    m_row=1;
    m_currCol=0;
    removeSpacer();
    qint16 totVar = m_VariableVect.size();
    for (qint16 i =0; i < totVar;i++)
    {
        if (qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i))->tobeVisible()){
            m_layOutPkg->addWidget(m_VariableVect.at(i),m_row,m_currCol);
            m_VariableVect.at(i)->setVisible(true);
            if (m_currCol >m_maxColumnVariable )
            {
                m_currCol=0;
                m_row++;
            } else {
                m_currCol++;

            }
        } else {
            m_VariableVect.at(i)->setVisible(false);

        }
    }
    m_spaced = new QSpacerItem (40,80,QSizePolicy::Expanding,QSizePolicy::Expanding) ;
    m_layOutPkg->addItem(m_spaced, m_row+1,m_maxColumnVariable+1);

}

bool HandlerPackage_65_Ver340::saveData()
{
    QString data;
    package::GraphicVariablePkg * p_variable = nullptr;

    for (int idx = 0; idx < this->m_VariableVect.size(); idx++)
    {
        p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
        if (p_variable->tobeVisible()){
            data += p_variable->valueOfVariable();
        } else {
            data += EMPTY_VALUE;
        }
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
    }

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;

    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;
}

void HandlerPackage_65_Ver340::deleteView()
{

    HandlerPackage::deleteView();
    // deleteLater();
}



void HandlerPackage_65_Ver340::loadPkg()
{
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    QString var;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);

        if (dataList.size() >= m_VariableVect.size())
        {
            for (int idx = 0; idx < m_VariableVect.size(); idx++) {
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                if (nullptr != p_variable){
                    var = dataList.at(idx);
                    if (var != EMPTY_VALUE){
                        p_variable->setDefaultValue(var.toInt());
                        p_variable->setTobeVisible(true);
                    } else {
                        p_variable->setTobeVisible(false);
                    }
                }
            }
        }

    }

}

}

