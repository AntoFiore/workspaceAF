#include "HandlerPackage_68_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_68_Ver340::HandlerPackage_68_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_nIterVar = nullptr;
    m_ScaleVar=nullptr;
    m_qTrackInitVar=nullptr;
    m_dTrackInitVar=nullptr;
    m_dTrackCondVar=nullptr;
    m_lTrackCondVar=nullptr;
    m_mTrackCondVar=nullptr;



    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=68;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_68_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    QString nameItem;
    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 68 - " + QString(BASELINE_3_4_0));

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
        m_lenPkgVar->setDefaultValue(67);
        m_lenPkgVar->setRange(0,8192);
        m_lenPkgVar->setVisible(false);
        m_VariableVect.push_back(m_lenPkgVar);
        m_lenPkgVar->setTobeVisible(true);

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

        nameItem = QString ("D_TRACKINIT");
        m_dTrackInitVar =  new package::GraphicVariablePkg ;
        m_dTrackInitVar->init(GraphicVariablePkg::type_integer);
        m_dTrackInitVar->setNameVariable(nameItem);
        m_dTrackInitVar->setInternalName(nameItem);
        m_dTrackInitVar->setDefaultValue(0);
        m_dTrackInitVar->setRange(0,327680);
        m_dTrackInitVar->setVisible(false);
        m_VariableVect.push_back(m_dTrackInitVar);
        m_dTrackInitVar->setTobeVisible(false);

        nameItem = QString ("D_TRACKCOND");
        m_dTrackCondVar =  new package::GraphicVariablePkg ;
        m_dTrackCondVar->init(GraphicVariablePkg::type_integer);
        m_dTrackCondVar->setNameVariable(nameItem);
        m_dTrackCondVar->setInternalName(nameItem);
        m_dTrackCondVar->setDefaultValue(0);
        m_dTrackCondVar->setRange(0,327680);
        m_dTrackCondVar->setVisible(false);
        m_VariableVect.push_back(m_dTrackCondVar);
        m_dTrackCondVar->setTobeVisible(true);

        nameItem = QString ("L_TRACKCOND");
        m_lTrackCondVar =  new package::GraphicVariablePkg ;
        m_lTrackCondVar->init(GraphicVariablePkg::type_integer);
        m_lTrackCondVar->setNameVariable(nameItem);
        m_lTrackCondVar->setInternalName(nameItem);
        m_lTrackCondVar->setDefaultValue(0);
        m_lTrackCondVar->setRange(0,327680);
        m_lTrackCondVar->setVisible(false);
        m_VariableVect.push_back(m_lTrackCondVar);
        m_lTrackCondVar->setTobeVisible(true);


        nameItem = QString ("M_TRACKCOND");
        m_mTrackCondVar =  new package::GraphicVariablePkg ;
        m_mTrackCondVar->init(GraphicVariablePkg::type_integer);
        m_mTrackCondVar->setNameVariable(nameItem);
        m_mTrackCondVar->setInternalName(nameItem);
        m_mTrackCondVar->setDefaultValue(0);
        m_mTrackCondVar->setRange(0,5);
        m_mTrackCondVar->setVisible(false);
        m_VariableVect.push_back(m_mTrackCondVar);
        m_mTrackCondVar->setTobeVisible(true);

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

        qint16 maxValueVariableIter=MAX_ITERATION;
        package::GraphicVariablePkg * dTrackCondIterVar=nullptr;
        package::GraphicVariablePkg * lTrackCondIterVar=nullptr;
        package::GraphicVariablePkg * mTrackCondIterVar=nullptr;



        for (int i = 0;i < maxValueVariableIter ;i++) {
            dTrackCondIterVar =  new package::GraphicVariablePkg ;
            dTrackCondIterVar->init(GraphicVariablePkg::type_integer);
            QString nameItem = QString ("D_TRACKCOND_%1").arg(QString::number(i+1));
            dTrackCondIterVar->setNameVariable(nameItem);
            dTrackCondIterVar->setInternalName(nameItem);
            dTrackCondIterVar->setRange(0,327680);
            dTrackCondIterVar->setDefaultValue(0);
            m_VariableVect.push_back(dTrackCondIterVar);
            dTrackCondIterVar->setVisible(false);
            dTrackCondIterVar->setTobeVisible(false);

            lTrackCondIterVar =  new package::GraphicVariablePkg ;
            lTrackCondIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("L_TRACKCOND_%1").arg(QString::number(i+1));
            lTrackCondIterVar->setNameVariable(nameItem);
            lTrackCondIterVar->setInternalName(nameItem);
            lTrackCondIterVar->setRange(0,327680);
            lTrackCondIterVar->setDefaultValue(0);
            m_VariableVect.push_back(lTrackCondIterVar);
            lTrackCondIterVar->setVisible(false);
            lTrackCondIterVar->setTobeVisible(false);


            mTrackCondIterVar =  new package::GraphicVariablePkg ;
            mTrackCondIterVar->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("M_TRACKCOND_%1").arg(QString::number(i+1));
            mTrackCondIterVar->setNameVariable(nameItem);
            mTrackCondIterVar->setInternalName(nameItem);
            mTrackCondIterVar->setRange(0,5);
            mTrackCondIterVar->setDefaultValue(0);
            m_VariableVect.push_back(mTrackCondIterVar);
            mTrackCondIterVar->setVisible(false);
            mTrackCondIterVar->setTobeVisible(false);
        }

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }

        showVariable();

    }
    connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
    connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
    connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
    connect (m_ScaleVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_68_Ver340::handleChangeScaleVariable_SL );
    connect (m_ScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
    connect (m_qTrackInitVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_68_Ver340::handleChangeQ_TrackInitVariable_SL );
    connect (m_qTrackInitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
    connect (m_dTrackInitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
    connect (m_dTrackCondVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
    connect (m_lTrackCondVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
    connect (m_mTrackCondVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::handleChangeIteration_SL );
    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );

    qint16 positionIterateVar = 10;
    qint16 size = m_VariableVect.size();
    for (int i = positionIterateVar ;i < size ;i++) {
        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
        if (nullptr != variable){
            connect (variable,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_68_Ver340::saveData );
        }

    }
    return true;

}
void HandlerPackage_68_Ver340::loadPkg()
{

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){

        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        qint16 size = dataList.size();
        qint8 positionIterate=6;

        m_isReload=false;
        qint8 positionFixVariable= 5;

        if (size >positionFixVariable)
        {

            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
            m_ScaleVar->setDefaultValue( dataList.at(3).toInt());
            m_qTrackInitVar->setDefaultValue( dataList.at(4).toInt());

            if (1 == m_qTrackInitVar->valueOfVariable().toInt()){
                m_dTrackInitVar->setDefaultValue(dataList.at(5).toInt());
                m_dTrackInitVar->setTobeVisible(true);
                for (int i = positionIterate;i< m_VariableVect.size();i++){
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
                    if (nullptr != variable){
                        variable->setTobeVisible(false);
                        variable->setDefaultValue(0);
                    }
                }

            } else {
                m_dTrackInitVar->setTobeVisible(false);
                m_dTrackInitVar->setDefaultValue(0);

                m_dTrackCondVar->setDefaultValue(dataList.at(5).toInt());
                m_dTrackCondVar->setTobeVisible(true);

                m_lTrackCondVar->setDefaultValue(dataList.at(6).toInt());
                m_lTrackCondVar->setTobeVisible(true);

                m_mTrackCondVar->setDefaultValue(dataList.at(7).toInt());
                m_mTrackCondVar->setTobeVisible(true);


                m_nIterVar->setDefaultValue(dataList.at(8).toInt());
                m_nIterVar->setTobeVisible(true);

                positionIterate=9;
                qint8 numberVariableIterate=3;
                qint16 numIteration = m_nIterVar->valueOfVariable().toInt();
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

}


void HandlerPackage_68_Ver340::handleChangeIteration_SL()
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
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = m_lenPkgVar->valueOfVariable().toInt()+ 15;
            m_lenPkgVar->setDefaultValue(updLen);

            nameIterateVar = QString ("M_TRACKCOND_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = m_lenPkgVar->valueOfVariable().toInt()+ 4;
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

            nameIterateVar = QString ("M_TRACKCOND_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 4;
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

void HandlerPackage_68_Ver340::handleChangeScaleVariable_SL(QString nameVariable)
{

    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){
        qint16 value = variable->valueOfVariable().toInt();
        qint32 maxValue = 0;
        qint32 minValue = 0;

        if (0 == value || 2 == value) {
            maxValue=327680;
        } else if (1 == value) {

            maxValue=32768;
        } else {
            maxValue=327680;
        }
        m_dTrackCondVar->setRange(minValue,maxValue);
        m_qTrackInitVar->setRange(minValue,maxValue);
        m_lTrackCondVar->setRange(minValue,maxValue);
        qint16 positionIterateVar = 10;
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
                        nameItem =QString ("_TRACKCOND_%1").arg(QString::number(iteration));
                    }
                }
            }

        }
        showVariable();
    }

}

void HandlerPackage_68_Ver340::handleChangeQ_TrackInitVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    if (nullptr != variable){

        qint16 size=m_lenPkgVar->valueOfVariable().toInt();
        qint16 value = variable->valueOfVariable().toInt();
        if (1 == value ){


            for (int i = 5 ; i < m_VariableVect.size();i++){
                package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
                if (nullptr != variable){
                    variable->setTobeVisible(false);
                    variable->setDefaultValue(0);
                }
            }
            m_dTrackInitVar->setTobeVisible(true);
            size = 41;

        } else {
            m_dTrackCondVar->setTobeVisible(true);
            m_lTrackCondVar->setTobeVisible(true);
            m_mTrackCondVar->setTobeVisible(true);

            m_nIterVar->setTobeVisible(true);

            m_dTrackInitVar->setTobeVisible(false);
            size=65;

        }
        m_lenPkgVar->setDefaultValue(size);
        showVariable();
    }


}


void HandlerPackage_68_Ver340::showVariable()
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


bool HandlerPackage_68_Ver340::saveData()
{

    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_ScaleVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qTrackInitVar->valueOfVariable();
    if (1 == m_qTrackInitVar->valueOfVariable().toInt()){
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
        data+=m_dTrackInitVar->valueOfVariable();

    } else {
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
        data+=m_dTrackCondVar->valueOfVariable();
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
        data+=m_lTrackCondVar->valueOfVariable();
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
        data+=m_mTrackCondVar->valueOfVariable();
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
        data+=m_nIterVar->valueOfVariable();
        qint8 positionIterate=10;

        qint8 numberVariableIterate=3;
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

    }

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;
    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);

    return true;

}

void HandlerPackage_68_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}


}
