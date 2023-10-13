#include "Controller.h"
#include <QMessageBox>
#include "Define.h"
#include <QDir>
#include <QDebug>
#include "StorageDataCommand.h"
#include "Data_Configuration.h"
#include "Defxml.h"
Controller::Controller(QObject *parent)
    : QObject{parent}
{

}

bool Controller::init_All()
{

    bool ret = true;

    QMessageBox msgbox;
    msgbox.setStandardButtons(QMessageBox::Ok);
    msgbox.setIcon(QMessageBox::Critical);
    msgbox.setWindowTitle(CCS_FATAL_ERROR_TITLE);
    ret = init_CommandFile();
    if ( ! ret) {
        QString errorValue = "Error in reading file's command";
        msgbox.setText(errorValue);
        msgbox.exec();

    }

    //debug
    if (ret) {
    //     storageData::StorageDataCommand::istance()->dump_MT_APDM();

     //   storageData::StorageDataCommand::istance()->dump_SIGNLE_CMD();

//        storageCmd::StorageDataCommand::istance()->dump_T_IO();
//        storageCmd::StorageDataCommand::istance()->dump_T_SIM();
//        storageCmd::StorageDataCommand::istance()->dump_T_APDM();
    }
    if (ret ){

        ret = init_MainWindow();
        if ( ! ret) {
            QString errorValue = "Error  initialization MainWindow";
            msgbox.setText(errorValue);
            msgbox.exec();

        }

    }
    return ret ;
}

bool Controller::init_MainWindow()
{

   bool ret =  mMainWin.init();
   if (ret) {
       mMainWin.show();
   }
   return ret;
}

bool Controller::init_CommandFile()
{

    bool ret = false;

    //load config file
   m_ReadConfigurationFile.loadConfigFile();
   QString  fullNameCfg;
   config::ConfigurationFile cfgFile = storageData::StorageDataCommand::istance()->confFile();
   foreach (config::ItemConfiguration item, cfgFile.m_configItems) {
       if (item.m_nameTag == TAG_CONFIG_COMMAND){
           QMap<QString,QString>::const_iterator it = item.m_keyValueAttribMap.find(ATT_PATH_COMMAND);
           if (it != item.m_keyValueAttribMap.end()) {
               qDebug () << it.value();
               fullNameCfg=it.value();
               ret=true;
               break;
           }

       }
   }
   if (!ret){
       qDebug () << "Path Configuration Commands not found";
   }  else {
       //load file command
       m_ReadConfigurationFile.setPathFileCommands(fullNameCfg);
       ret= m_ReadConfigurationFile.loadCommandsFile();
   }
   return ret;

}
