#include "GraphicHandlerCommand_T_SIM.h"
#include <QDebug>
#include "StorageDataCommand.h"
#include <QDateTime>
namespace hndcommand{
GraphicHandlerCommand_T_SIM::GraphicHandlerCommand_T_SIM(QObject *parent)
    : GraphicHandlerCommand{parent}
{
    m_idCommands=T_SIM_CMD;
    m_nameTab = "T_SIM_tab";
    m_Ente="T_SIM";
    m_page=CreationScenario_page;
}

bool GraphicHandlerCommand_T_SIM::initCommands()
{
    qDebug () << "GraphicHandlerCommand_T_SIM::initCommands";
    m_mainWin_Ptr->spinBox_Distance_T_SIM->setRange(0,MAX_DISTANCE);
    m_mainWin_Ptr->spinBox_Delay_T_SIM->setRange(0,MAX_DELAY);
    m_mainWin_Ptr->label_ChannelT_SIM->setVisible(false);
    m_mainWin_Ptr->comboBox_Channel_T_SIM->setVisible(false);
    m_isActionActive=true;

    removeInternalData();
    storageData::Data_T_SIM_Cmds cmd_T_SIM= storageData::StorageDataCommand::istance()->dataT_SIM_Cmds();
    m_mainWin_Ptr->comboBox_Action_T_SIM->addItem("");
    foreach (storageData::Data_T_SIM_Cmd cmd, cmd_T_SIM.cmds) {

        foreach (QString action, cmd.actions) {
            m_mainWin_Ptr->comboBox_Action_T_SIM->addItem(action);
        }


    }
    m_mainWin_Ptr->spinBox_Delay_T_SIM->setValue(0);
    m_mainWin_Ptr->spinBox_Distance_T_SIM->setValue(0);
    connect (m_mainWin_Ptr->comboBox_Action_T_SIM,&QComboBox::currentTextChanged,[this] (const QString &val){

        qDebug () << "Valore del Comando cambiato" <<val;
        if (val.size() ){
            storageData::Data_T_SIM_Cmds cmd_T_SIM= storageData::StorageDataCommand::istance()->dataT_SIM_Cmds();
            foreach (storageData::Data_T_SIM_Cmd cmd, cmd_T_SIM.cmds) {
                if (cmd.actions.size() > 0 ) {
                    if (cmd.actions.at(0) == val ){
                        if (cmd.isValidRange) {
                            m_isActiveRange=true;
                            m_mainWin_Ptr->label_MinValue_T_SIM->setText(QString::number(cmd.range_min));
                            m_mainWin_Ptr->label_MaxValue_T_SIM->setText(QString::number(cmd.range_max));
                            m_mainWin_Ptr->groupBox_Range_T_SIM->setVisible(true);
                            m_mainWin_Ptr->groupBox_Range_T_SIM->setEnabled(true);
                            m_mainWin_Ptr->spinBox_ValeInRange_T_SIM->setRange(cmd.range_min,cmd.range_max);
                            m_mainWin_Ptr->spinBox_ValeInRange_T_SIM->setValue(cmd.range_min);
                        } else {
                            m_mainWin_Ptr->groupBox_Range_T_SIM->setVisible(false);
                            m_mainWin_Ptr->groupBox_Range_T_SIM->setEnabled(false);
                            m_mainWin_Ptr->label_MinValue_T_SIM->clear();
                            m_mainWin_Ptr->label_MaxValue_T_SIM->clear();
                            m_mainWin_Ptr->spinBox_ValeInRange_T_SIM->clear();
                            m_isActiveRange=false;
                        }

                    }
                }
            }
        } else {
            removeInternalData();
        }
    });
    return true;
}

void GraphicHandlerCommand_T_SIM::removeInternalData()
{



    m_mainWin_Ptr->groupBox_Range_T_SIM->setVisible(false);
    m_mainWin_Ptr->groupBox_Range_T_SIM->setEnabled(false);
    m_mainWin_Ptr->label_MinValue_T_SIM->clear();
    m_mainWin_Ptr->label_MaxValue_T_SIM->clear();
    m_mainWin_Ptr->spinBox_ValeInRange_T_SIM->clear();
    m_mainWin_Ptr->spinBox_Delay_T_SIM->clear();
    m_mainWin_Ptr->spinBox_Distance_T_SIM->clear();
    m_isActiveRange=false;
    m_isActionActive=true;

}

bool GraphicHandlerCommand_T_SIM::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{

    bool ret = true ;
    ret = dataValidation();
    if (ret) {
        QString cmd  =  QString::number(m_mainWin_Ptr->spinBox_Distance_T_SIM->value());
        cmd+=INTERNAL_SEPARATOR+m_Ente;
        cmd+=INTERNAL_SEPARATOR+QString::number(m_mainWin_Ptr->spinBox_Delay_T_SIM->value());

        if (m_isActionActive) {
            cmd+= INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Action_T_SIM->currentText();
        }
        if (m_isActiveRange) {
            QString range = QString ("%1%2").arg(INTERNAL_SEPARATOR,
                                                 QString::number(m_mainWin_Ptr->spinBox_ValeInRange_T_SIM->value()) );
            cmd+= range;
        }
        QString pageAndTab = QString::number(m_page)+INTERNAL_SEPARATOR+m_nameTab;
        switch (actionCommand) {
        case add_command:
       // case remove_command:
            m_currentRowTable=-1;
            break;
        default:
            break;
        }


        emit addRemoveUpdateCommand_SG(cmd,actionCommand,pageAndTab,m_currentRowTable);
    }
    return ret;

}

bool GraphicHandlerCommand_T_SIM::dataValidation()
{

    bool ret = true;

    if (m_isActionActive) {
        if ( m_mainWin_Ptr->comboBox_Action_T_SIM->currentText() == ""){
            ret = false;
            m_mainWin_Ptr->statusbar->showMessage(tr(VALUE_NOT_VALID),TIME_OF_STATUS_MESS);
        }
    }

    return ret;
}

void GraphicHandlerCommand_T_SIM::showCommand_SL(QString command, qint32 rowTable )
{
    QStringList commandList = command.split(INTERNAL_SEPARATOR);
    qint32 sizeCmd = commandList.size();
    if (sizeCmd >=tab_position ){
        QString page = commandList[page_positon];
        QString tab =  commandList[tab_position];
        // qDebug () << "Page = "<< page;
        // qDebug () << "tab = "<< tab;

        if (sizeCmd >action_positon ){

            if ( tab ==m_nameTab){
                m_mainWin_Ptr->tabWidget_Commands->setCurrentIndex(m_TabId);

                QString distance = commandList[distance_position];
                m_mainWin_Ptr->spinBox_Distance_T_SIM->setValue(distance.toInt());

                QString delay = commandList[deleay_position];
                m_mainWin_Ptr->spinBox_Delay_T_SIM->setValue(delay.toInt());

                if (m_isActionActive){
                    QString action =   commandList[action_positon];
                    m_mainWin_Ptr->comboBox_Action_T_SIM->setCurrentText(action);

                }
                if (sizeCmd >range_position){
                    QString valueInRange =   commandList[range_position];
                    m_mainWin_Ptr->spinBox_ValeInRange_T_SIM->setValue(valueInRange.toInt());

                }
                m_currentRowTable=rowTable;
            }
        }
    }
    //  qDebug () << "GraphicHandlerCommand_T_SIM::showCommand_SL = " <<command ;
}
}
