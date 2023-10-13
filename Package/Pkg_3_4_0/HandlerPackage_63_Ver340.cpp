#include "HandlerPackage_63_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_63_Ver340::HandlerPackage_63_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_nIterVar = nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=63;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_63_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 63 - " + QString(BASELINE_3_4_0));

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
        m_lenPkgVar->setDefaultValue(28);
        m_lenPkgVar->setVisible(false);
        m_VariableVect.push_back(m_lenPkgVar);

        m_lenPkgVar->setTobeVisible(true);

        m_nIterVar =  new package::GraphicVariablePkg ;
        m_nIterVar->init(GraphicVariablePkg::type_integer);
        m_nIterVar->setNameVariable("N_ITER");
        m_nIterVar->setRange(0,31);
        m_nIterVar->setDefaultValue(0);
        m_nIterVar->setVisible(false);
        m_VariableVect.push_back(m_nIterVar);
        m_nIterVar->setTobeVisible(true);

        qint16 maxValueVariableIter=MAX_ITERATION;
        package::GraphicVariablePkg * qNewCountry=nullptr;
        package::GraphicVariablePkg * nidCIterVar=nullptr;
        package::GraphicVariablePkg * nidBgIterVar=nullptr;

        for (int i = 0;i < maxValueVariableIter ;i++) {
            qNewCountry =  new package::GraphicVariablePkg ;
            qNewCountry->init(GraphicVariablePkg::type_integer);
            QString nameItem = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(i+1));
            qNewCountry->setNameVariable(nameItem);
            qNewCountry->setInternalName(nameItem);
            qNewCountry->setRange(0,1);
            qNewCountry->setDefaultValue(0);
            m_VariableVect.push_back(qNewCountry);
            qNewCountry->setVisible(false);
            qNewCountry->setTobeVisible(false);
            //   connect (qNewCountry,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_63_Ver340::handleIterateVariable_SL );
            //   connect (qNewCountry,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_63_Ver340::saveData );


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


        }

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }

        showVariable();

    }
    connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_63_Ver340::saveData );
    connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_63_Ver340::saveData );
    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_63_Ver340::handleChangeIteration_SL );
    connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_63_Ver340::saveData );
    connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_63_Ver340::saveData );

    qint8 idxConnectIterate=2;
    qint16 positionIterateVar = 4;
    qint16 size = m_VariableVect.size();
    for (int i = positionIterateVar ;i < size ;i++) {
        package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
        if (nullptr != variable){
            if (2==idxConnectIterate){
                connect (variable,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_63_Ver340::handleIterateVariable_SL );

            }
            connect (variable,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_63_Ver340::saveData );
            idxConnectIterate--;
            if (idxConnectIterate < 0){
                idxConnectIterate=2;

            }
        }

    }
    return true;

}
void HandlerPackage_63_Ver340::loadPkg()
{
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){

        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        qint16 size = dataList.size();
        qint8 positionIterate=4;
        m_isReload=false;
        if (size >= 4){
            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
            qint16 numIter = dataList.at(3).toInt();
            m_nIterVar->setDefaultValue( numIter );

            if (size >=  ( numIter *3) ){
                for (int i = positionIterate;i < size;i++ ){

                    //get  Q_NEWCOUNTRY(i)
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
                    if (nullptr != variable ){
                        variable->setDefaultValue(dataList.at(i).toInt());
                        variable->setTobeVisible(true);

                    }
                    //get NID_C(i)
                    if (i +1 >= size) break;
                    variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i+1));
                    if (nullptr != variable ){
                        if (EMPTY_VALUE == dataList.at(i+1)){
                            variable->setDefaultValue(0);
                            variable->setTobeVisible(false);
                        } else {
                            variable->setDefaultValue(dataList.at(i+1).toInt());
                            variable->setTobeVisible(true);

                        }
                    }
                    //get  NID_BG(i)
                    if (i +2 >= size) break;
                    variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i+2));
                    if (nullptr != variable ){
                        variable->setDefaultValue(dataList.at(i+2).toInt());
                        variable->setTobeVisible(true);

                    }
                    i+=2;
                }
            }
        }
    }

}


void HandlerPackage_63_Ver340::handleChangeIteration_SL()
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
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()+ 1;
            m_lenPkgVar->setDefaultValue(updLen);


            nameIterateVar = QString ("NID_BG_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = m_lenPkgVar->valueOfVariable().toInt()+ 14;
            m_lenPkgVar->setDefaultValue(updLen);


        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            QString nameIterateVar = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            qint16 idx =  variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 1;
                m_lenPkgVar->setDefaultValue(updLen);
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }
            }

            nameIterateVar = QString ("NID_C_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            idx=variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 10;
                m_lenPkgVar->setDefaultValue(updLen);
                if (idx != -1 ) {
                    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                    variable->setDefaultValue(0);
                }


            }

            nameIterateVar = QString ("NID_BG_%1").arg(QString::number(numVisibile));
            idx= variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 14;
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

void HandlerPackage_63_Ver340::handleIterateVariable_SL(QString nameVariable)
{

    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< variable->valueOfVariable();
    qint16 value = variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString nidCIterate = QString ("NID_C_%1").arg(parseNameVar[parseNameVar.size()-1]);
        bool notUsed;
        if (1 == value ){
            //Marca l'item a  visibile

            variableUpdVisibleState(nidCIterate,true,notUsed);
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()+ 10;
            m_lenPkgVar->setDefaultValue(updLen);

        } else {
            //Marca l'item a non visibile
            variableUpdVisibleState(nidCIterate,false,notUsed);
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 10;
            m_lenPkgVar->setDefaultValue(updLen);
        }
    }

    showVariable();
}

void HandlerPackage_63_Ver340::showVariable()
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


bool HandlerPackage_63_Ver340::saveData()
{

    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nIterVar->valueOfVariable();
    qint8 positionIterate=4;
    qint8 numberVariableIterate=3;
    qint16 numIteration = m_nIterVar->valueOfVariable().toInt();
    qint16 sizeIterate = ( numIteration * numberVariableIterate);
    if (sizeIterate+positionIterate <= m_VariableVect.size()){
        for (int i =0; i < sizeIterate;i++ ){
            package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i+positionIterate));
            if (nullptr != variable){
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

void HandlerPackage_63_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}


}
