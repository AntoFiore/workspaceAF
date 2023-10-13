#ifndef STORAGEOUTDATABALISECOMMAND_H
#define STORAGEOUTDATABALISECOMMAND_H

#include <QObject>
#include "OutDataBalise_Command.h"
#include <QMap>
#include <QList>
namespace storageData{
class StorageOutDataBaliseCommand
{

public:
    StorageOutDataBaliseCommand();
    void removeAll();
    void  removeGrpBalise(qint16 numGrp);
    void addGrpBalise(OutDataGrpBalise_Cmd grpBalise, qint16 numBaliseGrp);
    void updSingleBalise(qint16 nimBaliseGrp, qint16 numSingleBalise, OutDataSingleBalise singleBalise);
    void removeSingleBalise(qint16 numBaliseGrp, qint16 numSingleBalise);
    void addPkgToBalise (qint16 numBaliseGrp, qint16 numSingleBalise, OutDataPkgSingleBalise &pkg);
     void updPkgToBalise (qint16 numBaliseGrp, qint16 numSingleBalise, qint16 numPkg,OutDataPkgSingleBalise &pkg);

    OutDataGrpBalise_Cmd * grpBalise(qint16 numBaliseGrp);
    OutDataSingleBalise * singleBalise(qint16 numBaliseGrp,qint16 numBalise);


    qint16 totGrpBalise();
    qint16 totBalise (qint16 numBaliseGrp );
    qint16 totPkg(qint16 numBaliseGrp,qint16 numBalise);
    void removePkgFromBalise(qint16 numBaliseGrp, qint16 numSingleBalise, qint16 pkg);
    OutDataPkgSingleBalise *pkgBalise(qint16 numBaliseGrp, qint16 numSingleBalise, qint16 numPkg);
    void removeAddSingleBalise(qint16 numBaliseGrp, qint16 numSingleBalise);
    qint16 getPositionBalGr(qint64 key);

private:


    QList <OutDataGrpBalise_Cmd> mOutBaliseGrpList;


};
}

#endif // STORAGEOUTDATABALISECOMMAND_H
