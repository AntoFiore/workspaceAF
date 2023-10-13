#include "GraphicHandlerCommand_BALISE.h"
#include <QDebug>
#include "StorageDataCommand.h"
#include <QDateTime>
#include "FormPackage_1.h"
#include "FormPackage_0.h"
#include "PackegeSerive.h"
#include "MngStorageOutCommand.h"

///////////
#include  "GraphicVariablePkg.h"
#include "GraphicTitlePkg.h"
#include <QSpacerItem>
///

namespace hndcommand{
GraphicHandlerCommand_BALISE::GraphicHandlerCommand_BALISE(QObject *parent)
    : GraphicHandlerCommand{parent}
{
    m_idCommands=T_BALISE;
    m_nameTab = "BALISE_tab";
    m_Ente="EBALISE";
    m_page=CreationScenario_page;
    m_grHandHeaderBal=nullptr;


    m_currentBaliseGrp=-1;
    m_currentBalise=-1;
    m_currentPkg=-1;
}

bool GraphicHandlerCommand_BALISE::initCommands()
{



    qDebug () << "Initialization Balise";
    //m_currentColumnPkg=0;
    //  m_currentRowPkg=0;
    m_HandlerCurrentPackage=nullptr;

    m_grTreeViewBl =new  GraphicHandlerTreeBalise;
    m_grTreeViewBl->init(m_mainWin_Ptr);

    m_grHandHeaderBal = new GraphicHandlerHeaderCommand_BALISE;
    m_grHandHeaderBal->init(m_mainWin_Ptr);

    connect (m_grHandHeaderBal,&GraphicHandlerHeaderCommand_BALISE::updNameBlGrp_SG,[this](QString nameBlGrp, qint16 rowBl){

        m_grTreeViewBl->updBaliseGrp(nameBlGrp,rowBl);
    });
    connect (m_grHandHeaderBal,&GraphicHandlerHeaderCommand_BALISE::setDefaultNameBlalise_SG,[this](qint16 totBal, qint16 rowBl){

        m_grTreeViewBl->updNamesBalise(totBal,rowBl);
    });
    connect (m_grTreeViewBl,&GraphicHandlerTreeBalise::itemBaliseSelected_SG,[this](qint16 numBalGrp,qint16 numSingleBal,qint16 numPkg) {

        m_currentBaliseGrp=numBalGrp;
        m_currentBalise=numSingleBal;
        m_currentPkg=numPkg;
        m_grHandHeaderBal->handleBaliseSelected(numBalGrp,numSingleBal);

        if (m_HandlerCurrentPackage != nullptr) {
            m_HandlerCurrentPackage->deleteView();
            m_HandlerCurrentPackage->deleteLater();
            m_HandlerCurrentPackage=nullptr;
        }
        //E' stato selezionato un package dal treeView
        if (m_currentPkg != -1 && m_currentBaliseGrp != -1 &&  m_currentBalise != -1){

            storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();


            storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
            if (nullptr != pkg){

                // TODO if 360 or 340

                if (pkg->balseLine == "BL 3.4.0") {

                    m_HandlerCurrentPackage = package::HandlerPaclage_3_4_0_Factory::createHandlerPackage(pkg->idPkg);

                } else if (pkg->balseLine == "BL 3.6.0") {

                    m_HandlerCurrentPackage = package::HandlerPaclage_3_6_0_Factory::createHandlerPackage(pkg->idPkg);

                }

                if (nullptr != m_HandlerCurrentPackage){
                    m_HandlerCurrentPackage->set_GrBalise_Balise_Pkg(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
                    m_HandlerCurrentPackage->setIsReload(true);
                    m_HandlerCurrentPackage->setWorkSpaceLayout(m_laytcontainerPackageView);
                    m_HandlerCurrentPackage->creteView();
                }

            }
            //Reload package
        }
    });
    connect (m_grHandHeaderBal,&GraphicHandlerHeaderCommand_BALISE::updNameSingleBalise_SG,[this](qint16 numBalGrp,qint16 numSingleBal,QString nameSingolBalise) {

        qDebug () << "Cambio Nome Balise . Bl Group =  "<< numBalGrp<< " Singol Balise N = " << numSingleBal << " Nome Nuovo balise = " << nameSingolBalise;

        m_grTreeViewBl->updNameBalise(numBalGrp,numSingleBal,nameSingolBalise);

    });



    //Gestione Cancellazione Item
    connect (m_grTreeViewBl,&GraphicHandlerTreeBalise::itemBlGrpdeleted_SG,[this](qint16 numBalGrp,qint16 numSingleBalise,qint16 numPkg) {


        if (numBalGrp != -1) {
            storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
            if (numPkg == -1 &&  numSingleBalise ==-1) {
                outBalsCmd.removeGrpBalise(numBalGrp);
                //Gestione Remove Gruppo

            } else {

                //Gestione Remove Balise
                if (numSingleBalise != -1 && numPkg == -1) {
                    outBalsCmd.removeSingleBalise(numBalGrp,numSingleBalise);
                    qint16 maxBl = m_mainWin_Ptr->spinBox_HdrBlCount->value();
                    maxBl--;
                    //  m_mainWin_Ptr->spinBox_HdrBlCount->setValue(maxBl);
                    storageData::OutDataGrpBalise_Cmd *grBalise = outBalsCmd.grpBalise(numBalGrp);
                    if ( grBalise != nullptr) {
                        grBalise->numGrpBalise=maxBl;
                    }

                    //Gestione remove Singola Balise
                }  else {

                    outBalsCmd.removePkgFromBalise(numBalGrp,numSingleBalise,numPkg);
                }

            }

            if (nullptr != m_HandlerCurrentPackage) {
                m_HandlerCurrentPackage->deleteView();
                m_HandlerCurrentPackage->deleteLater();
                m_HandlerCurrentPackage=nullptr;
            }


        }
        m_grHandHeaderBal->handleBaliseRemoved(numBalGrp,numSingleBalise,numPkg);
    });

    connect (&m_grPkgBl1,&pkg::GraphicBtnPackage_BL_3_2_0::pkgAndBaseLine_SG,[this](qint16 pkg){
        QString pkgString = QString ("%1 %2").arg(PKG_NAME,QString::number(pkg));
        QString baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_2_0);
        addPkgToBalise(pkgString,baseLine,pkg);
    });

    connect (&m_grPkgBl2,&pkg::GraphicBtnPackage_BL_3_4_0::pkgAndBaseLine_SG,[this](qint16 pkg){
        if (m_currentBaliseGrp == -1 ||  m_currentBalise==-1) {
            return ;
        }

        QString pkgString = QString ("%1 %2").arg(PKG_NAME,QString::number(pkg));
        QString baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_4_0);
        addPkgToBalise(pkgString,baseLine,pkg);

        //Se esiste una balise selezionata si crea il nuovo package

        if (nullptr != m_HandlerCurrentPackage) {
            m_HandlerCurrentPackage->deleteView();
            m_HandlerCurrentPackage->deleteLater();
        }
        m_HandlerCurrentPackage = package::HandlerPaclage_3_4_0_Factory::createHandlerPackage(pkg);
        if (nullptr != m_HandlerCurrentPackage ){

            storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();

            //In questo ramo viene gesito il nuovo package, che corrisponde all'altimo inserito nella struttura dati. La posizione
            //del package è zero based per questo viene decrementato di uno;
            //Al gestore del pacchetto sono passati la posizione del gruppo balise, la posizione della balise,e la posizione
            //dell'utlimo pacchetto appena creato
            qint16 currentPkg =outBalsCmd.totPkg(m_currentBaliseGrp,m_currentBalise);
            currentPkg--;
            m_HandlerCurrentPackage->set_GrBalise_Balise_Pkg(m_currentBaliseGrp,m_currentBalise,currentPkg);
            m_HandlerCurrentPackage->setWorkSpaceLayout(m_laytcontainerPackageView);
            //Crea la vista del nuovo pacchetto
            m_HandlerCurrentPackage->creteView();
        } else {
            qDebug () << "Packetnot Implementated yet";
        }
    });

    //Gestione nuovo package
    connect (&m_grPkgBl3,&pkg::GraphicBtnPackage_BL_3_6_0::pkgAndBaseLine_SG,[this](qint16 pkg){


        if (m_currentBaliseGrp == -1 ||  m_currentBalise==-1) {
            return ;
        }

        QString pkgString = QString ("%1 %2").arg(PKG_NAME,QString::number(pkg));
        QString baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
        addPkgToBalise(pkgString,baseLine,pkg);

        //Se esiste una balise selezionata si crea il nuovo package

        if (nullptr != m_HandlerCurrentPackage) {
            m_HandlerCurrentPackage->deleteView();
            m_HandlerCurrentPackage->deleteLater();
        }
        m_HandlerCurrentPackage = package::HandlerPaclage_3_6_0_Factory::createHandlerPackage(pkg);
        if (nullptr != m_HandlerCurrentPackage ){

            storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();

            //In questo ramo viene gesito il nuovo package, che corrisponde all'altimo inserito nella struttura dati. La posizione
            //del package è zero based per questo viene decrementato di uno;
            //Al gestore del pacchetto sono passati la posizione del gruppo balise, la posizione della balise,e la posizione
            //dell'utlimo pacchetto appena creato
            qint16 currentPkg =outBalsCmd.totPkg(m_currentBaliseGrp,m_currentBalise);
            currentPkg--;
            m_HandlerCurrentPackage->set_GrBalise_Balise_Pkg(m_currentBaliseGrp,m_currentBalise,currentPkg);
            m_HandlerCurrentPackage->setWorkSpaceLayout(m_laytcontainerPackageView);
            //Crea la vista del nuovo pacchetto
            m_HandlerCurrentPackage->creteView();
        } else {
            qDebug () << "Packetnot Implementated yet";
        }
    });


    auto mainPageBalise = m_mainWin_Ptr->stackedWidget_ContainerBalise->widget(0);
    m_mainWin_Ptr->stackedWidget_ContainerBalise->setCurrentWidget(mainPageBalise);

    m_containerPackageView = new QFrame(mainPageBalise);
    m_laytcontainerPackageView = new QGridLayout;
    m_containerPackageView->setLayout(m_laytcontainerPackageView);
    m_mainWin_Ptr->scrollArea->setWidget(m_containerPackageView);

   // m_GraphicEditBalise.init(m_mainWin_Ptr);
    m_grid_BtnPackageBalise = new QGridLayout;
    m_grid_BtnPackageBalise->setContentsMargins(1,1,1,1);
    m_mainWin_Ptr->frame_BtnPackageBalise->setLayout(m_grid_BtnPackageBalise);

    m_grPkgBl2.init(m_mainWin_Ptr->stackedWidget_MainContenitor);
    m_grid_BtnPackageBalise->addWidget(m_grPkgBl2.btnWidet());

    m_grPkgBl3.init(m_mainWin_Ptr->stackedWidget_MainContenitor);
    m_grPkgBl2.btnWidet()->hide();

    m_grPkgBl1.init(m_mainWin_Ptr->stackedWidget_MainContenitor);
    m_grid_BtnPackageBalise->addWidget(m_grPkgBl1.btnWidet());


    m_grid_BtnPackageBalise->addWidget(m_grPkgBl3.btnWidet());
    connect (m_mainWin_Ptr->comboBox_Version,&QComboBox::currentTextChanged,[this] (const QString &val){

        qDebug () << "Scatto Versione cambiata "<< val;
        if (val.contains("3.4.0")){
            m_grPkgBl2.btnWidet()->show();
            m_grPkgBl3.btnWidet()->hide();
            m_grPkgBl1.btnWidet()->hide();
        } else if (val.contains("3.6.0")) {
            m_grPkgBl2.btnWidet()->hide();
            m_grPkgBl1.btnWidet()->hide();
            m_grPkgBl3.btnWidet()->show();

        }  else if (val.contains("3.2.0")){
            m_grPkgBl1.btnWidet()->show();
            m_grPkgBl3.btnWidet()->hide();
            m_grPkgBl2.btnWidet()->hide();


        } else {
            m_grPkgBl2.btnWidet()->hide();
            m_grPkgBl3.btnWidet()->hide();
            m_grPkgBl1.btnWidet()->hide();

        }
    });

    return true;

}
void GraphicHandlerCommand_BALISE::addPkgToBalise(QString pkg,QString baseLine, qint16 idPkg){
    qDebug () << pkg;
    qDebug () << baseLine;
    QString namePkg = pkg + " - " +baseLine;

    m_grTreeViewBl->addPkg(m_grHandHeaderBal->currentGrpBalise(),m_grHandHeaderBal->currentSignleBalise(),namePkg);
    m_grHandHeaderBal->addPkg(idPkg,baseLine);
}


void GraphicHandlerCommand_BALISE::removeInternalData()
{
    m_mainWin_Ptr->spinBox_Distance_SINGLE_COMMAND->setMinimum(0);
    m_mainWin_Ptr->spinBox_Delay_SINGLE_COMMAND->setMinimum(0);

    m_mainWin_Ptr->spinBox_Distance_SINGLE_COMMAND->setRange(0,MAX_DISTANCE);
    m_mainWin_Ptr->spinBox_Delay_SINGLE_COMMAND->setRange(0,MAX_DELAY);
}

bool GraphicHandlerCommand_BALISE::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{

    bool ret = dataValidation() ;
    QString cmd ;
    if (ret) {

        if (add_command==actionCommand || update_command==actionCommand){

            if (add_command==actionCommand){
                m_currentRowTable=-1;
            }

            QString pageAndTab = QString::number(m_page)+INTERNAL_SEPARATOR+m_nameTab;
            storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
            storageData::OutDataGrpBalise_Cmd * cmdGrBal=outBalsCmd.grpBalise(m_currentBaliseGrp);
            if (nullptr != cmdGrBal){
                pageAndTab+=INTERNAL_SEPARATOR_KEYBALISE+QString::number(cmdGrBal->keyGrp);

                qint16 numberBalise= cmdGrBal->outSingleBaliseVect.size();
                qDebug () << "Balise Gropu N="<<m_currentBaliseGrp;
                qDebug () << "Total Balise="<<numberBalise;
                for(int idxBal=0;idxBal < numberBalise;idxBal++){
                    const storageData::OutDataSingleBalise &singolBalise = cmdGrBal->outSingleBaliseVect.at(idxBal);
                    qint16 numberPck= singolBalise.outPkgs4SingleBaliseVect.size();
                    qDebug () << "Balise N" <<idxBal <<   "  Tot Number Pkg"<< numberPck;
                    cmd+=QString::number(cmdGrBal->posGrpBalise);
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=cmdGrBal->nameCmdScenario;
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=QString::number(cmdGrBal->dirGrpBalise);
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=QString::number(singolBalise.baseLineSingleBalise);
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+="0"; //media TODO
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=QString::number(singolBalise.nPig);
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=QString::number(numberBalise-1);
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=QString::number(singolBalise.dupSingleBalise);
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=QString::number(singolBalise.countSingleBalise);
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=QString::number(cmdGrBal->nidCGrpBalise);
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=QString::number(cmdGrBal->nidBgGrpBalise);
                    cmd+=INTERNAL_SEPARATOR;
                    cmd+=QString::number(cmdGrBal->qLink);
                    if (0 == numberPck){
                        cmd+=INTERNAL_SEPARATOR;
                        cmd+="255";
                        emit addRemoveUpdateCommand_SG(cmd,actionCommand,pageAndTab,m_currentRowTable);
                        cmd.clear();

                    } else {
                        QString cmdPkg;
                        for (int idxPkg=0;idxPkg < numberPck;idxPkg++){
                            const storageData::OutDataPkgSingleBalise pkg=singolBalise.outPkgs4SingleBaliseVect.at(idxPkg);
                            QStringList pkgData = pkg.dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);
                            qint16 sizePkg =pkgData.size();
                            if (pkgData.size() > 0){
                                for (int idxPkg =0; idxPkg < sizePkg;idxPkg++){
                                    if (EMPTY_VALUE != pkgData.at(idxPkg)){
                                        if (0==idxPkg){
                                            cmd+=INTERNAL_SEPARATOR;
                                        } else {
                                            cmd+=INTERNAL_FIELD_SEPARATOR_PKG;
                                        }

                                        cmd+=pkgData.at(idxPkg);
                                    }
                                }

                            }
                        }
                        cmd+=INTERNAL_SEPARATOR;
                        cmd+="255";

                        emit addRemoveUpdateCommand_SG(cmd,actionCommand,pageAndTab,m_currentRowTable);
                        cmd.clear();
                    }
                }
            }
            if (update_command==actionCommand){
                emit addRemoveUpdateCommand_SG(EMPTY_VALUE,actionCommand,"",-1);

            }

        } else {
              emit addRemoveUpdateCommand_SG(EMPTY_VALUE,actionCommand,EMPTY_VALUE,m_currentRowTable);
        }
    }

    return ret;
}

bool GraphicHandlerCommand_BALISE::dataValidation()
{
    bool ret=true;

    if (m_currentBaliseGrp == -1) {
        ret=false;
        m_mainWin_Ptr->statusbar->showMessage(tr(VALUE_NOT_VALID),TIME_OF_STATUS_MESS);
    }
    return ret;

}
qint64 GraphicHandlerCommand_BALISE::getKeyBaliseFromCommand(QString command)
{
    qint64 keyBalise =-1;
    QStringList commandList = command.split(INTERNAL_SEPARATOR);
    qint32 sizeCmd = commandList.size();
    if (sizeCmd >tab_position ){

        QString tab =  commandList[tab_position];

        if (tab.contains(INTERNAL_SEPARATOR_KEYBALISE)){

            QStringList keyBaliseList = tab.split(INTERNAL_SEPARATOR_KEYBALISE);
            if (keyBaliseList.size() > 1){

                keyBalise=keyBaliseList[1].toLongLong();

            }
        }
    }

    return keyBalise;

}

void GraphicHandlerCommand_BALISE::showCommand_SL (QString command, qint32 rowTable)
{

    qint64 keyBalise =getKeyBaliseFromCommand(command);
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    qint16 totBalGr = outBalsCmd.totGrpBalise();
    storageData::OutDataGrpBalise_Cmd * cmdGrBal=nullptr;
    qint8 nPig=-1;
    qint16 idxBaliseGrp=-1;
    qint16 idxBalise=-1;
    m_currentRowTable=rowTable;
    idxBaliseGrp=outBalsCmd.getPositionBalGr(keyBalise);

    if (idxBaliseGrp != -1 ) {
        cmdGrBal = outBalsCmd.grpBalise(idxBaliseGrp);
        QStringList fieldBalise = command.split(INTERNAL_SEPARATOR);
        if (fieldBalise.size() > qlink_position){
            nPig= fieldBalise[npig_position].toInt(); //positon nPig

            if (nullptr != cmdGrBal ){
                QVector<storageData::OutDataSingleBalise>& outSingleBaliseVect=cmdGrBal->outSingleBaliseVect;
                qint16 size = cmdGrBal->outSingleBaliseVect.size();
                bool foundNpig=false;
                for (int idxBal = 0 ; idxBal < size && !foundNpig ;idxBal++){
                    if (outSingleBaliseVect.at(idxBal).nPig==nPig){
                        foundNpig=true;
                        idxBalise=idxBal;
                    }
                }
                if (foundNpig) {
                    m_grHandHeaderBal->handleBaliseSelected(idxBaliseGrp,idxBalise);
                    qint16 totPkg = outBalsCmd.totPkg(idxBaliseGrp,idxBalise);
                    qDebug () << "Tot  Pkg = "<< totPkg;
                    if (nullptr != m_HandlerCurrentPackage) {
                        m_HandlerCurrentPackage->deleteView();
                        m_HandlerCurrentPackage->deleteLater();
                        m_HandlerCurrentPackage=nullptr;
                    }
                    m_currentBaliseGrp=idxBaliseGrp;
                    m_currentBalise=idxBalise;
                    m_currentPkg=-1;
                    if (totPkg){
                        m_currentPkg=0;
                         storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
                         if (nullptr != pkg){

                             m_HandlerCurrentPackage = package::HandlerPaclage_3_6_0_Factory::createHandlerPackage(pkg->idPkg);
                             if (nullptr != m_HandlerCurrentPackage){
                                 m_HandlerCurrentPackage->set_GrBalise_Balise_Pkg(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
                                 m_HandlerCurrentPackage->setIsReload(true);
                                 m_HandlerCurrentPackage->setWorkSpaceLayout(m_laytcontainerPackageView);
                                 m_HandlerCurrentPackage->creteView();

                             }

                         }

                    }
                    m_grTreeViewBl->selectionManuallyTreeView(m_currentBaliseGrp,m_currentBalise,m_currentPkg);


                }
            }

        }

    }

    return ;
}
}
