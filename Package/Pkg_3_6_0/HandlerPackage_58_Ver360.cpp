#include "HandlerPackage_58_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_58_Ver360::HandlerPackage_58_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;

    m_qScaleVar = nullptr;
    m_tCyclocVar = nullptr;
    m_dCyclocVar = nullptr;
    m_mLocVar = nullptr;

    m_nIterVar = nullptr;

    m_dLoc_k_Var = nullptr;
    m_qLgtloc_k_Var = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg = 58;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_58_Ver360::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    bool ret = false;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 57 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::saveData );

        m_lenPkgVar = new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(49, 552);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::saveData );

        m_qScaleVar = new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::saveData );

        m_tCyclocVar = new package::GraphicVariablePkg ;
        m_tCyclocVar->init(GraphicVariablePkg::type_integer);
        m_tCyclocVar->setNameVariable("T_CYCLOC");
        m_tCyclocVar->setTobeVisible(true);
        m_tCyclocVar->setRange(0,255);
        m_tCyclocVar->setDefaultValue(0);
        m_tCyclocVar->setVariableBitSize(8);
        m_VariableVect.push_back(m_tCyclocVar);
        connect (m_tCyclocVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::saveData );

        m_dCyclocVar = new package::GraphicVariablePkg ;
        m_dCyclocVar->init(GraphicVariablePkg::type_integer);
        m_dCyclocVar->setNameVariable("D_CYCLOC");
        m_dCyclocVar->setTobeVisible(true);
        m_dCyclocVar->setRange(0,32767);
        m_dCyclocVar->setDefaultValue(0);
        m_dCyclocVar->setVariableBitSize(15);
        m_VariableVect.push_back(m_dCyclocVar);
        connect (m_dCyclocVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::saveData );

        m_mLocVar = new package::GraphicVariablePkg ;
        m_mLocVar->init(GraphicVariablePkg::type_integer);
        m_mLocVar->setNameVariable("M_LOC");
        m_mLocVar->setTobeVisible(true);
        m_mLocVar->setRange(0,7);
        m_mLocVar->setDefaultValue(0);
        m_mLocVar->setVariableBitSize(3);
        m_VariableVect.push_back(m_mLocVar);
        connect (m_mLocVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::saveData );

        m_nIterVar = new package::GraphicVariablePkg ;
        m_nIterVar->set_N_ITER();
        m_VariableVect.push_back(m_nIterVar);
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::handleChangeIteration_SL );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::saveData );

        qint16 maxValueVariableIter_n = 31;
        QString nameItem;
        for (int n = 0; n < maxValueVariableIter_n ; n++)
        {
            nameItem = QString("D_LOC_%1").arg(QString::number(n + 1));
            m_dLoc_k_Var = new package::GraphicVariablePkg;
            m_dLoc_k_Var->init(GraphicVariablePkg::type_integer);
            m_dLoc_k_Var->setNameVariable(nameItem);
            m_dLoc_k_Var->setInternalName(nameItem);
            m_dLoc_k_Var->setTobeVisible(false);
            m_dLoc_k_Var->setRange(0,32767);
            m_dLoc_k_Var->setDefaultValue(0);
            m_dLoc_k_Var->setVariableBitSize(15);
            m_VariableVect.push_back(m_dLoc_k_Var);
            connect (m_dLoc_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::saveData );

            nameItem = QString("Q_LGTLOC_%1").arg(QString::number(n + 1));
            m_qLgtloc_k_Var = new package::GraphicVariablePkg;
            m_qLgtloc_k_Var->init(GraphicVariablePkg::type_integer);
            m_qLgtloc_k_Var->setNameVariable(nameItem);
            m_qLgtloc_k_Var->setInternalName(nameItem);
            m_qLgtloc_k_Var->setTobeVisible(false);
            m_qLgtloc_k_Var->setRange(0,1);
            m_qLgtloc_k_Var->setDefaultValue(0);
            m_qLgtloc_k_Var->setVariableBitSize(1);
            m_VariableVect.push_back(m_qLgtloc_k_Var);
            connect (m_qLgtloc_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_58_Ver360::saveData );
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

void HandlerPackage_58_Ver360::handleChangeIteration_SL()
{
    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();
    package::GraphicVariablePkg * p_variable = nullptr;
    QString nameIterateVar;

    qint16 numVisibile = countVariableIterateisVisible("D_LOC_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        bool notUsed;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("D_LOC_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("Q_LGTLOC_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        bool oldvisibleState;
        for (int i=0;i< numberHideVariavble;i++){
            nameIterateVar = QString ("D_LOC_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("Q_LGTLOC_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            numVisibile--;
        }
    }

    showVariable();
    return ;
}

void HandlerPackage_58_Ver360::loadPkg()
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

void HandlerPackage_58_Ver360::showVariable()
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

bool HandlerPackage_58_Ver360::saveData()
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

void HandlerPackage_58_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}



}
