#include "HandlerPackage_39_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_39_Ver360::HandlerPackage_39_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar     =nullptr;
    m_qDirVar       =nullptr;
    m_lenPkgVar     =nullptr;
    m_qScaleVar        =nullptr;

    m_dTractionVar     =nullptr;
    m_mVoltageVar      =nullptr;
    m_nidCtractionVar  =nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg=39;
}

bool HandlerPackage_39_Ver360::creteView()
{

    qDebug () << "HandlerPackage_39_Ver360::creteView();";
    bool ret = false;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 39 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->init(GraphicVariablePkg::type_integer);
        m_nidPkgVar->setNameVariable("NID_PACKET");
        m_nidPkgVar->setIsOnlyRead(true);
        m_nidPkgVar->setDefaultValue(m_idPkg);
        m_nidPkgVar->setVisible(false);
        m_nidPkgVar->setTobeVisible(true);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar =  new package::GraphicVariablePkg;
        m_qDirVar->init(GraphicVariablePkg::type_integer);
        m_qDirVar->setNameVariable("Q_DIR");
        m_qDirVar->setRange(0,3);
        m_qDirVar->setDefaultValue(1);
        m_qDirVar->setVisible(false);
        m_qDirVar->setTobeVisible(true);
        m_VariableVect.push_back(m_qDirVar);

        m_lenPkgVar =  new package::GraphicVariablePkg;
        m_lenPkgVar->init(GraphicVariablePkg::type_integer);
        m_lenPkgVar->setNameVariable("L_PACKET");
        m_lenPkgVar->setIsOnlyRead(true);
        m_lenPkgVar->setDefaultValue(30);
        m_lenPkgVar->setVisible(false);
        m_lenPkgVar->setTobeVisible(true);
        m_VariableVect.push_back(m_lenPkgVar);

        m_qScaleVar =  new package::GraphicVariablePkg;
        m_qScaleVar->init(GraphicVariablePkg::type_integer);
        m_qScaleVar->setNameVariable("Q_SCALE");
        m_qScaleVar->setRange(0,3);
        m_qScaleVar->setDefaultValue(1);
        m_qScaleVar->setVisible(false);
        m_qScaleVar->setTobeVisible(true);
        m_VariableVect.push_back(m_qScaleVar);

        m_dTractionVar =  new package::GraphicVariablePkg;
        m_dTractionVar->init(GraphicVariablePkg::type_integer);
        m_dTractionVar->setNameVariable("D_TRACTION");
        m_dTractionVar->setRange(0,32767);
        m_dTractionVar->setDefaultValue(0);
        m_dTractionVar->setVisible(false);
        m_dTractionVar->setTobeVisible(true);
        m_VariableVect.push_back(m_dTractionVar);

        m_mVoltageVar =  new package::GraphicVariablePkg;
        m_mVoltageVar->init(GraphicVariablePkg::type_integer);
        m_mVoltageVar->setNameVariable("M_VOLTAGE");
        m_mVoltageVar->setRange(0,15);
        m_mVoltageVar->setDefaultValue(0);
        m_mVoltageVar->setVisible(false);
        m_mVoltageVar->setTobeVisible(true);
        m_VariableVect.push_back(m_mVoltageVar);

        m_nidCtractionVar =  new package::GraphicVariablePkg;
        m_nidCtractionVar->init(GraphicVariablePkg::type_integer);
        m_nidCtractionVar->setNameVariable("NID_CTRACTION");
        m_nidCtractionVar->setRange(0,1023);
        m_nidCtractionVar->setDefaultValue(0);
        m_nidCtractionVar->setVisible(false);
        m_nidCtractionVar->setTobeVisible(false);
        m_VariableVect.push_back(m_nidCtractionVar);


        qint16 totVar = m_VariableVect.size();
        int currCol =0;
        int row =0;

        m_layOutPkg->addWidget(m_titlePkg,row,currCol);
        row++;
        if (m_isReload) {
            loadPkg();
        }
        showVariable();
        ret = saveData();


        connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_39_Ver360::saveData );
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_39_Ver360::saveData );
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_39_Ver360::saveData );
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_39_Ver360::saveData );
        connect (m_dTractionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_39_Ver360::saveData );
        connect (m_mVoltageVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_39_Ver360::saveData );
         connect (m_mVoltageVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_39_Ver360::showNidCtraction );
        connect (m_nidCtractionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_39_Ver360::saveData );
    }


    return ret;

}

bool HandlerPackage_39_Ver360::saveData()
{
    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qScaleVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_dTractionVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_mVoltageVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    if (m_nidCtractionVar->isVisible()){

        data+=m_nidCtractionVar->valueOfVariable();

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

void HandlerPackage_39_Ver360::deleteView()
{

    HandlerPackage::deleteView();
    // deleteLater();
}

void HandlerPackage_39_Ver360::loadPkg()
{

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        if (dataList.size() == 7 ){

            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
            m_qScaleVar->setDefaultValue( dataList.at(3).toInt() );

            m_dTractionVar->setDefaultValue( dataList.at(4).toInt() );
            m_mVoltageVar->setDefaultValue( dataList.at(5).toInt() );

            if (dataList.at(6)!= EMPTY_VALUE){
                m_nidCtractionVar->setDefaultValue(dataList.at(6).toInt());
                m_nidCtractionVar->setTobeVisible(true);
            } else {
                m_nidCtractionVar->setTobeVisible(false);

            }
        }
    }



}

void HandlerPackage_39_Ver360::showNidCtraction()
{
    qDebug () <<  m_mVoltageVar->valueOfVariable().toInt();
    if (0 != m_mVoltageVar->valueOfVariable().toInt()){
        m_nidCtractionVar->setTobeVisible(true);
        m_lenPkgVar->setDefaultValue(54);
    } else {
        m_nidCtractionVar->setTobeVisible(false);
        m_lenPkgVar->setDefaultValue(44);
    }
    showVariable();
}

void HandlerPackage_39_Ver360::showVariable()
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

}
