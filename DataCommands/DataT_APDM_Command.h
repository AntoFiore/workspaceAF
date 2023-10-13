#ifndef DATAT_APDM_COMMAND_H
#define DATAT_APDM_COMMAND_H
#include <QString>
#include <QVector>
#include <QDebug>
namespace storageData{
struct Data_T_APDM_Cmd {

    QString action;
    qreal ritardo_range_min;
    qreal ritardo_range_max;
    qreal ritardo_default;
    bool existRitardoDef;
    bool isValidRitardoRange;

    qreal tempo_pressione_range_min;
    qreal tempo_pressione_range_max;
    qreal tempo_pressione_default;
    bool isValidTempoPressioneRange;
    bool existTimePressDef;


    Data_T_APDM_Cmd()

    {
        isValidTempoPressioneRange=false;
        existRitardoDef=false;
        existTimePressDef=false;
        isValidRitardoRange=false;
        ritardo_range_min =0.0;
        ritardo_range_max=0.0;
        ritardo_default=0.0;
        tempo_pressione_range_min=0.0;
        tempo_pressione_range_max=0.0;
        tempo_pressione_default=0.0;
    }
    void dump()
    {
        qDebug () << "*****************************";
        qDebug () << "Action = " << action;
        qDebug () << "Ritardo Min Range = " << ritardo_range_min;
        qDebug () << "Ritardo Max Range = " << ritardo_range_max;
        qDebug () << "Default Ritardo = " << ritardo_default;

        qDebug () << "Tempo Pressione Min Range = " << tempo_pressione_range_min;
        qDebug () << "Tempo Pressione Max Range = " << tempo_pressione_range_max;
        qDebug () << "Default Tempo Pressione = " << tempo_pressione_default;

        qDebug () << "*****************************";
    }

};

struct Data_T_APDM_Cmds{

    QString nameCmd;
    QVector<Data_T_APDM_Cmd> cmds;
    Data_T_APDM_Cmds(): nameCmd("#"){}
    void dump()
    {
        qDebug () << "Command Name  = " << nameCmd;
        foreach (auto cmd, cmds) {
            cmd.dump();

        }
    }
};
}

#endif // DATAT_APDM_COMMAND_H
