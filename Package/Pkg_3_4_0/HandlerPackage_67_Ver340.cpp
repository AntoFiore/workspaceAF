#include "HandlerPackage_67_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_67_Ver340::HandlerPackage_67_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_nIterVar = nullptr;
    m_ScaleVar=nullptr;
    m_dTrackCond=nullptr;
    m_lTrackCond=nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=67;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_67_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 67 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->init(GraphicVariablePkg::type_integer);
        m_nidPkgVar->setNameVariable("NID_PACKET");
        m_nidPkgVar->setIsOnlyRead(true);
        m_nidPkgVar->setDefaultValue(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);
        m_nidPkgVar->setVisible(false);
        m_nidPkgVar->setTobeVisible(true);


        m_qDirVar =  new package::GraphicVariablePkg ;
        m_qDirVar->init(GraphicVariablePkg::type_integer);
        m_qDirVar->setNameVariable("Q_DIR");
        m_qDirVar->setRange(0,3);
        m_qDirVar->setDefaultValue(0);
        m_qDirVar->setVisible(false);
        m_VariableVect.push_back(m_qDirVar);
        m_qDirVar->setTobeVisible(true);


        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->init(GraphicVariablePkg::type_integer);
        m_lenPkgVar->setNameVariable("L_PACKET");
        m_lenPkgVar->setIsOnlyRead(true);
        m_lenPkgVar->setDefaultValue(60);
        m_lenPkgVar->setRange(0,8192);
        m_lenPkgVar->setVisible(false);
        m_VariableVect.push_back(m_lenPkgVar);
        m_lenPkgVar->setTobeVisible(true);

        m_ScaleVar =  new package::GraphicVariablePkg ;
        m_ScaleVar->init(GraphicVariablePkg::type_integer);
        m_ScaleVar->setNameVariable("Q_SCALE");
        m_ScaleVar->setDefaultValue(0);
        m_ScaleVar->setRange(0,3);
        m_ScaleVar->setVisible(false);
        m_VariableVect.push_back(m_ScaleVar);
        m_ScaleVar->setTobeVisible(true);

        m_dTrackCond =  new package::GraphicVariablePkg ;
        m_dTrackCond->init(GraphicVariablePkg::type_integer);
        m_dTrackCond->setNameVariable("D_TRACKCOND");
        m_dTrackCond->setDefaultValue(0);
        m_dTrackCond->setRange(0,327670);
        m_dTrackCond->setVisible(false);
        m_VariableVect.push_back(m_dTrackCond);
        m_dTrackCond->setTobeVisible(true);

        m_lTrackCond =  new package::GraphicVariablePkg ;
        m_lTrackCond->init(GraphicVariablePkg::type_integer);
        m_lTrackCond->setNameVariable("L_TRACKCOND");
        m_lTrackCond->setDefaultValue(0);
        m_lTrackCond->setRange(0,327670);
        m_lTrackCond->setVisible(false);
        m_VariableVect.push_back(m_lTrackCond);
        m_lTrackCond->setTobeVisible(true);

        m_nIterVar =  new package::GraphicVariablePkg ;
        m_nIterVar->init(GraphicVariablePkg::type_integer);
        m_nIterVar->setNameVariable("N_ITER");
        m_nIterVar->setRange(0,31);
        m_nIterVar->setDefaultValue(0);
        m_nIterVar->setVisible(false);
        m_VariableVect.push_back(m_nIterVar);
        m_nIterVar->setTobeVisible(true);

        qint16 maxValueVariableIter=MAX_ITERATION;
        package::GraphicVariablePkg * dTrackCondIter=nullptr;
        package::GraphicVariablePkg * lTrackCondIter=nullptr;

        for (int i = 0;i < maxValueVariableIter ;i++) {
            dTrackCondIter =  new package::GraphicVariablePkg ;
            dTrackCondIter->init(GraphicVariablePkg::type_integer);
            QString nameItem = QString ("D_TRACKCOND_%1").arg(QString::number(i+1));
            dTrackCondIter->setNameVariable(nameItem);
            dTrackCondIter->setInternalName(nameItem);
            dTrackCondIter->setRange(0,327670);
            dTrackCondIter->setDefaultValue(0);
            m_VariableVect.push_back(dTrackCondIter);
            dTrackCondIter->setVisible(false);
            dTrackCondIter->setTobeVisible(false);

            lTrackCondIter =  new package::GraphicVariablePkg ;
            lTrackCondIter->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("L_TRACKCOND_%1").arg(QString::number(i+1));
            lTrackCondIter->setNameVariable(nameItem);
            lTrackCondIter->setInternalName(nameItem);
            lTrackCondIter->setRange(0,327670);
            lTrackCondIter->setDefaultValue(0);
            m_VariableVect.push_back(lTrackCondIter);
            lTrackCondIter->setVisible(false);
            lTrackCondIter->setTobeVisible(false);


        }

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }

        showVariable();

    }
    connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_67_Ver340::saveData );
    connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_67_Ver340::saveData );
    connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_67_Ver340::saveData );
    connect (m_ScaleVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_67_Ver340::handleIterateVariable_SL );
    connect (m_ScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_67_Ver340::saveData );
    connect (m_dTrackCond,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_67_Ver340::saveData );
    connect (m_lTrackCond,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_67_Ver340::saveData );

    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_67_Ver340::handleChangeIteration_SL );
    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_67_Ver340::saveData );


    qint16 positionIterateVar = 6;
    qint16 size = m_VariableVect.size();
    for (int i = positionIterateVar ;i < size ;i++) {
        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
        if (nullptr != variable){
            connect (variable,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_67_Ver340::saveData );
        }

    }
    return true;

}
void HandlerPackage_67_Ver340::loadPkg()
{
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){

        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        qint16 size = dataList.size();
        qint8 positionIterate=7;
        qint8 numberVariableIterate=2;
        m_isReload=false;

        if (size >=7)
        {
            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
            m_ScaleVar->setDefaultValue( dataList.at(3).toInt());
            m_dTrackCond->setDefaultValue( dataList.at(4).toInt());
            m_lTrackCond->setDefaultValue( dataList.at(5).toInt());
            qint16 numIteration = dataList.at(6).toInt();
            m_nIterVar->setDefaultValue( numIteration );

            qint16 sizeIterate = ( numIteration * numberVariableIterate);
            if (( sizeIterate+positionIterate ) <= m_VariableVect.size()){
                for (int i = 0;i < sizeIterate ;i++ ){
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(positionIterate+i));
                    if (nullptr != variable ){

                        if (dataList.at(positionIterate+i) != EMPTY_VALUE){

                            variable->setTobeVisible(true);
                            variable->setDefaultValue(dataList.at(positionIterate+i).toInt());
                        } else {
                            variable->setTobeVisible(false);
                            variable->setDefaultValue(0);
                        }

                    }

                }

            }

        }
    }

}


void HandlerPackage_67_Ver340::handleChangeIteration_SL()
{

    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("D_TRACKCOND_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;
    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue-numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            QString nameIterateVar = QString ("D_TRACKCOND_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()+ 15;
            m_lenPkgVar->setDefaultValue(updLen);


            nameIterateVar = QString ("L_TRACKCOND_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = m_lenPkgVar->valueOfVariable().toInt()+ 15;
            m_lenPkgVar->setDefaultValue(updLen);


        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            QString nameIterateVar = QString ("D_TRACKCOND_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            qint16 idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 15;
                m_lenPkgVar->setDefaultValue(updLen);
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("L_TRACKCOND_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 15;
                m_lenPkgVar->setDefaultValue(updLen);
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

void HandlerPackage_67_Ver340::handleIterateVariable_SL(QString nameVariable)
{

    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        qint16 value = variable->valueOfVariable().toInt();
        qint32 maxValue = 0;
        qint32 minValue = 0;

        if (0 == value || 2 == value) {
            maxValue=327670;
        } else if (1 == value) {

            maxValue=32767;
        } else {
            maxValue=327670;
        }
        m_lTrackCond->setRange(minValue,maxValue);
        m_dTrackCond->setRange(minValue,maxValue);
        qint16 positionIterateVar = 7;
        qint16 size = m_VariableVect.size();
        for (int i = positionIterateVar ;i < size ;i++) {
            package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
            if (nullptr !=variable ){
                variable->setRange(minValue,maxValue);
            }

        }
        showVariable();
    }


}

void HandlerPackage_67_Ver340::showVariable()
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


bool HandlerPackage_67_Ver340::saveData()
{

    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_ScaleVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_dTrackCond->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lTrackCond->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nIterVar->valueOfVariable();

    qint8 positionIterate=7;
    qint8 numberVariableIterate=2;
    qint16 numIteration = m_nIterVar->valueOfVariable().toInt();
    qint16 sizeIterate = ( numIteration * numberVariableIterate);
    if (( sizeIterate+positionIterate ) <= m_VariableVect.size()){
        for (int i =0; i < sizeIterate;i++ ){
            package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i+positionIterate));
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

void HandlerPackage_67_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}


}
