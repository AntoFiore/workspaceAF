#include "GraphicHandlerCommand_T_ODO.h"
#include <QDebug>
#include "StorageDataCommand.h"
#include <QDateTime>
namespace hndcommand{
GraphicHandlerCommand_T_ODO::GraphicHandlerCommand_T_ODO(QObject *parent)
    : GraphicHandlerCommand{parent}
{
    m_idCommands=T_ODO;
    m_nameTab = "T_ODO_tab";
    m_Ente="T_ODO";
    m_page=CreationScenario_page;
}

bool GraphicHandlerCommand_T_ODO::initCommands()
{

    qDebug () << "GraphicHandlerCommand_T_ODO::initCommands";
    m_mainWin_Ptr->spinBox_Distance_T_ODO->setRange(0,MAX_DISTANCE);
    m_mainWin_Ptr->spinBox_Delay_T_ODO->setRange(0,MAX_DELAY);

    removeInternalData();

    connect(m_mainWin_Ptr->spinBox_speed_T_ODO,QOverload<int>::of(&QSpinBox::valueChanged),[this](int val ) {
        qreal speedConvert =static_cast <qreal>(val)/1000;
        m_mainWin_Ptr->label_speedConvertValue_T_ODO->setText(QString::number(speedConvert));
    });
    connect(m_mainWin_Ptr->spinBox_Acc_T_ODO,QOverload<int>::of(&QSpinBox::valueChanged),[this](int val ) {
        qreal accConvert =static_cast <qreal>(val)/1000;
        m_mainWin_Ptr->label_AccConvertValue_T_ODO->setText(QString::number(accConvert));
    });
    storageData::Data_T_ODO_Cmds cmd_TODO= storageData::StorageDataCommand::istance()->data_T_ODO_Cmds();


    m_mainWin_Ptr->spinBox_Delay_T_APDM->setValue(0);
    m_mainWin_Ptr->spinBox_Distance_T_APDM->setValue(0);

    if ( cmd_TODO.cmds.size() ) {
        storageData::Data_T_ODO_Cmd cmd = cmd_TODO.cmds.at(0);
        qreal minSpeed=0;
        qreal maxSpeed=0;
        qreal minacc= 0;
        qreal maxacc=0;
        if (cmd.isSpeedValidRange) {
            minSpeed= cmd.speed_range_min;
            maxSpeed=cmd.speed_range_max;
        } else {
            QStringList speedRangeDefalt = QString (SPEED_RANGE_DEFAULT).split(INTERNAL_SEPARATOR);
            if (speedRangeDefalt.size() >= 2){
                QString value = speedRangeDefalt.at(0);
                minSpeed= value.toDouble();
                value = speedRangeDefalt.at(1);
                maxSpeed= value.toDouble();
            }

        }
        m_mainWin_Ptr->label_MinSpeedRangValue_T_ODO->setText( QString::number( minSpeed*1000));
        m_mainWin_Ptr->label_MaxSpeedRangValue_T_ODO->setText( QString::number( maxSpeed*1000));
        m_mainWin_Ptr->label_MinSpeedConvertRangValue_T_ODO->setText( QString::number( minSpeed));
        m_mainWin_Ptr->label_MaxSpeedConvertRangValue_T_ODO->setText( QString::number( maxSpeed));
        m_mainWin_Ptr->spinBox_speed_T_ODO->setMinimum(minSpeed*1000);
        m_mainWin_Ptr->spinBox_speed_T_ODO->setMaximum(maxSpeed*1000);
        m_mainWin_Ptr->spinBox_speed_T_ODO->setValue(minSpeed*1000);
        m_mainWin_Ptr->label_speedConvertValue_T_ODO->setText(QString::number(minSpeed));

        if (cmd.isAccValidRange) {
            minacc= cmd.acc_range_min;
            maxacc=cmd.acc_range_max;
        } else {
            QStringList accRangeDefalt = QString (ACC_RANGE_DEFAULT).split(INTERNAL_SEPARATOR);
            if (accRangeDefalt.size() >= 2){
                QString value = accRangeDefalt.at(0);
                minacc= value.toDouble();
                value = accRangeDefalt.at(1);
                maxacc= value.toDouble();
            }
        }
        m_mainWin_Ptr->label_MinAccRangValue_T_ODO->setText( QString::number( minacc*1000));
        m_mainWin_Ptr->label_MaxAccRangValue_T_ODO->setText( QString::number( maxacc*1000));
        m_mainWin_Ptr->label_MinAccConvertRangValue_T_ODO->setText( QString::number( minacc));
        m_mainWin_Ptr->label_MaxAccConvertRangValue_T_ODO->setText( QString::number( maxacc));
        m_mainWin_Ptr->spinBox_Acc_T_ODO->setMinimum(minacc*1000);
        m_mainWin_Ptr->spinBox_Acc_T_ODO->setMaximum(maxacc *1000);
        m_mainWin_Ptr->spinBox_Acc_T_ODO->setValue(minacc*1000);
        m_mainWin_Ptr->label_AccConvertValue_T_ODO->setText(QString::number(minacc));


    }
    return true;
}

void GraphicHandlerCommand_T_ODO::removeInternalData()
{

    //    m_mainWin_Ptr->groupBox_TempoPressioneRange_T_APDM->setVisible(false);
    //    m_mainWin_Ptr->label_TimePressRangeMinValue_T_APDM->clear();
    //    m_mainWin_Ptr->label_TimePressRangeMaxValue_T_APDM->clear();
    //    m_mainWin_Ptr->spinBox_TimePressRangeVale_T_APDM->clear();
    //    m_mainWin_Ptr->spinBox_Distance_T_APDM->clear();
    //    m_mainWin_Ptr->spinBox_Delay_T_APDM->clear();
    //    m_mainWin_Ptr->label_MinValue_TimePressInSec_T_APDM->clear();
    //    m_mainWin_Ptr->label_MaxValue_TimePressInSec_T_APDM->clear();
    //    m_mainWin_Ptr->label_ValueSec_TimePressConvert_T_APDM->clear();

}

bool GraphicHandlerCommand_T_ODO::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{

    bool ret = true ;
    QString cmd  =  QString::number(m_mainWin_Ptr->spinBox_Distance_T_ODO->value());
    cmd+=INTERNAL_SEPARATOR+m_Ente;
    cmd+= INTERNAL_SEPARATOR+QString::number(m_mainWin_Ptr->spinBox_Delay_T_ODO->value());
    cmd+=INTERNAL_SEPARATOR+m_mainWin_Ptr->label_AccConvertValue_T_ODO->text();
    cmd+=INTERNAL_SEPARATOR+m_mainWin_Ptr->label_speedConvertValue_T_ODO->text();

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
    return ret;
}

void GraphicHandlerCommand_T_ODO::showCommand_SL(QString command, qint32 rowTable )
{

    QStringList commandList = command.split(INTERNAL_SEPARATOR);
    qint32 sizeCmd = commandList.size();
    if (sizeCmd >=tab_position ){
        QString page = commandList[page_positon];
        QString tab =  commandList[tab_position];
    //    qDebug () << "Page = "<< page;
    //    qDebug () << "tab = "<< tab;
        if (sizeCmd > speed_position){
            if ( tab ==m_nameTab){
                m_mainWin_Ptr->tabWidget_Commands->setCurrentIndex(m_TabId);

                QString distance = commandList[distance_position];
                m_mainWin_Ptr->spinBox_Distance_T_ODO->setValue(distance.toInt());

                QString deley =   commandList[deleay_position];
                m_mainWin_Ptr->spinBox_Delay_T_ODO->setValue(deley.toInt());

                QString acc =   commandList[acc_position];
                m_mainWin_Ptr->spinBox_Acc_T_ODO->setValue(acc.toDouble()*1000);

                QString speed =   commandList[speed_position];
                m_mainWin_Ptr->spinBox_speed_T_ODO->setValue(speed.toDouble()*1000);

                m_currentRowTable=rowTable;

            }

        }

    }
}
}
