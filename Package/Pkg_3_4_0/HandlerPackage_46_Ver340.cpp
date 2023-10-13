#include "HandlerPackage_46_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_46_Ver340::HandlerPackage_46_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_mLevelTrVar=nullptr;
    m_NidNtcVar=nullptr;
    m_nIterVar = nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=46;
    m_maxColumnVariable=2;
    m_isReload=false;
}

bool HandlerPackage_46_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 46 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->init(GraphicVariablePkg::type_integer);
        m_nidPkgVar->setNameVariable("NID_PACKET");
        m_nidPkgVar->setIsOnlyRead(true);
        m_nidPkgVar->setDefaultValue(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);
        m_nidPkgVar->setVisible(false);
        m_nidPkgVar->setTobeVisible(true);
        connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::saveData );


        m_qDirVar =  new package::GraphicVariablePkg ;
        m_qDirVar->init(GraphicVariablePkg::type_integer);
        m_qDirVar->setNameVariable("Q_DIR");
        m_qDirVar->setRange(0,3);
        m_qDirVar->setDefaultValue(0);
        m_qDirVar->setVisible(false);
        m_VariableVect.push_back(m_qDirVar);
        m_qDirVar->setTobeVisible(true);


        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->init(GraphicVariablePkg::type_integer);
        m_lenPkgVar->setNameVariable("L_PACKET");
        m_lenPkgVar->setIsOnlyRead(true);
        m_lenPkgVar->setDefaultValue(32);
        m_lenPkgVar->setVisible(false);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::saveData );
        m_lenPkgVar->setTobeVisible(true);

        m_mLevelTrVar =  new package::GraphicVariablePkg ;
        m_mLevelTrVar->init(GraphicVariablePkg::type_integer);
        m_mLevelTrVar->setNameVariable("M_LEVELTR");
        m_mLevelTrVar->setRange(0,4);
        m_mLevelTrVar->setDefaultValue(0);
        m_mLevelTrVar->setVisible(false);
        m_VariableVect.push_back(m_mLevelTrVar);
        connect (m_mLevelTrVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::showNid_Ntc_SL );
        connect (m_mLevelTrVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::saveData );
        m_mLevelTrVar->setTobeVisible(true);

        m_NidNtcVar =  new package::GraphicVariablePkg ;
        m_NidNtcVar->init(GraphicVariablePkg::type_integer);
        m_NidNtcVar->setNameVariable("NID_NTC");
        m_NidNtcVar->setRange(0,255);
        m_NidNtcVar->setDefaultValue(0);
        m_VariableVect.push_back(m_NidNtcVar);
        m_NidNtcVar->setVisible(false);
        connect (m_NidNtcVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::saveData );
        m_NidNtcVar->setTobeVisible(false);

        m_nIterVar =  new package::GraphicVariablePkg ;
        m_nIterVar->init(GraphicVariablePkg::type_integer);
        m_nIterVar->setNameVariable("N_ITER");
        m_nIterVar->setRange(0,31);
        m_nIterVar->setDefaultValue(0);
        m_nIterVar->setVisible(false);
        m_VariableVect.push_back(m_nIterVar);
        m_nIterVar->setTobeVisible(true);


        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::handleChangeIteration_SL );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::saveData );

        qint16 maxValueVariableIter=31;
        package::GraphicVariablePkg * levelTrVar=nullptr;
        package::GraphicVariablePkg * nidNtcVar=nullptr;

        for (int i = 0;i < maxValueVariableIter ;i++) {
            levelTrVar =  new package::GraphicVariablePkg ;
            levelTrVar->init(GraphicVariablePkg::type_integer);
            QString nameItem = QString ("M_LEVELTR_%1").arg(QString::number(i+1));
            levelTrVar->setNameVariable(nameItem);
            levelTrVar->setInternalName(nameItem);
            levelTrVar->setRange(0,4);
            levelTrVar->setDefaultValue(0);
            m_VariableVect.push_back(levelTrVar);
            levelTrVar->setVisible(false);
            levelTrVar->setTobeVisible(false);
            connect (levelTrVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_46_Ver340::handleIterateVariable_SL );
            connect (levelTrVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::saveData );


            nidNtcVar =  new package::GraphicVariablePkg ;
            nidNtcVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("NID_NTC_%1").arg(QString::number(i+1));
            nidNtcVar->setNameVariable(nameItem);
            nidNtcVar->setInternalName(nameItem);

            nidNtcVar->setRange(0,255);
            nidNtcVar->setDefaultValue(0);
            m_VariableVect.push_back(nidNtcVar);
            nidNtcVar->setVisible(false);
            nidNtcVar->setTobeVisible(false);

            connect (nidNtcVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_46_Ver340::saveData );


        }
        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();

    }
    return true;

}
void HandlerPackage_46_Ver340::loadPkg()
{
        storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
        storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
        if (pkg != nullptr){
            m_isReload=false;
            QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
            qint16 size = dataList.size();
            if (size >= 6 ){
                m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
                m_qDirVar->setDefaultValue( dataList.at(1).toInt());
                m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
                m_mLevelTrVar->setDefaultValue( dataList.at(3).toInt() );
                if ( 1 == dataList.at(3).toInt() ){
                    m_NidNtcVar->setTobeVisible(true);
                    m_NidNtcVar->setDefaultValue(dataList.at(4).toInt());

                } else {

                    m_NidNtcVar->setTobeVisible(false);
                    m_NidNtcVar->setDefaultValue(0);
                }
                qint16 numIteration=dataList.at(5).toInt();
                //Ogni iterazione ha 2 campi
                qint16 sizeIterate = ( numIteration* 2)+6;
                m_nIterVar->setDefaultValue(numIteration);
                if (sizeIterate <= size && size <= m_VariableVect.size()){
                    for (int i =6;i < size;i++){
                        package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
                        if (nullptr != variable){
                            if (dataList.at(i)!= EMPTY_VALUE){
                                variable->setDefaultValue(dataList.at(i).toInt());
                                variable->setTobeVisible(true);
                            } else {
                                variable->setTobeVisible(false);

                            }

                        }

                    }

                }

            }
        }

}
void HandlerPackage_46_Ver340::showNid_Ntc_SL()
{
    qDebug () <<  m_mLevelTrVar->valueOfVariable().toInt();
    if (1 == m_mLevelTrVar->valueOfVariable().toInt()){
        m_NidNtcVar->setTobeVisible(true);
        m_lenPkgVar->setDefaultValue(40);
    } else {
        m_NidNtcVar->setTobeVisible(false);
        m_lenPkgVar->setDefaultValue(32);
    }
    showVariable();

}

void HandlerPackage_46_Ver340::handleChangeIteration_SL()
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
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()+ 3;
            m_lenPkgVar->setDefaultValue(updLen);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            QString nameIterateVar = QString ("M_LEVELTR_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 3;
                m_lenPkgVar->setDefaultValue(updLen);

            }

            nameIterateVar = QString ("NID_NTC_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 8;
                m_lenPkgVar->setDefaultValue(updLen);

            }
            numVisibile--;

        }
    }
    showVariable();
    return ;
}

void HandlerPackage_46_Ver340::handleIterateVariable_SL(QString nameVariable)
{

    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< variable->valueOfVariable();
    qint16 value = variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString nidNtcIterate = QString ("NID_NTC_%1").arg(parseNameVar[parseNameVar.size()-1]);
        bool notUsed;
        if (1 == value ){
            //Marca l'item a  visibile

            variableUpdVisibleState(nidNtcIterate,true,notUsed);
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()+ 8;
            m_lenPkgVar->setDefaultValue(updLen);

        } else {
            //Marca l'item a non visibile
            variableUpdVisibleState(nidNtcIterate,false,notUsed);
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 8;
            m_lenPkgVar->setDefaultValue(updLen);
        }
    }

    showVariable();
}

void HandlerPackage_46_Ver340::showVariable()
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


bool HandlerPackage_46_Ver340::saveData()
{

    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_mLevelTrVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    if (m_NidNtcVar->isVisible()){

        data+=m_NidNtcVar->valueOfVariable();
    } else{
        data+=EMPTY_VALUE;
    }
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nIterVar->valueOfVariable();


    qint16 numIteration = m_nIterVar->valueOfVariable().toInt();
    qint16 sizeIterate = ( numIteration* 2);
    if (sizeIterate+6 <=m_VariableVect.size()){
        for (int i =0; i < sizeIterate;i++ ){
            package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i+6));
            data+=INTERNAL_FIELD_SEPARATOR_PKG;
            if (variable->tobeVisible()){
                data+=variable->valueOfVariable();
            } else {
                data+=EMPTY_VALUE;
            }

        }

    }



    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;


    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;

}

void HandlerPackage_46_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}


}
