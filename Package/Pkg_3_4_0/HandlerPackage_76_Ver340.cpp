#include "HandlerPackage_76_Ver340.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_76_Ver340::HandlerPackage_76_Ver340(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;

    m_qScaleVar = nullptr;

    m_qTextclassVar = nullptr;
    m_qTextdisplayVar = nullptr;
    m_dTextdisplayVar = nullptr;
    m_mModeltextdisplay_1_Var = nullptr;
    m_mLeveltextdisplay_1_Var = nullptr;
    m_nidNtc_1_Var = nullptr;

    m_lTextdisplayVar = nullptr;
    m_tTextdisplayVar = nullptr;
    m_mModeltextdisplay_2_Var = nullptr;
    m_mLeveltextdisplay_2_Var = nullptr;
    m_nidNtc_2_Var = nullptr;

    m_qTextconfirmVar = nullptr;
    m_qConftextdisplayVar = nullptr;
    m_qTextreportVar = nullptr;
    m_nidTextmessageVar = nullptr;
    m_nidCVar = nullptr;
    m_nidRBCVar = nullptr;

    m_lTextVar = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
    m_idPkg = 76;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_76_Ver340::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 76 - " + QString(BASELINE_3_4_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);

        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_lenPkgVar = new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(100);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_qScaleVar = new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_qTextclassVar = new package::GraphicVariablePkg ;
        m_qTextclassVar->set_Q_TEXTCLASS();
        m_VariableVect.push_back(m_qTextclassVar);
        connect (m_qTextclassVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_qTextdisplayVar = new package::GraphicVariablePkg ;
        m_qTextdisplayVar->set_Q_TEXTDISPLAY();
        m_VariableVect.push_back(m_qTextdisplayVar);
        connect (m_qTextdisplayVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_dTextdisplayVar = new package::GraphicVariablePkg ;
        m_dTextdisplayVar->set_D_TEXTDISPLAY();
        m_VariableVect.push_back(m_dTextdisplayVar);
        connect (m_dTextdisplayVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_mModeltextdisplay_1_Var = new package::GraphicVariablePkg ;
        m_mModeltextdisplay_1_Var->set_M_MODETEXTDISPLAY();
        m_VariableVect.push_back(m_mModeltextdisplay_1_Var);
        connect (m_mModeltextdisplay_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_mLeveltextdisplay_1_Var = new package::GraphicVariablePkg ;
        m_mLeveltextdisplay_1_Var->set_M_LEVELTEXTDISPLAY();
        m_VariableVect.push_back(m_mLeveltextdisplay_1_Var);
        connect (m_mLeveltextdisplay_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );
        connect (m_mLeveltextdisplay_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::show_nidNtc_1_SL );

        {
            m_nidNtc_1_Var = new package::GraphicVariablePkg ;
            m_nidNtc_1_Var->set_NID_NTC();
            m_nidNtc_1_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_nidNtc_1_Var);
            connect (m_nidNtc_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );
        }

        m_lTextdisplayVar = new package::GraphicVariablePkg ;
        m_lTextdisplayVar->set_L_TEXTDISPLAY();
        m_VariableVect.push_back(m_lTextdisplayVar);
        connect (m_lTextdisplayVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_tTextdisplayVar = new package::GraphicVariablePkg ;
        m_tTextdisplayVar->set_T_TEXTDISPLAY();
        m_VariableVect.push_back(m_tTextdisplayVar);
        connect (m_tTextdisplayVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_mModeltextdisplay_2_Var = new package::GraphicVariablePkg ;
        m_mModeltextdisplay_2_Var->set_M_MODETEXTDISPLAY();
        m_VariableVect.push_back(m_mModeltextdisplay_2_Var);
        connect (m_mModeltextdisplay_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

        m_mLeveltextdisplay_2_Var = new package::GraphicVariablePkg ;
        m_mLeveltextdisplay_2_Var->set_M_LEVELTEXTDISPLAY();
        m_VariableVect.push_back(m_mLeveltextdisplay_2_Var);
        connect (m_mLeveltextdisplay_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );
        connect (m_mLeveltextdisplay_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::show_nidNtc_2_SL );

        {
            m_nidNtc_2_Var = new package::GraphicVariablePkg ;
            m_nidNtc_2_Var->set_NID_NTC();
            m_nidNtc_2_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_nidNtc_2_Var);
            connect (m_nidNtc_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );
        }

        m_qTextconfirmVar = new package::GraphicVariablePkg ;
        m_qTextconfirmVar->set_Q_TEXTCONFIRM();
        m_VariableVect.push_back(m_qTextconfirmVar);
        connect (m_qTextconfirmVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );
        connect (m_qTextconfirmVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::show_qTextConfirm_SL );

        {
            m_qConftextdisplayVar = new package::GraphicVariablePkg ;
            m_qConftextdisplayVar->set_Q_CONFTEXTDISPLAY();
            m_qConftextdisplayVar->setTobeVisible(false);
            m_VariableVect.push_back(m_qConftextdisplayVar);
            connect (m_qConftextdisplayVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

            m_qTextreportVar = new package::GraphicVariablePkg ;
            m_qTextreportVar->set_Q_TEXTREPORT();
            m_qTextreportVar->setTobeVisible(false);
            m_VariableVect.push_back(m_qTextreportVar);
            connect (m_qTextreportVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

            m_nidTextmessageVar = new package::GraphicVariablePkg ;
            m_nidTextmessageVar->set_NID_TEXTMESSAGE();
            m_nidTextmessageVar->setTobeVisible(false);
            m_VariableVect.push_back(m_nidTextmessageVar);
            connect (m_nidTextmessageVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

            m_nidCVar = new package::GraphicVariablePkg ;
            m_nidCVar->set_NID_C();
            m_nidCVar->setTobeVisible(false);
            m_VariableVect.push_back(m_nidCVar);
            connect (m_nidCVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );

            m_nidRBCVar = new package::GraphicVariablePkg ;
            m_nidRBCVar->set_NID_RBC();
            m_nidRBCVar->setTobeVisible(false);
            m_VariableVect.push_back(m_nidRBCVar);
            connect (m_nidRBCVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );
        }

        m_lTextVar = new package::GraphicVariablePkg ;
        m_lTextVar->set_L_TEXT();
        m_VariableVect.push_back(m_lTextVar);
        connect (m_lTextVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_76_Ver340::saveData );



        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();

    }
    return true;

}

void HandlerPackage_76_Ver340::show_nidNtc_1_SL()
{
    int value = m_mLeveltextdisplay_1_Var->valueOfVariable().toInt();
    if (1 == value){
        m_nidNtc_1_Var->setTobeVisible(true);
        m_nidNtc_1_Var->setDefaultValue(0);
    } else {
        m_nidNtc_1_Var->setTobeVisible(false);
        m_nidNtc_1_Var->setDefaultValue(0);
    }
    showVariable();
}

void HandlerPackage_76_Ver340::show_nidNtc_2_SL()
{
    int value = m_mLeveltextdisplay_2_Var->valueOfVariable().toInt();
    if (1 == value){
        m_nidNtc_2_Var->setTobeVisible(true);
        m_nidNtc_2_Var->setDefaultValue(0);
    } else {
        m_nidNtc_2_Var->setTobeVisible(false);
        m_nidNtc_2_Var->setDefaultValue(0);
    }
    showVariable();
}

void HandlerPackage_76_Ver340::show_qTextConfirm_SL()
{
    int value = m_qTextconfirmVar->valueOfVariable().toInt();
    if (0 == value){
        m_qConftextdisplayVar->setTobeVisible(false);
        m_qConftextdisplayVar->setDefaultValue(0);
        m_qTextreportVar->setTobeVisible(false);
        m_qTextreportVar->setDefaultValue(0);
        m_nidTextmessageVar->setTobeVisible(false);
        m_nidTextmessageVar->setDefaultValue(0);
        m_nidCVar->setTobeVisible(false);
        m_nidCVar->setDefaultValue(0);
        m_nidRBCVar->setTobeVisible(false);
        m_nidRBCVar->setDefaultValue(0);
    } else if (1 == value){
        m_qConftextdisplayVar->setTobeVisible(true);
        m_qTextreportVar->setTobeVisible(true);

        m_nidTextmessageVar->setTobeVisible(true);
        m_nidCVar->setTobeVisible(true);
        m_nidRBCVar->setTobeVisible(true);
    } else {
        m_qConftextdisplayVar->setTobeVisible(true);
        m_qTextreportVar->setTobeVisible(true);

        m_nidTextmessageVar->setTobeVisible(false);
        m_nidTextmessageVar->setDefaultValue(0);
        m_nidCVar->setTobeVisible(false);
        m_nidCVar->setDefaultValue(0);
        m_nidRBCVar->setTobeVisible(false);
        m_nidRBCVar->setDefaultValue(0);
    }

    showVariable();
}

void HandlerPackage_76_Ver340::loadPkg()
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

void HandlerPackage_76_Ver340::showVariable()
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

bool HandlerPackage_76_Ver340::saveData()
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

void HandlerPackage_76_Ver340::deleteView()
{
    HandlerPackage::deleteView();
}





}
