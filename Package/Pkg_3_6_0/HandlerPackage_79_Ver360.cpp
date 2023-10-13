#include "HandlerPackage_79_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_79_Ver360::HandlerPackage_79_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_nIterVar = nullptr;
    m_ScaleVar=nullptr;
    m_qNewCountryVar=nullptr;
    m_NidCVar=nullptr;
    m_nidBgVar=nullptr;
    m_dPosOffVar=nullptr;
    m_qMPositionVar=nullptr;
    m_MPositionVar=nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg=79;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_79_Ver360::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    QString nameItem;

    bool ret = false;
    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 79 - " + QString(BASELINE_3_6_0));

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


        nameItem = QString ("Q_NEWCOUNTRY");
        m_qNewCountryVar =  new package::GraphicVariablePkg ;
        m_qNewCountryVar->init(GraphicVariablePkg::type_integer);
        m_qNewCountryVar->setNameVariable(nameItem);
        m_qNewCountryVar->setInternalName(nameItem);
        m_qNewCountryVar->setDefaultValue(0);
        m_qNewCountryVar->setRange(0,1);
        m_qNewCountryVar->setVisible(false);
        m_VariableVect.push_back(m_qNewCountryVar);
        m_qNewCountryVar->setTobeVisible(true);
        m_qNewCountryVar->setVariableBitSize(1);


        nameItem = QString ("NID_C");
        m_NidCVar =  new package::GraphicVariablePkg ;
        m_NidCVar->init(GraphicVariablePkg::type_integer);
        m_NidCVar->setNameVariable(nameItem);
        m_NidCVar->setInternalName(nameItem);
        m_NidCVar->setDefaultValue(0);
        m_NidCVar->setRange(0,1023);
        m_NidCVar->setVisible(false);
        m_VariableVect.push_back(m_NidCVar);
        m_NidCVar->setTobeVisible(false);
        m_NidCVar->setVariableBitSize(10);

        nameItem = QString ("NID_BG");
        m_nidBgVar =  new package::GraphicVariablePkg ;
        m_nidBgVar->init(GraphicVariablePkg::type_integer);
        m_nidBgVar->setNameVariable(nameItem);
        m_nidBgVar->setInternalName(nameItem);
        m_nidBgVar->setDefaultValue(0);
        m_nidBgVar->setRange(0,16383);
        m_nidBgVar->setVisible(false);
        m_VariableVect.push_back(m_nidBgVar);
        m_nidBgVar->setTobeVisible(true);
        m_nidBgVar->setVariableBitSize(14);

        nameItem = QString ("D_POSOFF");
        m_dPosOffVar =  new package::GraphicVariablePkg ;
        m_dPosOffVar->init(GraphicVariablePkg::type_integer);
        m_dPosOffVar->setNameVariable(nameItem);
        m_dPosOffVar->setInternalName(nameItem);
        m_dPosOffVar->setDefaultValue(0);
        m_dPosOffVar->setRange(0,32767);
        m_dPosOffVar->setVisible(false);
        m_VariableVect.push_back(m_dPosOffVar);
        m_dPosOffVar->setTobeVisible(true);
        m_dPosOffVar->setVariableBitSize(15);

        nameItem = QString ("Q_MPOSITION");
        m_qMPositionVar =  new package::GraphicVariablePkg ;
        m_qMPositionVar->init(GraphicVariablePkg::type_integer);
        m_qMPositionVar->setNameVariable(nameItem);
        m_qMPositionVar->setInternalName(nameItem);
        m_qMPositionVar->setDefaultValue(0);
        m_qMPositionVar->setRange(0,1);
        m_qMPositionVar->setVisible(false);
        m_VariableVect.push_back(m_qMPositionVar);
        m_qMPositionVar->setTobeVisible(true);
        m_qMPositionVar->setVariableBitSize(1);

        nameItem = QString ("M_POSITION");
        m_qMPositionVar =  new package::GraphicVariablePkg ;
        m_qMPositionVar->init(GraphicVariablePkg::type_integer);
        m_qMPositionVar->setNameVariable(nameItem);
        m_qMPositionVar->setInternalName(nameItem);
        m_qMPositionVar->setDefaultValue(0);
        m_qMPositionVar->setRange(0,9999999);
        m_qMPositionVar->setVisible(false);
        m_VariableVect.push_back(m_qMPositionVar);
        m_qMPositionVar->setTobeVisible(true);
        m_qMPositionVar->setVariableBitSize(24);

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
        package::GraphicVariablePkg * qNewCountryIterVar=nullptr;
        package::GraphicVariablePkg * nidCIterVar=nullptr;
        package::GraphicVariablePkg * nidBgIterVar=nullptr;
        package::GraphicVariablePkg * dPosOffIterVar=nullptr;
        package::GraphicVariablePkg * qMpositionIterVar=nullptr;
        package::GraphicVariablePkg * mPositionIterVar=nullptr;


        for (int i = 0;i < maxValueVariableIter ;i++) {
            qNewCountryIterVar =  new package::GraphicVariablePkg ;
            qNewCountryIterVar->init(GraphicVariablePkg::type_integer);
            QString nameItem = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(i+1));
            qNewCountryIterVar->setNameVariable(nameItem);
            qNewCountryIterVar->setInternalName(nameItem);
            qNewCountryIterVar->setRange(0,1);
            qNewCountryIterVar->setDefaultValue(0);
            m_VariableVect.push_back(qNewCountryIterVar);
            qNewCountryIterVar->setVisible(false);
            qNewCountryIterVar->setTobeVisible(false);
            qNewCountryIterVar->setVariableBitSize(1);


            nidCIterVar =  new package::GraphicVariablePkg ;
            nidCIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("NID_C_%1").arg(QString::number(i+1));
            nidCIterVar->setNameVariable(nameItem);
            nidCIterVar->setInternalName(nameItem);
            nidCIterVar->setRange(0,1023);
            nidCIterVar->setDefaultValue(0);
            m_VariableVect.push_back(nidCIterVar);
            nidCIterVar->setVisible(false);
            nidCIterVar->setTobeVisible(false);
            nidCIterVar->setVariableBitSize(10);


            nidBgIterVar =  new package::GraphicVariablePkg ;
            nidBgIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("NID_BG_%1").arg(QString::number(i+1));
            nidBgIterVar->setNameVariable(nameItem);
            nidBgIterVar->setInternalName(nameItem);
            nidBgIterVar->setRange(0,16383);
            nidBgIterVar->setDefaultValue(0);
            m_VariableVect.push_back(nidBgIterVar);
            nidBgIterVar->setVisible(false);
            nidBgIterVar->setTobeVisible(false);
            nidBgIterVar->setVariableBitSize(14);

            dPosOffIterVar =  new package::GraphicVariablePkg ;
            dPosOffIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("D_POSOFF_%1").arg(QString::number(i+1));
            dPosOffIterVar->setNameVariable(nameItem);
            dPosOffIterVar->setInternalName(nameItem);
            dPosOffIterVar->setRange(0,32767);
            dPosOffIterVar->setDefaultValue(0);
            m_VariableVect.push_back(dPosOffIterVar);
            dPosOffIterVar->setVisible(false);
            dPosOffIterVar->setTobeVisible(false);
            dPosOffIterVar->setVariableBitSize(15);

            qMpositionIterVar =  new package::GraphicVariablePkg ;
            qMpositionIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("Q_MPOSITION_%1").arg(QString::number(i+1));
            qMpositionIterVar->setNameVariable(nameItem);
            qMpositionIterVar->setInternalName(nameItem);
            qMpositionIterVar->setRange(0,1);
            qMpositionIterVar->setDefaultValue(0);
            m_VariableVect.push_back(qMpositionIterVar);
            qMpositionIterVar->setVisible(false);
            qMpositionIterVar->setTobeVisible(false);
            qMpositionIterVar->setVariableBitSize(1);


            mPositionIterVar =  new package::GraphicVariablePkg ;
            mPositionIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("M_POSITION_%1").arg(QString::number(i+1));
            mPositionIterVar->setNameVariable(nameItem);
            mPositionIterVar->setInternalName(nameItem);
            mPositionIterVar->setRange(0,9999999);
            mPositionIterVar->setDefaultValue(0);
            m_VariableVect.push_back(mPositionIterVar);
            mPositionIterVar->setVisible(false);
            mPositionIterVar->setTobeVisible(false);
            mPositionIterVar->setVariableBitSize(24);
        }

         m_lenPkgVar->setDefaultValue(countPacketBitSize());

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }

        showVariable();
        ret= saveData();
        connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );
        connect (m_ScaleVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_79_Ver360::handleChangeScaleVariable_SL );
        connect (m_ScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );

        connect (m_qNewCountryVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_79_Ver360::handleChangeQ_NewCountryVariable_SL );
        connect (m_qNewCountryVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );
        connect (m_NidCVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );
        connect (m_nidBgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );

        connect (m_dPosOffVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );
        connect (m_qMPositionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );
        connect (m_MPositionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::handleChangeIteration_SL );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );


        qint16 positionIterateVar = 11;
        qint16 size = m_VariableVect.size();
        for (int i = positionIterateVar ;i < size ;i++) {
            package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
            if (nullptr != variable){

                if (variable->internalName().contains("Q_NEWCOUNTRY_")){
                    connect (variable,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_79_Ver360::handleChangeQ_NewCountryIterVariable_SL );
                }
                connect (variable,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_79_Ver360::saveData );
            }
        }
    }
    return ret;

}


void HandlerPackage_79_Ver360::handleChangeIteration_SL()
{

    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("Q_NEWCOUNTRY_");

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue-numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            QString nameIterateVar = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            nameIterateVar = QString ("NID_BG_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            nameIterateVar = QString ("D_POSOFF_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("Q_MPOSITION_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("M_POSITION_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);


        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            QString nameIterateVar = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            qint16 idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("NID_C_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("NID_BG_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("D_POSOFF_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }
            nameIterateVar = QString ("Q_MPOSITION_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }
            nameIterateVar = QString ("M_POSITION_%1").arg(QString::number(numVisibile));
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

void HandlerPackage_79_Ver360::handleChangeScaleVariable_SL(QString nameVariable)
{

    //TODO
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        qint16 value = variable->valueOfVariable().toInt();
        qint32 maxValue = 0;
        qint32 minValue = 0;

        if (0 == value || 2 == value) {
            maxValue=327790;
        } else if (1 == value) {

            maxValue=32779;
        } else {
            maxValue=327790;
        }
        m_nidBgVar->setRange(minValue,maxValue);
        m_qNewCountryVar->setRange(minValue,maxValue);
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

void HandlerPackage_79_Ver360::handleChangeQ_NewCountryVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
     if (nullptr != variable){

         qint16 value = variable->valueOfVariable().toInt();
         if (1 == value ){
             m_NidCVar->setTobeVisible(true);

         } else {
             m_NidCVar->setTobeVisible(0);
             m_NidCVar->setDefaultValue(0);
         }
         m_lenPkgVar->setDefaultValue(countPacketBitSize());
         showVariable();
     }
}

void HandlerPackage_79_Ver360::handleChangeQ_NewCountryIterVariable_SL(QString nameVariable)
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
            nameIterateVar = QString ("NID_C_%1").arg(QString::number(numberIteration));

            if (1 == value ){
                variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
                variableUpdVisibleState(nameIterateVar,true,oldvisibleState);

            } else {
                idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }
            m_lenPkgVar->setDefaultValue(countPacketBitSize());
            showVariable();

        }
    }

}


void HandlerPackage_79_Ver360::showVariable()
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
bool HandlerPackage_79_Ver360::saveData()
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
void HandlerPackage_79_Ver360::loadPkg()
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


void HandlerPackage_79_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}


}
