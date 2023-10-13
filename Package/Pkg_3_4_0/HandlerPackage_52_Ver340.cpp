#include "HandlerPackage_52_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_52_Ver340::HandlerPackage_52_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;
    m_qScaleVar = nullptr;

    m_qTrackinitVar = nullptr;
    m_dTrackinitVar = nullptr;

    m_dPBDVar = nullptr;
    m_qGdirVar = nullptr;
    m_gPBDSRVar = nullptr;
    m_qPBDSRVar = nullptr;
    m_dPBDSRVar = nullptr;
    m_lPBDSRVar = nullptr;

    m_nIter_k_Var = nullptr;
    m_dPBD_k_Var = nullptr;
    m_qGdir_k_Var = nullptr;
    m_gPBDSR_k_Var = nullptr;
    m_qPBDSR_k_Var = nullptr;
    m_dPBDSR_k_Var = nullptr;
    m_lPBDSR_k_Var = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg = 51;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_52_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 52 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(41);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

        m_qScaleVar = new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

        m_qTrackinitVar = new package::GraphicVariablePkg;
        m_qTrackinitVar->set_Q_TRACKINIT();
        m_VariableVect.push_back(m_qTrackinitVar);
        connect (m_qTrackinitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::show_qTrackinit_SL );
        connect (m_qTrackinitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

        {
            /* case Q_TRACKINIT == 1 */
            m_dTrackinitVar = new package::GraphicVariablePkg;
            m_dTrackinitVar->set_D_TRACKINIT();
            m_dTrackinitVar->setTobeVisible(false);
            m_VariableVect.push_back(m_dTrackinitVar);
            connect (m_dTrackinitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

            /* case Q_TRACKINIT == 0 */
            m_dPBDVar = new package::GraphicVariablePkg;
            m_dPBDVar->set_D_PBD();
            m_dPBDVar->setTobeVisible(true);
            m_VariableVect.push_back(m_dPBDVar);
            connect (m_dPBDVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

            m_qGdirVar = new package::GraphicVariablePkg;
            m_qGdirVar->set_Q_GDIR();
            m_qGdirVar->setTobeVisible(true);
            m_VariableVect.push_back(m_qGdirVar);
            connect (m_qGdirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

            m_gPBDSRVar = new package::GraphicVariablePkg;
            m_gPBDSRVar->set_G_PBDSR();
            m_gPBDSRVar->setTobeVisible(true);
            m_VariableVect.push_back(m_gPBDSRVar);
            connect (m_gPBDSRVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

            m_qPBDSRVar = new package::GraphicVariablePkg;
            m_qPBDSRVar->set_Q_PBDSR();
            m_qPBDSRVar->setTobeVisible(true);
            m_VariableVect.push_back(m_qPBDSRVar);
            connect (m_qPBDSRVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

            m_dPBDSRVar = new package::GraphicVariablePkg;
            m_dPBDSRVar->set_D_PBDSR();
            m_dPBDSRVar->setTobeVisible(true);
            m_VariableVect.push_back(m_dPBDSRVar);
            connect (m_dPBDSRVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

            m_lPBDSRVar = new package::GraphicVariablePkg;
            m_lPBDSRVar->set_L_PBDSR();
            m_lPBDSRVar->setTobeVisible(true);
            m_VariableVect.push_back(m_lPBDSRVar);
            connect (m_lPBDSRVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

            m_nIter_k_Var =  new package::GraphicVariablePkg ;
            m_nIter_k_Var->set_N_ITER();
            m_nIter_k_Var->setNameVariable("N_ITER");
            m_nIter_k_Var->setTobeVisible(true);
            m_VariableVect.push_back(m_nIter_k_Var);
            connect (m_nIter_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::handleChangeIteration_k_SL );
            connect (m_nIter_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

            qint16 maxValueVariableIter_n = 31;
            QString nameItem;
            for (int n = 0; n < maxValueVariableIter_n ; n++)
            {
                nameItem = QString("D_PBD_%1").arg(QString::number(n + 1));
                m_dPBD_k_Var = new package::GraphicVariablePkg;
                m_dPBD_k_Var->set_D_PBD();
                m_dPBD_k_Var->setNameVariable(nameItem);
                m_dPBD_k_Var->setInternalName(nameItem);
                m_dPBD_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_dPBD_k_Var);
                connect (m_dPBD_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

                nameItem = QString("Q_GDIR_%1").arg(QString::number(n + 1));
                m_qGdir_k_Var = new package::GraphicVariablePkg;
                m_qGdir_k_Var->set_Q_GDIR();
                m_qGdir_k_Var->setNameVariable(nameItem);
                m_qGdir_k_Var->setInternalName(nameItem);
                m_qGdir_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_qGdir_k_Var);
                connect (m_qGdir_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

                nameItem = QString("G_PBDSR_%1").arg(QString::number(n + 1));
                m_gPBDSR_k_Var = new package::GraphicVariablePkg;
                m_gPBDSR_k_Var->set_G_PBDSR();
                m_gPBDSR_k_Var->setNameVariable(nameItem);
                m_gPBDSR_k_Var->setInternalName(nameItem);
                m_gPBDSR_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_gPBDSR_k_Var);
                connect (m_gPBDSR_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

                nameItem = QString("Q_PBDSR_%1").arg(QString::number(n + 1));
                m_qPBDSR_k_Var = new package::GraphicVariablePkg;
                m_qPBDSR_k_Var->set_Q_PBDSR();
                m_qPBDSR_k_Var->setNameVariable(nameItem);
                m_qPBDSR_k_Var->setInternalName(nameItem);
                m_qPBDSR_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_qPBDSR_k_Var);
                connect (m_qPBDSR_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

                nameItem = QString("Q_PBDSR_%1").arg(QString::number(n + 1));
                m_dPBDSR_k_Var = new package::GraphicVariablePkg;
                m_dPBDSR_k_Var->set_D_PBDSR();
                m_dPBDSR_k_Var->setNameVariable(nameItem);
                m_dPBDSR_k_Var->setInternalName(nameItem);
                m_dPBDSR_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_dPBDSR_k_Var);
                connect (m_dPBDSR_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );

                nameItem = QString("Q_PBDSR_%1").arg(QString::number(n + 1));
                m_lPBDSR_k_Var = new package::GraphicVariablePkg;
                m_lPBDSR_k_Var->set_L_PBDSR();
                m_lPBDSR_k_Var->setNameVariable(nameItem);
                m_lPBDSR_k_Var->setInternalName(nameItem);
                m_lPBDSR_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_lPBDSR_k_Var);
                connect (m_lPBDSR_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_52_Ver340::saveData );
            }
        }

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();

    }
    return true;

}
void HandlerPackage_52_Ver340::loadPkg()
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

void HandlerPackage_52_Ver340::show_qTrackinit_SL()
{
    int value = m_qTrackinitVar->valueOfVariable().toInt();
    qDebug () << value;
    if (1 == value){
        /* variable to show */
        m_dTrackinitVar->setTobeVisible(true);

        /* variables to remove */
        m_dPBDVar->setTobeVisible(false);
        m_qGdirVar->setTobeVisible(false);
        m_gPBDSRVar->setTobeVisible(false);
        m_qPBDSRVar->setTobeVisible(false);
        m_dPBDSRVar->setTobeVisible(false);
        m_lPBDSRVar->setTobeVisible(false);
        m_nIter_k_Var->setTobeVisible(false);
        m_nIter_k_Var->setDefaultValue(0);
    } else { // value == 0
        /* variable to show */
        m_dTrackinitVar->setTobeVisible(false);

        /* variables to remove */
        m_dPBDVar->setTobeVisible(true);
        m_qGdirVar->setTobeVisible(true);
        m_gPBDSRVar->setTobeVisible(true);
        m_qPBDSRVar->setTobeVisible(true);
        m_dPBDSRVar->setTobeVisible(true);
        m_lPBDSRVar->setTobeVisible(true);
        m_nIter_k_Var->setTobeVisible(true);
    }
    showVariable();
}

void HandlerPackage_52_Ver340::handleChangeIteration_k_SL()
{
    qint16 currentValue = m_nIter_k_Var->valueOfVariable().toInt();
    package::GraphicVariablePkg * p_variable = nullptr;
    QString nameIterateVar;

    qint16 numVisibile = countVariableIterateisVisible("D_PBD_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        bool notUsed;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("D_PBD_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("Q_GDIR_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("G_PBDSR_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("Q_PBDSR_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("D_PBDSR_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("L_PBDSR_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        bool oldvisibleState;
        for (int i=0;i< numberHideVariavble;i++){
            nameIterateVar = QString ("D_PBD_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("Q_GDIR_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("G_PBDSR_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("Q_PBDSR_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("D_PBDSR_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("L_PBDSR_%1").arg(QString::number(numVisibile));
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

void HandlerPackage_52_Ver340::showVariable()
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


bool HandlerPackage_52_Ver340::saveData()
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

void HandlerPackage_52_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}



}
