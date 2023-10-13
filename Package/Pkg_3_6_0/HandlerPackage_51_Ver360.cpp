#include "HandlerPackage_51_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_51_Ver360::HandlerPackage_51_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;
    m_qScaleVar = nullptr;

    m_qTrackinitVar = nullptr;
    m_dTrackinitVar = nullptr;
    m_dAxleloadVar = nullptr;
    m_lAxleloadVar = nullptr;
    m_qFrontVar = nullptr;

    m_nIter_n_Var = nullptr;
    m_mAxleloadcat_n_Var = nullptr;
    m_vAxleload_n_Var = nullptr;

    m_nIter_k_Var = nullptr;
    m_dAxleload_k_Var = nullptr;
    m_lAxleload_k_Var = nullptr;
    m_qFront_k_Var = nullptr;

    m_nIter_k_m_Var = nullptr;
    m_mAxleloadCat_k_m_Var = nullptr;
    m_vAxleload_k_m_Var = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg = 51;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_51_Ver360::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    bool ret = false;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 51 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(41);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

        m_qScaleVar = new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

        m_qTrackinitVar = new package::GraphicVariablePkg;
        m_qTrackinitVar->set_Q_TRACKINIT();
        m_VariableVect.push_back(m_qTrackinitVar);
        connect (m_qTrackinitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::show_qTrackinit_SL );
        connect (m_qTrackinitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

        {
            m_dTrackinitVar = new package::GraphicVariablePkg;
            m_dTrackinitVar->set_D_TRACKINIT();
            m_dTrackinitVar->setTobeVisible(false);
            m_VariableVect.push_back(m_dTrackinitVar);
            connect (m_dTrackinitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

            m_dAxleloadVar = new package::GraphicVariablePkg;
            m_dAxleloadVar->set_D_AXLELOAD();
            m_dAxleloadVar->setTobeVisible(true);
            m_VariableVect.push_back(m_dAxleloadVar);
            connect (m_dAxleloadVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

            m_lAxleloadVar = new package::GraphicVariablePkg;
            m_lAxleloadVar->set_L_AXLELOAD();
            m_lAxleloadVar->setTobeVisible(true);
            m_VariableVect.push_back(m_lAxleloadVar);
            connect (m_lAxleloadVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

            m_qFrontVar = new package::GraphicVariablePkg;
            m_qFrontVar->set_Q_FRONT();
            m_qFrontVar->setTobeVisible(true);
            m_VariableVect.push_back(m_qFrontVar);
            connect (m_qFrontVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

            m_nIter_n_Var =  new package::GraphicVariablePkg ;
            m_nIter_n_Var->set_N_ITER();
            m_nIter_n_Var->setNameVariable("N_ITER (n)");
            m_nIter_n_Var->setTobeVisible(true);
            m_VariableVect.push_back(m_nIter_n_Var);
            connect (m_nIter_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::handleChangeIteration_n_SL );
            connect (m_nIter_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

            qint16 maxValueVariableIter_n = 31;
            QString nameItem_n;
            for (int n = 0; n < maxValueVariableIter_n ; n++)
            {
                nameItem_n = QString ("M_AXLELOADCAT_%1").arg(QString::number(n+1));
                m_mAxleloadcat_n_Var = new package::GraphicVariablePkg ;
                m_mAxleloadcat_n_Var->init(GraphicVariablePkg::type_integer);
                m_mAxleloadcat_n_Var->setNameVariable(nameItem_n);
                m_mAxleloadcat_n_Var->setInternalName(nameItem_n);
                m_mAxleloadcat_n_Var->setTobeVisible(false);
                m_mAxleloadcat_n_Var->setVariableBitSize(7);
                m_VariableVect.push_back(m_mAxleloadcat_n_Var);
                connect (m_mAxleloadcat_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

                nameItem_n = QString ("V_AXLELOAD_%1").arg(QString::number(n+1));
                m_vAxleload_n_Var = new package::GraphicVariablePkg;
                m_vAxleload_n_Var->init(GraphicVariablePkg::type_integer);
                m_vAxleload_n_Var->setNameVariable(nameItem_n);
                m_vAxleload_n_Var->setInternalName(nameItem_n);
                m_vAxleload_n_Var->setTobeVisible(false);
                m_vAxleload_n_Var->setVariableBitSize(7);
                m_VariableVect.push_back(m_vAxleload_n_Var);
                connect (m_vAxleload_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );
            }

            m_nIter_k_Var =  new package::GraphicVariablePkg ;
            m_nIter_k_Var->set_N_ITER();
            m_nIter_k_Var->setNameVariable("N_ITER (k)");
            m_nIter_k_Var->setTobeVisible(true);
            m_VariableVect.push_back(m_nIter_k_Var);
            connect (m_nIter_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::handleChangeIteration_k_SL );
            connect (m_nIter_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

            qint16 maxValueVariableIter_k = 31;
            QString nameItem_k;
            for (int k = 0;k < maxValueVariableIter_k ;k++)
            {
                nameItem_k = QString ("D_AXLELOAD_%1").arg(QString::number(k+1));
                m_dAxleload_k_Var = new package::GraphicVariablePkg ;
                m_dAxleload_k_Var->set_D_AXLELOAD();
                m_dAxleload_k_Var->setNameVariable(nameItem_k);
                m_dAxleload_k_Var->setInternalName(nameItem_k);
                m_dAxleload_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_dAxleload_k_Var);
                connect (m_dAxleload_k_Var,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_51_Ver360::handleIterateVariable_SL );
                connect (m_dAxleload_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

                nameItem_k = QString ("L_AXLELOAD_%1").arg(QString::number(k+1));
                m_lAxleload_k_Var = new package::GraphicVariablePkg ;
                m_lAxleload_k_Var->set_L_AXLELOAD();
                m_lAxleload_k_Var->setNameVariable(nameItem_k);
                m_lAxleload_k_Var->setInternalName(nameItem_k);
                m_lAxleload_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_lAxleload_k_Var);
                connect (m_lAxleload_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

                nameItem_k = QString ("Q_FRONT_%1").arg(QString::number(k+1));
                m_lAxleload_k_Var = new package::GraphicVariablePkg ;
                m_lAxleload_k_Var->set_Q_FRONT();
                m_lAxleload_k_Var->setNameVariable(nameItem_k);
                m_lAxleload_k_Var->setInternalName(nameItem_k);
                m_lAxleload_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_lAxleload_k_Var);
                connect (m_lAxleload_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

                nameItem_k = QString ("N_ITER_%1").arg(QString::number(k+1));
                m_nIter_k_m_Var =  new package::GraphicVariablePkg ;
                m_nIter_k_m_Var->set_N_ITER();
                m_nIter_k_m_Var->setNameVariable(nameItem_k + " (k_m)");
                m_nIter_k_m_Var->setInternalName(nameItem_k);
                m_nIter_k_m_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_nIter_k_m_Var);
                connect (m_nIter_k_m_Var,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_51_Ver360::handleChangeIteration_k_m_SL );
                connect (m_nIter_k_m_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

                qint16 maxValueVariableIter_k_m = 31;
                QString nameItem_k_m;
                for (int m = 0;m < maxValueVariableIter_k_m ;m++)
                {
                    nameItem_k_m = QString ("M_AXLELOADCAT_%1_%2").arg(QString::number(k+1), QString::number(m+1));
                    m_mAxleloadCat_k_m_Var = new package::GraphicVariablePkg ;
                    m_mAxleloadCat_k_m_Var->init(GraphicVariablePkg::type_integer);
                    m_mAxleloadCat_k_m_Var->setNameVariable(nameItem_k_m);
                    m_mAxleloadCat_k_m_Var->setInternalName(nameItem_k_m);
                    m_mAxleloadCat_k_m_Var->setTobeVisible(false);
                    m_mAxleloadCat_k_m_Var->setVariableBitSize(7);
                    m_VariableVect.push_back(m_mAxleloadCat_k_m_Var);
                    connect (m_mAxleloadCat_k_m_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );

                    nameItem_k = QString ("V_AXLELOAD_%1_%2").arg(QString::number(k+1), QString::number(m+1));
                    m_vAxleload_k_m_Var = new package::GraphicVariablePkg ;
                    m_vAxleload_k_m_Var->init(GraphicVariablePkg::type_integer);
                    m_vAxleload_k_m_Var->setNameVariable(nameItem_k);
                    m_vAxleload_k_m_Var->setInternalName(nameItem_k);
                    m_vAxleload_k_m_Var->setTobeVisible(false);
                    m_vAxleload_k_m_Var->setVariableBitSize(7);
                    m_VariableVect.push_back(m_vAxleload_k_m_Var);
                    connect (m_vAxleload_k_m_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_51_Ver360::saveData );
                }
            }
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
void HandlerPackage_51_Ver360::loadPkg()
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

void HandlerPackage_51_Ver360::show_qTrackinit_SL()
{
    int value = m_qTrackinitVar->valueOfVariable().toInt();
    qDebug () << value;
    if (1 == value){
        /* variable to show */
        m_dTrackinitVar->setTobeVisible(true);

        /* variables to remove */
        m_dAxleloadVar->setTobeVisible(false);
        m_lAxleloadVar->setTobeVisible(false);
        m_qFrontVar->setTobeVisible(false);
        m_nIter_n_Var->setTobeVisible(false);
        m_nIter_n_Var->setDefaultValue(0);
        m_nIter_k_Var->setTobeVisible(false);
        m_nIter_k_Var->setDefaultValue(0);
    } else { // value == 0
        /* variable to show */
        m_dTrackinitVar->setTobeVisible(false);

        /* variables to remove */
        m_dAxleloadVar->setTobeVisible(true);
        m_lAxleloadVar->setTobeVisible(true);
        m_qFrontVar->setTobeVisible(true);
        m_nIter_n_Var->setTobeVisible(true);
        m_nIter_k_Var->setTobeVisible(true);
    }
    showVariable();
}

void HandlerPackage_51_Ver360::handleChangeIteration_n_SL()
{
    qint16 currentValue = m_nIter_n_Var->valueOfVariable().toInt();

    qint16 numVisibile = countVariableIterateisVisible("M_AXLELOADCAT_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("M_AXLELOADCAT_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("V_AXLELOAD_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            nameIterateVar = QString ("M_AXLELOADCAT_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("V_AXLELOAD_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }
            numVisibile--;
        }
    }

    m_lenPkgVar->setDefaultValue(updLen);

    showVariable();
    return ;
}

void HandlerPackage_51_Ver360::handleChangeIteration_k_SL()
{
    qint16 currentValue = m_nIter_k_Var->valueOfVariable().toInt();

    qint16 numVisibile = countVariableIterateisVisible("D_AXLELOAD_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("D_AXLELOAD_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("L_AXLELOAD_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("N_ITER_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            nameIterateVar = QString ("D_AXLELOAD_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("L_AXLELOAD_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("N_ITER_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }
            numVisibile--;
        }
    }

    m_lenPkgVar->setDefaultValue(updLen);

    showVariable();
    return ;
}

void HandlerPackage_51_Ver360::handleChangeIteration_k_m_SL(QString nameVariable)
{
    package::GraphicVariablePkg * p_variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< p_variable->valueOfVariable();
    QStringList parseNameVar = nameVariable.split("_");
    qint16 variableIdx = -1;

    QString k_value = parseNameVar.last();
    QString m_value;

    qint16 currentValue = p_variable->valueOfVariable().toInt();
    QString countingVar = QString("M_AXLELOADCAT_%1_").arg(k_value);
    qint16 numVisibile = countVariableIterateisVisible(countingVar);
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            // calculate m_esima variable
            m_value = QString::number(numVisibile + i + 1);
            nameIterateVar = QString ("M_AXLELOADCAT_%1_%2").arg(k_value, m_value);
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("V_AXLELOAD_%1_%2").arg(k_value, m_value);
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            m_value = QString::number(numVisibile);
            nameIterateVar = QString ("M_AXLELOADCAT_%1_%2").arg(k_value, m_value);
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("V_AXLELOAD_%1_%2").arg(k_value, m_value);
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }
            numVisibile--;
        }
    }

    m_lenPkgVar->setDefaultValue(updLen);

    showVariable();
    return ;
}

void HandlerPackage_51_Ver360::handleIterateVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * p_variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< p_variable->valueOfVariable();
    qint16 value = p_variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    qint16 variableIdx = -1;

    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString tSectionTimerVar = QString ("NID_C_%1").arg(parseNameVar[parseNameVar.size()-1]);

        bool notUsed;
        if (1 == value){
            variableUpdVisibleState(tSectionTimerVar,true,notUsed);
        } else {
            variableIdx = variableUpdVisibleState(tSectionTimerVar,false,notUsed);
            p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
            p_variable->setDefaultValue(0);
        }
    }

    showVariable();
}

void HandlerPackage_51_Ver360::showVariable()
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


bool HandlerPackage_51_Ver360::saveData()
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

void HandlerPackage_51_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}



}
