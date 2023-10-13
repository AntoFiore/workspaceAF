#include "HandlerPackage_6_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_6_Ver340::HandlerPackage_6_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_nidqVBCOVar=nullptr;
    m_nidVBCMKVar=nullptr;
    m_nidCVar=nullptr;
    m_TVBCVar=nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=6;
}

bool HandlerPackage_6_Ver340::creteView()
{

    qDebug () << "HandlerPackage_6_Ver340::creteView();";

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 6 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->init(GraphicVariablePkg::type_integer);
        m_nidPkgVar->setNameVariable("NID_PACKET");
        m_nidPkgVar->setIsOnlyRead(true);
        m_nidPkgVar->setDefaultValue(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);
        m_nidPkgVar->setTobeVisible(true);
        m_nidPkgVar->setVisible(false);



        m_qDirVar =  new package::GraphicVariablePkg;
        m_qDirVar->init(GraphicVariablePkg::type_integer);
        m_qDirVar->setNameVariable("Q_DIR");
        m_qDirVar->setRange(0,3);
        m_qDirVar->setDefaultValue(1);
        m_qDirVar->setTobeVisible(true);
        m_qDirVar->setVisible(false);
        m_VariableVect.push_back(m_qDirVar);


        m_lenPkgVar =  new package::GraphicVariablePkg;
        m_lenPkgVar->init(GraphicVariablePkg::type_integer);
        m_lenPkgVar->setNameVariable("L_PACKET");
        m_lenPkgVar->setRange(40,48);
        m_VariableVect.push_back(m_lenPkgVar);
        m_lenPkgVar->setTobeVisible(true);
        m_lenPkgVar->setVisible(false);


        m_nidqVBCOVar =  new package::GraphicVariablePkg;
        m_nidqVBCOVar->init(GraphicVariablePkg::type_integer);
        m_nidqVBCOVar->setNameVariable("Q_VBCO");
        m_nidqVBCOVar->setRange(0,1);
        m_nidqVBCOVar->setDefaultValue(0);
        m_nidqVBCOVar->setVisible(false);
        m_VariableVect.push_back( m_nidqVBCOVar);
        m_nidqVBCOVar->setTobeVisible(true);

        m_nidVBCMKVar =  new package::GraphicVariablePkg;
        m_nidVBCMKVar->init(GraphicVariablePkg::type_integer);
        m_nidVBCMKVar->setNameVariable("NID_VBCMK");
        m_nidVBCMKVar->setRange(0,63);
        m_nidVBCMKVar->setDefaultValue(0);
        m_VariableVect.push_back( m_nidVBCMKVar);
        m_nidVBCMKVar->setTobeVisible(true);
        m_nidVBCMKVar->setVisible(false);



        m_nidCVar =  new package::GraphicVariablePkg;
        m_nidCVar->init(GraphicVariablePkg::type_integer);
        m_nidCVar->setNameVariable("NIC_C");
        m_nidCVar->setRange(0,1023);
        m_nidCVar->setDefaultValue(0);
        m_nidCVar->setTobeVisible(true);
        m_nidCVar->setVisible(false);
        m_VariableVect.push_back(  m_nidCVar);


        m_TVBCVar =  new package::GraphicVariablePkg;
        m_TVBCVar->init(GraphicVariablePkg::type_integer);
        m_TVBCVar->setNameVariable("T_VBC");
        m_TVBCVar->setRange(0,256);
        m_VariableVect.push_back(m_TVBCVar);
        m_TVBCVar->setVisible(false);
        m_TVBCVar->setTobeVisible(true);


        qint16 totVar = m_VariableVect.size();
        int currCol =0;
        int row =0;

        m_layOutPkg->addWidget(m_titlePkg,row,currCol);
        row++;

         showVariable();

//        for (qint16 i =0; i < totVar;i++){
//            //    vectVariable.at(i)->setParent(m_containerPackageView);
//            m_layOutPkg->addWidget(m_VariableVect.at(i),row,currCol);
//            if (currCol >m_maxCalumnVariable ){
//                currCol=0;
//                row++;
//            } else {
//                currCol++;
//            }

//        }
//        m_spaced = new QSpacerItem (40,80,QSizePolicy::Expanding,QSizePolicy::Expanding) ;
//        m_layOutPkg->addItem(m_spaced,++row,4);

    }
    if (m_isReload) {
        loadPkg();
    }
    connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_6_Ver340::saveData );
    connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_6_Ver340::saveData );
    connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_6_Ver340::saveData );
    connect ( m_nidqVBCOVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_6_Ver340::saveData );
    connect ( m_nidqVBCOVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_6_Ver340::showTVBC );
    connect ( m_nidVBCMKVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_6_Ver340::saveData );
    connect (  m_nidCVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_6_Ver340::saveData );
    connect ( m_TVBCVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_6_Ver340::saveData );

    this->saveData();
    return true;

}

void HandlerPackage_6_Ver340::showTVBC()
{
    qDebug () <<  m_nidqVBCOVar->valueOfVariable().toInt();
    if (1 == m_nidqVBCOVar->valueOfVariable().toInt()){
        m_TVBCVar->setTobeVisible(true);
        m_TVBCVar->setDefaultValue(1);
        m_lenPkgVar->setDefaultValue(48);
    } else {
        m_TVBCVar->setTobeVisible(false);
        m_TVBCVar->setDefaultValue(0);
        m_lenPkgVar->setDefaultValue(40);
    }
    showVariable();
}

void HandlerPackage_6_Ver340::showVariable()
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

bool HandlerPackage_6_Ver340::saveData()
{
    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nidqVBCOVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nidVBCMKVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nidCVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    if (m_TVBCVar->isVisible()){

        data+=m_TVBCVar->valueOfVariable();
    } else{
        data+=EMPTY_VALUE;
    }

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;


    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;

}

void HandlerPackage_6_Ver340::deleteView()
{

    HandlerPackage::deleteView();
    // deleteLater();
}

void HandlerPackage_6_Ver340::loadPkg()
{

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        if (dataList.size() >= 6 ){

            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
            m_nidqVBCOVar->setDefaultValue(dataList.at(3).toInt());
            m_nidVBCMKVar->setDefaultValue(dataList.at(4).toInt());
            m_nidCVar->setDefaultValue(dataList.at(5).toInt());
            if (dataList.at(5)!= EMPTY_VALUE){
                 m_TVBCVar->setDefaultValue(dataList.at(6).toInt());
                 m_TVBCVar->setTobeVisible(true);
            } else {
                m_TVBCVar->setTobeVisible(false);

            }

        }
    }

}
}
