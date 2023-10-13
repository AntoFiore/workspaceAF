#include "HandlerPackage_13_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_13_Ver360::HandlerPackage_13_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;
    m_qScaleVar = nullptr;

    m_qNewcountry_1_Var = nullptr;
    m_nidC_1_Var = nullptr;
    m_nidBG_1_Var = nullptr;

    m_qNewcountry_2_Var = nullptr;
    m_nidC_2_Var = nullptr;
    m_nidBG_2_Var = nullptr;
    m_dSRVar = nullptr;

    m_nIterVar = nullptr;

    m_qNewcountry_k_Var = nullptr;
    m_nidC_k_Var = nullptr;
    m_nidBG_k_Var = nullptr;
    m_dSRV_k_ar = nullptr;


    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg = 13;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_13_Ver360::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    bool ret= false;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 13 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(72, 1462);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

        m_qScaleVar = new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

        m_qNewcountry_1_Var = new package::GraphicVariablePkg;
        m_qNewcountry_1_Var->set_Q_NEWCOUNTRY();
        m_VariableVect.push_back(m_qNewcountry_1_Var);
        connect (m_qNewcountry_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::show_NIDc_1_SL );
        connect (m_qNewcountry_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

        {
            m_nidC_1_Var = new package::GraphicVariablePkg;
            m_nidC_1_Var->set_NID_C();
            m_nidC_1_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_nidC_1_Var);
            connect (m_nidC_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );
        }

        m_nidBG_1_Var = new package::GraphicVariablePkg;
        m_nidBG_1_Var->set_NID_BG();
        m_VariableVect.push_back(m_nidBG_1_Var);
        connect (m_nidBG_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

        m_qNewcountry_2_Var = new package::GraphicVariablePkg;
        m_qNewcountry_2_Var->set_Q_NEWCOUNTRY();
        m_VariableVect.push_back(m_qNewcountry_2_Var);
        connect (m_qNewcountry_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::show_NIDc_2_SL );
        connect (m_qNewcountry_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

        {
            m_nidC_2_Var = new package::GraphicVariablePkg;
            m_nidC_2_Var->set_NID_C();
            m_nidC_2_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_nidC_2_Var);
            connect (m_nidC_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );
        }

        m_nidBG_2_Var = new package::GraphicVariablePkg;
        m_nidBG_2_Var->set_NID_BG();
        m_VariableVect.push_back(m_nidBG_2_Var);
        connect (m_nidBG_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

        m_dSRVar = new package::GraphicVariablePkg;
        m_dSRVar->set_D_SR();
        m_VariableVect.push_back(m_dSRVar);
        connect (m_dSRVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

        m_nIterVar =  new package::GraphicVariablePkg ;
        m_nIterVar->set_N_ITER();
        m_VariableVect.push_back(m_nIterVar);
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::handleChangeIteration_SL );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

        qint16 maxValueVariableIter = 31;
        QString nameItem;
        for (int i = 0;i < maxValueVariableIter ;i++)
        {
            nameItem = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(i+1));
            m_qNewcountry_k_Var = new package::GraphicVariablePkg ;
            m_qNewcountry_k_Var->set_Q_NEWCOUNTRY();
            m_qNewcountry_k_Var->setNameVariable(nameItem);
            m_qNewcountry_k_Var->setInternalName(nameItem);
            m_qNewcountry_k_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_qNewcountry_k_Var);
            connect (m_qNewcountry_k_Var,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_13_Ver360::handleIterateVariable_SL );
            connect (m_qNewcountry_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

            {
                nameItem = QString ("NID_C_%1").arg(QString::number(i+1));
                m_nidC_k_Var = new package::GraphicVariablePkg ;
                m_nidC_k_Var->set_NID_C();
                m_nidC_k_Var->setNameVariable(nameItem);
                m_nidC_k_Var->setInternalName(nameItem);
                m_nidC_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_nidC_k_Var);
                connect (m_nidC_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );
            }


            nameItem = QString ("NID_BG_%1").arg(QString::number(i+1));
            m_nidBG_k_Var = new package::GraphicVariablePkg ;
            m_nidBG_k_Var->set_NID_BG();
            m_nidBG_k_Var->setNameVariable(nameItem);
            m_nidBG_k_Var->setInternalName(nameItem);
            m_nidBG_k_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_nidBG_k_Var);
            connect (m_nidBG_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );

            nameItem = QString ("D_SR_%1").arg(QString::number(i+1));
            m_dSRV_k_ar = new package::GraphicVariablePkg ;
            m_dSRV_k_ar->init(GraphicVariablePkg::type_integer);
            m_dSRV_k_ar->setNameVariable(nameItem);
            m_dSRV_k_ar->setInternalName(nameItem);
            m_dSRV_k_ar->setTobeVisible(false);
            m_VariableVect.push_back(m_dSRV_k_ar);
            connect (m_dSRV_k_ar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_13_Ver360::saveData );
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
void HandlerPackage_13_Ver360::loadPkg()
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

void HandlerPackage_13_Ver360::show_NIDc_1_SL()
{
    int value = m_qNewcountry_1_Var->valueOfVariable().toInt();
    qDebug () << value;

    if (1 == value){
        m_nidC_1_Var->setTobeVisible(true);
    } else {
        m_nidC_1_Var->setTobeVisible(false);
    }

    showVariable();
}

void HandlerPackage_13_Ver360::show_NIDc_2_SL()
{
    int value = m_qNewcountry_2_Var->valueOfVariable().toInt();
    qDebug () << value;

    if (1 == value){
        m_nidC_2_Var->setTobeVisible(true);
    } else {
        m_nidC_2_Var->setTobeVisible(false);
    }

    showVariable();
}

void HandlerPackage_13_Ver360::handleChangeIteration_SL()
{
    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();

    qint16 numVisibile = countVariableIterateisVisible("Q_NEWCOUNTRY_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = updLen + 15;

            nameIterateVar = QString ("NID_C_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,false,notUsed);
            updLen = updLen + 1;

            nameIterateVar = QString ("NID_BG_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("D_SR_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            nameIterateVar = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("NID_C_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("NID_BG_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("D_SR_%1").arg(QString::number(numVisibile));
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

void HandlerPackage_13_Ver360::handleIterateVariable_SL(QString nameVariable)
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

void HandlerPackage_13_Ver360::showVariable()
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


bool HandlerPackage_13_Ver360::saveData()
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
//    //= m_nidPkgVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qDirVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_lenPkgVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qScaleVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_vMainVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_vEmaVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_tEmaVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_nIterVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;

//    qint16 numIteration = m_nIterVar->valueOfVariable().toInt();
//    qint16 sizeIterate = ( numIteration * 4);
//    if (sizeIterate+6 <=m_VariableVect.size()){
//        for (int i =0; i < sizeIterate;i++ ){
//            package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i+6));
//            data+=INTERNAL_FIELD_SEPARATOR_PKG;
//            if (variable->tobeVisible()){
//                data+=variable->valueOfVariable();
//            } else {
//                data+=EMPTY_VALUE;
//            }
//        }
//    }

//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_lEndSectionVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qSectionTimerVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_tSectionTimerVar->isVisible()){
//        data+=m_tSectionTimerVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dSectionTimerStopLocVar->isVisible()){
//        data+=m_dSectionTimerStopLocVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }

//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qEndTimerVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_tEndTimerVar->isVisible()){
//        data+=m_tEndTimerVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dEndTimerStartLocVar->isVisible()){
//        data+=m_dEndTimerStartLocVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }

//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qDangerPointVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dDpVar->isVisible()){
//        data+=m_dDpVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_vReleaseDpVar->isVisible()){
//        data+=m_vReleaseDpVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }

//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qOverlapVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dStartOLVar->isVisible()){
//        data+=m_dStartOLVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_tOLVar->isVisible()){
//        data+=m_tOLVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dOLVar->isVisible()){
//        data+=m_dOLVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_vReleaseOLVar->isVisible()){
//        data+=m_vReleaseOLVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;

    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;

}

void HandlerPackage_13_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}



}
