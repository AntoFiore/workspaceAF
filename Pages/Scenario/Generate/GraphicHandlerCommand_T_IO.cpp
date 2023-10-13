#include "GraphicHandlerCommand_T_IO.h"
#include <QDebug>
#include "StorageDataCommand.h"
#include <QDateTime>
namespace hndcommand{
GraphicHandlerCommand_T_IO::GraphicHandlerCommand_T_IO(QObject *parent)
    : GraphicHandlerCommand{parent}
{
    m_idCommands=T_IO_CMD;
    m_nameTab = "T_IO_tab";
    m_Ente="T_IO";
    m_page=CreationScenario_page;
}

bool GraphicHandlerCommand_T_IO::initCommands()
{
    qDebug () << "GraphicHandlerCommand_T_IO::initCommands";
    m_mainWin_Ptr->spinBox_Distance_T_IO->setRange(0,MAX_DISTANCE);
    m_mainWin_Ptr->spinBox_Delay_T_IO->setRange(0,MAX_DELAY);

    removeInternalData();
    storageData::Data_T_IO_Cmds cmd_T_IO= storageData::StorageDataCommand::istance()->dataT_IO_Cmds();
    m_mainWin_Ptr->comboBox_Channel_T_IO->addItem("");
    foreach (storageData::Data_T_IO_Cmd cmd, cmd_T_IO.cmds) {
        m_mainWin_Ptr->comboBox_Channel_T_IO->addItem(cmd.nameChannel);
    }
    m_mainWin_Ptr->spinBox_Delay_T_IO->setValue(0);
    m_mainWin_Ptr->spinBox_Distance_T_IO->setValue(0);
    connect (m_mainWin_Ptr->comboBox_Channel_T_IO,&QComboBox::currentTextChanged,[this] (const QString &val){

        qDebug () << "Valore del Comando cambiato" <<val;
        if (val.size() ){

            m_mainWin_Ptr->comboBox_Action_T_IO->clear();

            storageData::Data_T_IO_Cmds cmd_T_IO= storageData::StorageDataCommand::istance()->dataT_IO_Cmds();
            foreach (storageData::Data_T_IO_Cmd cmd, cmd_T_IO.cmds) {
                if (cmd.nameChannel == val ){

                    if (cmd.actions.size() ){
                        m_mainWin_Ptr->label_Action_T_IO->setVisible(true);
                        m_mainWin_Ptr->comboBox_Action_T_IO->setVisible(true);
                        m_mainWin_Ptr->comboBox_Action_T_IO->addItem("");
                        m_isActionActive=true;
                        foreach (QString action, cmd.actions) {
                            m_mainWin_Ptr->comboBox_Action_T_IO->addItem(action);
                        }
                        if (cmd.defaultactions.size()  && cmd.actions.size() ){
                            qint32 sizeAction= m_mainWin_Ptr->comboBox_Action_T_IO->count();
                            for (int idx =0 ; idx < sizeAction;idx++) {

                                qDebug () <<m_mainWin_Ptr->comboBox_Action_T_IO->itemText(idx).trimmed().toUpper();
                                qDebug () <<cmd.defaultactions.at(0).trimmed().toUpper();

                                if ( m_mainWin_Ptr->comboBox_Action_T_IO->itemText(idx) == cmd.defaultactions.at(0) )
                                {
                                    m_mainWin_Ptr->comboBox_Action_T_IO->setCurrentText(cmd.defaultactions.at(0));
                                    break;
                                }
                            }
                        }
                    } else {
                        m_isActionActive=false;
                        m_mainWin_Ptr->label_Action_T_IO->setVisible(false);
                        m_mainWin_Ptr->comboBox_Action_T_IO->setVisible(false);
                    }

                    if (cmd.isValidRange) {

                        m_isActiveRange=true;
                        m_mainWin_Ptr->label_MinValue_T_IO->setText(QString::number(cmd.range_min));
                        m_mainWin_Ptr->label_MaxValue_T_IO->setText(QString::number(cmd.range_max));
                        m_mainWin_Ptr->groupBox_Range_T_IO->setVisible(true);
                        m_mainWin_Ptr->groupBox_Range_T_IO->setEnabled(true);
                        m_mainWin_Ptr->spinBox_ValeInRange_T_IO->setRange(cmd.range_min,cmd.range_max);
                        m_mainWin_Ptr->spinBox_ValeInRange_T_IO->setValue(cmd.range_min);
                    } else {
                        m_mainWin_Ptr->groupBox_Range_T_IO->setVisible(false);
                        m_mainWin_Ptr->groupBox_Range_T_IO->setEnabled(false);
                        m_mainWin_Ptr->label_MinValue_T_IO->clear();
                        m_mainWin_Ptr->label_MaxValue_T_IO->clear();
                        m_mainWin_Ptr->spinBox_ValeInRange_T_IO->clear();
                        m_isActiveRange=false;
                    }

                }
            }
        } else {
            removeInternalData();
        }
    });
    return true;
}

void GraphicHandlerCommand_T_IO::removeInternalData()
{
    m_mainWin_Ptr->label_Action_T_IO->setVisible(false);
    m_mainWin_Ptr->comboBox_Action_T_IO->setVisible(false);
    m_mainWin_Ptr->comboBox_Action_T_IO->clear();
    m_mainWin_Ptr->groupBox_Range_T_IO->setVisible(false);
    m_mainWin_Ptr->groupBox_Range_T_IO->setEnabled(false);
    m_mainWin_Ptr->label_MinValue_T_IO->clear();
    m_mainWin_Ptr->label_MaxValue_T_IO->clear();
    m_mainWin_Ptr->spinBox_ValeInRange_T_IO->clear();
    m_mainWin_Ptr->spinBox_Delay_T_IO->clear();
    m_mainWin_Ptr->spinBox_Distance_T_IO->clear();
    m_mainWin_Ptr->comboBox_Channel_T_IO->setCurrentText("");
    m_isActiveRange=false;
    m_isActionActive=false;

}

bool GraphicHandlerCommand_T_IO::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{
    // qDebug () << "GraphicHandlerCommand_T_IO::addCommand()";
    bool ret = dataValidation() ;
    if (ret ){


        QString cmd  =  QString::number(m_mainWin_Ptr->spinBox_Distance_T_IO->value());
        cmd+=INTERNAL_SEPARATOR+m_Ente;
        cmd+=INTERNAL_SEPARATOR+QString::number(m_mainWin_Ptr->spinBox_Delay_T_IO->value());

        switch (actionCommand) {
        case add_command:
       // case remove_command:
            m_currentRowTable=-1;
            break;
        default:
            break;
        }


        if (m_isActionActive) {
            cmd+= INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Action_T_IO->currentText();
        }
        if (m_isActiveRange) {
            QString range = QString ("%1%2").arg(INTERNAL_SEPARATOR,
                                                 QString::number(m_mainWin_Ptr->spinBox_ValeInRange_T_IO->value()) );

            cmd+= range;
        }
        cmd +=INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Channel_T_IO->currentText();


        if (m_isActionActive || m_isActiveRange ){
            QString pageAndTab = QString::number(m_page)+INTERNAL_SEPARATOR+m_nameTab;
            emit addRemoveUpdateCommand_SG(cmd,actionCommand,pageAndTab,m_currentRowTable);
            //        if (actionCommand){
            //            bool addCommand = true;
            //            emit addOrRemoveCommand_SG(cmd,actionCommand,pageAndTab);
            //        } else {
            //            bool addCommand = false;
            //            emit addOrRemoveCommand_SG(cmd,actionCommand,pageAndTab);
            //        }
        } else {
            ret = false;
            qDebug () << "Command Step Not Valid";
        }
    }
    return ret;

}

bool GraphicHandlerCommand_T_IO::dataValidation()
{
    bool ret = true;
    if ( m_mainWin_Ptr->comboBox_Channel_T_IO->currentText() == ""){
        ret = false;
        m_mainWin_Ptr->statusbar->showMessage(tr(VALUE_NOT_VALID),TIME_OF_STATUS_MESS);
    }
    if (ret) {
        if (m_isActionActive) {
            if (m_mainWin_Ptr->comboBox_Action_T_IO->currentText() == ""){
                ret = false;
                m_mainWin_Ptr->statusbar->showMessage(tr(VALUE_NOT_VALID),TIME_OF_STATUS_MESS);
            }
        }
    }
    return ret;
}

void GraphicHandlerCommand_T_IO::showCommand_SL(QString command , qint32 rowTable)
{
    QStringList commandList = command.split(INTERNAL_SEPARATOR);
    qint32 sizeCmd = commandList.size();

    if (sizeCmd >=tab_position ){

        QString tab =  commandList[tab_position];
        //   qDebug () << "Page = "<< page;
        //   qDebug () << "tab = "<< tab;
        if (commandList.size() >channel_position ){

            if ( tab ==m_nameTab){
                m_mainWin_Ptr->tabWidget_Commands->setCurrentIndex(m_TabId);

                QString distance = commandList[distance_position];
                m_mainWin_Ptr->spinBox_Distance_T_IO->setValue(distance.toInt());

                QString delay = commandList[deleay_position];
                m_mainWin_Ptr->spinBox_Delay_T_IO->setValue(delay.toInt());


                QString channel =   commandList[channel_position];
                m_mainWin_Ptr->comboBox_Channel_T_IO->setCurrentText(channel);
                if (m_isActiveRange) {
                    QString valueInRange =   commandList[rangeOrAction_position];
                    m_mainWin_Ptr->spinBox_ValeInRange_T_IO->setValue(valueInRange.toInt());

                }
                if (m_isActionActive){
                    QString action =   commandList[rangeOrAction_position];
                    m_mainWin_Ptr->comboBox_Action_T_IO->setCurrentText(action);
                }
                m_currentRowTable=rowTable;
            }
        }
    }

    // qDebug () << "GraphicHandlerCommand_T_IO::showCommand_SL = " <<command ;
}
}
