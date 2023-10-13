#include "HandlerPackage_49_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_49_Ver340::HandlerPackage_49_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_nIterVar = nullptr;


    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=49;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_49_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    QString nameItem;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 49 - " + QString(BASELINE_3_4_0));

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
        package::GraphicVariablePkg * nidBGIterVar=nullptr;


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
            nidCIterVar->set_NID_C();
            nameItem = QString ("NID_C_%1").arg(QString::number(i+1));
            nidCIterVar->setNameVariable(nameItem);
            nidCIterVar->setInternalName(nameItem);
            nidCIterVar->setVisible(false);
            nidCIterVar->setTobeVisible(false);
            m_VariableVect.push_back(nidCIterVar);

            nidBGIterVar =  new package::GraphicVariablePkg ;
            nidBGIterVar->set_NID_BG();
            nameItem = QString ("NID_BG_%1").arg(QString::number(i+1));
            nidBGIterVar->setNameVariable(nameItem);
            nidBGIterVar->setInternalName(nameItem);
            nidBGIterVar->setVisible(false);
            nidBGIterVar->setTobeVisible(false);
            m_VariableVect.push_back(nidBGIterVar);

        }

         m_lenPkgVar->setDefaultValue(countPacketBitSize());

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }

        showVariable();

    }
    connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_49_Ver340::saveData );
    connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_49_Ver340::saveData );
    connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_49_Ver340::saveData );

    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_49_Ver340::handleChangeIteration_SL );
    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_49_Ver340::saveData );

    qint16 positionIterateVar = 4;
    qint16 size = m_VariableVect.size();
    for (int i = positionIterateVar ;i < size ;i++) {
        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
        if (nullptr != variable){
            connect (variable,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_49_Ver340::saveData );
            if (variable->internalName().contains("Q_NEWCOUNTRY_")){
                connect (variable,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_49_Ver340::handleChangeQ_NewCountry_IterVariable_SL );
            }
        }

    }
    return true;

}


void HandlerPackage_49_Ver340::handleChangeIteration_SL()
{

    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("Q_NEWCOUNTRY_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;
    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue-numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            QString nameIterateVar = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            nameIterateVar = QString ("NID_BG_%1").arg(QString::number(numVisibile+i+1));
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
            numVisibile--;
        }
    }
    m_lenPkgVar->setDefaultValue(countPacketBitSize());
    showVariable();
    return ;
}

void HandlerPackage_49_Ver340::handleChangeQ_NewCountry_IterVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        QStringList parseNameVar = nameVariable.split("_");
        if (parseNameVar.size() ){
            qint16 numberIteration = parseNameVar[parseNameVar.size()-1].toInt();
            qint16 value = variable->valueOfVariable().toInt();
            QString nameIterateVar;
             bool oldvisibleState=false;
              nameIterateVar = QString ("NID_C_%1").arg(QString::number(numberIteration));
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
        m_lenPkgVar->setDefaultValue(countPacketBitSize());
        showVariable();
    }

}

void HandlerPackage_49_Ver340::showVariable()
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


bool HandlerPackage_49_Ver340::saveData()
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
void HandlerPackage_49_Ver340::loadPkg()
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


void HandlerPackage_49_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}


}
