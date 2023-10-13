#include "HandlerXmlReader.h"
#include <QDebug>
#include "Defxml.h"
#include "DataT_IO_Command.h"
#include <QStringList>
#include "StorageDataCommand.h"
#include "DataSubSet.h"
#include "DataT_APDM_Command.h"
#include "DataMT_APDM_Command.h"
#include "DataT_ODO_Command.h"
#include "Data_Configuration.h"

bool isbeginSectiom=false;
namespace config{
HandlerXmlReader::HandlerXmlReader()
{
    // m_currentFamily="";
}
bool HandlerXmlReader::endElement( const QString &namespaceURI, const QString &localName,
                                   const QString &qName )
{
    //    qDebug() << namespaceURI;
    //    qDebug() << localName;
    //    qDebug() << qName;

    Q_UNUSED(namespaceURI)
    Q_UNUSED(localName)
    Q_UNUSED(qName)


    return true;
}


bool HandlerXmlReader::startElement( const QString &namespaceURI, const QString &localName,
                                     const QString &qName, const QXmlAttributes &atts )
{
    Q_UNUSED(namespaceURI)
    Q_UNUSED(localName)
    if (  qName == TAG_ROOT_CONFIGURATION){
        m_familyName=qName;
    }


    if (  qName == TAG_FAMILY_COMMAND){
        m_familyName=atts.value(0);
    }
    if (  qName == TAG_SIGNLE_COMMAND){
        m_familyName=qName;
    }


    if (  qName == TAG_SET){
        m_familyName=qName;
    }


    if ( qName == TAG_COMMAND ) {
        if (NAME_T_IO_CMD_XML==m_familyName){
            handleCmd_T_IO(atts);
        } else if (NAME_T_SIM_CMD_XML==m_familyName){

            handleCmd_T_SIM(atts);
        } else if (NAME_T_APDM_CMD_XML==m_familyName){
            handle_T_APDM(atts);
        }  else if (NAME_T_ODO_XML==m_familyName){
            handle_T_ODO(atts);
        }
        else if (NAME_T_RADIO_HOLE_XML==m_familyName){
            handle_T_RADIO_HOLE(atts);
        }

    }

    if (TAG_COMMAND==qName ){
        if (NAME_MT_APDM_XML == m_familyName){
           handle_T_APDM(atts,m_program);
        }
    }

    if (NAME_MT_APDM_XML == m_familyName){
        if (qName == TAG_PROGRAM){
            m_program=atts.value(0);
        }

    }
    if (TAG_SIGNLE_COMMAND == m_familyName){
        if (qName == TAG_NATIONAL_SYSTEM){
            m_nationalSystem=atts.value(0);
        }

    }
    if (TAG_COMMAND==qName ){
        if (TAG_SIGNLE_COMMAND == m_familyName){
           handle_T_SingleCommand(atts,m_nationalSystem);
        }
    }


    if ( qName == TAG_SUBSET ) {
        if (TAG_SET==m_familyName){

            handleSetSubSet(atts);
        }
    }
      if (  m_familyName == TAG_ROOT_CONFIGURATION){
          if (qName==TAG_CONFIG_COMMAND){

              handle_ConfigurationFile(TAG_CONFIG_COMMAND,atts);
          }


      }

    return true;
}
void HandlerXmlReader::handle_T_ODO(const QXmlAttributes &atts)
{
    storageData::Data_T_ODO_Cmd cmd;
    for( int i=0; i<atts.length(); ++i ){
        if (ATT_RANGE_SPEED ==atts.qName(i)){
            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString Value = range.at(0);
                cmd.speed_range_min=Value.toDouble();
                Value = range.at(1);
                cmd.speed_range_max=Value.toDouble();
                cmd.isSpeedValidRange=true;
            } else {
                cmd.isSpeedValidRange=false;
            }

        } else if (ATT_RANGE_ACC ==atts.qName(i)){
            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString Value = range.at(0);
                cmd.acc_range_min=Value.toDouble();
                Value = range.at(1);
                cmd.acc_range_max=Value.toDouble();
                cmd.isAccValidRange=true;
            } else {
                cmd.isAccValidRange=false;
            }
        }

    }
   storageData::StorageDataCommand::istance()->add_T_ODO_Cmd(cmd);

}

void HandlerXmlReader::handle_T_RADIO_HOLE(const QXmlAttributes &atts)
{
    storageData::Data_T_RADIO_HOLE_Cmd cmd;
    for( int i=0; i<atts.length(); ++i ){
        if (ATT_MODEM ==atts.qName(i)){
            QStringList modem = atts.value(i).split(XML_SEP);
            foreach (QString mod, modem) {
                cmd.modem.push_back(mod);
            }
        } else if (ATT_HOLE_TYPE==atts.qName(i)) {
            QStringList holeType = atts.value(i).split(XML_SEP);
            foreach (QString ht, holeType) {
                cmd.hole_type.push_back(ht);
            }
        } else if (ATT_COMMAND==atts.qName(i)) {
            QStringList command = atts.value(i).split(XML_SEP);
            foreach (QString comm, command) {
                cmd.command.push_back(comm);
            }
        }
    }
    storageData::StorageDataCommand::istance()->add_T_RADIO_HOLE_Cmd(cmd);
}

void HandlerXmlReader::handle_ConfigurationFile(const QString &nameTag, const QXmlAttributes &atts)
{

    qDebug() << nameTag;
    qDebug () << "HandlerXmlReader::handle_ConfigurationFile";

    config::ItemConfiguration item;
    item.m_nameTag=nameTag;
     for( int i=0; i<atts.length(); ++i ){
         item.m_keyValueAttribMap.insert(atts.qName(i),atts.value(i));
     }
     storageData::StorageDataCommand::istance()->add_ItemConfigFile(item);
}
bool HandlerXmlReader::characters( const QString &ch )
{
    Q_UNUSED(ch)
    return true;
}

void HandlerXmlReader::handleCmd_T_IO(const QXmlAttributes &atts)
{

    storageData::Data_T_IO_Cmd cmd;
    for( int i=0; i<atts.length(); ++i ){

        if (ATT_CANNEL ==atts.qName(i)){
            cmd.nameChannel= atts.value(i).trimmed().toUpper();

        } else if (ATT_ACTION ==atts.qName(i)){
            QStringList actions = atts.value(i).split(XML_SEP);
            foreach (auto action, actions) {
                if (action.trimmed().toUpper().size() ){
                    cmd.actions.push_back(action.trimmed().toUpper());
                }
            }

        }  else if (ATT_DEFAULT_ACTION ==atts.qName(i)){
            QStringList defaultactions = atts.value(i).split(XML_SEP);
            foreach (auto action, defaultactions) {
                if (action.trimmed().toUpper().size()){
                    cmd.defaultactions.push_back(action.trimmed().toUpper());
                }
            }

        } else if (ATT_RANGE ==atts.qName(i)){

            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString Value = range.at(0);
                cmd.range_min=Value.toDouble();
                Value = range.at(1);
                cmd.range_max=Value.toDouble();
                cmd.isValidRange=true;
            } else {
                cmd.isValidRange=false;
            }

        } else {
            qDebug () << "Unknow Attribute. < " << atts.qName(i)<< " ";
        }

    }
    storageData::StorageDataCommand::istance()->add_T_IO_Cmd(cmd);


}

void HandlerXmlReader::handleCmd_T_SIM(const QXmlAttributes &atts)
{
    storageData::Data_T_SIM_Cmd cmd;
    for( int i=0; i<atts.length(); ++i ){

        if (ATT_CANNEL ==atts.qName(i)){
            cmd.nameChannel= atts.value(i).trimmed().toUpper();

        } else if (ATT_ACTION ==atts.qName(i)){
            QStringList actions = atts.value(i).split(XML_SEP);
            foreach (auto action, actions) {
                if (action.trimmed().toUpper().size() ){
                    cmd.actions.push_back(action.trimmed().toUpper());
                }
            }

        }  else if (ATT_DEFAULT_ACTION ==atts.qName(i)){
            QStringList defaultactions = atts.value(i).split(XML_SEP);
            foreach (auto action, defaultactions) {
                if (action.trimmed().toUpper().size()){
                    cmd.defaultactions.push_back(action.trimmed().toUpper());
                }
            }

        } else if (ATT_RANGE ==atts.qName(i)){

            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString Value = range.at(0);
                cmd.range_min=Value.toDouble();
                Value = range.at(1);
                cmd.range_max=Value.toDouble();
                cmd.isValidRange=true;
            } else {
                cmd.isValidRange=false;
            }

        } else {
            qDebug () << "Unknow Attribute. < " << atts.qName(i)<< " ";
        }

    }
    storageData::StorageDataCommand::istance()->add_T_SIM_Cmd(cmd);

}

void HandlerXmlReader::handleSetSubSet(const QXmlAttributes &atts)
{

    storageData::Data_SubSet subset;
    for( int i=0; i<atts.length(); ++i ){
        if (ATT_REF ==atts.qName(i)){
            subset.ref = atts.value(i).trimmed().toUpper();
        }
        if (ATT_ISSUE ==atts.qName(i)){
            QStringList issues = atts.value(i).split(XML_SEP);
            foreach (QString issue, issues) {
                subset.issues.push_back(issue.trimmed().toUpper());
            }

        }
    }
    storageData::StorageDataCommand::istance()->add_SubSet(subset);


}

void HandlerXmlReader::handle_T_APDM(const QXmlAttributes &atts)
{
    storageData::Data_T_APDM_Cmd apdmCmd;
    for( int i=0; i<atts.length(); ++i ){
        if (ATT_ACTION ==atts.qName(i)){
            apdmCmd.action = atts.value(i).trimmed().toUpper();
        }

        if (ATT_RANGE_DELAY ==atts.qName(i)){
            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString value = range.at(0);
                apdmCmd.ritardo_range_min=value.toDouble();
                value = range.at(1);
                apdmCmd.ritardo_range_max=value.toDouble();
                apdmCmd.isValidRitardoRange=true;

            } else {
                apdmCmd.isValidRitardoRange=false;
            }
        }
        if (true == apdmCmd.isValidRitardoRange && ATT_DELAY_DEFAULT ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size() ){
                apdmCmd.existRitardoDef=true;
                apdmCmd.ritardo_default=value.toDouble();
            }

        }
        if (ATT_RANGE_TIME_PRESSURE ==atts.qName(i)){
            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString value = range.at(0);
                apdmCmd.tempo_pressione_range_min=value.toDouble();
                value = range.at(1);
                apdmCmd.tempo_pressione_range_max=value.toDouble();
                apdmCmd.isValidTempoPressioneRange=true;

            } else {
                apdmCmd.isValidTempoPressioneRange=false;
            }
        }
        if (true == apdmCmd.isValidRitardoRange && ATT_TIME_PRESSURE_DEFAULT ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size()  ){
                apdmCmd.existTimePressDef=true;
                apdmCmd.tempo_pressione_default=value.toDouble();

            }

        }
    }
    storageData::StorageDataCommand::istance()->add_T_APDM_Cmd(apdmCmd);

}

void HandlerXmlReader::handle_T_APDM(const QXmlAttributes &atts,QString program)
{

    storageData::Data_MT_APDM_Cmd mt_apdmCmd;
    for( int i=0; i<atts.length(); ++i ){
        if (ATT_ACTION ==atts.qName(i)){
            mt_apdmCmd.action = atts.value(i).trimmed().toUpper();
        }

        if (ATT_RANGE_DELAY ==atts.qName(i)){
            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString value = range.at(0);
                mt_apdmCmd.ritardo_range_min=value.toDouble();
                value = range.at(1);
                mt_apdmCmd.ritardo_range_max=value.toDouble();
                mt_apdmCmd.isValidRitardoRange=true;

            } else {
                mt_apdmCmd.isValidRitardoRange=false;
            }
        }
        if (true == mt_apdmCmd.isValidRitardoRange && ATT_DELAY_DEFAULT ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size() ){
                mt_apdmCmd.existRitardoDef=true;
                mt_apdmCmd.ritardo_default=value.toDouble();
            }

        }
        if (ATT_RANGE_TIME_PRESSURE ==atts.qName(i)){
            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString value = range.at(0);
                mt_apdmCmd.tempo_pressione_range_min=value.toDouble();
                value = range.at(1);
                mt_apdmCmd.tempo_pressione_range_max=value.toDouble();
                mt_apdmCmd.isValidTempoPressioneRange=true;

            } else {
                mt_apdmCmd.isValidTempoPressioneRange=false;
            }
        }
        if (true == mt_apdmCmd.isValidRitardoRange && ATT_TIME_PRESSURE_DEFAULT ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size()  ){
                mt_apdmCmd.existTimePressDef=true;
                mt_apdmCmd.tempo_pressione_default=value.toDouble();

            }

        }
        if (SUB_DELAY ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size()  ){
                mt_apdmCmd.sub_delay=value.toDouble();

            } else {
                mt_apdmCmd.sub_delay=SUB_DELAY_DEFAULT;
            }
        }
        if (SUB_DELAY_PRESSURE ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size()  ){
                mt_apdmCmd.sub_delay_pressure=value.toDouble();

            } else {
                mt_apdmCmd.sub_delay_pressure=SUB_DELAY_PRESSUREDEFAULT;
            }
        }
        if (ATT_SUB_ACTION ==atts.qName(i)){

            QStringList value=atts.value(i).trimmed().split(XML_SEP);
            if (value.size()  ){
                foreach (QString subAction, value) {
                    mt_apdmCmd.subActions.push_back(subAction);
                }

            }
        }

    }
    storageData::StorageDataCommand::istance()->add_MT_APDM_Cmd(program,mt_apdmCmd);


}

void HandlerXmlReader::handle_T_SingleCommand(const QXmlAttributes &atts, QString nationalSystem)
{

    storageData::Data_Single_Cmd singleCmd;
     for( int i=0; i<atts.length(); ++i ){
         if (ATT_ENTE ==atts.qName(i)){
             singleCmd.ente = atts.value(i).trimmed().toUpper();
         } else if (ATT_VALUE ==atts.qName(i)){
             singleCmd.value = atts.value(i).trimmed().toUpper();

         } else if (ATT_COMMAND ==atts.qName(i)){
             singleCmd.command = atts.value(i).trimmed().toUpper();

         } else if (ATT_DESCRIPTION ==atts.qName(i)){
             singleCmd.description = atts.value(i).trimmed().toUpper();

         }
     }
    storageData::StorageDataCommand::istance()->add_Single_Cmd(nationalSystem,singleCmd);
}
/*
void HandlerXmlReader::handle_MT_APDM(const QXmlAttributes &atts)
{


    storageData::Data_MT_APDM_Cmd mt_apdmCmd;
    for( int i=0; i<atts.length(); ++i ){
        if (ATT_ACTION ==atts.qName(i)){
            mt_apdmCmd.action = atts.value(i).trimmed().toUpper();
        }

        if (ATT_RANGE_DELAY ==atts.qName(i)){
            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString value = range.at(0);
                mt_apdmCmd.ritardo_range_min=value.toDouble();
                value = range.at(1);
                mt_apdmCmd.ritardo_range_max=value.toDouble();
                mt_apdmCmd.isValidRitardoRange=true;

            } else {
                mt_apdmCmd.isValidRitardoRange=false;
            }
        }
        if (true == mt_apdmCmd.isValidRitardoRange && ATT_DELAY_DEFAULT ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size() ){
                mt_apdmCmd.existRitardoDef=true;
                mt_apdmCmd.ritardo_default=value.toDouble();
            }

        }
        if (ATT_RANGE_TIME_PRESSURE ==atts.qName(i)){
            QStringList range = atts.value(i).split(XML_SEP);
            if (range.size() > 1){
                QString value = range.at(0);
                mt_apdmCmd.tempo_pressione_range_min=value.toDouble();
                value = range.at(1);
                mt_apdmCmd.tempo_pressione_range_max=value.toDouble();
                mt_apdmCmd.isValidTempoPressioneRange=true;

            } else {
                mt_apdmCmd.isValidTempoPressioneRange=false;
            }
        }
        if (true == mt_apdmCmd.isValidRitardoRange && ATT_TIME_PRESSURE_DEFAULT ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size()  ){
                mt_apdmCmd.existTimePressDef=true;
                mt_apdmCmd.tempo_pressione_default=value.toDouble();

            }

        }
        if (SUB_DELAY ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size()  ){
                mt_apdmCmd.sub_delay=value.toDouble();

            } else {
                mt_apdmCmd.sub_delay=SUB_DELAY_DEFAULT;
            }
        }
        if (SUB_DELAY_PRESSURE ==atts.qName(i)){

            QString value=atts.value(i).trimmed();
            if (value.size()  ){
                mt_apdmCmd.sub_delay_pressure=value.toDouble();

            } else {
                mt_apdmCmd.sub_delay_pressure=SUB_DELAY_PRESSUREDEFAULT;
            }
        }
        if (ATT_SUB_ACTION ==atts.qName(i)){

            QStringList value=atts.value(i).trimmed().split(XML_SEP);
            if (value.size()  ){
                foreach (QString subAction, value) {
                    mt_apdmCmd.subActions.push_back(subAction);
                }

            }
        }

    }
    storageData::StorageDataCommand::istance()->add_MT_APDM_Cmd(mt_apdmCmd);
}
*/


}
