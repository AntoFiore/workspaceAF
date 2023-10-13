#include "HandlerPackage_42_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_42_Ver360::HandlerPackage_42_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_qRbcVar=nullptr;
    m_nidCVar=nullptr;
    m_nidRbcVar=nullptr;
    m_nidRadioVar=nullptr;
    m_SleepSessionVar=nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg=42;
}

bool HandlerPackage_42_Ver360::creteView()
{

    qDebug () << "HandlerPackage_40_Ver360::creteView();";
    bool ret = false;

    if (nullptr != m_layOutPkg){
        m_maxColumnVariable = 4;
        m_currCol=0;
        m_row =0;

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 42 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->init(GraphicVariablePkg::type_integer);
        m_nidPkgVar->setNameVariable("NID_PACKET");
        m_nidPkgVar->setIsOnlyRead(true);
        m_nidPkgVar->setDefaultValue(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);
        m_nidPkgVar->setVisible(false);
        m_nidPkgVar->setTobeVisible(true);
        m_nidPkgVar->setVariableBitSize(8);



        m_qDirVar =  new package::GraphicVariablePkg;
        m_qDirVar->init(GraphicVariablePkg::type_integer);
        m_qDirVar->setNameVariable("Q_DIR");
        m_qDirVar->setRange(0,3);
        m_qDirVar->setDefaultValue(0);
        m_qDirVar->setVisible(false);
        m_qDirVar->setTobeVisible(true);
        m_qDirVar->setVariableBitSize(2);
        m_VariableVect.push_back(m_qDirVar);


        m_lenPkgVar =  new package::GraphicVariablePkg;
        m_lenPkgVar->init(GraphicVariablePkg::type_integer);
        m_lenPkgVar->setNameVariable("L_PACKET");
        m_lenPkgVar->setIsOnlyRead(true);
        m_lenPkgVar->setRange(0,8192);
        m_lenPkgVar->setVisible(false);
        m_lenPkgVar->setTobeVisible(true);
        m_lenPkgVar->setVariableBitSize(13);
        m_VariableVect.push_back(m_lenPkgVar);



        m_qRbcVar =  new package::GraphicVariablePkg;
        m_qRbcVar->init(GraphicVariablePkg::type_integer);
        m_qRbcVar->setNameVariable("Q_RBC");
        m_qRbcVar->setRange(0,1);
        m_qRbcVar->setDefaultValue(0);
        m_qRbcVar->setVisible(false);
        m_qRbcVar->setTobeVisible(true);
        m_qRbcVar->setVariableBitSize(1);
        m_VariableVect.push_back(m_qRbcVar);



        m_nidCVar =  new package::GraphicVariablePkg;
        m_nidCVar->init(GraphicVariablePkg::type_integer);
        m_nidCVar->setNameVariable("NID_C");
        m_nidCVar->setRange(0,1023);
        m_nidCVar->setDefaultValue(0);
        m_nidCVar->setVisible(false);
        m_nidCVar->setTobeVisible(true);
        m_nidCVar->setVariableBitSize(10);
        m_VariableVect.push_back(m_nidCVar);


        m_nidRbcVar =  new package::GraphicVariablePkg;
        m_nidRbcVar->init(GraphicVariablePkg::type_integer);
        m_nidRbcVar->setNameVariable("NID_RBC");
        m_nidRbcVar->setRange(0,16383);
        m_nidRbcVar->setDefaultValue(0);
        m_nidRbcVar->setVisible(false);
        m_nidRbcVar->setTobeVisible(true);
        m_nidRbcVar->setVariableBitSize(14);
        m_VariableVect.push_back(m_nidRbcVar);


        m_nidRadioVar =  new package::GraphicVariablePkg;
        m_nidRadioVar->set_NID_RADIO();
        m_VariableVect.push_back(m_nidRadioVar);

        m_SleepSessionVar =  new package::GraphicVariablePkg;
        m_SleepSessionVar->init(GraphicVariablePkg::type_integer);
        m_SleepSessionVar->setNameVariable("Q_SLEEPSESSION");
        m_SleepSessionVar->setRange(0,1);
        m_SleepSessionVar->setDefaultValue(0);
        m_SleepSessionVar->setVisible(false);
        m_SleepSessionVar->setTobeVisible(true);
        m_SleepSessionVar->setVariableBitSize(1);
        m_VariableVect.push_back(m_SleepSessionVar);

        m_lenPkgVar->setDefaultValue(countPacketBitSize());
        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }

        showVariable();
        ret=saveData();
        connect (m_SleepSessionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_42_Ver360::saveData );
        connect (m_nidRadioVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_42_Ver360::saveData );
        connect (m_nidRbcVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_42_Ver360::saveData );
        connect (m_nidCVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_42_Ver360::saveData );
        connect (m_qRbcVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_42_Ver360::saveData );
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_42_Ver360::saveData );
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_42_Ver360::saveData );
        connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_42_Ver360::saveData );



    }
    return ret;

}
void HandlerPackage_42_Ver360::showVariable()
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
bool HandlerPackage_42_Ver360::saveData()
{
    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qRbcVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nidCVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nidRbcVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_nidRadioVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_SleepSessionVar->valueOfVariable();


    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;

    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);




    return true;

}

void HandlerPackage_42_Ver360::deleteView()
{

    HandlerPackage::deleteView();

}

void HandlerPackage_42_Ver360::loadPkg()
{
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        if (dataList.size() == 8 ){

            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
            m_qRbcVar->setDefaultValue( dataList.at(3).toInt() );
            m_nidCVar->setDefaultValue( dataList.at(4).toInt() );
            m_nidRbcVar->setDefaultValue( dataList.at(5).toInt() );
            m_nidRadioVar->setDefaultValue( dataList.at(6));
            m_SleepSessionVar->setDefaultValue( dataList.at(7).toInt() );
        }
    }


}




}
