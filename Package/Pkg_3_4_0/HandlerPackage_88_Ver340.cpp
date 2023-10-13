#include "HandlerPackage_88_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_88_Ver340::HandlerPackage_88_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;

    m_qScaleVar = nullptr;
    m_nidLxVar = nullptr;
    m_dLxVar = nullptr;
    m_lLxVar = nullptr;
    m_qLxstatusVar = nullptr;
    m_vLxVar = nullptr;
    m_qStoplxVar = nullptr;
    m_lStoplxVar = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg = 88;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_88_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 88 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(57,80);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );

        m_qScaleVar =  new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );


        m_nidLxVar =  new package::GraphicVariablePkg ;
        m_nidLxVar->set_NID_LX();
        m_VariableVect.push_back(m_nidLxVar);
        connect (m_nidLxVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );

        m_dLxVar =  new package::GraphicVariablePkg ;
        m_dLxVar->set_D_LX();
        m_VariableVect.push_back(m_dLxVar);
        connect (m_dLxVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );

        m_lLxVar =  new package::GraphicVariablePkg ;
        m_lLxVar->set_L_LX();
        m_VariableVect.push_back(m_lLxVar);
        connect (m_lLxVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );

        m_qLxstatusVar =  new package::GraphicVariablePkg ;
        m_qLxstatusVar->set_Q_LXSTATUS();
        m_VariableVect.push_back(m_qLxstatusVar);
        connect (m_qLxstatusVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );
        connect (m_qLxstatusVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::show_VLX_QSTOPLX_SL );

        m_vLxVar =  new package::GraphicVariablePkg ;
        m_vLxVar->set_V_LX();
        m_vLxVar->setTobeVisible(false);
        m_VariableVect.push_back(m_vLxVar);
        connect (m_vLxVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );

        m_qStoplxVar =  new package::GraphicVariablePkg ;
        m_qStoplxVar->set_Q_STOPLX();
        m_qStoplxVar->setTobeVisible(false);
        m_VariableVect.push_back(m_qStoplxVar);
        connect (m_qStoplxVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );
        connect (m_qStoplxVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::show_LSTOPLX_SL );

        m_lStoplxVar =  new package::GraphicVariablePkg ;
        m_lStoplxVar->set_L_STOPLX();
        m_lStoplxVar->setTobeVisible(false);
        m_VariableVect.push_back(m_lStoplxVar);
        connect (m_lStoplxVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_88_Ver340::saveData );

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();

    }
    return true;

}

void HandlerPackage_88_Ver340::show_LSTOPLX_SL()
{
    int value = m_qStoplxVar->valueOfVariable().toInt();
    qDebug () << value;

    if (1 == value){
        m_lStoplxVar->setTobeVisible(true);

    } else {
        m_lStoplxVar->setTobeVisible(false);

    }

    showVariable();
}

void HandlerPackage_88_Ver340::show_VLX_QSTOPLX_SL()
{
    int value = m_qLxstatusVar->valueOfVariable().toInt();
    qDebug () << value;

    if (1 == value){
        m_vLxVar->setTobeVisible(true);
        m_qStoplxVar->setTobeVisible(true);
    } else {
        m_vLxVar->setTobeVisible(false);
        m_qStoplxVar->setTobeVisible(false);
    }

    showVariable();
}

void HandlerPackage_88_Ver340::loadPkg()
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


void HandlerPackage_88_Ver340::showVariable()
{
    m_row=1;
    m_currCol=0;

    qint16 actualPktSize = this->countPacketBitSize();
    m_lenPkgVar->setDefaultValue(actualPktSize);

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


bool HandlerPackage_88_Ver340::saveData()
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

void HandlerPackage_88_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}



}
