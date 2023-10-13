//classe che gestisce i dati di configurazione file xml
#include "StorageDataCommand.h"
#include "Defxml.h"
namespace storageData{
StorageDataCommand* StorageDataCommand::mIstance;
StorageDataCommand *StorageDataCommand::istance()
{
    if (mIstance == nullptr)
    {
        mIstance = new StorageDataCommand;
    }

    return mIstance;

}

void StorageDataCommand::add_T_IO_Cmd(Data_T_IO_Cmd & cmd)
{

    if ("#" == m_DataT_IO_Cmds.nameCmd) {
        m_DataT_IO_Cmds.nameCmd=NAME_T_IO_CMD_XML;
    }
    m_DataT_IO_Cmds.cmds.push_back(cmd);
}

void StorageDataCommand::add_T_SIM_Cmd(Data_T_SIM_Cmd &cmd)
{
    if ("#" == m_DataT_SIM_Cmds.nameCmd) {
        m_DataT_SIM_Cmds.nameCmd=NAME_T_SIM_CMD_XML;
    }
    m_DataT_SIM_Cmds.cmds.push_back(cmd);


}

//void StorageDataCommand::add_MT_APDM_Cmd(Data_MT_APDM_Cmd &cmd)
//{
//    if ("#"== m_DataMT_APDM_Cmds.nameCmd){
//        m_DataMT_APDM_Cmds.nameCmd=NAME_MT_APDM_XML;
//    }
//    m_DataMT_APDM_Cmds.cmds.push_back(cmd);

//}
void StorageDataCommand::add_Single_Cmd(QString nationalSystem, Data_Single_Cmd &cmd)
{
   if ( ! m_Data_SingleNationalSystem.nationalSystem_Map.contains(nationalSystem) ) {
//      QMap<QString,Data_Single_Cmd> cmdsMap;
      QVector <Data_Single_Cmd> cmds;
      cmds.push_back(cmd);
//      cmdsMap.insert(cmd.command,cmd);


       m_Data_SingleNationalSystem.nationalSystem_Map.insert(nationalSystem,cmds);
   } else {

       m_Data_SingleNationalSystem.nationalSystem_Map[nationalSystem].push_back(cmd);
   }
   ////////////new

   if ( ! m_Data_SingleNationalSystem.nationalSystemNew_Map.contains(nationalSystem) ) {


       QVector <Data_Single_Cmd> cmds;
       cmds.push_back(cmd);
       QMap<QString,QVector <Data_Single_Cmd>> commandValueMap;
       commandValueMap.insert(cmd.command,cmds);
       m_Data_SingleNationalSystem.nationalSystemNew_Map.insert(nationalSystem,commandValueMap);

   } else {

      if (m_Data_SingleNationalSystem.nationalSystemNew_Map[nationalSystem].contains(cmd.command)) {
           m_Data_SingleNationalSystem.nationalSystemNew_Map[nationalSystem][cmd.command].push_back(cmd);
       } else {
          QVector <Data_Single_Cmd> cmds;
           cmds.push_back(cmd);
          QMap<QString,QVector <Data_Single_Cmd>> commandValueMap;
          commandValueMap.insert(cmd.command,cmds);
           m_Data_SingleNationalSystem.nationalSystemNew_Map[nationalSystem].insert(cmd.command,cmds);

      }
  }

}

void StorageDataCommand::add_MT_APDM_Cmd(QString program, Data_MT_APDM_Cmd &cmd)
{

    m_DataMT_APDM_All;

    if (! m_DataMT_APDM_All.mt_ApdmMap.contains(program)){
        QVector<Data_MT_APDM_Cmd> cmds;
        cmds.push_back(cmd);
        m_DataMT_APDM_All.mt_ApdmMap.insert(program,cmds);
    } else {

       m_DataMT_APDM_All.mt_ApdmMap[program].push_back(cmd);
    }

}

void StorageDataCommand::add_T_APDM_Cmd(Data_T_APDM_Cmd &cmd)
{
    if ("#"== m_DataT_APDM_Cmds.nameCmd){
        m_DataT_APDM_Cmds.nameCmd=NAME_T_APDM_CMD_XML;
    }
    m_DataT_APDM_Cmds.cmds.push_back(cmd);



}

void StorageDataCommand::add_T_ODO_Cmd(Data_T_ODO_Cmd &cmd)
{
    if ("#"== m_Data_T_ODO_Cmds.nameCmd){
        m_Data_T_ODO_Cmds.nameCmd=NAME_T_ODO_XML;
    }
    m_Data_T_ODO_Cmds.cmds.push_back(cmd);

}

void StorageDataCommand::add_T_RADIO_HOLE_Cmd(Data_T_RADIO_HOLE_Cmd &cmd)
{
    if ("#"== m_Data_T_RADIO_HOLE_Cmds.nameCmd){
        m_Data_T_RADIO_HOLE_Cmds.nameCmd=NAME_T_ODO_XML;
    }
    m_Data_T_RADIO_HOLE_Cmds.cmds.push_back(cmd);

}

void StorageDataCommand::add_SubSet(Data_SubSet &subSet)
{
    m_subSet=subSet;
}


void StorageDataCommand::add_ItemConfigFile(config::ItemConfiguration item)
{
    m_confFile.m_configItems.push_back(item);
}

StorageDataCommand::StorageDataCommand()
{

}

const Data_Single_NationalSystems &StorageDataCommand::data_SingleNationalSystem() const
{
    return m_Data_SingleNationalSystem;
}

const Data_MT_APDM_Allprogram &StorageDataCommand::dataMT_APDM_All() const
{
    return m_DataMT_APDM_All;
}

//const Data_MT_APDM_Cmds &StorageDataCommand::dataMT_APDM_Cmds() const
//{
//    return m_DataMT_APDM_Cmds;
//}

config::ConfigurationFile &StorageDataCommand::confFile()
{
    return m_confFile;
}

const Data_T_RADIO_HOLE_Cmds &StorageDataCommand::data_T_RADIO_HOLE_Cmds() const
{
    return m_Data_T_RADIO_HOLE_Cmds;
}

const Data_T_ODO_Cmds &StorageDataCommand::data_T_ODO_Cmds() const
{
    return m_Data_T_ODO_Cmds;
}



const Data_T_APDM_Cmds &StorageDataCommand::dataT_APDM_Cmds() const
{
    return m_DataT_APDM_Cmds;
}


const Data_SubSet &StorageDataCommand::subSet() const
{
    return m_subSet;
}

const Data_T_IO_Cmds &StorageDataCommand::dataT_IO_Cmds() const
{
    return m_DataT_IO_Cmds;
}

const Data_T_SIM_Cmds &StorageDataCommand::dataT_SIM_Cmds() const
{
    return m_DataT_SIM_Cmds;
}

void StorageDataCommand::dump_T_IO()
{
    m_DataT_IO_Cmds.dump();
}

void StorageDataCommand::dump_T_SIM()
{
    m_DataT_SIM_Cmds.dump();
}

void StorageDataCommand::dump_T_APDM()
{
    m_DataT_APDM_Cmds.dump();

}

void StorageDataCommand::dump_MT_APDM()
{

    m_DataMT_APDM_All.dump();
}

void StorageDataCommand::dump_SIGNLE_CMD()
{
   // m_Data_SingleNationalSystem.dump();
     m_Data_SingleNationalSystem.dumpNew();

}

void StorageDataCommand::dump_T_ODO()
{
    m_Data_T_ODO_Cmds.dump();

}

void StorageDataCommand::dump_T_RADIO_HOLE()
{
    m_Data_T_RADIO_HOLE_Cmds.dump();
}

}
