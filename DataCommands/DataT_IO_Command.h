#ifndef DATAT_IO_COMMAND_H
#define DATAT_IO_COMMAND_H
#include <QString>
#include <QVector>
#include <QDebug>
namespace storageData{
struct Data_T_IO_Cmd {


    QString nameChannel;
    QVector <QString> actions;
    QVector <QString> defaultactions;
    qreal range_min;
    qreal range_max;
    bool isValidRange;
    Data_T_IO_Cmd():range_min (0.0),range_max(0.0),isValidRange(false){}
    void dump()
    {
        qDebug () << "*****************************";
        qDebug () << "Channel = " << nameChannel;
        foreach (auto action, actions) {
            qDebug () << "Action = " << action;
        }
        foreach (auto action, defaultactions) {
            qDebug () << " default Action = " << action;
        }
        qDebug () << "Min Range = " << range_min;
        qDebug () << "Max Range = " << range_max;
        qDebug () << "*****************************";
    }

};

struct Data_T_IO_Cmds{

     QString nameCmd;
     QVector<Data_T_IO_Cmd> cmds;
     Data_T_IO_Cmds(): nameCmd("#"){}
     void dump()
     {
         qDebug () << "Command Name  = " << nameCmd;
         foreach (auto cmd, cmds) {
             cmd.dump();

         }
     }
};
}

#endif // DATAT_IO_COMMAND_H
