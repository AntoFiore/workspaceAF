#include "GraphicHandlerCommand_T_APDM.h"
#include <QDebug>
#include "StorageDataCommand.h"
#include <QDateTime>
namespace hndcommand{
GraphicHandlerCommand_T_APDM::GraphicHandlerCommand_T_APDM(QObject *parent)
    : GraphicHandlerCommand{parent}
{
    m_idCommands=T_APDM_CMD;
    m_nameTab = "T_APDM_tab";
    m_Ente="T_APDM";
    m_page=CreationScenario_page;
}

bool GraphicHandlerCommand_T_APDM::initCommands()
{

    qDebug () << "GraphicHandlerCommand_T_APDM::initCommands";
    m_mainWin_Ptr->spinBox_Distance_T_APDM->setRange(0,MAX_DISTANCE);
    m_mainWin_Ptr->spinBox_Delay_T_APDM->setRange(0,MAX_DELAY);

    removeInternalData();

    connect(m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM,QOverload<int>::of(&QSpinBox::valueChanged),[this](int val ) {
        qreal valSeconds =static_cast <qreal>(val)/1000;
        m_mainWin_Ptr->label_ValueSec_TimePressConvert_T_APDM->setText(QString::number(valSeconds));
    });
    storageData::Data_T_APDM_Cmds cmd_T_APDM= storageData::StorageDataCommand::istance()->dataT_APDM_Cmds();
    m_mainWin_Ptr->comboBox_Action_T_APDM->addItem("");
    foreach (storageData::Data_T_APDM_Cmd cmd, cmd_T_APDM.cmds) {
        m_mainWin_Ptr->comboBox_Action_T_APDM->addItem(cmd.action);
    }

    m_mainWin_Ptr->spinBox_Delay_T_APDM->setValue(0);
    m_mainWin_Ptr->spinBox_Distance_T_APDM->setValue(0);
    connect (m_mainWin_Ptr->comboBox_Action_T_APDM,&QComboBox::currentTextChanged,[this] (const QString &val){
        storageData::Data_T_APDM_Cmds cmd_T_APDM= storageData::StorageDataCommand::istance()->dataT_APDM_Cmds();

        foreach (storageData::Data_T_APDM_Cmd cmd, cmd_T_APDM.cmds) {
            if (cmd.action == val ) {
                if (cmd.isValidRitardoRange) {
                    m_mainWin_Ptr->spinBox_Delay_T_APDM->setMinimum(cmd.ritardo_range_min);
                    m_mainWin_Ptr->spinBox_Delay_T_APDM->setMaximum(cmd.ritardo_range_max);
                    if (cmd.existRitardoDef){
                        m_mainWin_Ptr->spinBox_Delay_T_APDM->setValue(cmd.ritardo_default);
                    }

                }
                if (cmd.isValidTempoPressioneRange) {
                    m_mainWin_Ptr->groupBox_TempoPressioneRange_T_APDM->setVisible(true);
                    m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->setValue(0);

                    QString minValue = QString::number(cmd.tempo_pressione_range_min * 1000);
                    m_mainWin_Ptr->label_TimePressRangeMinValue_T_APDM->setText(minValue);
                    m_mainWin_Ptr->label_TimePressRangeMinValue_T_APDM->setToolTip(minValue);
                    QString mmaxValue = QString::number(cmd.tempo_pressione_range_max * 1000);
                    m_mainWin_Ptr->label_TimePressRangeMaxValue_T_APDM ->setText(mmaxValue);
                    m_mainWin_Ptr->label_TimePressRangeMaxValue_T_APDM ->setToolTip(mmaxValue);

                    m_mainWin_Ptr->label_MinValue_TimePressInSec_T_APDM->setText(QString::number(cmd.tempo_pressione_range_min));
                    m_mainWin_Ptr->label_MinValue_TimePressInSec_T_APDM->setToolTip(QString::number(cmd.tempo_pressione_range_min));
                    m_mainWin_Ptr->label_MaxValue_TimePressInSec_T_APDM->setText(QString::number(cmd.tempo_pressione_range_max));
                    m_mainWin_Ptr->label_MaxValue_TimePressInSec_T_APDM->setToolTip(QString::number(cmd.tempo_pressione_range_max));

                    m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->setMinimum(cmd.tempo_pressione_range_min*1000); //mseconds
                    m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->setMaximum(cmd.tempo_pressione_range_max*1000);
                    if (cmd.existTimePressDef){
                        QString vlueDefaul = QString::number(cmd.tempo_pressione_default * 1000);
                        m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->setValue(cmd.tempo_pressione_default*1000);
                        m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->setToolTip(vlueDefaul);
                        m_mainWin_Ptr->label_ValueSec_TimePressConvert_T_APDM->setText(QString::number(cmd.tempo_pressione_default));
                    }
                } else {
                    m_mainWin_Ptr->groupBox_TempoPressioneRange_T_APDM->setVisible(false);

                    break;
                }

            }

        }

    });

    return true;

}

void GraphicHandlerCommand_T_APDM::removeInternalData()
{

    m_mainWin_Ptr->groupBox_TempoPressioneRange_T_APDM->setVisible(false);
    m_mainWin_Ptr->label_TimePressRangeMinValue_T_APDM->clear();
    m_mainWin_Ptr->label_TimePressRangeMaxValue_T_APDM->clear();
    m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->clear();
    m_mainWin_Ptr->spinBox_Distance_T_APDM->clear();
    m_mainWin_Ptr->spinBox_Delay_T_APDM->clear();
    m_mainWin_Ptr->label_MinValue_TimePressInSec_T_APDM->clear();
    m_mainWin_Ptr->label_MaxValue_TimePressInSec_T_APDM->clear();
    m_mainWin_Ptr->label_ValueSec_TimePressConvert_T_APDM->clear();

}

bool GraphicHandlerCommand_T_APDM::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{

    bool ret = dataValidation() ;
    if (ret){


        QString cmd  =  QString::number(m_mainWin_Ptr->spinBox_Distance_T_APDM->value());
        cmd+=INTERNAL_SEPARATOR+m_Ente;
        cmd+= INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Action_T_APDM->currentText();
        cmd+=INTERNAL_SEPARATOR+QString::number(m_mainWin_Ptr->spinBox_Delay_T_APDM->value());

        qreal valSeconds =static_cast <qreal>(m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->value())/1000;
        cmd+=INTERNAL_SEPARATOR+QString::number(valSeconds);

        //cmd+=INTERNAL_SEPARATOR+QString::number(m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->value());
        switch (actionCommand) {
        case add_command:
        //case remove_command:
           m_currentRowTable=-1;
            break;
        default:
            break;
        }
        QString pageAndTab = QString::number(m_page)+INTERNAL_SEPARATOR+m_nameTab;
        emit addRemoveUpdateCommand_SG(cmd,actionCommand,pageAndTab,m_currentRowTable);
       // if (actionCommand==remove_command)  m_currentRowTable=-1;
        /*
    if (actionCommand){
        bool addCommand = true;
       emit addOrRemoveCommand_SG(cmd,actionCommand,pageAndTab);
    } else {
        bool addCommand = false;
        emit addOrRemoveCommand_SG(cmd,actionCommand,pageAndTab);
    }
    */
    }
    return ret;
}

bool GraphicHandlerCommand_T_APDM::isCurrentTab()
{

    return GraphicHandlerCommand::isCurrentTab() || (m_TabId==MT_APDM_CMD);
}

bool GraphicHandlerCommand_T_APDM::dataValidation()
{

    bool ret=true;
    if (m_mainWin_Ptr->comboBox_Action_T_APDM->currentText() ==""){
        ret = false;
        m_mainWin_Ptr->statusbar->showMessage(tr(VALUE_NOT_VALID),TIME_OF_STATUS_MESS);
    }

    return ret;
}

void GraphicHandlerCommand_T_APDM::showCommand_SL(QString command, qint32 rowTable )
{

    QStringList commandList = command.split(INTERNAL_SEPARATOR);
    qint32 sizeCmd = commandList.size();
    if (sizeCmd >=tab_position ){
        QString page = commandList[page_positon];
        QString tab =  commandList[tab_position];
        //  qDebug () << "Page = "<< page;
        //  qDebug () << "tab = "<< tab;
        if (sizeCmd > delaypressure_position){
            if ( tab ==m_nameTab){
                m_mainWin_Ptr->tabWidget_Commands->setCurrentIndex(m_TabId);

                QString distance = commandList[distance_position];
                m_mainWin_Ptr->spinBox_Distance_T_APDM->setValue(distance.toInt());

                QString action =   commandList[action_positon];
                m_mainWin_Ptr->comboBox_Action_T_APDM->setCurrentText(action);

                QString position =   commandList[deleay_position];
                m_mainWin_Ptr->spinBox_Delay_T_APDM->setValue(position.toInt());

                QString deleyPressure =   commandList[delaypressure_position];
                m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->setValue(deleyPressure.toDouble()*1000);

                m_currentRowTable=rowTable;

            }

        }

    }
}
}
