#ifndef DATAMT_APDM_COMMAND_H
#define DATAMT_APDM_COMMAND_H
#include <QString>
#include <QVector>
#include <QDebug>
#include <QMap>
namespace storageData{
struct Data_MT_APDM_Cmd {

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

    qreal sub_delay;
    qreal sub_delay_pressure;
    QVector <QString> subActions;


    Data_MT_APDM_Cmd()

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
        sub_delay=0.0;
        sub_delay_pressure=0.0;
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
        qDebug () << "Sub delay = " << sub_delay;
         qDebug () << "Sub delay pressure = " << sub_delay_pressure;
         foreach (QString subAction, subActions) {
              qDebug () << "Sub Action = " << subAction;

         }
        qDebug () << "*****************************";
    }

};

//struct Data_MT_APDM_Cmds{

//    QString nameCmd;
//    QVector<Data_MT_APDM_Cmd> cmds;
//    Data_MT_APDM_Cmds(): nameCmd("#"){}
//    void dump()
//    {
//        qDebug () << "Command Name  = " << nameCmd;
//        foreach (auto cmd, cmds) {
//            cmd.dump();

//        }
//    }
//};




struct Data_MT_APDM_Allprogram {
    QString mFamily;

    QMap<QString,QVector<Data_MT_APDM_Cmd>> mt_ApdmMap;
    Data_MT_APDM_Allprogram() {mFamily="MT_APDM";}
    void dump(){
        qDebug () << "*****************************";
        qDebug () << "Family = " << mFamily;
        QMapIterator <QString,QVector<Data_MT_APDM_Cmd>> it (mt_ApdmMap);
        while (it.hasNext()){
            it.next();
            qDebug () << "Program = " << it.key();

            foreach (Data_MT_APDM_Cmd cmd, it.value()) {
             cmd.dump();

            }

       }
        qDebug () << "*****************************";
    }
};

}

#endif // DATAMT_APDM_COMMAND_H
