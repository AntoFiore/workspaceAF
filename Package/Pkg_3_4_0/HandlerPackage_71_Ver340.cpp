#include "HandlerPackage_71_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_71_Ver340::HandlerPackage_71_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar=nullptr;
    m_qDirVar=nullptr;
    m_lenPkgVar=nullptr;
    m_ScaleVar=nullptr;
    m_dAdhesionVar=nullptr;
    m_lAdhesionVar=nullptr;
    m_mAdhesionVar=nullptr;


    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg=71;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_71_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    QString nameItem;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 71 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->init(GraphicVariablePkg::type_integer);
        m_nidPkgVar->setNameVariable("NID_PACKET");
        m_nidPkgVar->setIsOnlyRead(true);
        m_nidPkgVar->setDefaultValue(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);
        m_nidPkgVar->setVisible(false);
        m_nidPkgVar->setTobeVisible(true);
        m_nidPkgVar->setVariableBitSize(8);


        m_qDirVar =  new package::GraphicVariablePkg ;
        m_qDirVar->init(GraphicVariablePkg::type_integer);
        m_qDirVar->setNameVariable("Q_DIR");
        m_qDirVar->setRange(0,3);
        m_qDirVar->setDefaultValue(0);
        m_qDirVar->setVisible(false);
        m_VariableVect.push_back(m_qDirVar);
        m_qDirVar->setTobeVisible(true);
        m_qDirVar->setVariableBitSize(2);


        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->init(GraphicVariablePkg::type_integer);
        m_lenPkgVar->setNameVariable("L_PACKET");
        m_lenPkgVar->setIsOnlyRead(true);

        m_lenPkgVar->setRange(0,8192);
        m_lenPkgVar->setVisible(false);
        m_VariableVect.push_back(m_lenPkgVar);
        m_lenPkgVar->setTobeVisible(true);
         m_lenPkgVar->setVariableBitSize(13);

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
        m_ScaleVar->setVariableBitSize(2);


        nameItem = QString ("D_ADHESION");
        m_dAdhesionVar =  new package::GraphicVariablePkg ;
        m_dAdhesionVar->init(GraphicVariablePkg::type_integer);
        m_dAdhesionVar->setNameVariable(nameItem);
        m_dAdhesionVar->setInternalName(nameItem);
        m_dAdhesionVar->setDefaultValue(0);
        m_dAdhesionVar->setRange(0,32767);
        m_dAdhesionVar->setVisible(false);
        m_VariableVect.push_back(m_dAdhesionVar);
        m_dAdhesionVar->setTobeVisible(true);
        m_dAdhesionVar->setVariableBitSize(15);


        nameItem = QString ("L_ADHESION");
        m_lAdhesionVar =  new package::GraphicVariablePkg ;
        m_lAdhesionVar->init(GraphicVariablePkg::type_integer);
        m_lAdhesionVar->setNameVariable(nameItem);
        m_lAdhesionVar->setInternalName(nameItem);
        m_lAdhesionVar->setDefaultValue(0);
        m_lAdhesionVar->setRange(0,32767);
        m_lAdhesionVar->setVisible(false);
        m_VariableVect.push_back(m_lAdhesionVar);
        m_lAdhesionVar->setTobeVisible(true);
        m_lAdhesionVar->setVariableBitSize(15);

        nameItem = QString ("M_ADHESION");
        m_mAdhesionVar =  new package::GraphicVariablePkg ;
        m_mAdhesionVar->init(GraphicVariablePkg::type_integer);
        m_mAdhesionVar->setNameVariable(nameItem);
        m_mAdhesionVar->setInternalName(nameItem);
        m_mAdhesionVar->setDefaultValue(0);
        m_mAdhesionVar->setRange(0,1);
        m_mAdhesionVar->setVisible(false);
        m_VariableVect.push_back(m_mAdhesionVar);
        m_mAdhesionVar->setTobeVisible(true);
        m_mAdhesionVar->setVariableBitSize(1);



         m_lenPkgVar->setDefaultValue(countPacketBitSize());

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_isReload){
            loadPkg();
        }
        showVariable();
    }
    connect (m_nidPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_71_Ver340::saveData );
    connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_71_Ver340::saveData );
    connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_71_Ver340::saveData );

    connect (m_ScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_71_Ver340::saveData );

    connect (m_dAdhesionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_71_Ver340::saveData );
    connect (m_lAdhesionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_71_Ver340::saveData );
    connect (m_mAdhesionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_71_Ver340::saveData );
}


void HandlerPackage_71_Ver340::showVariable()
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


bool HandlerPackage_71_Ver340::saveData()
{
    QString data;
    package::GraphicVariablePkg * p_variable = nullptr;

    for (int idx = 0; idx < this->m_VariableVect.size(); idx++)
    {
        p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
        if (p_variable->tobeVisible()){
            data += p_variable->valueOfVariable();
        } else {
            data += EMPTY_VALUE;
        }
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
    }

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;

    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;

}
void HandlerPackage_71_Ver340::loadPkg()
{
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    QString var;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);

        if (dataList.size() >= m_VariableVect.size())
        {
            for (int idx = 0; idx < m_VariableVect.size(); idx++) {
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                if (nullptr != p_variable){
                    var = dataList.at(idx);
                    if (var != EMPTY_VALUE){
                        p_variable->setDefaultValue(var.toInt());
                        p_variable->setTobeVisible(true);
                    } else {
                        p_variable->setTobeVisible(false);
                    }
                }
            }
        }

    }

}


void HandlerPackage_71_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}


}
