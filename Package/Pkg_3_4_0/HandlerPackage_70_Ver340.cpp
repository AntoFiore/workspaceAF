#include "HandlerPackage_70_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_70_Ver340::HandlerPackage_70_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_nIterVar = nullptr;
    m_ScaleVar=nullptr;
    m_qTrackInitVar=nullptr;
    m_dTrackInitVar=nullptr;
    m_dSuitabilityVar=nullptr;
    m_qSuitabilityVar=nullptr;
    m_mLineGaugeVar=nullptr;
    m_mAxleloadcatVar=nullptr;
    m_mVoltageVar=nullptr;
    m_nid_CtractionVar=nullptr;


    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=70;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_70_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    QString nameItem;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 70 - " + QString(BASELINE_3_4_0));

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
        m_VariableVect.push_back(m_lenPkgVar);
        m_lenPkgVar->setTobeVisible(true);
         m_lenPkgVar->setVariableBitSize(13);

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


        nameItem = QString ("Q_TRACKINIT");
        m_qTrackInitVar =  new package::GraphicVariablePkg ;
        m_qTrackInitVar->init(GraphicVariablePkg::type_integer);
        m_qTrackInitVar->setNameVariable(nameItem);
        m_qTrackInitVar->setInternalName(nameItem);
        m_qTrackInitVar->setDefaultValue(0);
        m_qTrackInitVar->setRange(0,1);
        m_qTrackInitVar->setVisible(false);
        m_VariableVect.push_back(m_qTrackInitVar);
        m_qTrackInitVar->setTobeVisible(true);
        m_qTrackInitVar->setVariableBitSize(1);


        nameItem = QString ("D_TRACKINIT");
        m_dTrackInitVar =  new package::GraphicVariablePkg ;
        m_dTrackInitVar->init(GraphicVariablePkg::type_integer);
        m_dTrackInitVar->setNameVariable(nameItem);
        m_dTrackInitVar->setInternalName(nameItem);
        m_dTrackInitVar->setDefaultValue(0);
        m_dTrackInitVar->setRange(0,327700);
        m_dTrackInitVar->setVisible(false);
        m_VariableVect.push_back(m_dTrackInitVar);
        m_dTrackInitVar->setTobeVisible(false);
        m_dTrackInitVar->setVariableBitSize(15);

        nameItem = QString ("D_SUITABILITY");
        m_dSuitabilityVar =  new package::GraphicVariablePkg ;
        m_dSuitabilityVar->init(GraphicVariablePkg::type_integer);
        m_dSuitabilityVar->setNameVariable(nameItem);
        m_dSuitabilityVar->setInternalName(nameItem);
        m_dSuitabilityVar->setDefaultValue(0);
        m_dSuitabilityVar->setRange(0,327700);
        m_dSuitabilityVar->setVisible(false);
        m_VariableVect.push_back(m_dSuitabilityVar);
        m_dSuitabilityVar->setTobeVisible(true);
        m_dSuitabilityVar->setVariableBitSize(15);

        nameItem = QString ("Q_SUITABILITY");
        m_qSuitabilityVar =  new package::GraphicVariablePkg ;
        m_qSuitabilityVar->init(GraphicVariablePkg::type_integer);
        m_qSuitabilityVar->setNameVariable(nameItem);
        m_qSuitabilityVar->setInternalName(nameItem);
        m_qSuitabilityVar->setDefaultValue(0);
        m_qSuitabilityVar->setRange(0,3);
        m_qSuitabilityVar->setVisible(false);
        m_VariableVect.push_back(m_qSuitabilityVar);
        m_qSuitabilityVar->setTobeVisible(true);
        m_qSuitabilityVar->setVariableBitSize(2);


        nameItem = QString ("M_LINEGAUGE");
        m_mLineGaugeVar =  new package::GraphicVariablePkg ;
        m_mLineGaugeVar->init(GraphicVariablePkg::type_integer);
        m_mLineGaugeVar->setNameVariable(nameItem);
        m_mLineGaugeVar->setInternalName(nameItem);
        m_mLineGaugeVar->setDefaultValue(0);
        m_mLineGaugeVar->setRange(0,255);
        m_mLineGaugeVar->setVisible(false);
        m_VariableVect.push_back(m_mLineGaugeVar);
        m_mLineGaugeVar->setTobeVisible(true);
        m_mLineGaugeVar->setVariableBitSize(8);


        nameItem = QString ("M_AXLELOADCAT");
        m_mAxleloadcatVar =  new package::GraphicVariablePkg ;
        m_mAxleloadcatVar->init(GraphicVariablePkg::type_integer);
        m_mAxleloadcatVar->setNameVariable(nameItem);
        m_mAxleloadcatVar->setInternalName(nameItem);
        m_mAxleloadcatVar->setDefaultValue(0);
        m_mAxleloadcatVar->setRange(0,128);
        m_mLineGaugeVar->setVisible(false);
        m_VariableVect.push_back(m_mAxleloadcatVar);
        m_mAxleloadcatVar->setTobeVisible(false);
        m_mAxleloadcatVar->setVariableBitSize(7);

        nameItem = QString ("M_VOLTAGE");
        m_mVoltageVar =  new package::GraphicVariablePkg ;
        m_mVoltageVar->init(GraphicVariablePkg::type_integer);
        m_mVoltageVar->setNameVariable(nameItem);
        m_mVoltageVar->setInternalName(nameItem);
        m_mVoltageVar->setDefaultValue(0);
        m_mVoltageVar->setRange(0,15);
        m_mVoltageVar->setVisible(false);
        m_VariableVect.push_back(m_mVoltageVar);
        m_mVoltageVar->setTobeVisible(false);
        m_mVoltageVar->setVariableBitSize(4);

        nameItem = QString ("NID_CTRACTION");
        m_nid_CtractionVar =  new package::GraphicVariablePkg ;
        m_nid_CtractionVar->init(GraphicVariablePkg::type_integer);
        m_nid_CtractionVar->setNameVariable(nameItem);
        m_nid_CtractionVar->setInternalName(nameItem);
        m_nid_CtractionVar->setDefaultValue(0);
        m_nid_CtractionVar->setRange(0,1023);
        m_nid_CtractionVar->setVisible(false);
        m_VariableVect.push_back(m_nid_CtractionVar);
        m_nid_CtractionVar->setTobeVisible(false);
        m_nid_CtractionVar->setVariableBitSize(10);

        nameItem = QString ("N_ITER");
        m_nIterVar =  new package::GraphicVariablePkg ;
        m_nIterVar->init(GraphicVariablePkg::type_integer);
        m_nIterVar->setNameVariable(nameItem);
        m_nIterVar->setInternalName(nameItem);
        m_nIterVar->setRange(0,31);
        m_nIterVar->setDefaultValue(0);
        m_nIterVar->setVisible(false);
        m_VariableVect.push_back(m_nIterVar);
        m_nIterVar->setTobeVisible(true);
        m_nIterVar->setVariableBitSize(5);

        qint16 maxValueVariableIter=MAX_ITERATION;
        package::GraphicVariablePkg * dSuitAbilityIterVar=nullptr;
        package::GraphicVariablePkg * qSuiteAbilityIterVar=nullptr;
        package::GraphicVariablePkg * mLinegaugeIterVar=nullptr;
        package::GraphicVariablePkg * mAxleloadcatIterVar=nullptr;
        package::GraphicVariablePkg * mVoltageIterVar=nullptr;
        package::GraphicVariablePkg * mNidCtractionIterVar=nullptr;


        for (int i = 0;i < maxValueVariableIter ;i++) {
            dSuitAbilityIterVar =  new package::GraphicVariablePkg ;
            dSuitAbilityIterVar->init(GraphicVariablePkg::type_integer);
            QString nameItem = QString ("D_SUITABILITY_%1").arg(QString::number(i+1));
            dSuitAbilityIterVar->setNameVariable(nameItem);
            dSuitAbilityIterVar->setInternalName(nameItem);
            dSuitAbilityIterVar->setRange(0,327700);
            dSuitAbilityIterVar->setDefaultValue(0);
            m_VariableVect.push_back(dSuitAbilityIterVar);
            dSuitAbilityIterVar->setVisible(false);
            dSuitAbilityIterVar->setTobeVisible(false);
            dSuitAbilityIterVar->setVariableBitSize(15);


            qSuiteAbilityIterVar =  new package::GraphicVariablePkg ;
            qSuiteAbilityIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("Q_SUITABILITY_%1").arg(QString::number(i+1));
            qSuiteAbilityIterVar->setNameVariable(nameItem);
            qSuiteAbilityIterVar->setInternalName(nameItem);
            qSuiteAbilityIterVar->setRange(0,3);
            qSuiteAbilityIterVar->setDefaultValue(0);
            m_VariableVect.push_back(qSuiteAbilityIterVar);
            qSuiteAbilityIterVar->setVisible(false);
            qSuiteAbilityIterVar->setTobeVisible(false);
            qSuiteAbilityIterVar->setVariableBitSize(2);


            mLinegaugeIterVar =  new package::GraphicVariablePkg ;
            mLinegaugeIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("M_LINEGAUGE_%1").arg(QString::number(i+1));
            mLinegaugeIterVar->setNameVariable(nameItem);
            mLinegaugeIterVar->setInternalName(nameItem);
            mLinegaugeIterVar->setRange(0,255);
            mLinegaugeIterVar->setDefaultValue(0);
            m_VariableVect.push_back(mLinegaugeIterVar);
            mLinegaugeIterVar->setVisible(false);
            mLinegaugeIterVar->setTobeVisible(false);
            mLinegaugeIterVar->setVariableBitSize(8);

            mAxleloadcatIterVar =  new package::GraphicVariablePkg ;
            mAxleloadcatIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("M_AXLELOADCAT_%1").arg(QString::number(i+1));
            mAxleloadcatIterVar->setNameVariable(nameItem);
            mAxleloadcatIterVar->setInternalName(nameItem);
            mAxleloadcatIterVar->setRange(0,128);
            mAxleloadcatIterVar->setDefaultValue(0);
            m_VariableVect.push_back(mAxleloadcatIterVar);
            mAxleloadcatIterVar->setVisible(false);
            mAxleloadcatIterVar->setTobeVisible(false);
            mAxleloadcatIterVar->setVariableBitSize(7);

            mVoltageIterVar =  new package::GraphicVariablePkg ;
            mVoltageIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("M_VOLTAGE_%1").arg(QString::number(i+1));
            mVoltageIterVar->setNameVariable(nameItem);
            mVoltageIterVar->setInternalName(nameItem);
            mVoltageIterVar->setRange(0,15);
            mVoltageIterVar->setDefaultValue(0);
            m_VariableVect.push_back(mVoltageIterVar);
            mVoltageIterVar->setVisible(false);
            mVoltageIterVar->setTobeVisible(false);
            mVoltageIterVar->setVariableBitSize(4);


            mNidCtractionIterVar =  new package::GraphicVariablePkg ;
            mNidCtractionIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("NID_CTRACTION_%1").arg(QString::number(i+1));
            mNidCtractionIterVar->setNameVariable(nameItem);
            mNidCtractionIterVar->setInternalName(nameItem);
            mNidCtractionIterVar->setRange(0,15);
            mNidCtractionIterVar->setDefaultValue(0);
            m_VariableVect.push_back(mNidCtractionIterVar);
            mNidCtractionIterVar->setVisible(false);
            mNidCtractionIterVar->setTobeVisible(false);
            mNidCtractionIterVar->setVariableBitSize(10);
        }

         m_lenPkgVar->setDefaultValue(countPacketBitSize());

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }

        showVariable();

    }
    connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );
    connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );
    connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );
    connect (m_ScaleVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_70_Ver340::handleChangeScaleVariable_SL );
    connect (m_ScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );

    connect (m_qTrackInitVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_70_Ver340::handleChangeQ_TrackInitVariable_SL );
    connect (m_qTrackInitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );

    connect (m_dSuitabilityVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );


    connect (m_qSuitabilityVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_70_Ver340::handleChangeQ_SUITABILITYVariable_SL );
    connect (m_qSuitabilityVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );


    connect (m_mLineGaugeVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );
    connect (m_mAxleloadcatVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );

    connect (m_mVoltageVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_70_Ver340::handleChangeM_Voltage_SL );
    connect (m_mVoltageVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );

    connect (m_nid_CtractionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );

    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::handleChangeIteration_SL );
    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );

    qint16 positionIterateVar = 10;
    qint16 size = m_VariableVect.size();
    for (int i = positionIterateVar ;i < size ;i++) {
        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
        if (nullptr != variable){
            connect (variable,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_70_Ver340::saveData );
            if (variable->internalName().contains("Q_SUITABILITY_")){
                connect (variable,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_70_Ver340::handleChangeQ_SUITABILITY_IterVariable_SL );
            } else if (variable->internalName().contains("M_VOLTAGE_")){
               connect (variable,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_70_Ver340::handleChangeM_VoltageIterVariable_SL );
            }
        }

    }
    return true;

}


void HandlerPackage_70_Ver340::handleChangeIteration_SL()
{

    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("D_SUITABILITY_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;
    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue-numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            QString nameIterateVar = QString ("D_SUITABILITY_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            nameIterateVar = QString ("Q_SUITABILITY_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            nameIterateVar = QString ("M_LINEGAUGE_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);

        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            QString nameIterateVar = QString ("D_SUITABILITY_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            qint16 idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("Q_SUITABILITY_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("M_LINEGAUGE_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("M_AXLELOADCAT_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }
            nameIterateVar = QString ("M_VOLTAGE_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }
            nameIterateVar = QString ("NID_CTRACTION_%1").arg(QString::number(numVisibile));
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
    m_lenPkgVar->setDefaultValue(countPacketBitSize());
    showVariable();
    return ;
}

void HandlerPackage_70_Ver340::handleChangeScaleVariable_SL(QString nameVariable)
{

    //TODO
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        qint16 value = variable->valueOfVariable().toInt();
        qint32 maxValue = 0;
        qint32 minValue = 0;

        if (0 == value || 2 == value) {
            maxValue=327700;
        } else if (1 == value) {

            maxValue=32770;
        } else {
            maxValue=327700;
        }
        m_dSuitabilityVar->setRange(minValue,maxValue);
        m_qTrackInitVar->setRange(minValue,maxValue);
        qint16 positionIterateVar = 11;
        qint16 size = m_VariableVect.size();


        qint8 iteration = 1;
        qint8 numberVariableIterate=2;
        QString nameItem =QString ("D_TRACKCOND_%1").arg(QString::number(iteration));

        for (int i = positionIterateVar ;i < size ;i++) {
            package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
            if (nullptr !=variable ){
                if (nameItem==variable->internalName()) {
                    --numberVariableIterate;
                    variable->setRange(minValue,maxValue);
                    if (numberVariableIterate == 0){
                        iteration++;
                        numberVariableIterate=2;
                        nameItem =QString ("D_TRACKCOND_%1").arg(QString::number(iteration));

                    }else {
                        nameItem =QString ("L_TRACKCOND_%1").arg(QString::number(iteration));
                    }
                }
            }

        }
        showVariable();
    }

}

void HandlerPackage_70_Ver340::handleChangeQ_TrackInitVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        qint16 value = variable->valueOfVariable().toInt();
        if (1 == value ){


            for (int i = 6 ; i < m_VariableVect.size();i++){
                package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
                if (nullptr != variable){
                    variable->setTobeVisible(false);
                    variable->setDefaultValue(0);
                }
            }
            m_dTrackInitVar->setTobeVisible(true);


        } else {
            m_dSuitabilityVar->setTobeVisible(true);
            m_qSuitabilityVar->setTobeVisible(true);
            m_mLineGaugeVar->setTobeVisible(true);
            m_nIterVar->setTobeVisible(true);
            m_dTrackInitVar->setTobeVisible(false);
        }
        m_lenPkgVar->setDefaultValue(countPacketBitSize());
        showVariable();
    }


}

void HandlerPackage_70_Ver340::handleChangeQ_SUITABILITYVariable_SL(QString nameVariable)
{

    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){

         qint16 value = variable->valueOfVariable().toInt();
         if (0 == value){ //loading gauge
             m_mLineGaugeVar->setTobeVisible(true);
             m_mAxleloadcatVar->setTobeVisible(false);
             m_mAxleloadcatVar->setDefaultValue(0);
             m_mVoltageVar->setTobeVisible(false);
             m_mVoltageVar->setDefaultValue(0);
             if (m_nid_CtractionVar->isVisible()){
                 m_nid_CtractionVar->setTobeVisible(false);

             }

         } else if (1== value){//Max axle load
             m_mLineGaugeVar->setTobeVisible(false);
             m_mLineGaugeVar->setDefaultValue(0);
             m_mAxleloadcatVar->setTobeVisible(true);
             m_mVoltageVar->setTobeVisible(false);
             m_mVoltageVar->setDefaultValue(0);
             if (m_nid_CtractionVar->isVisible()){
                 m_nid_CtractionVar->setTobeVisible(false);

             }

         } else if (2 == value){ //traction system
             m_mLineGaugeVar->setTobeVisible(false);
             m_mLineGaugeVar->setDefaultValue(0);
             m_mAxleloadcatVar->setTobeVisible(false);
             m_mAxleloadcatVar->setDefaultValue(0);
             m_mVoltageVar->setTobeVisible(true);



         } else if (3 == value){ //spare
             m_mLineGaugeVar->setTobeVisible(false);
             m_mLineGaugeVar->setDefaultValue(0);

             m_mAxleloadcatVar->setTobeVisible(false);
             m_mAxleloadcatVar->setDefaultValue(0);

             m_mVoltageVar->setTobeVisible(false);
              m_mVoltageVar->setDefaultValue(0);

             m_nid_CtractionVar->setTobeVisible(false);
             m_nid_CtractionVar->setDefaultValue(0);
         }
         m_lenPkgVar->setDefaultValue(countPacketBitSize());
         showVariable();
    }


}

void HandlerPackage_70_Ver340::handleChangeM_Voltage_SL(QString nameVariable)
{
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        qint16 valueVoltage = variable->valueOfVariable().toInt();
        qint16 valueQSuitAbility = m_qSuitabilityVar->valueOfVariable().toInt();

        if (2 == valueQSuitAbility ){ //loading gauge

            if (0 != valueVoltage){
                m_nid_CtractionVar->setTobeVisible(true);
            } else {
                m_nid_CtractionVar->setTobeVisible(false);
                m_nid_CtractionVar->setDefaultValue(0);

            }

        }

        m_lenPkgVar->setDefaultValue(countPacketBitSize());
        showVariable();
    }
}

void HandlerPackage_70_Ver340::handleChangeQ_SUITABILITY_IterVariable_SL(QString nameVariable)
{

    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){

        QStringList parseNameVar = nameVariable.split("_");
        if (parseNameVar.size() ){
            qint16 numberIteration = parseNameVar[parseNameVar.size()-1].toInt();
            qint16 value = variable->valueOfVariable().toInt();
            QString nameIterateVar;
             bool oldvisibleState=false;
             qint16 idx =-1;
            if (0 == value){ //loading gauge

                nameIterateVar = QString ("M_LINEGAUGE_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                variableUpdVisibleState(nameIterateVar,true,oldvisibleState);

                nameIterateVar = QString ("M_AXLELOADCAT_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }

                nameIterateVar = QString ("M_VOLTAGE_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }

                nameIterateVar = QString ("NID_CTRACTION_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }

            } else if (1 == value){ //Max axle load

                nameIterateVar = QString ("M_AXLELOADCAT_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                variableUpdVisibleState(nameIterateVar,true,oldvisibleState);

                nameIterateVar = QString ("M_LINEGAUGE_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }
                nameIterateVar = QString ("M_VOLTAGE_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }

                nameIterateVar = QString ("NID_CTRACTION_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }




            } else if (2 == value){ //traction system

                nameIterateVar = QString ("M_VOLTAGE_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx=variableUpdVisibleState(nameIterateVar,true,oldvisibleState);

                nameIterateVar = QString ("M_LINEGAUGE_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }
                nameIterateVar = QString ("M_AXLELOADCAT_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }
            } else if (3 == value) { //spare

                nameIterateVar = QString ("M_LINEGAUGE_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }

                nameIterateVar = QString ("M_AXLELOADCAT_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }
                nameIterateVar = QString ("M_VOLTAGE_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (oldvisibleState){
                    if (idx != -1 ) {
                        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                        variable->setDefaultValue(0);
                    }
                }

                nameIterateVar = QString ("NID_CTRACTION_%1").arg(QString::number(numberIteration));
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
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

void HandlerPackage_70_Ver340::handleChangeM_VoltageIterVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
         QStringList parseNameVar = nameVariable.split("_");
         if (parseNameVar.size() ){

             qint16 numberIteration = parseNameVar[parseNameVar.size()-1].toInt();
             qint16 idx = -1;
             QString nameIterateVar;
              bool oldvisibleState=false;
             qint16 valueVoltageIerVar = variable->valueOfVariable().toInt();
             qint16 valueQSuitAbilityIterVar = -1;
             nameIterateVar = QString ("Q_SUITABILITY_%1").arg(QString::number(numberIteration));
             variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameIterateVar));
             if (nullptr != variable){
                 valueQSuitAbilityIterVar=variable->valueOfVariable().toInt();
                 if (2==valueQSuitAbilityIterVar){//traction system

                      nameIterateVar = QString ("NID_CTRACTION_%1").arg(QString::number(numberIteration));
                     if ( 0 != valueVoltageIerVar ){
                         variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
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
                 m_lenPkgVar->setDefaultValue(countPacketBitSize());
                 showVariable();
             }

         }
    }

}


void HandlerPackage_70_Ver340::showVariable()
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


bool HandlerPackage_70_Ver340::saveData()
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
void HandlerPackage_70_Ver340::loadPkg()
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


void HandlerPackage_70_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}


}
