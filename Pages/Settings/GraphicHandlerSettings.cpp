#include "GraphicHandlerSettings.h"
#include <QDebug>

#include "Define.h"
#include <QPushButton>

#include "StorageDataCommand.h"
#include "ui_mainwindow.h"
#include "StorageDataCommand.h"
#include "Data_Configuration.h"
#include "Defxml.h"
#include <QFileDialog>
#include "ReadWriteConfigurationFile.h"
namespace page{
GraphicHandlerSettings::GraphicHandlerSettings(QObject *parent)
    : GraphicHandlerPage{parent}
{
    m_page= Settings_page;
}

GraphicHandlerSettings::~GraphicHandlerSettings()
{
}
QString  GraphicHandlerSettings::defaultPathCommon(){
    QString  pathCommands;
    config::ConfigurationFile cfgFile = storageData::StorageDataCommand::istance()->confFile();
    foreach (config::ItemConfiguration item, cfgFile.m_configItems) {
        if (item.m_nameTag == TAG_CONFIG_COMMAND){
            QMap<QString,QString>::const_iterator it = item.m_keyValueAttribMap.find(ATT_PATH_COMMAND);
            if (it != item.m_keyValueAttribMap.end()) {
                qDebug () << it.value();
                pathCommands=it.value();
                break;
            }

        }
    }
    return pathCommands;

}
void GraphicHandlerSettings::updateDataConfiguration()
{
    config::ConfigurationFile& cfgFile = storageData::StorageDataCommand::istance()->confFile();
    for (int idxItem = 0 ; idxItem<cfgFile.m_configItems.size(); idxItem++){

        if (cfgFile.m_configItems[idxItem].m_nameTag == TAG_CONFIG_COMMAND )
        {
            cfgFile.m_configItems[idxItem].m_keyValueAttribMap[ATT_PATH_COMMAND]=m_mainWin_Ptr->lineEdit_ConfigPathCommands->text();
            break;
        }
    }

}

bool GraphicHandlerSettings::initPage()
{
    bool ret = true;
    // m_mainWin_Ptr->lineEdit_ConfigPathCommands->setReadOnly(true);
    // m_mainWin_Ptr->lineEdit_ConfigPathCommands->setEnabled(true);

    connect (m_mainWin_Ptr->pushButton_applySettings,&QPushButton::clicked,[this]() {
        updateDataConfiguration();
        config::ReadWriteConfigurationFile rwConfFile;
        bool ret = rwConfFile.updateConfigFile();
        if (ret){
            qDebug () << "Update Config file  ok";
             m_mainWin_Ptr->statusbar->showFullScreen();
            m_mainWin_Ptr->statusbar->showMessage(tr(SAVE_CONFIG_FILE_OK),TIME_OF_STATUS_MESS);
        }else {
             m_mainWin_Ptr->statusbar->showMessage(tr(SAVE_CONFIG_FILE_KO),TIME_OF_STATUS_MESS);
            qDebug () << "Error on updateing Config file";

        }
    });
    /*
     * */
    connect (m_mainWin_Ptr->pushButton_RestorePathCommand,&QPushButton::clicked,[this]() {
        QString  pathCommands = defaultPathCommon();
        config::ConfigurationFile cfgFile = storageData::StorageDataCommand::istance()->confFile();
        m_mainWin_Ptr->lineEdit_ConfigPathCommands->setText(pathCommands);
        m_mainWin_Ptr->lineEdit_ConfigPathCommands->setToolTip(pathCommands);
    });



    //m_mainWin_Ptr->lineEdit_ConfigPathCommands->setReadOnly(true);
    connect (m_mainWin_Ptr->pushButton_selectFolder,&QPushButton::clicked,[this](){
        QString path =QFileDialog::getExistingDirectory( nullptr,
                                                         tr ("Selection Path Commands"),
                                                         ".",
                                                         QFileDialog::ShowDirsOnly);
        if (path.size()){
            m_mainWin_Ptr->lineEdit_ConfigPathCommands->setText(path);
            m_mainWin_Ptr->lineEdit_ConfigPathCommands->setToolTip(path);
        }
    });


    QString  pathCommands = defaultPathCommon();;
    config::ConfigurationFile cfgFile = storageData::StorageDataCommand::istance()->confFile();
    ret = pathCommands.size() ? true:false;
    if (ret){
        m_mainWin_Ptr->lineEdit_ConfigPathCommands->setText(pathCommands);
        m_mainWin_Ptr->lineEdit_ConfigPathCommands->setToolTip(pathCommands);
    }
    return ret;
}


}

