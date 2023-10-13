#include "HandlerPackage_15_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_15_Ver360::HandlerPackage_15_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;
    m_qScaleVar = nullptr;

    m_vEmaVar = nullptr;
    m_tEmaVar = nullptr;

    m_nIterVar = nullptr;

    m_lEndsectionVar = nullptr;
    m_qSectiontimerVar = nullptr;
    m_tSectiontimerVar = nullptr;
    m_dSectiontimerstoplocVar = nullptr;
    m_qEndtimerVar = nullptr;
    m_tEndtimerVar = nullptr;
    m_dEndtimerstartlocVar = nullptr;
    m_qDangerpointVar = nullptr;
    m_dDpVar = nullptr;
    m_vReleasedpVar = nullptr;
    m_qOverlapVar = nullptr;
    m_dStartolVar = nullptr;
    m_tOlVar = nullptr;
    m_dOlVar = nullptr;
    m_vReleaseolVar = nullptr;

    //itezione

    m_lSection_n_Var = nullptr;
    m_qSectiontimer_n_Var = nullptr;
    m_tSectiontimer_n_Var = nullptr;
    m_dSectiontierstoploc_n_Var = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg = 15;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_15_Ver360::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    bool ret = false;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 15 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(66,1456);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

        m_qScaleVar = new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

        m_vEmaVar = new package::GraphicVariablePkg ;
        m_vEmaVar->set_V_EMA();
        m_VariableVect.push_back(m_vEmaVar);
        connect (m_vEmaVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

        m_tEmaVar = new package::GraphicVariablePkg ;
        m_tEmaVar->set_T_EMA();
        m_VariableVect.push_back(m_tEmaVar);
        connect (m_tEmaVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

        m_nIterVar = new package::GraphicVariablePkg ;
        m_nIterVar->set_N_ITER();
        m_VariableVect.push_back(m_nIterVar);
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::handleChangeIteration_SL );

        qint16 maxValueVariableIter = 31;
        QString nameItem;

        for (int i = 0;i < maxValueVariableIter ;i++)
        {

            nameItem = QString ("L_SECTION_%1").arg(QString::number(i+1));
            m_lSection_n_Var = new package::GraphicVariablePkg ;
            m_lSection_n_Var->set_L_SECTION();
            m_lSection_n_Var->setNameVariable(nameItem);
            m_lSection_n_Var->setInternalName(nameItem);
            m_lSection_n_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_lSection_n_Var);
            connect (m_lSection_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

            nameItem = QString ("Q_SECTIONTIMER_%1").arg(QString::number(i+1));
            m_qSectiontimer_n_Var = new package::GraphicVariablePkg ;
            m_qSectiontimer_n_Var->set_Q_SECTIONTIMER();
            m_qSectiontimer_n_Var->setNameVariable(nameItem);
            m_qSectiontimer_n_Var->setInternalName(nameItem);
            m_qSectiontimer_n_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_qSectiontimer_n_Var);
            connect (m_qSectiontimer_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );
            connect (m_qSectiontimer_n_Var,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_15_Ver360::handleIterateVariable_SL);

            {
                nameItem = QString ("T_SECTIONTIMER_%1").arg(QString::number(i+1));
                m_tSectiontimer_n_Var = new package::GraphicVariablePkg ;
                m_tSectiontimer_n_Var->set_T_SECTIONTIMER();
                m_tSectiontimer_n_Var->setNameVariable(nameItem);
                m_tSectiontimer_n_Var->setInternalName(nameItem);
                m_tSectiontimer_n_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_tSectiontimer_n_Var);
                connect (m_tSectiontimer_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

                nameItem = QString ("D_SECTIONTIMERSTOPLOC_%1").arg(QString::number(i+1));
                m_dSectiontierstoploc_n_Var = new package::GraphicVariablePkg ;
                m_dSectiontierstoploc_n_Var->set_D_SECTIONTIMERSTOPLOC();
                m_dSectiontierstoploc_n_Var->setNameVariable(nameItem);
                m_dSectiontierstoploc_n_Var->setInternalName(nameItem);
                m_dSectiontierstoploc_n_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_dSectiontierstoploc_n_Var);
                connect (m_dSectiontierstoploc_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );
            }

        }

        m_lEndsectionVar = new package::GraphicVariablePkg ;
        m_lEndsectionVar->set_L_ENDSECTION();
        m_VariableVect.push_back(m_lEndsectionVar);
        connect (m_lEndsectionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

        m_qSectiontimerVar = new package::GraphicVariablePkg ;
        m_qSectiontimerVar->set_Q_SECTIONTIMER();
        m_VariableVect.push_back(m_qSectiontimerVar);
        connect (m_qSectiontimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );
        connect (m_qSectiontimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::show_SECTION_SL );

        {

            m_tSectiontimerVar = new package::GraphicVariablePkg ;
            m_tSectiontimerVar->set_T_SECTIONTIMER();
            m_tSectiontimerVar->setTobeVisible(false);
            m_VariableVect.push_back(m_tSectiontimerVar);
            connect (m_tSectiontimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

            m_dSectiontimerstoplocVar = new package::GraphicVariablePkg ;
            m_dSectiontimerstoplocVar->set_D_SECTIONTIMERSTOPLOC();
            m_dSectiontimerstoplocVar->setTobeVisible(false);
            m_VariableVect.push_back(m_dSectiontimerstoplocVar);
            connect (m_dSectiontimerstoplocVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

        }
        m_qEndtimerVar = new package::GraphicVariablePkg ;
        m_qEndtimerVar->set_Q_ENDTIMER();
        m_VariableVect.push_back(m_qEndtimerVar);
        connect (m_qEndtimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );
        connect (m_qEndtimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::show_ENDTIMER_SL );

        {
            m_tEndtimerVar = new package::GraphicVariablePkg ;
            m_tEndtimerVar->set_T_ENDTIME();
            m_tEndtimerVar->setTobeVisible(false);
            m_VariableVect.push_back(m_tEndtimerVar);
            connect (m_tEndtimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

            m_dEndtimerstartlocVar = new package::GraphicVariablePkg ;
            m_dEndtimerstartlocVar->set_D_ENDTIMERSTARTLOC();
            m_dEndtimerstartlocVar->setTobeVisible(false);
            m_VariableVect.push_back(m_dEndtimerstartlocVar);
            connect (m_dEndtimerstartlocVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

        }

        m_qDangerpointVar = new package::GraphicVariablePkg ;
        m_qDangerpointVar->set_Q_DANGERPOINT();
        m_VariableVect.push_back(m_qDangerpointVar);
        connect (m_qDangerpointVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );
        connect (m_qDangerpointVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::show_DP_SL );

        {
            m_dDpVar = new package::GraphicVariablePkg ;
            m_dDpVar->set_D_DP();
            m_dDpVar->setTobeVisible(false);
            m_VariableVect.push_back(m_dDpVar);
            connect (m_dDpVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

            m_vReleasedpVar = new package::GraphicVariablePkg ;
            m_vReleasedpVar->set_V_RELEASEDP();
            m_vReleasedpVar->setTobeVisible(false);
            m_VariableVect.push_back(m_vReleasedpVar);
            connect (m_vReleasedpVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

        }

        m_qOverlapVar = new package::GraphicVariablePkg ;
        m_qOverlapVar->set_Q_OVERLAP();
        m_VariableVect.push_back(m_qOverlapVar);
        connect (m_qOverlapVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );
        connect (m_qOverlapVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::show_OL_SL );

        {
            m_dStartolVar = new package::GraphicVariablePkg ;
            m_dStartolVar->set_D_STARTOL();
            m_dStartolVar->setTobeVisible(false);
            m_VariableVect.push_back(m_dStartolVar);
            connect (m_dStartolVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

            m_tOlVar = new package::GraphicVariablePkg ;
            m_tOlVar->set_T_OL();
            m_tOlVar->setTobeVisible(false);
            m_VariableVect.push_back(m_tOlVar);
            connect (m_tOlVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

            m_dOlVar = new package::GraphicVariablePkg ;
            m_dOlVar->set_D_OL();
            m_dOlVar->setTobeVisible(false);
            m_VariableVect.push_back(m_dOlVar);
            connect (m_dOlVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

            m_vReleaseolVar = new package::GraphicVariablePkg ;
            m_vReleaseolVar->set_V_RELEASEOL();
            m_vReleaseolVar->setTobeVisible(false);
            m_VariableVect.push_back(m_vReleaseolVar);
            connect (m_vReleaseolVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_15_Ver360::saveData );

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
void HandlerPackage_15_Ver360::loadPkg()
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

void HandlerPackage_15_Ver360::handleChangeIteration_SL()
{
    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();

    qint16 numVisibile = countVariableIterateisVisible("L_SECTION_");

    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;


    //Prima Iterazione
    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("L_SECTION_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("Q_SECTIONTIMER_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("T_SECTIONTIMER_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,false,notUsed);

            nameIterateVar = QString ("D_SECTIONTIMERSTOPLOC_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,false,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            nameIterateVar = QString ("L_SECTION_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("Q_SECTIONTIMER_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("T_SECTIONTIMER_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("D_SECTIONTIMERSTOPLOC_%1").arg(QString::number(numVisibile));
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
}

void HandlerPackage_15_Ver360::show_SECTION_SL()
{
    int value = m_qSectiontimerVar->valueOfVariable().toInt();
    qDebug () << value;

    if (1 == value){
        m_tSectiontimerVar->setTobeVisible(true);
        m_dSectiontimerstoplocVar->setTobeVisible(true);
    } else {
        m_tSectiontimerVar->setTobeVisible(false);
        m_dSectiontimerstoplocVar->setTobeVisible(false);
    }

    showVariable();
}

void HandlerPackage_15_Ver360::show_ENDTIMER_SL()
{
    int value = m_qEndtimerVar->valueOfVariable().toInt();
    qDebug () << value;

    if (1 == value){
        m_tEndtimerVar->setTobeVisible(true);
        m_dEndtimerstartlocVar->setTobeVisible(true);
    } else {
        m_tEndtimerVar->setTobeVisible(false);
        m_dEndtimerstartlocVar->setTobeVisible(false);
    }

    showVariable();
}

void HandlerPackage_15_Ver360::show_DP_SL()
{
    int value = m_qDangerpointVar->valueOfVariable().toInt();
    qDebug () << value;

    if (1 == value){
        m_dDpVar->setTobeVisible(true);
        m_vReleasedpVar->setTobeVisible(true);
    } else {
        m_dDpVar->setTobeVisible(false);
        m_vReleasedpVar->setTobeVisible(false);
    }

    showVariable();
}

void HandlerPackage_15_Ver360::show_OL_SL()
{
    int value = m_qOverlapVar->valueOfVariable().toInt();
    qDebug () << value;

    if (1 == value){
        m_dStartolVar->setTobeVisible(true);
        m_tOlVar->setTobeVisible(true);
        m_dOlVar->setTobeVisible(true);
        m_vReleaseolVar->setTobeVisible(true);
    } else {
        m_dStartolVar->setTobeVisible(false);
        m_tOlVar->setTobeVisible(false);
        m_dOlVar->setTobeVisible(false);
        m_vReleaseolVar->setTobeVisible(false);
    }

    showVariable();
}

void HandlerPackage_15_Ver360::showVariable()
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
    m_spaced = new QSpacerItem (40,15,QSizePolicy::Expanding,QSizePolicy::Expanding) ;
    m_layOutPkg->addItem(m_spaced, m_row+1,m_maxColumnVariable+1);

}

void HandlerPackage_15_Ver360::handleIterateVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * p_variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< p_variable->valueOfVariable();
    qint16 value = p_variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    qint16 variableIdx = -1;

    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString tSectionTimerVar = QString ("T_SECTIONTIMER_%1").arg(parseNameVar[parseNameVar.size()-1]);
        QString tSectionTimerVar2 = QString ("D_SECTIONTIMERSTOPLOC_%1").arg(parseNameVar[parseNameVar.size()-1]);

        bool notUsed;
        if (0 == value){
            variableUpdVisibleState(tSectionTimerVar,false,notUsed);
            variableUpdVisibleState(tSectionTimerVar2,false,notUsed);
            p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
            p_variable->setDefaultValue(0);
        }else{
            variableIdx = variableUpdVisibleState(tSectionTimerVar,true,notUsed);
            variableUpdVisibleState(tSectionTimerVar2,true,notUsed);
        }
    }

    showVariable();
}

bool HandlerPackage_15_Ver360::saveData()
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

void HandlerPackage_15_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}



}
