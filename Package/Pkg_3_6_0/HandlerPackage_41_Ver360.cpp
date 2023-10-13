#include "HandlerPackage_41_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_41_Ver360::HandlerPackage_41_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_ScaleVar=nullptr;
    m_dLevelTrVar=nullptr;
    m_mLevelTrVar=nullptr;
    m_nidNtcVar=nullptr;
    m_lAckLevelTrVar=nullptr;

    m_nIterVar = nullptr;


    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg=41;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_41_Ver360::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    QString nameItem;
    bool ret = true;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 41 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->init(GraphicVariablePkg::type_integer);
        m_nidPkgVar->setNameVariable("NID_PACKET");
        m_nidPkgVar->setIsOnlyRead(true);
        m_nidPkgVar->setDefaultValue(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);
        m_nidPkgVar->setVisible(false);
        m_nidPkgVar->setTobeVisible(true);
        m_nidPkgVar->setVariableBitSize(8);


        m_qDirVar =  new package::GraphicVariablePkg ;
        m_qDirVar->init(GraphicVariablePkg::type_integer);
        m_qDirVar->setNameVariable("Q_DIR");
        m_qDirVar->setRange(0,3);
        m_qDirVar->setDefaultValue(0);
        m_qDirVar->setVisible(false);
        m_VariableVect.push_back(m_qDirVar);
        m_qDirVar->setTobeVisible(true);
        m_qDirVar->setVariableBitSize(2);


        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->init(GraphicVariablePkg::type_integer);
        m_lenPkgVar->setNameVariable("L_PACKET");
        m_lenPkgVar->setIsOnlyRead(true);
        m_lenPkgVar->setRange(0,8192);
        m_lenPkgVar->setVisible(false);
        m_lenPkgVar->setTobeVisible(true);
        m_lenPkgVar->setVariableBitSize(13);
        m_VariableVect.push_back(m_lenPkgVar);

        nameItem = QString ("Q_SCALE");
        m_ScaleVar =  new package::GraphicVariablePkg ;
        m_ScaleVar->init(GraphicVariablePkg::type_integer);
        m_ScaleVar->setNameVariable(nameItem);
        m_ScaleVar->setInternalName(nameItem);
        m_ScaleVar->setDefaultValue(0);
        m_ScaleVar->setRange(0,3);
        m_ScaleVar->setVisible(false);
        m_VariableVect.push_back(m_ScaleVar);
        m_ScaleVar->setTobeVisible(true);
        m_ScaleVar->setVariableBitSize(2);

        m_dLevelTrVar;
        nameItem = QString ("D_LEVELTR");
        m_dLevelTrVar =  new package::GraphicVariablePkg ;
        m_dLevelTrVar->init(GraphicVariablePkg::type_integer);
        m_dLevelTrVar->setNameVariable(nameItem);
        m_dLevelTrVar->setInternalName(nameItem);
        m_dLevelTrVar->setDefaultValue(0);
        m_dLevelTrVar->setRange(0,32767);
        m_dLevelTrVar->setVisible(false);
        m_VariableVect.push_back(m_dLevelTrVar);
        m_dLevelTrVar->setTobeVisible(true);
        m_dLevelTrVar->setVariableBitSize(15);

        nameItem = QString ("M_LEVELTR");
        m_mLevelTrVar =  new package::GraphicVariablePkg ;
        m_mLevelTrVar->init(GraphicVariablePkg::type_integer);
        m_mLevelTrVar->setNameVariable(nameItem);
        m_mLevelTrVar->setInternalName(nameItem);
        m_mLevelTrVar->setDefaultValue(0);
        m_mLevelTrVar->setRange(0,7);
        m_mLevelTrVar->setVisible(false);
        m_VariableVect.push_back(m_mLevelTrVar);
        m_mLevelTrVar->setTobeVisible(true);
        m_mLevelTrVar->setVariableBitSize(3);

        m_nidNtcVar =  new package::GraphicVariablePkg ;
        m_nidNtcVar->set_NID_NTC();
        m_nidNtcVar->setVisible(false);
        m_nidNtcVar->setTobeVisible(false);
        m_VariableVect.push_back(m_nidNtcVar);

        nameItem = QString ("L_ACKLEVELTR");
        m_lAckLevelTrVar =  new package::GraphicVariablePkg ;
        m_lAckLevelTrVar->init(GraphicVariablePkg::type_integer);
        m_lAckLevelTrVar->setNameVariable(nameItem);
        m_lAckLevelTrVar->setInternalName(nameItem);
        m_lAckLevelTrVar->setDefaultValue(0);
        m_lAckLevelTrVar->setRange(0,32767);
        m_lAckLevelTrVar->setVisible(false);
        m_lAckLevelTrVar->setVariableBitSize(15);
        m_mLevelTrVar->setTobeVisible(true);
        m_VariableVect.push_back(m_lAckLevelTrVar);



        nameItem = QString ("N_ITER");
        m_nIterVar =  new package::GraphicVariablePkg ;
        m_nIterVar->init(GraphicVariablePkg::type_integer);
        m_nIterVar->setNameVariable(nameItem);
        m_nIterVar->setInternalName(nameItem);
        m_nIterVar->setRange(0,31);
        m_nIterVar->setDefaultValue(0);
        m_nIterVar->setVisible(false);
        m_nIterVar->setTobeVisible(true);
        m_nIterVar->setVariableBitSize(5);
        m_VariableVect.push_back(m_nIterVar);

        qint16 maxValueVariableIter=MAX_ITERATION;
        package::GraphicVariablePkg * mLevelTrIterVar=nullptr;
        package::GraphicVariablePkg * nidNtcIterVar=nullptr;
        package::GraphicVariablePkg * lAckLevelTrIterVar=nullptr;


        for (int i = 0;i < maxValueVariableIter ;i++) {
            mLevelTrIterVar =  new package::GraphicVariablePkg ;
            mLevelTrIterVar->init(GraphicVariablePkg::type_integer);
            QString nameItem = QString ("M_LEVELTR_%1").arg(QString::number(i+1));
            mLevelTrIterVar->setNameVariable(nameItem);
            mLevelTrIterVar->setInternalName(nameItem);
            mLevelTrIterVar->setRange(0,7);
            mLevelTrIterVar->setDefaultValue(0);
            m_VariableVect.push_back(mLevelTrIterVar);
            mLevelTrIterVar->setVisible(false);
            mLevelTrIterVar->setTobeVisible(false);
            mLevelTrIterVar->setVariableBitSize(3);


            nidNtcIterVar =  new package::GraphicVariablePkg ;
            nidNtcIterVar->set_NID_NTC();
            nameItem = QString ("NID_NTC_%1").arg(QString::number(i+1));
            nidNtcIterVar->setNameVariable(nameItem);
            nidNtcIterVar->setInternalName(nameItem);
            nidNtcIterVar->setVisible(false);
            nidNtcIterVar->setTobeVisible(false);
            m_VariableVect.push_back(nidNtcIterVar);

            lAckLevelTrIterVar =  new package::GraphicVariablePkg ;
            lAckLevelTrIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("L_ACKLEVELTR_%1").arg(QString::number(i+1));
            lAckLevelTrIterVar->setNameVariable(nameItem);
            lAckLevelTrIterVar->setInternalName(nameItem);
            lAckLevelTrIterVar->setRange(0,32767);
            lAckLevelTrIterVar->setDefaultValue(0);
            m_VariableVect.push_back(lAckLevelTrIterVar);
            lAckLevelTrIterVar->setVisible(false);
            lAckLevelTrIterVar->setTobeVisible(false);
            lAckLevelTrIterVar->setVariableBitSize(15);

        }
        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }

        showVariable();
        ret=saveData();
        connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );
        connect (m_ScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );
        connect (m_dLevelTrVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );

        connect (m_mLevelTrVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_41_Ver360::handleChangeM_LevelTrVariable_SL );
        connect (m_mLevelTrVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );

        connect (m_nidNtcVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );

        connect (m_lAckLevelTrVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );


        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::handleChangeIteration_SL );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );

        qint16 positionIterateVar = 9;
        qint16 size = m_VariableVect.size();
        for (int i = positionIterateVar ;i < size ;i++) {
            package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
            if (nullptr != variable){
                connect (variable,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_41_Ver360::saveData );
                if (variable->internalName().contains("M_LEVELTR_")){
                    connect (variable,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_41_Ver360::handleChangeM_LevelTrIterVariable_SL );
                }
            }

        }

    }

    return ret;

}
void HandlerPackage_41_Ver360::handleChangeM_LevelTrIterVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        QStringList parseNameVar = nameVariable.split("_");
        if (parseNameVar.size() ){

            qint16 numberIteration = parseNameVar[parseNameVar.size()-1].toInt();
            qint16 idx = -1;
            QString nameIterateVar;
            bool oldvisibleState=false;
            qint16 valueLevTrIter = variable->valueOfVariable().toInt();
            nameIterateVar = QString ("NID_NTC_%1").arg(QString::number(numberIteration));
            if (1==valueLevTrIter){
                variableUpdVisibleState(nameIterateVar,true,oldvisibleState);
            } else {
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }
            }
            m_lenPkgVar->setDefaultValue(countPacketBitSize());
            showVariable();
        }

    }


}

void HandlerPackage_41_Ver360::handleChangeIteration_SL()
{

    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("M_LEVELTR_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;
    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue-numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            QString nameIterateVar = QString ("M_LEVELTR_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            nameIterateVar = QString ("L_ACKLEVELTR_%1").arg(QString::number(numVisibile+i+1));
            variableUpdVisibleState(nameIterateVar,true,notUsed);

        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            QString nameIterateVar = QString ("M_LEVELTR_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            qint16 idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("NID_NTC_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("L_ACKLEVELTR_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }
            numVisibile--;
        }
    }
    showVariable();
    return ;
}

void HandlerPackage_41_Ver360::handleChangeQ_NewCountry_IterVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        QStringList parseNameVar = nameVariable.split("_");
        if (parseNameVar.size() ){
            qint16 numberIteration = parseNameVar[parseNameVar.size()-1].toInt();
            qint16 value = variable->valueOfVariable().toInt();
            QString nameIterateVar;
            bool oldvisibleState=false;
            nameIterateVar = QString ("NID_NTC_%1").arg(QString::number(numberIteration));
            qint16 idx =-1;
            if (1 == value){
                variableUpdVisibleState(nameIterateVar,true,oldvisibleState);
            } else {
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }

            }

        }

        showVariable();
    }


}

void HandlerPackage_41_Ver360::handleChangeM_LevelTrVariable_SL()
{
    if (1 == m_mLevelTrVar->valueOfVariable().toInt()){
        m_nidNtcVar->setTobeVisible(true);
    } else {
        m_nidNtcVar->setTobeVisible(false);
    }
    showVariable();
}



void HandlerPackage_41_Ver360::showVariable()
{
    m_row=1;
    m_currCol=0;
    removeSpacer();
    m_lenPkgVar->setDefaultValue(countPacketBitSize());
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


bool HandlerPackage_41_Ver360::saveData()
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
void HandlerPackage_41_Ver360::loadPkg()
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


void HandlerPackage_41_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}


}
