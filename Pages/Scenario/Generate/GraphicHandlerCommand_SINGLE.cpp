#include "GraphicHandlerCommand_SINGLE.h"
#include <QDebug>
#include "StorageDataCommand.h"
#include <QDateTime>
namespace hndcommand{
GraphicHandlerCommand_SINGLE::GraphicHandlerCommand_SINGLE(QObject *parent)
    : GraphicHandlerCommand{parent}
{
    m_idCommands=T_SINGLE_CMD;
    m_nameTab = "SINGLE_COMMAND_tab";
    m_Ente="";
    m_page=CreationScenario_page;
}

bool GraphicHandlerCommand_SINGLE::initCommands()
{

    removeInternalData();

    // storageData::Data_MT_APDM_Cmds cmd_MT_APDM= storageData::StorageDataCommand::istance()->dataMT_APDM_Cmds();

    m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND->addItem("");
    storageData::Data_Single_NationalSystems singleCmdAll = storageData::StorageDataCommand::istance()->data_SingleNationalSystem();

    QMapIterator <QString,QMap<QString,QVector <storageData::Data_Single_Cmd>>> itNew (singleCmdAll.nationalSystemNew_Map);



    QMapIterator <QString,QVector<storageData::Data_Single_Cmd>> it ( singleCmdAll.nationalSystem_Map);
    while (itNew.hasNext()){
        itNew.next();
        m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND->addItem(itNew.key());

    }

    connect (m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND,&QComboBox::currentTextChanged,[this] (const QString &val){
        m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->disconnect();
        m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->clear();
        m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->addItem("");
        m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND->clear();

        storageData::Data_Single_NationalSystems singleCmdAll = storageData::StorageDataCommand::istance()->data_SingleNationalSystem();
        if ( singleCmdAll.nationalSystemNew_Map.contains(val)){

            QMap<QString,QVector <storageData::Data_Single_Cmd>> cmdsMap = singleCmdAll.nationalSystemNew_Map.value(val);
            QMapIterator <QString,QVector<storageData::Data_Single_Cmd>> it (cmdsMap);
            while (it.hasNext()){
                it.next();
                m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->addItem(it.key());

            }

            // m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->addItem(cmd.command);

        }
        connect ( m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND,&QComboBox::currentTextChanged,
                  this,&GraphicHandlerCommand_SINGLE::currentCommandChangedCmd_SL);



        //        if ( singleCmdAll.nationalSystem_Map.contains(val)){
        //            QVector<storageData::Data_Single_Cmd> cmds=singleCmdAll.nationalSystem_Map.value(val);
        //            foreach (storageData::Data_Single_Cmd cmd, cmds) {
        //                m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->addItem(cmd.command);

        //            }
        //        }
    });


    return true;

}
void GraphicHandlerCommand_SINGLE::currentCommandChangedCmd_SL(QString cmd)
{
    qDebug ()<< "Command= " << cmd;
    m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND->disconnect();
    m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND->clear();
    m_mainWin_Ptr->labelDescription_SINGLE_COMMAND->clear();

    storageData::Data_Single_NationalSystems singleCmdAll = storageData::StorageDataCommand::istance()->data_SingleNationalSystem();
    QString nationalSystem = m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND->currentText();
    if ( singleCmdAll.nationalSystemNew_Map.contains(nationalSystem)){
        QMap<QString,QVector <storageData::Data_Single_Cmd>> cmdsMap = singleCmdAll.nationalSystemNew_Map.value(nationalSystem);

        if (cmdsMap.contains(cmd )) {
            QVector <storageData::Data_Single_Cmd> cmds = cmdsMap[cmd];
            foreach (storageData::Data_Single_Cmd cmd ,cmds) {
                m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND->addItem(cmd.value);


            }
            QString cmdValue = m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND->currentText();
            QString nationalSystem=m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND->currentText();
            QString command=m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->currentText();

            QString desc = singleCmdAll.getDescriptionByCommand(nationalSystem,command,cmdValue);
            m_mainWin_Ptr->labelDescription_SINGLE_COMMAND->setText(desc);
            connect (m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND,&QComboBox::currentTextChanged,this,&GraphicHandlerCommand_SINGLE::currentValueChangedCmd_SL);
        }
    }
}

void GraphicHandlerCommand_SINGLE::currentValueChangedCmd_SL(QString cmdValue)
{

    storageData::Data_Single_NationalSystems singleCmdAll = storageData::StorageDataCommand::istance()->data_SingleNationalSystem();
     QString nationalSystem=m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND->currentText();
     QString command=m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->currentText();
     QString desc = singleCmdAll.getDescriptionByCommand(nationalSystem,command,cmdValue);
     m_mainWin_Ptr->labelDescription_SINGLE_COMMAND->setText(desc);
}
void GraphicHandlerCommand_SINGLE::removeInternalData()
{
    m_mainWin_Ptr->spinBox_Distance_SINGLE_COMMAND->setMinimum(0);
    m_mainWin_Ptr->spinBox_Delay_SINGLE_COMMAND->setMinimum(0);

    m_mainWin_Ptr->spinBox_Distance_SINGLE_COMMAND->setRange(0,MAX_DISTANCE);
    m_mainWin_Ptr->spinBox_Delay_SINGLE_COMMAND->setRange(0,MAX_DELAY);
}

bool GraphicHandlerCommand_SINGLE::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{
    bool ret = true ;
    ret=dataValidation();
    if (ret ){
        if (add_command==actionCommand ){
            m_currentRowTable=-1;
            //QString ente;
            //  storageData::Data_MT_APDM_Allprogram mtApdmAll = storageData::StorageDataCommand::istance()->dataMT_APDM_All();
            QString  nationaleSystem=m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND->currentText();
            QString  command = m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->currentText();
            storageData::Data_Single_NationalSystems singleCmdAll = storageData::StorageDataCommand::istance()->data_SingleNationalSystem();
            QString ente = singleCmdAll.getEnteByNationalSystem(nationaleSystem);



            //        if ( singleCmdAll.nationalSystemNew_Map.contains(nationaleSystem)){
            //            QMap<QString,QVector <storageData::Data_Single_Cmd>> cmdsMap = singleCmdAll.nationalSystemNew_Map.value(nationaleSystem);

            //            if (cmdsMap.contains(command )) {
            //                QVector <storageData::Data_Single_Cmd> cmds = cmdsMap[command];
            //                foreach (storageData::Data_Single_Cmd cmd, cmds) {
            //                    if (cmd.command == command){
            //                        ente=cmd.ente;
            //                        break;
            //                    }

            //                }

            //            }

            //        }
            QString cmd = QString::number(m_mainWin_Ptr->spinBox_Distance_SINGLE_COMMAND->value());
            cmd+=INTERNAL_SEPARATOR+ente;
            cmd+=INTERNAL_SEPARATOR+QString::number(m_mainWin_Ptr->spinBox_Delay_SINGLE_COMMAND->value());
            cmd+=INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND->currentText();
            cmd+=INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->currentText();
            QString pageAndTab = QString::number(m_page)+ INTERNAL_SEPARATOR+ m_nameTab;
            qDebug () << "add Cmd =  "<< cmd;
            emit addRemoveUpdateCommand_SG(cmd,actionCommand,pageAndTab,m_currentRowTable);
        } else if (remove_command == actionCommand || update_command == actionCommand ){


            QString cmd = QString::number(m_mainWin_Ptr->spinBox_Distance_SINGLE_COMMAND->value());
            storageData::Data_Single_NationalSystems singleCmdAll = storageData::StorageDataCommand::istance()->data_SingleNationalSystem();
            QString  nationaleSystem=m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND->currentText();
            QString ente = singleCmdAll.getEnteByNationalSystem(nationaleSystem);
            cmd+=INTERNAL_SEPARATOR+ente;
            cmd+=INTERNAL_SEPARATOR+QString::number(m_mainWin_Ptr->spinBox_Delay_SINGLE_COMMAND->value());
            cmd+=INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND->currentText();
            cmd+=INTERNAL_SEPARATOR+m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->currentText();
            QString pageAndTab = QString::number(m_page)+ INTERNAL_SEPARATOR+ m_nameTab;
           // qDebug () << "Remove Cmd =  "<< cmd;

//            if (remove_command == actionCommand){
//                m_currentRowTable=-1;
//            }
            emit addRemoveUpdateCommand_SG(cmd,actionCommand,pageAndTab,m_currentRowTable);
        }

    }
    return ret;
}

bool GraphicHandlerCommand_SINGLE::dataValidation()
{
    bool ret=false;
    if (m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND->currentText()!= ""  &&
        m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->currentText()!= ""       &&
        m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND->currentText()!= ""    ){
             ret= true;
    } else {
        m_mainWin_Ptr->statusbar->showMessage(tr(VALUE_NOT_VALID),TIME_OF_STATUS_MESS);
    }
    return ret;

}



void GraphicHandlerCommand_SINGLE::showCommand_SL(QString command, qint32 rowTable )
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
            //    qDebug () << "command = " << command;
                qDebug () << "rowtable = "<< rowTable;
                m_mainWin_Ptr->tabWidget_Commands->setCurrentIndex(m_TabId);
                QString distance = commandList[distance_position];
                m_mainWin_Ptr->spinBox_Distance_SINGLE_COMMAND->setValue(distance.toInt());

                QString ente = commandList[ente_position];
                storageData::Data_Single_NationalSystems singleCmdAll = storageData::StorageDataCommand::istance()->data_SingleNationalSystem();
                QString nationalSystem = singleCmdAll.getNationalSystemByEnte(ente);


                QString deleyPressure =   commandList[deleay_positon];
                m_mainWin_Ptr->spinBox_Delay_SINGLE_COMMAND->setValue(deleyPressure.toInt());

                QString valueCommand= commandList[valuecommand_position];
                QString command= commandList[command_position];

                 m_currentRowTable=rowTable;

                m_mainWin_Ptr->comboBox_nationalSyst_SINGLE_COMMAND->setCurrentText(nationalSystem);
                m_mainWin_Ptr->comboBox_Command_SINGLE_COMMAND->setCurrentText(command);
                m_mainWin_Ptr->comboBox_Value_SINGLE_COMMAND->setCurrentText(valueCommand);
            }

        }
    }


    return ;
}
}
