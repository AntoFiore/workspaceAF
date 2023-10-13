#ifndef OUTDATABALISE_COMMAND_H
#define OUTDATABALISE_COMMAND_H
#include <QString>
#include <QVector>
#include <QDebug>
#include <QDateTime>
namespace storageData{

struct OutDataPkgSingleBalise {

    qint16 idPkg;
    QString balseLine;
    QString dataPkg;

    OutDataPkgSingleBalise(){
        idPkg=-1;
      //  memset (dataPkg,0,sizeof(dataPkg)) ;
    } void dump(){

        qDebug () << "id Pkg "<<idPkg;

        qDebug () << "balseLine ="<< balseLine;
        qDebug () << "Data ="<< dataPkg;

    }
};

struct OutDataSingleBalise{
    QString nameSingleBalise;
    QString descSingleBalise;
    qint32 baseLineSingleBalise;
    qint32 dupSingleBalise;
    qint16 countSingleBalise;
    qint8 nPig;

    OutDataSingleBalise(){
        baseLineSingleBalise=0;
        dupSingleBalise=0;
        countSingleBalise=0;
        nPig=0;
    }

    QVector <OutDataPkgSingleBalise> outPkgs4SingleBaliseVect;

    void dump(){
        qDebug () << "Name Single Balise"<<nameSingleBalise;
        qDebug () << "Description Single Balise"<<descSingleBalise;
        qDebug () << "Base Line Single Balise"<<baseLineSingleBalise;
        qDebug () << "N Pig "<<nPig;
        qDebug () << "M Dup Single Balise"<<dupSingleBalise;
        qDebug () << "M Country Single Balise"<<countSingleBalise;

        foreach (OutDataPkgSingleBalise pkg, outPkgs4SingleBaliseVect) {
            pkg.dump();
        }
    }
};

struct OutDataGrpBalise_Cmd{

    QString nameGrpBalise;
    QString descGrpBalise;
    qint32 posGrpBalise;
    qint16  numGrpBalise;
    qint16 nidCGrpBalise;
    qint16 nidBgGrpBalise;
    qint8 dirGrpBalise;
    qint16 intDistGrpBalise;
    qint8 qLink;

    qint64 keyGrp;
    QString nameCmdScenario;

    QVector<OutDataSingleBalise> outSingleBaliseVect;

    OutDataGrpBalise_Cmd(){
        posGrpBalise=0;
        numGrpBalise=0;
        nidCGrpBalise=0;
        nidBgGrpBalise=0;
        dirGrpBalise=0;
        intDistGrpBalise=0;
        qLink=0;
        keyGrp=QDateTime::currentDateTime().toMSecsSinceEpoch();
        nameCmdScenario="EBALISE";
    }
    void dump(){
         qDebug () << "*****************************";
         qDebug () << "Name Group Balise = "<<nameGrpBalise ;
         qDebug () << "Description Group Balise = "<<descGrpBalise ;
         qDebug () << "Position Balise = "<<posGrpBalise ;
         qDebug () << "Number Balise = "<<numGrpBalise ;
         qDebug () << "NidC Group Balise = "<<nidCGrpBalise ;
         qDebug () << "NidC Group Balise = "<<nidCGrpBalise ;
         qDebug () << "NiBg Group Balise = "<<nidBgGrpBalise ;
         qDebug () << "Direction Group Balise = "<<dirGrpBalise ;
         qDebug () << "Internal Distance Group Balise = "<<intDistGrpBalise ;
         qDebug () << "Q Link Group Balise = "<<qLink ;

         foreach (auto singleBalise, outSingleBaliseVect) {
             singleBalise.dump();

         }


          qDebug () << "*****************************";

    }

};

}
#endif // OUTDATABALISE_COMMAND_H
