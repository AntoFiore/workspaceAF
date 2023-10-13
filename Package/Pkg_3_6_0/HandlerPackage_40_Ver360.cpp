#include "HandlerPackage_40_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_40_Ver360::HandlerPackage_40_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_qScaleVar=nullptr;
    m_dCurrent=nullptr;
    m_mCurrent=nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg=40;
}

bool HandlerPackage_40_Ver360::creteView()
{

    qDebug () << "HandlerPackage_40_Ver360::creteView();";
    bool ret = false;

    if (nullptr != m_layOutPkg){
        m_maxColumnVariable = 4;
        m_currCol=0;
        m_row =0;

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 40 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->init(GraphicVariablePkg::type_integer);
        m_nidPkgVar->setNameVariable("NID_PACKET");
        m_nidPkgVar->setIsOnlyRead(true);
        m_nidPkgVar->setDefaultValue(m_idPkg);
        m_nidPkgVar->setVisible(false);
        m_nidPkgVar->setTobeVisible(true);
        m_VariableVect.push_back(m_nidPkgVar);
        m_nidPkgVar->setVariableBitSize(8);



        m_qDirVar =  new package::GraphicVariablePkg;
        m_qDirVar->init(GraphicVariablePkg::type_integer);
        m_qDirVar->setNameVariable("Q_DIR");
        m_qDirVar->setRange(0,3);
        m_qDirVar->setDefaultValue(0);
        m_VariableVect.push_back(m_qDirVar);
        m_qDirVar->setVisible(false);
        m_qDirVar->setTobeVisible(true);
        m_qDirVar->setVariableBitSize(2);

        m_lenPkgVar =  new package::GraphicVariablePkg;
        m_lenPkgVar->init(GraphicVariablePkg::type_integer);
        m_lenPkgVar->setNameVariable("L_PACKET");
        m_lenPkgVar->setIsOnlyRead(true);
        m_lenPkgVar->setRange(0,8192);
        m_VariableVect.push_back(m_lenPkgVar);
        m_lenPkgVar->setVisible(false);
        m_lenPkgVar->setTobeVisible(true);
        m_lenPkgVar->setVariableBitSize(13);


        m_qScaleVar =  new package::GraphicVariablePkg;
        m_qScaleVar->init(GraphicVariablePkg::type_integer);
        m_qScaleVar->setNameVariable("Q_SCALE");
        m_qScaleVar->setRange(0,3);
        m_qScaleVar->setDefaultValue(0);
        m_VariableVect.push_back(m_qScaleVar);
        m_qScaleVar->setVisible(false);
        m_qScaleVar->setTobeVisible(true);
        m_qScaleVar->setVariableBitSize(2);

        m_dCurrent =  new package::GraphicVariablePkg;
        m_dCurrent->init(GraphicVariablePkg::type_integer);
        m_dCurrent->setNameVariable("D_CURRENT");
        m_dCurrent->setRange(0,32767);
        m_dCurrent->setDefaultValue(0);
        m_dCurrent->setVisible(false);
        m_dCurrent->setTobeVisible(true);
        m_dCurrent->setVariableBitSize(15);
        m_VariableVect.push_back(m_dCurrent);


        m_mCurrent =  new package::GraphicVariablePkg;
        m_mCurrent->init(GraphicVariablePkg::type_integer);
        m_mCurrent->setNameVariable("M_CURRENT");
        m_mCurrent->setRange(0,10000);
        m_mCurrent->setDefaultValue(0);
        m_mCurrent->setResolution(10);
        m_mCurrent->setVisible(false);
        m_mCurrent->setTobeVisible(true);
        m_mCurrent->setVariableBitSize(10);
        m_VariableVect.push_back(m_mCurrent);

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();
        ret=saveData();
        connect (m_mCurrent,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_40_Ver360::saveData );
        connect (m_dCurrent,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_40_Ver360::saveData );
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_40_Ver360::saveData );
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_40_Ver360::saveData );
        connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_40_Ver360::saveData );
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_40_Ver360::saveData );

    }


    return ret;

}
void HandlerPackage_40_Ver360::showVariable()
{
    m_row=1;
    m_currCol=0;
    m_lenPkgVar->setDefaultValue(countPacketBitSize());
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

bool HandlerPackage_40_Ver360::saveData()
{
    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qScaleVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_dCurrent->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_mCurrent->valueOfVariable();

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;

    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);

    return true;

}

void HandlerPackage_40_Ver360::deleteView()
{

    HandlerPackage::deleteView();

}

void HandlerPackage_40_Ver360::loadPkg()
{
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        if (dataList.size() == 6 ){

            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at (2).toInt());
            m_qScaleVar->setDefaultValue( dataList.at(3).toInt() );
            m_dCurrent->setDefaultValue( dataList.at(4).toInt() );
            m_mCurrent->setDefaultValue( dataList.at(5).toInt() );
        }
    }

}


}
