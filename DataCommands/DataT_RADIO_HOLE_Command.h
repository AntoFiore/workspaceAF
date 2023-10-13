#ifndef DATAT_RADIO_HOLE_COMMAND_H
#define DATAT_RADIO_HOLE_COMMAND_H
#include <QString>
#include <QVector>
#include <QDebug>

namespace storageData{
struct Data_T_RADIO_HOLE_Cmd {
    QVector <QString> modem;
    QVector <QString> hole_type;
    QVector <QString> command;
    Data_T_RADIO_HOLE_Cmd() {}
    void dump()
    {
        qDebug () << "*****************************";
        foreach (QString modemId, modem) {
            qDebug () << "Modem Id = "<< modemId;
        }
        foreach (QString hole, hole_type) {
            qDebug () << "hole type  = "<< hole;
        }
        foreach (QString cmd, command) {
            qDebug () << "command  = "<< cmd;
        }
        qDebug () << "*****************************";
    }
};

struct Data_T_RADIO_HOLE_Cmds{

    QString nameCmd;
    QVector<Data_T_RADIO_HOLE_Cmd> cmds;
    Data_T_RADIO_HOLE_Cmds(): nameCmd("#"){}
    void dump()
    {
        qDebug () << "Command Name  = " << nameCmd;
        foreach (auto cmd, cmds) {
            cmd.dump();

        }
    }
};
}

#endif // DATAT_RADIO_HOLE_COMMAND_H
