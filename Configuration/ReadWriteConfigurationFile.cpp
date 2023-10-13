#include "ReadWriteConfigurationFile.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QXmlInputSource>
#include "HandlerXmlReader.h"
#include "QXmlSimpleReader"
#include <Defxml.h>
#include <QXmlStreamReader>
#include <QDomDocument>
#include "StorageDataCommand.h"
#include <QCoreApplication>
#include "Define.h"
//#include "Data_Configuration.h"
//#include "check/xmlhandlerjunit.h"
namespace config{
QString ReadWriteConfigurationFile::nameConfigFile() const
{
    return m_namePathCommands;
}
void ReadWriteConfigurationFile::setPathFileCommands(QString namePathCommands)
{
    m_namePathCommands = namePathCommands;
}

bool ReadWriteConfigurationFile::loadCommandsFile()
{
    bool ret = true;
    QString fullName ;
    for (int idxFile =0 ; idxFile < MAX_NUM_FILE && ret ;idxFile++  ){


        QString path = m_namePathCommands+ QDir::separator()+CommandsFile[idxFile];
        path=QDir::toNativeSeparators(path);
        QFileInfo f (path);


        if (false  ==  f.exists()){
            path = QCoreApplication::applicationDirPath()+QDir::separator()+DEFAULT_CFG_PATH + QDir::separator()+CommandsFile[idxFile];

        }
        fullName= path;
        qDebug () << "Read File : " << fullName;
        QFile file( fullName );
        if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        {
            qDebug() <<  "Failed to open file : "  << fullName;
            ret=false;
        } else {
            QXmlInputSource source( &file );
            HandlerXmlReader handler;
            QXmlSimpleReader reader;
            reader.setContentHandler( &handler );
            ret=reader.parse( source );

            if (! ret){
                qDebug () << "Error parser. File : " << fullName;
                break;
            } else {
                fullName.clear();
            }
            file.close();

        }
    }
    return ret;
}

bool ReadWriteConfigurationFile::loadConfigFile()
{
    bool ret = true;
    qDebug () << QDir::currentPath();

    QString fullName= QCoreApplication::applicationDirPath()+ QDir::separator()+NAME_CONFIG_FILE;
     qDebug () << "Path applicativo = " << fullName;


    QFile file( fullName );
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        qDebug() <<  "Failed to open file : "  << fullName;
        ret=false;
    } else {
        QXmlInputSource source( &file );
        HandlerXmlReader handler;
        QXmlSimpleReader reader;
        QXmlStreamReader render1;
        reader.setContentHandler( &handler );
        ret=reader.parse( source );
        if (! ret){
            qDebug () << "Error parser. File : " << fullName;

        }
        file.close();
    }
    return ret;
}

bool ReadWriteConfigurationFile::updateConfigFile()
{
    bool ret = true;
    QDomDocument doc("configfile");
    QDomElement root = doc.createElement(TAG_ROOT_CONFIGURATION);
    doc.appendChild(root);

    const config::ConfigurationFile confData=storageData::StorageDataCommand::istance()->confFile();
    foreach (config::ItemConfiguration itemcfg, confData.m_configItems) {

        QDomElement tag = doc.createElement(itemcfg.m_nameTag);
        QMapIterator <QString,QString> it(itemcfg.m_keyValueAttribMap);
        while (it.hasNext()) {
            it.next();
            tag.setAttribute( it.key(), it.value());
        }
        root.appendChild(tag);
    }
    QString pathDirExe = QCoreApplication::applicationDirPath()+QDir::separator();
    QString configFileUpdate = pathDirExe+ QString ("UpdateTmp_%1").arg(NAME_CONFIG_FILE);

    QFile fileCfgUpd(configFileUpdate);
    if (!fileCfgUpd.open(QIODevice::WriteOnly|QIODevice::Text)) {
        qDebug() << "Cannot open the file: " << NAME_CONFIG_FILE;
       ret= false;
    } else {
        QTextStream stream (&fileCfgUpd);
        stream << doc.toString();
        fileCfgUpd.close();

    }
    QFile origFile (pathDirExe+NAME_CONFIG_FILE);
    if (origFile.exists() ){
        QString tmpFile = QString ("tmp_%1").arg(NAME_CONFIG_FILE);
        ret = origFile.rename(pathDirExe+NAME_CONFIG_FILE,tmpFile);
        if (ret) {
            ret = fileCfgUpd.rename(configFileUpdate,pathDirExe+NAME_CONFIG_FILE);
            if (ret) {
                origFile.setFileName(tmpFile);
                ret = origFile.remove();
                if (!ret) {
                   qDebug () << "Error on deleting file: [ " <<  tmpFile << " ]";
                }

            } else {
                qDebug () << "Error rename file from [ " << configFileUpdate << " ] to [ "<< NAME_CONFIG_FILE << " ]";
            }

        }else{
            qDebug () << "Error rename file from [ " << configFileUpdate << " ] to [ "<< tmpFile << " ]";
        }

    } else {
        ret=false;
        qDebug () << "File [ " << NAME_CONFIG_FILE << " ] not found";
    }

    return ret;
}


ReadWriteConfigurationFile::ReadWriteConfigurationFile(QWidget *parent) :
    QWidget(parent)
{

}
}
