#include "GraphicHandlerCommand_T_RADIO_HOLE.h"
#include <QDebug>
#include "StorageDataCommand.h"
#include <QDateTime>
#include "DataT_RADIO_HOLE_Command.h"
namespace hndcommand{
GraphicHandlerCommand_T_RADIO_HOLE::GraphicHandlerCommand_T_RADIO_HOLE(QObject *parent)
    : GraphicHandlerCommand{parent}
{
    m_idCommands=T_RADIO_HOLE;
    m_nameTab = "T_RADIO_HOLE_tab";
    m_Ente="T_RADIO_HOLE";
    m_page=CreationScenario_page;
}

bool GraphicHandlerCommand_T_RADIO_HOLE::initCommands()
{

    qDebug () << "GraphicHandlerCommand_T_HOLE::initCommands";
    m_mainWin_Ptr->spinBox_Distance_T_ODO->setRange(0,MAX_DISTANCE);
    m_mainWin_Ptr->spinBox_Delay_T_ODO->setRange(0,MAX_DELAY);
    removeInternalData();
    storageData::Data_T_RADIO_HOLE_Cmds cmds_RadioHole= storageData::StorageDataCommand::istance()->data_T_RADIO_HOLE_Cmds();
    m_mainWin_Ptr->comboBox_Modem_T_RADIO_HOLE->addItem("");
    m_mainWin_Ptr->comboBox_HoleTYpe_T_RADIO_HOLE->addItem("");
    m_mainWin_Ptr->comboBox_Command_T_RADIO_HOLE->addItem("");
  foreach (storageData::Data_T_RADIO_HOLE_Cmd cmd , cmds_RadioHole.cmds) {
        foreach (QString modemId, cmd.modem) {
            m_mainWin_Ptr->comboBox_Modem_T_RADIO_HOLE->addItem(modemId);

       }
        foreach (QString holetype, cmd.hole_type) {
            m_mainWin_Ptr->comboBox_HoleTYpe_T_RADIO_HOLE->addItem(holetype);

        }
        foreach (QString command, cmd.command) {
            m_mainWin_Ptr->comboBox_Command_T_RADIO_HOLE->addItem(command);

        }

    }


    return true;
}

void GraphicHandlerCommand_T_RADIO_HOLE::removeInternalData()
{
    m_mainWin_Ptr->comboBox_Modem_T_RADIO_HOLE->setCurrentText("");
    m_mainWin_Ptr->comboBox_HoleTYpe_T_RADIO_HOLE->setCurrentText("");
    m_mainWin_Ptr->comboBox_Command_T_RADIO_HOLE->setCurrentText("");
    m_mainWin_Ptr->spinBox_Delay_T_APDM->setValue(0);
    m_mainWin_Ptr->spinBox_Distance_T_APDM->setValue(0);

}

bool GraphicHandlerCommand_T_RADIO_HOLE::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{

    bool ret = true ;
    ret=dataValidation();
    if (ret){
        QString cmd  =  QString::number(m_mainWin_Ptr->spinBox_Distance_T_RADIO_HOLE->value());
        cmd+=INTERNAL_SEPARATOR+m_Ente;
        cmd+= INTERNAL_SEPARATOR+QString::number(m_mainWin_Ptr->spinBox_Delay_T_RADIO_HOLE->value());
        cmd+=INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Modem_T_RADIO_HOLE->currentText();
        cmd+=INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_HoleTYpe_T_RADIO_HOLE->currentText();
        cmd+=INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Command_T_RADIO_HOLE->currentText();

        QString pageAndTab = QString::number(m_page)+INTERNAL_SEPARATOR+m_nameTab;
        switch (actionCommand) {
        case add_command:
        //case remove_command:
            m_currentRowTable=-1;
        break;
        default:
            break;
        }

         emit addRemoveUpdateCommand_SG(cmd,actionCommand,pageAndTab,m_currentRowTable);
//        if (actionCommand){
//            bool addCommand = true;
//            emit addOrRemoveCommand_SG(cmd,actionCommand,pageAndTab);
//        } else {
//            bool addCommand = false;
//            emit addOrRemoveCommand_SG(cmd,actionCommand,pageAndTab);
//        }

    }

    return ret;
}

bool GraphicHandlerCommand_T_RADIO_HOLE::dataValidation()
{

    bool ret = true;

    if (m_mainWin_Ptr->comboBox_Modem_T_RADIO_HOLE->currentText()   == "" ||
         m_mainWin_Ptr->comboBox_HoleTYpe_T_RADIO_HOLE->currentText() == "" ||
         m_mainWin_Ptr->comboBox_Command_T_RADIO_HOLE->currentText()  == "" ){
        ret=false;
         m_mainWin_Ptr->statusbar->showMessage(tr(VALUE_NOT_VALID),TIME_OF_STATUS_MESS);
    }

    return ret ;
}

void GraphicHandlerCommand_T_RADIO_HOLE::showCommand_SL(QString command, qint32 rowTable )
{

    QStringList commandList = command.split(INTERNAL_SEPARATOR);
    qint32 sizeCmd = commandList.size();
    if (sizeCmd >=tab_position ){
        QString page = commandList[page_positon];
        QString tab =  commandList[tab_position];
      //  qDebug () << "Page = "<< page;
      //  qDebug () << "tab = "<< tab;
        if (sizeCmd > command_position){
            if ( tab ==m_nameTab){
                m_mainWin_Ptr->tabWidget_Commands->setCurrentIndex(m_TabId);

                QString distance = commandList[distance_position];
                m_mainWin_Ptr->spinBox_Distance_T_RADIO_HOLE->setValue(distance.toInt());

                QString deley =   commandList[deleay_position];
                m_mainWin_Ptr->spinBox_Delay_T_RADIO_HOLE->setValue(deley.toInt());

                QString modemId =   commandList[modem_position];
                m_mainWin_Ptr->comboBox_Modem_T_RADIO_HOLE->setCurrentText(modemId);

                QString holeType =   commandList[holetype_position];
                m_mainWin_Ptr->comboBox_HoleTYpe_T_RADIO_HOLE->setCurrentText(holeType);

                QString command =   commandList[command_position];
                m_mainWin_Ptr->comboBox_Command_T_RADIO_HOLE->setCurrentText(command);

                m_currentRowTable=rowTable;


            }
        }
    }
}
}
