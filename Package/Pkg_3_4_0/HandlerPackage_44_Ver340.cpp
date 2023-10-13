#include "HandlerPackage_44_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_44_Ver340::HandlerPackage_44_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_NidXUserVar=nullptr;
    m_NidNtcVar=nullptr;
    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=44;
}

bool HandlerPackage_44_Ver340::creteView()
{
    bool ret = false;
    if (nullptr != m_layOutPkg){
        m_maxColumnVariable = 4;
        m_currCol=0;
        m_row =0;

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 44 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->init(GraphicVariablePkg::type_integer);
        m_nidPkgVar->setNameVariable("NID_PACKET");
        m_nidPkgVar->setIsOnlyRead(true);
        m_nidPkgVar->setDefaultValue(m_idPkg);
        m_nidPkgVar->setVisible(false);
        m_nidPkgVar->setTobeVisible(true);
        m_nidPkgVar->setVariableBitSize(8);
        m_VariableVect.push_back(m_nidPkgVar);
        connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_44_Ver340::saveData );


        m_qDirVar =  new package::GraphicVariablePkg;
        m_qDirVar->init(GraphicVariablePkg::type_integer);
        m_qDirVar->setNameVariable("Q_DIR");
        m_qDirVar->setRange(0,3);
        m_qDirVar->setDefaultValue(0);
        m_qDirVar->setVisible(false);
        m_qDirVar->setTobeVisible(true);
        m_qDirVar->setVariableBitSize(2);
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_44_Ver340::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg;
        m_lenPkgVar->init(GraphicVariablePkg::type_integer);
        m_lenPkgVar->setNameVariable("L_PACKET");
        m_lenPkgVar->setIsOnlyRead(true);
        m_lenPkgVar->setVisible(false);
        m_lenPkgVar->setTobeVisible(true);
        m_lenPkgVar->setVariableBitSize(13);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_44_Ver340::saveData );

        m_NidXUserVar =  new package::GraphicVariablePkg;
        m_NidXUserVar->init(GraphicVariablePkg::type_integer);
        m_NidXUserVar->setNameVariable("NID_XUSER");
        m_NidXUserVar->setRange(0,511);
        m_NidXUserVar->setDefaultValue(0);
        m_NidXUserVar->setVisible(false);
        m_NidXUserVar->setTobeVisible(true);
        m_NidXUserVar->setVariableBitSize(9);

        m_VariableVect.push_back(m_NidXUserVar);
        connect (m_NidXUserVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_44_Ver340::saveData );
        connect (m_NidXUserVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_44_Ver340::showNid_Ntc_SL );



        m_NidNtcVar =  new package::GraphicVariablePkg;
        m_NidNtcVar->init(GraphicVariablePkg::type_integer);
        m_NidNtcVar->setNameVariable("NID_NTC");
        m_NidNtcVar->setRange(0,255);
        m_NidNtcVar->setDefaultValue(0);
        m_NidNtcVar->setVisible(false);
        m_NidNtcVar->setTobeVisible(false);
        m_NidNtcVar->setVariableBitSize(8);
        m_VariableVect.push_back(m_NidNtcVar);

        connect (m_NidNtcVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_44_Ver340::saveData );

        m_lenPkgVar->setDefaultValue(countPacketBitSize());
        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();
        ret = true;
    }



    return ret;

}
void HandlerPackage_44_Ver340::showNid_Ntc_SL()
{
    if (102 == m_NidXUserVar->valueOfVariable().toInt()){
         m_NidNtcVar->setTobeVisible(true);
    } else {
        m_NidNtcVar->setTobeVisible(false);
    }
    showVariable();
}

void HandlerPackage_44_Ver340::showVariable()
{
    m_row=1;
    m_currCol=0;

    qint16 actualPktSize = this->countPacketBitSize();
    m_lenPkgVar->setDefaultValue(actualPktSize);

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

bool HandlerPackage_44_Ver340::saveData()
{
    QString data = m_nidPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_qDirVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_lenPkgVar->valueOfVariable();
    data+=INTERNAL_FIELD_SEPARATOR_PKG;
    data+=m_NidXUserVar->valueOfVariable();
    if (m_NidNtcVar->isVisible()){
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
        data+=m_NidNtcVar->valueOfVariable();
    }

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;


    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;

}

void HandlerPackage_44_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}

void HandlerPackage_44_Ver340::loadPkg()
{
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    if (pkg != nullptr){

        m_isReload=false;

        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
        qint16 size = dataList.size();
        if (size >= 4 ){
            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
            m_NidXUserVar->setDefaultValue( dataList.at(3).toInt() );
            if (size==5){
                m_NidNtcVar->setDefaultValue( dataList.at (4).toInt() );
                m_NidNtcVar->setVisible(true);

            }
        }
    }

}


}
