#ifndef DATAT_ODO_COMMAND_H
#define DATAT_ODO_COMMAND_H
#include <QString>
#include <QVector>
#include <QDebug>

namespace storageData{
struct Data_T_ODO_Cmd {
    qreal speed_range_min;
    qreal speed_range_max;
    qreal acc_range_min;
    qreal acc_range_max;
    bool isSpeedValidRange;
    bool isAccValidRange;

    Data_T_ODO_Cmd():speed_range_min (0.0),
                     speed_range_max(0.0),
                     acc_range_min(0.0),
                     acc_range_max(0.0),
                     isSpeedValidRange(false),
                     isAccValidRange(false) {}
    void dump()
    {
        qDebug () << "*****************************";
        qDebug () << "Speed Min Range = " << speed_range_min;
        qDebug () << "Speed Max Range = " << speed_range_max;
        qDebug () << "Acceleration Min Range = " << acc_range_min;
        qDebug () << "Acceleration Max Range = " << acc_range_max;
        qDebug () << "*****************************";
    }

};

struct Data_T_ODO_Cmds{

     QString nameCmd;
     QVector<Data_T_ODO_Cmd> cmds;
     Data_T_ODO_Cmds(): nameCmd("#"){}
     void dump()
     {
         qDebug () << "Command Name  = " << nameCmd;
         foreach (auto cmd, cmds) {
             cmd.dump();

         }
     }
};
}

#endif // DATAT_ODO_COMMAND_H
