#ifndef DATAMT_SINGLE_COMMAND_H
#define DATAMT_SINGLE_COMMAND_H
#include <QString>
#include <QVector>
#include <QDebug>
#include <QMap>
namespace storageData{
struct Data_Single_Cmd {

    QString ente;
    QString value;
    QString command;
    QString description;


    Data_Single_Cmd()

    {

    }
    void dump()
    {
        qDebug () << "*****************************";
        qDebug () << "Ente = " << ente;
        qDebug () << "Value = " << value;
        qDebug () << "Command = " << command;
        qDebug () << "Description = " << description;

        qDebug () << "*****************************";
    }

};

struct Data_Single_NationalSystems {
    QString mFamily;

   QMap<QString,QVector<Data_Single_Cmd>> nationalSystem_Map;
    // QMap<QString,QMap<QString,Data_Single_Cmd>> nationalSystem_Map;
    Data_Single_NationalSystems() {mFamily="Single Command";}


     //programma - comando - valore
     QMap<QString,QMap<QString,QVector <Data_Single_Cmd>>> nationalSystemNew_Map;


    void dump(){
        qDebug () << "*****************************";
        qDebug () << "Family = " << mFamily;
        QMapIterator <QString,QVector<Data_Single_Cmd>> it (nationalSystem_Map);
        while (it.hasNext()){
            it.next();
            qDebug () << "National System = " << it.key();

//            foreach (Data_Single_Cmd cmd, it.value()) {
//                cmd.dump();

//            }

        }
        qDebug () << "*****************************";
    }

    void dumpNew(){
        qDebug () << "*****************************";
        qDebug () << "Family = " << mFamily;
        QMapIterator <QString,QMap<QString,QVector <Data_Single_Cmd>>> it (nationalSystemNew_Map);
        while (it.hasNext()){
            it.next();
            qDebug () << "National System = " << it.key();

             QMapIterator <QString,QVector <Data_Single_Cmd>> cmdValueCmdIt (it.value());
             while (cmdValueCmdIt.hasNext()){
                 qDebug () << "*****************************";
                 cmdValueCmdIt.next();
                 qDebug () << "Command = " << cmdValueCmdIt.key();
                 foreach (Data_Single_Cmd cmd, cmdValueCmdIt.value()) {
                     qDebug () << "Ente =  " << cmd.ente;
                     qDebug () << "Value =  " << cmd.value;

                 }
             }

        }
        qDebug () << "*****************************";
    }
    QString getNationalSystemByEnte(QString ente) {
        QString nstationalSystem="";
         QMapIterator <QString,QMap<QString,QVector <Data_Single_Cmd>>> it (nationalSystemNew_Map);

         while (it.hasNext()){
             it.next();
             QMapIterator <QString,QVector <Data_Single_Cmd>> cmdValueCmdIt (it.value());
             nstationalSystem=it.key();
             bool found  = false;
             while (cmdValueCmdIt.hasNext() && found == false){
                 cmdValueCmdIt.next();
                 foreach (Data_Single_Cmd cmd, cmdValueCmdIt.value()) {

                     if (ente == cmd.ente){
                         found=true;
                         break;

                     }

                 }
                 if (found) {
                     break;
                 }
             }
             if (found) {
                 break;
             }

         }

        return nstationalSystem;
    }

    QString getEnteByNationalSystem(QString nationalSystem) {
        QString ente="";
        QMapIterator <QString,QMap<QString,QVector <Data_Single_Cmd>>> it (nationalSystemNew_Map);

        while (it.hasNext()){
            it.next();

            if (nationalSystem == it.key()) {
                QMapIterator <QString,QVector <Data_Single_Cmd>> cmdValueCmdIt (it.value());
                bool found  = false;
                while (cmdValueCmdIt.hasNext() && found == false){
                    cmdValueCmdIt.next();
                    foreach (Data_Single_Cmd cmd, cmdValueCmdIt.value()) {

                        if (cmd.ente.size()){
                            ente=cmd.ente;
                            found=true;
                            break;
                        }

                    }
                    if (found) {
                        break;
                    }

                }
                if (found) {
                    break;
                }
            }

        }
        return ente;
    }
    QString getDescriptionByCommand(QString nationalSystem,QString command,QString value) {
        QString description="";
        QMapIterator <QString,QMap<QString,QVector <Data_Single_Cmd>>> it (nationalSystemNew_Map);

        while (it.hasNext()){
            it.next();

            if (nationalSystem == it.key()) {
                QMapIterator <QString,QVector <Data_Single_Cmd>> cmdValueCmdIt (it.value());
                bool found  = false;
                while (cmdValueCmdIt.hasNext() && found == false){
                    cmdValueCmdIt.next();
                    foreach (Data_Single_Cmd cmd, cmdValueCmdIt.value()) {

                        if (cmd.command == command && cmd.value==value){
                            description=cmd.description;
                            found=true;
                            break;
                        }

                    }
                    if (found) {
                        break;
                    }

                }
                if (found) {
                    break;
                }
            }

        }
        return description;
    }

};

}

#endif // DATAMT_SINGLE_COMMAND_H
