#ifndef DEFINE_H
#define DEFINE_H
#include <QString>
#include <QObject>
#include <QVector>
#include <QDir>
#define CCS_FATAL_ERROR_TITLE "CCS - Fatal Error"

// static const QVector <char*> HELP_MENU_AND_OPT ={ QT_TR_NOOP("Help"),QT_TR_NOOP("About"),QT_TR_NOOP("About1")};
//static const char *HELP_FILE_AND_OPT[] ={ QT_TR_NOOP("File"),QT_TR_NOOP("Opz1"),QT_TR_NOOP("Opz2")};
#define HELP_MENU_NAME "Help"
#define HELP_OPT_ABOUT "About"

#define FILE_MENU_NOME "File"
#define FILE_OPT_START_SESSION "Start Session"
#define FILE_OPT_CLOSE_SESSION "Stop Session"

#define ACTION_TOOLBAR_CREATE "Create"
#define ACTION_TOOLBAR_GENERATE "Generate"
#define ACTION_TOOLBAR_SETTINGS "Settings"
#define ACTION_TOOLBAR_CONVERT  "Convert"
//#define ACTION_TOOLBAR_CLOSE "Close"

//T_IO graphic Tab
enum Commands_E {
    T_IO_CMD=0,
    T_SIM_CMD,
    T_APDM_CMD,
    MT_APDM_CMD,
    T_ODO,
    T_RADIO_HOLE,
    T_SINGLE_CMD,
    T_BALISE

};

enum EventPage_E {
    envent_create_page,
    event_settings_page,
    event_all_pages,
};

#define MAX_DISTANCE 65535
#define MAX_DELAY 65535 //sec
#define MAX_COLUMN_STEP_SEQ 20
#define NAME_COLUMN "Field"
enum Page_E {
    CreationScenario_page=0,
    ConvertScenario_page,
    Settings_page,

    CreationScenario_page_all

};
enum ActionCommand_E {
    add_command,
    remove_command,
    update_command
};

//#define MAX_TAB_CREATE_CMD 5
#define MAX_NUMBER_PAG 2
#define TOOL_TIP_ADD_CMD "Add Command"
#define TOOL_TIP_REMOVE_CMD "Remove Command"
#define TOOL_TIP_EXPORT_CMD "Export Command"
#define TOOL_TIP_UPDATE_CMD "Update Command"

#define EXPORT_OK "Export  Ok"
#define EXPORT_KO "Export  Error"
#define EXPORT_TITLE "Export Scenario"

#define INTERNAL_SEPARATOR_KEYBALISE "+"
#define INTERNAL_SEPARATOR "#"
#define EMPTY_PACKAGE "----"
#define EMPTY_VALUE "-"
//#define EMPTY_STRING ""
#define INTERNAL_FIELD_SEPARATOR_PKG ";"
#define INTERNAL_SEPARATOR_PKG "<>"

#define SPEED_RANGE_DEFAULT "0;400"
#define ACC_RANGE_DEFAULT "0;120"

#define SAVE_CONFIG_FILE_OK "Save parameters ok"
#define SAVE_CONFIG_FILE_KO "error during the saving  the paramater"
#define TIME_OF_STATUS_MESS 2 * 1000 //sec

#define VALUE_NOT_VALID "Value not valid"


#define DELETE_GRPBALSE_ACTNAME "Remove"
#define PKG_NAME "Pkg"
#define BASE_LINE_NAME "BL"
#define NAME_BALISE_DEFAULT "Balise N. "
#define BASELINE_3_2_0 "3.2.0"
#define BASELINE_3_4_0 "3.4.0"
#define BASELINE_3_6_0 "3.6.0"

#define DEFAULT_CFG_PATH "etc"
enum BaseLine {
    baseline_unknow = 0,
    baseline_320 = 320,
    baseline_340 = 340,
    baseline_360 = 360
};

#endif // DEFINE_H
