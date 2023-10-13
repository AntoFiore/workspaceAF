#include "HandlerPackage_180_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_180_Ver360::HandlerPackage_180_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;

    m_qLssmaVar = nullptr;
    m_tLssmaVar = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg = 180;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_180_Ver360::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    bool ret= false;
    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 180 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_180_Ver360::saveData );

        m_lenPkgVar = new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(24, 32);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_180_Ver360::saveData );

        m_qLssmaVar = new package::GraphicVariablePkg ;
        m_qLssmaVar->init(GraphicVariablePkg::type_integer);
        m_qLssmaVar->setNameVariable("Q_LSSMA");
        m_qLssmaVar->setTobeVisible(true);
        m_qLssmaVar->setRange(0,1);
        m_qLssmaVar->setDefaultValue(0);
        m_qLssmaVar->setVariableBitSize(1);
        m_VariableVect.push_back(m_qLssmaVar);
        connect (m_qLssmaVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_180_Ver360::show_qLssma_SL );
        connect (m_qLssmaVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_180_Ver360::saveData );

        {
            m_tLssmaVar = new package::GraphicVariablePkg ;
            m_tLssmaVar->init(GraphicVariablePkg::type_integer);
            m_tLssmaVar->setNameVariable("T_LSSMA");
            m_tLssmaVar->setTobeVisible(false);
            m_tLssmaVar->setRange(0,255);
            m_tLssmaVar->setDefaultValue(0);
            m_tLssmaVar->setVariableBitSize(8);
            m_VariableVect.push_back(m_tLssmaVar);
            connect (m_tLssmaVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_180_Ver360::saveData );
        }

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();
        ret=saveData();

    }
    return ret;

}

void HandlerPackage_180_Ver360::show_qLssma_SL()
{
    int value = m_qLssmaVar->valueOfVariable().toInt();
    qDebug () << value;
    if (1 == value){
        /* variable to show */
        m_tLssmaVar->setTobeVisible(true);
    } else { // value == 0
        /* variable to show */
        m_tLssmaVar->setTobeVisible(false);
    }
    showVariable();
}

void HandlerPackage_180_Ver360::loadPkg()
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

void HandlerPackage_180_Ver360::showVariable()
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

bool HandlerPackage_180_Ver360::saveData()
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

void HandlerPackage_180_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}



}
