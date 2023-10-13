#include "HandlerPackage_80_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_80_Ver340::HandlerPackage_80_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_nIterVar = nullptr;
    m_ScaleVar=nullptr;
    m_dMaModeVar=nullptr;
    m_mMaModeVar=nullptr;
    m_vMaModeVar=nullptr;
    m_lMaModeVar=nullptr;
    m_lAckMaModeVar=nullptr;
    m_qMaModeVar=nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=80;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_80_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    QString nameItem;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 80 - " + QString(BASELINE_3_4_0));

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


        nameItem = QString ("D_MAMODE");
        m_dMaModeVar =  new package::GraphicVariablePkg ;
        m_dMaModeVar->init(GraphicVariablePkg::type_integer);
        m_dMaModeVar->setNameVariable(nameItem);
        m_dMaModeVar->setInternalName(nameItem);
        m_dMaModeVar->setDefaultValue(0);
        m_dMaModeVar->setRange(0,32767);
        m_dMaModeVar->setVisible(false);
        m_VariableVect.push_back(m_dMaModeVar);
        m_dMaModeVar->setTobeVisible(true);
        m_dMaModeVar->setVariableBitSize(15);


        nameItem = QString ("M_MAMODE");
        m_mMaModeVar =  new package::GraphicVariablePkg ;
        m_mMaModeVar->init(GraphicVariablePkg::type_integer);
        m_mMaModeVar->setNameVariable(nameItem);
        m_mMaModeVar->setInternalName(nameItem);
        m_mMaModeVar->setDefaultValue(0);
        m_mMaModeVar->setRange(0,4);
        m_mMaModeVar->setVisible(false);
        m_VariableVect.push_back(m_mMaModeVar);
        m_mMaModeVar->setTobeVisible(true);
        m_mMaModeVar->setVariableBitSize(2);

        nameItem = QString ("V_MAMODE");
        m_vMaModeVar =  new package::GraphicVariablePkg ;
        m_vMaModeVar->init(GraphicVariablePkg::type_integer);
        m_vMaModeVar->setNameVariable(nameItem);
        m_vMaModeVar->setInternalName(nameItem);
        m_vMaModeVar->setDefaultValue(0);
        m_vMaModeVar->setRange(0,127);
        m_vMaModeVar->setVisible(false);
        m_VariableVect.push_back(m_vMaModeVar);
        m_vMaModeVar->setTobeVisible(true);
        m_vMaModeVar->setVariableBitSize(7);

        nameItem = QString ("L_MAMODE");
        m_lMaModeVar =  new package::GraphicVariablePkg ;
        m_lMaModeVar->init(GraphicVariablePkg::type_integer);
        m_lMaModeVar->setNameVariable(nameItem);
        m_lMaModeVar->setInternalName(nameItem);
        m_lMaModeVar->setDefaultValue(0);
        m_lMaModeVar->setRange(0,32767);
        m_lMaModeVar->setVisible(false);
        m_VariableVect.push_back(m_lMaModeVar);
        m_lMaModeVar->setTobeVisible(true);
        m_lMaModeVar->setVariableBitSize(15);

        nameItem = QString ("L_ACKMAMODE");
        m_lAckMaModeVar =  new package::GraphicVariablePkg ;
        m_lAckMaModeVar->init(GraphicVariablePkg::type_integer);
        m_lAckMaModeVar->setNameVariable(nameItem);
        m_lAckMaModeVar->setInternalName(nameItem);
        m_lAckMaModeVar->setDefaultValue(0);
        m_lAckMaModeVar->setRange(0,32767);
        m_lAckMaModeVar->setVisible(false);
        m_VariableVect.push_back(m_lAckMaModeVar);
        m_lAckMaModeVar->setTobeVisible(true);
        m_lAckMaModeVar->setVariableBitSize(15);

        nameItem = QString ("Q_MAMODE");
        m_lAckMaModeVar =  new package::GraphicVariablePkg ;
        m_lAckMaModeVar->init(GraphicVariablePkg::type_integer);
        m_lAckMaModeVar->setNameVariable(nameItem);
        m_lAckMaModeVar->setInternalName(nameItem);
        m_lAckMaModeVar->setDefaultValue(0);
        m_lAckMaModeVar->setRange(0,1);
        m_lAckMaModeVar->setVisible(false);
        m_VariableVect.push_back(m_lAckMaModeVar);
        m_lAckMaModeVar->setTobeVisible(true);
        m_lAckMaModeVar->setVariableBitSize(1);

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
        package::GraphicVariablePkg * dMaModeIterVar=nullptr;
        package::GraphicVariablePkg * mMaModeIterVar=nullptr;
        package::GraphicVariablePkg * vMaModeIterVar=nullptr;
        package::GraphicVariablePkg * lMaModeIterVar=nullptr;
        package::GraphicVariablePkg * lAckMaModeIterVar=nullptr;
        package::GraphicVariablePkg * qMaModeIterVar=nullptr;


        for (int i = 0;i < maxValueVariableIter ;i++) {
            dMaModeIterVar =  new package::GraphicVariablePkg ;
            dMaModeIterVar->init(GraphicVariablePkg::type_integer);
            QString nameItem = QString ("D_MAMODE_%1").arg(QString::number(i+1));
            dMaModeIterVar->setNameVariable(nameItem);
            dMaModeIterVar->setInternalName(nameItem);
            dMaModeIterVar->setRange(0,32767);
            dMaModeIterVar->setDefaultValue(0);
            m_VariableVect.push_back(dMaModeIterVar);
            dMaModeIterVar->setVisible(false);
            dMaModeIterVar->setTobeVisible(false);
            dMaModeIterVar->setVariableBitSize(15);


            mMaModeIterVar =  new package::GraphicVariablePkg ;
            mMaModeIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("M_MAMODE_%1").arg(QString::number(i+1));
            mMaModeIterVar->setNameVariable(nameItem);
            mMaModeIterVar->setInternalName(nameItem);
            mMaModeIterVar->setRange(0,4);
            mMaModeIterVar->setDefaultValue(0);
            m_VariableVect.push_back(mMaModeIterVar);
            mMaModeIterVar->setVisible(false);
            mMaModeIterVar->setTobeVisible(false);
            mMaModeIterVar->setVariableBitSize(2);


            vMaModeIterVar =  new package::GraphicVariablePkg ;
            vMaModeIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("V_MAMODE_%1").arg(QString::number(i+1));
            vMaModeIterVar->setNameVariable(nameItem);
            vMaModeIterVar->setInternalName(nameItem);
            vMaModeIterVar->setRange(0,127);
            vMaModeIterVar->setDefaultValue(0);
            m_VariableVect.push_back(vMaModeIterVar);
            vMaModeIterVar->setVisible(false);
            vMaModeIterVar->setTobeVisible(false);
            vMaModeIterVar->setVariableBitSize(7);

            lMaModeIterVar =  new package::GraphicVariablePkg ;
            lMaModeIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("L_MAMODE_%1").arg(QString::number(i+1));
            lMaModeIterVar->setNameVariable(nameItem);
            lMaModeIterVar->setInternalName(nameItem);
            lMaModeIterVar->setRange(0,32767);
            lMaModeIterVar->setDefaultValue(0);
            m_VariableVect.push_back(lMaModeIterVar);
            lMaModeIterVar->setVisible(false);
            lMaModeIterVar->setTobeVisible(false);
            lMaModeIterVar->setVariableBitSize(15);

            lAckMaModeIterVar =  new package::GraphicVariablePkg ;
            lAckMaModeIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("L_ACKMAMODE_%1").arg(QString::number(i+1));
            lAckMaModeIterVar->setNameVariable(nameItem);
            lAckMaModeIterVar->setInternalName(nameItem);
            lAckMaModeIterVar->setRange(0,32767);
            lAckMaModeIterVar->setDefaultValue(0);
            m_VariableVect.push_back(lAckMaModeIterVar);
            lAckMaModeIterVar->setVisible(false);
            lAckMaModeIterVar->setTobeVisible(false);
            lAckMaModeIterVar->setVariableBitSize(15);


            qMaModeIterVar =  new package::GraphicVariablePkg ;
            qMaModeIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("Q_MAMODE_%1").arg(QString::number(i+1));
            qMaModeIterVar->setNameVariable(nameItem);
            qMaModeIterVar->setInternalName(nameItem);
            qMaModeIterVar->setRange(0,1);
            qMaModeIterVar->setDefaultValue(0);
            m_VariableVect.push_back(qMaModeIterVar);
            qMaModeIterVar->setVisible(false);
            qMaModeIterVar->setTobeVisible(false);
            qMaModeIterVar->setVariableBitSize(1);
        }

         m_lenPkgVar->setDefaultValue(countPacketBitSize());

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }

        showVariable();

    }
    connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );
    connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );
    connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );
    connect (m_ScaleVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_80_Ver340::handleChangeScaleVariable_SL );
    connect (m_ScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );

    connect (m_dMaModeVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );
    connect (m_mMaModeVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );
    connect (m_vMaModeVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );

    connect (m_lMaModeVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );
    connect (m_lAckMaModeVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );
    connect (m_qMaModeVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );
    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::handleChangeIteration_SL );
    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );


    qint16 positionIterateVar = 11;
    qint16 size = m_VariableVect.size();
    for (int i = positionIterateVar ;i < size ;i++) {
        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
        if (nullptr != variable){
            connect (variable,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_80_Ver340::saveData );
        }
    }
    return true;

}


void HandlerPackage_80_Ver340::handleChangeIteration_SL()
{

    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("D_MAMODE_");

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue-numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            QString nameIterateVar = QString ("D_MAMODE_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            nameIterateVar = QString ("M_MAMODE_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            nameIterateVar = QString ("V_MAMODE_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("L_MAMODE_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("L_ACKMAMODE_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("Q_MAMODE_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);


        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            QString nameIterateVar = QString ("D_MAMODE_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            qint16 idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("M_MAMODE_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("V_MAMODE_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("L_MAMODE_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }
            nameIterateVar = QString ("L_ACKMAMODE_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }
            nameIterateVar = QString ("Q_MAMODE_%1").arg(QString::number(numVisibile));
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

void HandlerPackage_80_Ver340::handleChangeScaleVariable_SL(QString nameVariable)
{

    //TODO
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        qint16 value = variable->valueOfVariable().toInt();
        qint32 maxValue = 0;
        qint32 minValue = 0;

        if (0 == value || 2 == value) {
            maxValue=327800;
        } else if (1 == value) {

            maxValue=32780;
        } else {
            maxValue=327800;
        }
        m_vMaModeVar->setRange(minValue,maxValue);
        m_dMaModeVar->setRange(minValue,maxValue);
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
void HandlerPackage_80_Ver340::showVariable()
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
bool HandlerPackage_80_Ver340::saveData()
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
void HandlerPackage_80_Ver340::loadPkg()
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


void HandlerPackage_80_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}


}
