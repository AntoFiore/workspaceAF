#include "StorageOutDataBaliseCommand.h"
#include "Define.h"
namespace storageData{
StorageOutDataBaliseCommand::StorageOutDataBaliseCommand()
{

}

void StorageOutDataBaliseCommand::removeAll()
{
    mOutBaliseGrpList.clear();



}
void StorageOutDataBaliseCommand::removeGrpBalise(qint16 numBaliseGrp)
{

    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {
        mOutBaliseGrpList.removeAt(numBaliseGrp);
    }
}
void StorageOutDataBaliseCommand::addGrpBalise(OutDataGrpBalise_Cmd grpBalise,qint16 numBaliseGrp)
{
qDebug () << "addGrpBalise(OutDataGrpBalise_Cmd grpBalise,qint16 numBaliseGrp)";
    qint16 totGrBal = mOutBaliseGrpList.size();
    if (totGrBal == 0 ){
        mOutBaliseGrpList.push_back(grpBalise);
    } else {
        if (numBaliseGrp >=0){
            if (numBaliseGrp < totGrBal ){
               OutDataGrpBalise_Cmd &outDataGrpBas = mOutBaliseGrpList[numBaliseGrp] ;
               outDataGrpBas.nameGrpBalise=grpBalise.nameGrpBalise;
               outDataGrpBas.descGrpBalise=grpBalise.descGrpBalise;
               outDataGrpBas.posGrpBalise=grpBalise.posGrpBalise;
               outDataGrpBas.numGrpBalise=grpBalise.numGrpBalise;
               outDataGrpBas.nidCGrpBalise=grpBalise.nidCGrpBalise;
               outDataGrpBas.nidBgGrpBalise=grpBalise.nidBgGrpBalise;
               outDataGrpBas.dirGrpBalise=grpBalise.dirGrpBalise;
               outDataGrpBas.intDistGrpBalise=grpBalise.intDistGrpBalise;
               outDataGrpBas.qLink=grpBalise.qLink;

            } else {
                mOutBaliseGrpList.push_back(grpBalise);
            }
        }
    }
}

void StorageOutDataBaliseCommand::updSingleBalise(qint16 numBaliseGrp , qint16 numSingleBalise,OutDataSingleBalise singleBalise)
{

    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {

       QVector<OutDataSingleBalise> &baliseVec= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect;
        if (numSingleBalise >=0 ) {

            if (numSingleBalise < baliseVec.size() ) {
                baliseVec[numSingleBalise]=singleBalise;
            }/* else {
                baliseVec.push_back(singleBalise);
            }*/
        }
    }
}

void StorageOutDataBaliseCommand::removeSingleBalise(qint16 numBaliseGrp, qint16 numSingleBalise)
{
    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {
        QVector<OutDataSingleBalise> &baliseVec= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect;
         qint16 totBalise = baliseVec.size();
         if (numSingleBalise >=0 && numSingleBalise  < totBalise ){
             baliseVec.removeAt(numSingleBalise);

         }

    }

}

void StorageOutDataBaliseCommand::removeAddSingleBalise(qint16 numBaliseGrp , qint16 numSingleBalise){
    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {
        QVector<OutDataSingleBalise> &baliseVec= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect;
        qint16 totBalise = baliseVec.size();

        if (totBalise < numSingleBalise ){
            qint16 addSingBalise = numSingleBalise - totBalise ;
            for (int i =0; i < addSingBalise;i++){
                OutDataSingleBalise balise;
                QString nameDefaultSingleBal =  QString("%1%2").arg(NAME_BALISE_DEFAULT,QString::number(totBalise+i+1)) ;
                balise.nameSingleBalise=nameDefaultSingleBal;

                balise.nPig = totBalise+i;

                baliseVec.push_back(balise);

            }
        } else if (totBalise > numSingleBalise){

            qint16 removeSingBalise = totBalise - numSingleBalise;
            for (int i =0; i <removeSingBalise;i++ ){
                baliseVec.removeLast();
            }

        }
    }
}

qint16 StorageOutDataBaliseCommand::getPositionBalGr(qint64 key)
{

    qint16 pos=-1;
    qint16 size = mOutBaliseGrpList.size();
    for (int idx =0; idx<size;idx++){
        if (key==mOutBaliseGrpList.at(idx).keyGrp){
            pos=idx;
            break;
        }
    }

    return pos;
}


//void StorageOutDataBaliseCommand::removeSingleBalise(qint16 numBaliseGrp , qint16 numSingleBalise)
//{
//    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {
//        QVector<OutDataSingleBalise> &baliseVec= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect;
//        if (numSingleBalise >=0 && numSingleBalise < baliseVec.size()) {
//            baliseVec.remove(numSingleBalise);
//        }
//    }
//}

void StorageOutDataBaliseCommand::addPkgToBalise(qint16 numBaliseGrp, qint16 numSingleBalise, OutDataPkgSingleBalise& pkg)
{
    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {
        QVector<OutDataSingleBalise> &baliseVec= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect;
        if (numSingleBalise >=0 && numSingleBalise < baliseVec.size()) {
            QVector <OutDataPkgSingleBalise> &outPkgs4SingleBaliseVect =baliseVec[numSingleBalise].outPkgs4SingleBaliseVect ;
             outPkgs4SingleBaliseVect.push_back(pkg);


        }
    }

}

void StorageOutDataBaliseCommand::updPkgToBalise(qint16 numBaliseGrp, qint16 numSingleBalise, qint16 numPkg, OutDataPkgSingleBalise &pkg)
{
    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {
         QVector<OutDataSingleBalise> &baliseVec= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect;
          if (numSingleBalise >=0 && numSingleBalise < baliseVec.size()) {
              QVector <OutDataPkgSingleBalise> &outPkgs4SingleBaliseVect =baliseVec[numSingleBalise].outPkgs4SingleBaliseVect ;
               qint16 sizePkgs = outPkgs4SingleBaliseVect.size();
               if (numPkg >=0 && numPkg < sizePkgs){
                   outPkgs4SingleBaliseVect[numPkg]=pkg;
               }
          }
    }

}
void StorageOutDataBaliseCommand::removePkgFromBalise(qint16 numBaliseGrp, qint16 numSingleBalise, qint16 idpkg){

    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {

       QVector<OutDataSingleBalise> &baliseVec= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect;
        if (numSingleBalise >=0 && numSingleBalise < baliseVec.size()) {

            QVector <OutDataPkgSingleBalise> &outPkgs4SingleBaliseVect =baliseVec[numSingleBalise].outPkgs4SingleBaliseVect ;
            qint16 sizePkgs = outPkgs4SingleBaliseVect.size();
            if (idpkg >=0 && idpkg< sizePkgs){
                outPkgs4SingleBaliseVect.remove(idpkg);
            }
        }
    }
}
qint16 StorageOutDataBaliseCommand::totBalise(qint16 numBaliseGrp)
{
    qint16 totBalise=-1;
    if (numBaliseGrp >=0 &&numBaliseGrp <  mOutBaliseGrpList.size()){

        totBalise= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect.size();
    }
    return totBalise;

}

qint16 StorageOutDataBaliseCommand::totPkg(qint16 numBaliseGrp, qint16 numBalise)
{
    qint16 totPkg=-1;
    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {
        QVector<OutDataSingleBalise> &baliseVec= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect;
        if (numBalise >=0 && numBalise < baliseVec.size()) {
            totPkg=baliseVec[numBalise].outPkgs4SingleBaliseVect.size();

        }
    }
    return totPkg;

}
OutDataPkgSingleBalise * StorageOutDataBaliseCommand::pkgBalise(qint16 numBaliseGrp, qint16 numSingleBalise,  qint16 numPkg){

    OutDataPkgSingleBalise *pkg = nullptr;
    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {

       QVector<OutDataSingleBalise> &baliseVec= mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect;
        if (numSingleBalise >=0 && numSingleBalise < baliseVec.size()) {
            QVector <OutDataPkgSingleBalise> &outPkgs4SingleBaliseVect =baliseVec[numSingleBalise].outPkgs4SingleBaliseVect ;
            qint16 sizePkgs = outPkgs4SingleBaliseVect.size();
            if (numPkg>=0 && numPkg <sizePkgs){
                 pkg=&outPkgs4SingleBaliseVect[numPkg];

            }
        }
    }

    return pkg;
}
OutDataGrpBalise_Cmd *StorageOutDataBaliseCommand::grpBalise(qint16 numBaliseGrp)
{
    OutDataGrpBalise_Cmd *gGrpBal = nullptr;
    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {
        gGrpBal= &mOutBaliseGrpList[numBaliseGrp];
    }

    return gGrpBal;

}

OutDataSingleBalise *StorageOutDataBaliseCommand::singleBalise(qint16 numBaliseGrp, qint16 numBalise)
{
    OutDataSingleBalise *singleBalise = nullptr;
    if (numBaliseGrp >=0 && numBaliseGrp < mOutBaliseGrpList.size()) {

        if (numBalise >=0 && numBalise < mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect.size()){

            singleBalise=&mOutBaliseGrpList[numBaliseGrp].outSingleBaliseVect[numBalise];

        }

    }

    return singleBalise;

}



qint16 StorageOutDataBaliseCommand::totGrpBalise()
{
    return mOutBaliseGrpList.size();

}





}
