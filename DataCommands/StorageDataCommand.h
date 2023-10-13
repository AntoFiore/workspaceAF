#ifndef STORAGEDATACOMMAND_H
#define STORAGEDATACOMMAND_H

#include <QObject>
#include "DataT_IO_Command.h"
#include "DataSubSet.h"
#include "DataT_SIM_Command.h"
#include "DataT_APDM_Command.h"
#include "DataMT_APDM_Command.h"
#include "DataT_ODO_Command.h"
#include "DataT_RADIO_HOLE_Command.h"
#include "Data_Configuration.h"
#include "DataSingle_Command..h"

namespace storageData{
class StorageDataCommand
{
public:

    static StorageDataCommand *istance();

    void add_T_IO_Cmd(Data_T_IO_Cmd&cmd);
    void add_T_SIM_Cmd(Data_T_SIM_Cmd&cmd);
   // void add_MT_APDM_Cmd(Data_MT_APDM_Cmd&cmd);
    void add_MT_APDM_Cmd(QString program,Data_MT_APDM_Cmd&cmd);
    void add_T_APDM_Cmd(Data_T_APDM_Cmd&cmd);
    void add_T_ODO_Cmd(Data_T_ODO_Cmd &cmd);
    void add_T_RADIO_HOLE_Cmd(Data_T_RADIO_HOLE_Cmd &cmd);
    void add_SubSet(Data_SubSet &subSet);
    void add_Single_Cmd(QString nationalSystem, Data_Single_Cmd &cmd);

    void add_ItemConfigFile(config::ItemConfiguration item);

    const Data_T_IO_Cmds &dataT_IO_Cmds() const;
    const Data_T_SIM_Cmds &dataT_SIM_Cmds() const;
    const Data_SubSet &subSet() const;
    const Data_T_APDM_Cmds &dataT_APDM_Cmds() const;
    //const Data_MT_APDM_Cmds &dataMT_APDM_Cmds() const;
    const Data_MT_APDM_Allprogram &dataMT_APDM_All() const;

    const Data_T_ODO_Cmds &data_T_ODO_Cmds() const;
    const Data_T_RADIO_HOLE_Cmds &data_T_RADIO_HOLE_Cmds() const;
     const Data_Single_NationalSystems &data_SingleNationalSystem() const;


    void dump_T_IO();
    void dump_T_SIM();
    void dump_T_APDM();
    void dump_MT_APDM();
    void dump_SIGNLE_CMD();
    void dump_T_ODO();
    void dump_T_RADIO_HOLE();


    config::ConfigurationFile &confFile();


private:
     StorageDataCommand();


    static  StorageDataCommand* mIstance;

    Data_T_IO_Cmds  m_DataT_IO_Cmds;
    Data_T_SIM_Cmds  m_DataT_SIM_Cmds;
    Data_SubSet m_subSet;
    Data_T_APDM_Cmds  m_DataT_APDM_Cmds;
    //Data_MT_APDM_Cmds  m_DataMT_APDM_Cmds;
    Data_MT_APDM_Allprogram m_DataMT_APDM_All;
     Data_Single_NationalSystems m_Data_SingleNationalSystem;
    Data_T_ODO_Cmds   m_Data_T_ODO_Cmds;
    Data_T_RADIO_HOLE_Cmds m_Data_T_RADIO_HOLE_Cmds;



    config::ConfigurationFile m_confFile;


};
}
#endif // STORAGEDATACOMMAND_H
