#include "GraphicHandlerCommand_MT_APDM.h"
#include <QDebug>
#include "StorageDataCommand.h"
#include <QDateTime>
namespace hndcommand{
GraphicHandlerCommand_MT_APDM::GraphicHandlerCommand_MT_APDM(QObject *parent)
    : GraphicHandlerCommand{parent}
{
    m_idCommands=MT_APDM_CMD;
    m_nameTab = "MT_APDM_tab";
    m_Ente="MT_APDM";
    m_page=CreationScenario_page;
}

bool GraphicHandlerCommand_MT_APDM::initCommands()
{

    qDebug () << "GraphicHandlerCommand_T_APDM::initCommands";


    removeInternalData();

    // storageData::Data_MT_APDM_Cmds cmd_MT_APDM= storageData::StorageDataCommand::istance()->dataMT_APDM_Cmds();

    m_mainWin_Ptr->comboBox_Program_MT_APDM->addItem("");
    storageData::Data_MT_APDM_Allprogram mtApdmAll = storageData::StorageDataCommand::istance()->dataMT_APDM_All();
    QMapIterator <QString,QVector<storageData::Data_MT_APDM_Cmd>> it ( mtApdmAll.mt_ApdmMap);
    while (it.hasNext()){
        it.next();
        m_mainWin_Ptr->comboBox_Program_MT_APDM->addItem(it.key());

    }

    connect (m_mainWin_Ptr->comboBox_Program_MT_APDM,&QComboBox::currentTextChanged,[this] (const QString &val){
        m_mainWin_Ptr->comboBox_Command_MT_APDM->clear();
        m_mainWin_Ptr->comboBox_Command_MT_APDM->addItem("");
        storageData::Data_MT_APDM_Allprogram mtApdmAll = storageData::StorageDataCommand::istance()->dataMT_APDM_All();
        if ( mtApdmAll.mt_ApdmMap.contains(val)){
            QVector<storageData::Data_MT_APDM_Cmd> cmds=mtApdmAll.mt_ApdmMap.value(val);
            foreach (storageData::Data_MT_APDM_Cmd cmd, cmds) {
                m_mainWin_Ptr->comboBox_Command_MT_APDM->addItem(cmd.action);

            }
        }
    });
    return true;

}

void GraphicHandlerCommand_MT_APDM::removeInternalData()
{
    m_mainWin_Ptr->spinBox_Distance_MT_APDM->setMinimum(0);
    m_mainWin_Ptr->spinBox_Delay_MT_APDM->setMinimum(0);

    m_mainWin_Ptr->spinBox_Distance_MT_APDM->setRange(0,MAX_DISTANCE);
    m_mainWin_Ptr->spinBox_Delay_MT_APDM->setRange(0,MAX_DELAY);
}

bool GraphicHandlerCommand_MT_APDM::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{

    bool ret = true ;
    if (add_command==actionCommand ){
        storageData::Data_MT_APDM_Allprogram mtApdmAll = storageData::StorageDataCommand::istance()->dataMT_APDM_All();
        QString program = m_mainWin_Ptr->comboBox_Program_MT_APDM->currentText();

        if ( mtApdmAll.mt_ApdmMap.contains(program)){
            QVector<storageData::Data_MT_APDM_Cmd> cmds=mtApdmAll.mt_ApdmMap.value(program);

            storageData::Data_MT_APDM_Cmd command;
            bool isFound=false;
            foreach (storageData::Data_MT_APDM_Cmd cmd, cmds) {
               // qDebug () << cmd.action;
               // qDebug () << m_mainWin_Ptr->comboBox_Command_MT_APDM->currentText();

                if (cmd.action == m_mainWin_Ptr->comboBox_Command_MT_APDM->currentText()) {

                    command=cmd;
                    isFound=true;
                    break;
                }
            }
            if (!isFound) {
                ret = false;
                m_mainWin_Ptr->statusbar->showMessage(tr(VALUE_NOT_VALID),TIME_OF_STATUS_MESS);
            } else {
                bool isFirst = true;
                foreach (QString actd, command.subActions) {
                    QString cmd  =  QString::number(m_mainWin_Ptr->spinBox_Distance_MT_APDM->value());
                    cmd+=QString ("%1%2").arg(INTERNAL_SEPARATOR,"T_APDM");
                    cmd+= INTERNAL_SEPARATOR+actd;
                    if (isFirst) {
                        isFirst=false;
                        cmd+=INTERNAL_SEPARATOR+ QString::number(m_mainWin_Ptr->spinBox_Delay_MT_APDM->value());

                    } else {
                        cmd+=INTERNAL_SEPARATOR+QString::number(command.ritardo_default);
                    }
                    cmd+=INTERNAL_SEPARATOR+QString::number(command.sub_delay_pressure);
                    QString pageAndTab = QString::number(m_page)+ INTERNAL_SEPARATOR+ "T_APDM_tab";
                    emit addRemoveUpdateCommand_SG(cmd,actionCommand,pageAndTab,m_currentRowTable);
                }
            }

        } else {
            ret = false;
            m_mainWin_Ptr->statusbar->showMessage(tr(VALUE_NOT_VALID),TIME_OF_STATUS_MESS);
        }
        m_currentRowTable=-1;
    }


    return ret;
}


void GraphicHandlerCommand_MT_APDM::showCommand_SL (QString command, qint32 rowTable)
{

    Q_UNUSED (command)
     Q_UNUSED (rowTable)
    return ;
}
}
