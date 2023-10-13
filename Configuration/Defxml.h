#ifndef DEFXML_H
#define DEFXML_H
#include <QString>

#define TAG_FAMILY_COMMAND "command_family"
//t_io T_sim command xml
#define  TAG_COMMAND  "comando"
#define ATT_CANNEL "canale"
#define ATT_ACTION "action"
#define ATT_DEFAULT_ACTION "azione_default"
#define ATT_RANGE "range"
#define XML_SEP ";"

//subset xml
#define TAG_SET "set"
#define TAG_SUBSET "subset"
#define ATT_ISSUE "issue"
#define ATT_REF "ref"
//bl xml
#define TAG_BL "bl"
#define ATT_BL "version"

//t_io T_apdm MT_apdmcommand xml
#define ATT_RANGE_DELAY "range_delay"
#define ATT_DELAY_DEFAULT "delay_default"
#define ATT_RANGE_TIME_PRESSURE "range_time_pressure"
#define ATT_TIME_PRESSURE_DEFAULT "default_time_pressure"
#define ATT_SUB_ACTION "sub_action"
#define SUB_DELAY "sub_delay"
#define SUB_DELAY_PRESSURE "sub_delay_pressure"
#define TAG_PROGRAM "program"
#define ATT_NAME_T_PROGRAM "name_program"
#define SUB_DELAY_DEFAULT 1.0
#define SUB_DELAY_PRESSUREDEFAULT 0.5
//t_io T_odo command xml
#define ATT_RANGE_SPEED "range_speed"
#define ATT_RANGE_ACC "range_acc"
//t_radio_hole command xml
#define ATT_MODEM "modem"
#define ATT_HOLE_TYPE "hole_type"
#define ATT_COMMAND "command"

//name family command in xml file
#define NAME_T_IO_CMD_XML "T_IO"
#define NAME_T_SIM_CMD_XML "T_SIM"
#define NAME_T_APDM_CMD_XML "T_APDM"
#define NAME_T_ODO_XML "T_ODO"
#define NAME_T_RADIO_HOLE_XML "T_RADIO_HOLE"
#define NAME_MT_APDM_XML "MT_APDM"


#define NAME_NAT_SYSTEM_FNM "STM_FNM"
#define NAME_NAT_SYSTEM_LZB "STM_LZB"
#define NAME_NAT_SYSTEM_PZB "STM_PZB"
#define NAME_NAT_SYSTEM_ATB "STM_ATB"
#define NAME_NAT_SYSTEM_TBL "STM_TBL1P"
#define NAME_NAT_SYSTEM_ADIF "STM_ADIF"

//signle command
#define ATT_DESCRIPTION "description"
#define ATT_ENTE "ente"
#define ATT_VALUE "value"
#define ATT_NAME "name"
#define TAG_NATIONAL_SYSTEM "national_system"
#define TAG_SIGNLE_COMMAND "single_command"

#define MAX_NUM_FILE 8
static const char * CommandsFile [] = {
    "subset_026.xml",
    "t_io_config_scenario_creator.xml",
    "t_sim_config_scenario_creator.xml",
    "t_apdm_config_scenario_creator.xml",
    "t_odo_config_scenario_creator.xml",
    "t_radio_hole_config_scenario_creator.xml",
    "t_mt_apdm_config_scenario_creator.xml",
    "t_single_command.xml"

};

//config xml
#define TAG_ROOT_CONFIGURATION "configuration"
#define TAG_CONFIG_COMMAND "configuration_commands"

#define ATT_PATH_COMMAND "path_cmd"

#define NAME_CONFIG_FILE "Config.xml"
#endif // DEFXML_H
