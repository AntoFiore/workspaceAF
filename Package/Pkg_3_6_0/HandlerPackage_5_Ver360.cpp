#include "HandlerPackage_5_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_5_Ver360::HandlerPackage_5_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_qScaleVar=nullptr;
    m_dLinkVar=nullptr;
    m_qNewcountryVar=nullptr;
    m_nidCVar=nullptr;
    m_qLinkorientationVar=nullptr;
    m_qLinkreactionVar=nullptr;
    m_qLocaccVar=nullptr;
    m_nidBGVar_k=nullptr;
    m_dLinkVar_k=nullptr;
    m_qNewcountryVar_k=nullptr;
    m_nidCVar_k=nullptr;
    m_qLinkorientationVar_k=nullptr;
    m_qLinkreactionVar_k=nullptr;
    m_qLocaccVar_k=nullptr;
    m_nidBGVar_k=nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg=5;
}

bool HandlerPackage_5_Ver360::creteView()
{

    qDebug () << "HandlerPackage_5_Ver360::creteView();";
    bool ret = false;
    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 5 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);

        m_qDirVar =  new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);

        m_lenPkgVar =  new package::GraphicVariablePkg;
        m_lenPkgVar->set_L_PACKET(56,1585);
        m_VariableVect.push_back(m_lenPkgVar);

        m_qScaleVar =  new package::GraphicVariablePkg;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back( m_qScaleVar);

        m_dLinkVar =  new package::GraphicVariablePkg;
        m_dLinkVar->set_D_LINK();
        m_VariableVect.push_back( m_dLinkVar);


        m_qNewcountryVar =  new package::GraphicVariablePkg;
        m_qNewcountryVar->init(GraphicVariablePkg::type_integer);
        m_qNewcountryVar->setNameVariable("Q_NEWCOUNTRY");
        m_qNewcountryVar->setRange(0,1);
        m_qNewcountryVar->setDefaultValue(0);
        m_qNewcountryVar->setTobeVisible(true);
        m_qNewcountryVar->setVisible(false);
        m_VariableVect.push_back(m_qNewcountryVar);

        m_nidCVar =  new package::GraphicVariablePkg;
        m_nidCVar->init(GraphicVariablePkg::type_integer);
        m_nidCVar->setNameVariable("NID_C");
        m_nidCVar->setRange(0,1023);
        m_nidCVar->setDefaultValue(0);
        m_nidCVar->setTobeVisible(false);
        m_nidCVar->setVisible(false);
        m_VariableVect.push_back(m_nidCVar);

        m_nidBGVar =  new package::GraphicVariablePkg;
        m_nidBGVar->init(GraphicVariablePkg::type_integer);
        m_nidBGVar->setNameVariable("NID_BG");
        m_nidBGVar->setRange(0,16381);
        m_VariableVect.push_back(m_nidBGVar);
        m_nidBGVar->setTobeVisible(true);
        m_nidBGVar->setVisible(false);

        m_qLinkorientationVar =  new package::GraphicVariablePkg;
        m_qLinkorientationVar->init(GraphicVariablePkg::type_integer);
        m_qLinkorientationVar->setNameVariable("Q_LINKORIENTATION");
        m_qLinkorientationVar->setRange(0,1);
        m_qLinkorientationVar->setDefaultValue(0);
        m_qLinkorientationVar->setTobeVisible(true);
        m_qLinkorientationVar->setVisible(false);
        m_VariableVect.push_back(m_qLinkorientationVar);

        m_qLinkreactionVar =  new package::GraphicVariablePkg;
        m_qLinkreactionVar->init(GraphicVariablePkg::type_integer);
        m_qLinkreactionVar->setNameVariable("Q_LINKREACTION");
        m_qLinkreactionVar->setRange(0,3);
        m_qLinkreactionVar->setDefaultValue(0);
        m_qLinkreactionVar->setTobeVisible(true);
        m_qLinkreactionVar->setVisible(false);
        m_VariableVect.push_back(m_qLinkreactionVar);

        m_qLocaccVar =  new package::GraphicVariablePkg;
        m_qLocaccVar->init(GraphicVariablePkg::type_integer);
        m_qLocaccVar->setNameVariable("Q_LOCACC");
        m_qLocaccVar->setRange(0,63);
        m_qLocaccVar->setDefaultValue(0);
        m_qLocaccVar->setTobeVisible(true);
        m_qLocaccVar->setVisible(false);
        m_VariableVect.push_back(m_qLocaccVar);

        m_nIterVar =  new package::GraphicVariablePkg;
        m_nIterVar->init(GraphicVariablePkg::type_integer);
        m_nIterVar->setNameVariable("N_ITER");
        m_nIterVar->setRange(0,31);
        m_nIterVar->setDefaultValue(0);
        m_nIterVar->setTobeVisible(true);
        m_nIterVar->setVisible(false);
        m_VariableVect.push_back(m_nIterVar);

        connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_dLinkVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_qNewcountryVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::show_nidC );
        connect (m_qNewcountryVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_nidCVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_qLinkorientationVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_nidBGVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_qLinkorientationVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        connect (m_qLocaccVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );

        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::handleChangeIteration_SL );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );


        qint16 maxValueVariableIter=31;
        package::GraphicVariablePkg * levelTrVar=nullptr;
        QString name;
        for (int i = 0;i < maxValueVariableIter ;i++) {
            levelTrVar =  new package::GraphicVariablePkg ;
            levelTrVar->init(GraphicVariablePkg::type_integer);

            m_dLinkVar_k =  new package::GraphicVariablePkg;
            m_dLinkVar_k->init(GraphicVariablePkg::type_integer);
            name = QString ("D_LINK_%1").arg(QString::number(i+1));
            m_dLinkVar_k->setNameVariable(name);
            m_dLinkVar_k->setInternalName(name);
            m_dLinkVar_k->setRange(0,32768);
            m_dLinkVar_k->setDefaultValue(0);
            m_VariableVect.push_back( m_dLinkVar_k);
            m_dLinkVar_k->setTobeVisible(false);
            m_dLinkVar_k->setVisible(false);

            m_qNewcountryVar_k =  new package::GraphicVariablePkg;
            m_qNewcountryVar_k->init(GraphicVariablePkg::type_integer);
            name = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(i+1));
            m_qNewcountryVar_k->setNameVariable(name);
            m_qNewcountryVar_k->setInternalName(name);
            m_qNewcountryVar_k->setRange(0,1);
            m_qNewcountryVar_k->setDefaultValue(0);
            m_qNewcountryVar_k->setTobeVisible(false);
            m_qNewcountryVar_k->setVisible(false);
            m_VariableVect.push_back(m_qNewcountryVar_k);

            m_nidCVar_k =  new package::GraphicVariablePkg;
            m_nidCVar_k->init(GraphicVariablePkg::type_integer);
            name = QString ("NID_C_%1").arg(QString::number(i+1));
            m_nidCVar_k->setNameVariable(name);
            m_nidCVar_k->setInternalName(name);
            m_nidCVar_k->setRange(0,1023);
            m_nidCVar_k->setDefaultValue(0);
            m_nidCVar_k->setTobeVisible(false);
            m_nidCVar_k->setVisible(false);
            m_VariableVect.push_back(m_nidCVar_k);

            m_nidBGVar_k =  new package::GraphicVariablePkg;
            m_nidBGVar_k->init(GraphicVariablePkg::type_integer);
            name = QString ("NID_BG_%1").arg(QString::number(i+1));
            m_nidBGVar_k->setNameVariable(name);
            m_nidBGVar_k->setInternalName(name);
            m_nidBGVar_k->setRange(0,16381);
            m_VariableVect.push_back(m_nidBGVar_k);
            m_nidBGVar_k->setTobeVisible(false);
            m_nidBGVar_k->setVisible(false);

            m_qLinkorientationVar_k =  new package::GraphicVariablePkg;
            m_qLinkorientationVar_k->init(GraphicVariablePkg::type_integer);
            name = QString ("Q_LINKORIENTATION_%1").arg(QString::number(i+1));
            m_qLinkorientationVar_k->setNameVariable(name);
            m_qLinkorientationVar_k->setInternalName(name);
            m_qLinkorientationVar_k->setRange(0,1);
            m_qLinkorientationVar_k->setDefaultValue(0);
            m_qLinkorientationVar_k->setTobeVisible(false);
            m_qLinkorientationVar_k->setVisible(false);
            m_VariableVect.push_back(m_qLinkorientationVar_k);

            m_qLinkreactionVar_k =  new package::GraphicVariablePkg;
            m_qLinkreactionVar_k->init(GraphicVariablePkg::type_integer);
            name = QString ("Q_LINKREACTION_%1").arg(QString::number(i+1));
            m_qLinkreactionVar_k->setNameVariable(name);
            m_qLinkreactionVar_k->setInternalName(name);
            m_qLinkreactionVar_k->setRange(0,3);
            m_qLinkreactionVar_k->setDefaultValue(0);
            m_qLinkreactionVar_k->setTobeVisible(false);
            m_qLinkreactionVar_k->setVisible(false);
            m_VariableVect.push_back(m_qLinkreactionVar_k);

            m_qLocaccVar_k =  new package::GraphicVariablePkg;
            m_qLocaccVar_k->init(GraphicVariablePkg::type_integer);
            name = QString ("Q_LOCACC_%1").arg(QString::number(i+1));
            m_qLocaccVar_k->setNameVariable(name);
            m_qLocaccVar_k->setInternalName(name);;
            m_qLocaccVar_k->setRange(0,63);
            m_qLocaccVar_k->setDefaultValue(0);
            m_qLocaccVar_k->setTobeVisible(false);
            m_qLocaccVar_k->setVisible(false);
            m_VariableVect.push_back(m_qLocaccVar_k);


            connect (m_dLinkVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
            connect (m_qNewcountryVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
            connect (m_qNewcountryVar_k,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_5_Ver360::handleIterateVariable_SL);
            connect (m_nidCVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );            
            connect (m_nidBGVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
            connect (m_qLinkorientationVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
            connect (m_qLinkorientationVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
            connect (m_qLocaccVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_5_Ver360::saveData );
        }
        int currCol =0;
        int row =0;
        m_layOutPkg->addWidget(m_titlePkg,row,currCol);
        if (m_isReload) {
            loadPkg();
        }
        showVariable();
        ret=saveData();
    }
    return ret;

}

void HandlerPackage_5_Ver360::show_nidC()
{
    qDebug () <<  m_qNewcountryVar->valueOfVariable().toInt();
    if (1 == m_qNewcountryVar->valueOfVariable().toInt()){
        m_nidCVar->setTobeVisible(true);
        m_nidCVar->setDefaultValue(1);
        m_lenPkgVar->setDefaultValue(49*m_nidBGVar->valueOfVariable().toInt()+66);
    } else {
        m_nidCVar->setTobeVisible(false);
        m_nidCVar->setDefaultValue(0);
        m_lenPkgVar->setDefaultValue(49*m_nidBGVar->valueOfVariable().toInt()+56);
    }
    showVariable();
}

void HandlerPackage_5_Ver360::handleIterateVariable_SL(QString nameVariable)
{
    //QString nameVariable = "Q_NEWCOUNTRY_" +QString::number(i+1);
    package::GraphicVariablePkg * variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< variable->valueOfVariable();
    qint16 value = variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString nidNtcIterate = QString ("NID_C_%1").arg(parseNameVar[parseNameVar.size()-1]);
        bool notUsed;
        if (1 == value ){
            //Marca l'item a  visibile

            variableUpdVisibleState(nidNtcIterate,true,notUsed);
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()+ 10;
            m_lenPkgVar->setDefaultValue(updLen);

        } else {
            //Marca l'item a non visibile
            variableUpdVisibleState(nidNtcIterate,false,notUsed);
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 10;
            m_lenPkgVar->setDefaultValue(updLen);
        }
    }

    showVariable();
}

void HandlerPackage_5_Ver360::show_nidC_k()
{
    qint16 numVisibile = countVariableIterateisVisible("Q_NEWCOUNTRY_");
    for(int i=0;i<numVisibile;i++){
        QString nameIterationVariable = "Q_NEWCOUNTRY_" +QString::number(i+1);
        qDebug () <<  m_qNewcountryVar_k->valueOfVariable().toInt();
        if (1 == m_qNewcountryVar_k->valueOfVariable().toInt()){
            m_nidCVar_k->setTobeVisible(true);
            m_nidCVar_k->setDefaultValue(1);
            m_lenPkgVar->setDefaultValue(48);
        } else {
            m_nidCVar_k->setTobeVisible(false);
            m_nidCVar_k->setDefaultValue(0);
            m_lenPkgVar->setDefaultValue(66);
        }
    }
    showVariable();
}

void HandlerPackage_5_Ver360::handleChangeIteration_SL()
{

    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("D_LINK_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue-numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            QString nameIterateVar = QString ("D_LINK_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()+ 15;
            m_lenPkgVar->setDefaultValue(updLen);

            nameIterateVar = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = m_lenPkgVar->valueOfVariable().toInt()+ 1;
            m_lenPkgVar->setDefaultValue(updLen);

            nameIterateVar = QString ("NID_BG_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = m_lenPkgVar->valueOfVariable().toInt()+ 14;
            m_lenPkgVar->setDefaultValue(updLen);

            nameIterateVar = QString ("Q_LINKORIENTATION_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = m_lenPkgVar->valueOfVariable().toInt()+ 1;
            m_lenPkgVar->setDefaultValue(updLen);

            nameIterateVar = QString ("Q_LINKREACTION_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = m_lenPkgVar->valueOfVariable().toInt()+ 2;
            m_lenPkgVar->setDefaultValue(updLen);

            nameIterateVar = QString ("Q_LOCACC_%1").arg(QString::number(numVisibile+i+1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = m_lenPkgVar->valueOfVariable().toInt()+ 6;
            m_lenPkgVar->setDefaultValue(updLen);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;

            QString nameIterateVar = QString ("D_LINK_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableUpdVisibleState(nameIterateVar,false,oldvisibleState);

            nameIterateVar = QString ("Q_NEWCOUNTRY_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableUpdVisibleState(nameIterateVar,false,oldvisibleState);

            nameIterateVar = QString ("NID_BG_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableUpdVisibleState(nameIterateVar,false,oldvisibleState);;

            nameIterateVar = QString ("Q_LINKORIENTATION_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableUpdVisibleState(nameIterateVar,false,oldvisibleState);

            nameIterateVar = QString ("Q_LINKREACTION_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableUpdVisibleState(nameIterateVar,false,oldvisibleState);

            nameIterateVar = QString ("Q_LOCACC_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableUpdVisibleState(nameIterateVar,false,oldvisibleState);

            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
                updLen = updLen - 15; //D_LINK
                updLen = updLen - 1; //Q_NEWCOUNTRY
                updLen = updLen - 14; //NID_BG
                updLen = updLen - 1; //Q_LINKORIENTATION
                updLen = updLen - 2; //Q_LINKREACTION
                updLen = updLen - 6; //Q_LOCACC
                m_lenPkgVar->setDefaultValue(updLen);

            }

            nameIterateVar = QString ("NID_C_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()- 10;
                m_lenPkgVar->setDefaultValue(updLen);

            }
            numVisibile--;

        }
    }
    showVariable();
    return ;
}

void HandlerPackage_5_Ver360::showVariable()
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

bool HandlerPackage_5_Ver360::saveData()
{
    QString data = m_nidPkgVar->valueOfVariable();

    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qScaleVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_dLinkVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qNewcountryVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;

    if (m_nidCVar->isVisible()){
        data+=m_nidCVar->valueOfVariable();
    } else{
        data+=EMPTY_VALUE;
    }
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qLinkorientationVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nidBGVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qLinkreactionVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qLocaccVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nIterVar->valueOfVariable();

    qint16 numIteration = m_nIterVar->valueOfVariable().toInt();
    qint16 sizeIterate = ( numIteration* 8);
    if (sizeIterate+12 <=m_VariableVect.size()){
        for (int i =0; i < sizeIterate;i++ ){
            package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i+12));
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

void HandlerPackage_5_Ver360::deleteView()
{

    HandlerPackage::deleteView();
    // deleteLater();
}



void HandlerPackage_5_Ver360::loadPkg()
{

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        qint16 size = dataList.size();

        if (size >= 11 ){

            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
            m_qScaleVar->setDefaultValue( dataList.at(3).toInt());
            m_dLinkVar->setDefaultValue( dataList.at(4).toInt());
            m_qNewcountryVar->setDefaultValue( dataList.at(5).toInt());
            if (dataList.at(6)!= EMPTY_VALUE){
                 m_nidCVar->setDefaultValue(dataList.at(6).toInt());
                 m_nidCVar->setTobeVisible(true);
            } else {
                 m_nidCVar->setTobeVisible(false);
            }
            m_qLinkorientationVar->setDefaultValue( dataList.at(7).toInt());
            m_nidBGVar->setDefaultValue( dataList.at(8).toInt());
            m_qLinkreactionVar->setDefaultValue( dataList.at(9).toInt());
            m_qLocaccVar->setDefaultValue( dataList.at(10).toInt());
            m_nIterVar->setDefaultValue(dataList.at(11).toInt());

            qint16 numIteration=dataList.at(11).toInt();
            //Ogni iterazione ha 8 campi
            qint16 sizeIterate = ( numIteration* 8)+12;
            m_nIterVar->setDefaultValue(numIteration);
            if (sizeIterate <= size && size <= m_VariableVect.size()){
                for (int i =12;i < size;i++){
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

}

