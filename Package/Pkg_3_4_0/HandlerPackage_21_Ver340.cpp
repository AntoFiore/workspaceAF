#include "HandlerPackage_21_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_21_Ver340::HandlerPackage_21_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;
    m_qScaleVar = nullptr;

    m_nidPkgVar= nullptr;
    m_qDirVar= nullptr;
    m_lenPkgVar= nullptr;
    m_qScaleVar= nullptr;

    m_dGradientVar= nullptr;
    m_qGdirVar= nullptr;
    m_GAVar= nullptr;

    m_nIterVar = nullptr;

    /* elementi usati nella iterazione */
    m_dGradient_k_Var = nullptr;
    m_qGdir_k_Var = nullptr;
    m_GA_k_Var= nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg = 21;
    m_maxColumnVariable=8;
    m_isReload=false;
}

bool HandlerPackage_21_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 21 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(58, 780);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );

        m_qScaleVar = new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );

        m_dGradientVar =  new package::GraphicVariablePkg;
        m_dGradientVar->init(GraphicVariablePkg::type_integer);
        m_dGradientVar->setNameVariable("D_GRADIENT");
        m_dGradientVar->setRange(0,32768);
        m_dGradientVar->setDefaultValue(0);
        m_dGradientVar->setTobeVisible(true);
        m_dGradientVar->setVisible(false);
        m_VariableVect.push_back(m_dGradientVar);
        connect (m_dGradientVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );

        m_qGdirVar =  new package::GraphicVariablePkg;
        m_qGdirVar->init(GraphicVariablePkg::type_integer);
        m_qGdirVar->setNameVariable("Q_GDIR");
        m_qGdirVar->setRange(0,1);
        m_qGdirVar->setDefaultValue(0);
        m_qGdirVar->setTobeVisible(true);
        m_qGdirVar->setVisible(false);
        m_VariableVect.push_back(m_qGdirVar);
        connect (m_qGdirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );

        m_GAVar =  new package::GraphicVariablePkg;
        m_GAVar->init(GraphicVariablePkg::type_integer);
        m_GAVar->setNameVariable("G_A");
        m_GAVar->setRange(0,256);
        m_GAVar->setDefaultValue(0);
        m_GAVar->setTobeVisible(true);
        m_GAVar->setVisible(false);
        m_VariableVect.push_back(m_GAVar);
        connect (m_GAVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );

        m_nIterVar =  new package::GraphicVariablePkg ;
        m_nIterVar->set_N_ITER();
        m_VariableVect.push_back(m_nIterVar);
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::handleChangeIteration_SL );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );

        qint16 maxValueVariableIter = 31;
        QString nameItem;
        for (int i = 0;i < maxValueVariableIter ;i++)
        {
            nameItem = QString ("D_GRADIENT_%1").arg(QString::number(i+1));
            m_dGradient_k_Var = new package::GraphicVariablePkg ;
            m_dGradient_k_Var->init(GraphicVariablePkg::type_integer);
            m_dGradient_k_Var->setNameVariable(nameItem);
            m_dGradient_k_Var->setInternalName(nameItem);
            m_dGradient_k_Var->setRange(0,32768);
            m_dGradient_k_Var->setDefaultValue(0);
            m_dGradient_k_Var->setTobeVisible(false);
            m_dGradient_k_Var->setVisible(false);
            m_VariableVect.push_back(m_dGradient_k_Var);
            connect (m_dGradient_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );

            nameItem = QString ("Q_GDIR_%1").arg(QString::number(i+1));
            m_qGdir_k_Var = new package::GraphicVariablePkg ;
            m_qGdir_k_Var->init(GraphicVariablePkg::type_integer);
            m_qGdir_k_Var->setNameVariable(nameItem);
            m_qGdir_k_Var->setInternalName(nameItem);
            m_qGdir_k_Var->setRange(0,1);
            m_qGdir_k_Var->setDefaultValue(0);
            m_qGdir_k_Var->setTobeVisible(false);
            m_qGdir_k_Var->setVisible(false);
            m_VariableVect.push_back(m_qGdir_k_Var);
            connect (m_qGdir_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );

            nameItem = QString ("G_A_%1").arg(QString::number(i+1));
            m_GA_k_Var = new package::GraphicVariablePkg ;
            m_GA_k_Var->init(GraphicVariablePkg::type_integer);
            m_GA_k_Var->setNameVariable(nameItem);
            m_GA_k_Var->setInternalName(nameItem);
            m_GA_k_Var->setRange(0,256);
            m_GA_k_Var->setDefaultValue(0);
            m_GA_k_Var->setTobeVisible(false);
            m_GA_k_Var->setVisible(false);
            m_VariableVect.push_back(m_GA_k_Var);
            connect (m_GA_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_21_Ver340::saveData );
        }


        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();

    }
    return true;

}
void HandlerPackage_21_Ver340::loadPkg()
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

void HandlerPackage_21_Ver340::handleChangeIteration_SL()
{
    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();

    qint16 numVisibile = countVariableIterateisVisible("D_GRADIENT_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        for (int i=0;i< numberShowVariavble;i++){

            nameIterateVar = QString ("D_GRADIENT_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = updLen + 15;

            nameIterateVar = QString ("Q_GDIR_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = updLen + 1;

            nameIterateVar = QString ("G_A_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = updLen + 8;

        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        updLen = m_lenPkgVar->valueOfVariable().toInt();
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            nameIterateVar = QString ("D_GRADIENT_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
                updLen= updLen - 15;
            }

            nameIterateVar = QString ("Q_GDIR_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
                updLen= updLen - 1;
            }

            nameIterateVar = QString ("G_A_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
                updLen= updLen - 8;
            }

            numVisibile--;
        }
    }

    m_lenPkgVar->setDefaultValue(updLen);

    showVariable();
    return ;
}

void HandlerPackage_21_Ver340::showVariable()
{
    m_row=1;
    m_currCol=0;

   //qint16 actualPktSize = this->countPacketBitSize();
   //m_lenPkgVar->setDefaultValue(actualPktSize);

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


bool HandlerPackage_21_Ver340::saveData()
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

void HandlerPackage_21_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}



}
