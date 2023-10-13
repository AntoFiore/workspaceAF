#include "GraphicHandlerHeaderCommand_BALISE.h"
#include <QDebug>
#include "StorageDataCommand.h"
#include <QDateTime>
#include "FormPackage_1.h"
#include "FormPackage_0.h"
#include "PackegeSerive.h"
#include "MngStorageOutCommand.h"
#include <QString>
namespace hndcommand{
QStandardItem *Provaitem ;
GraphicHandlerHeaderCommand_BALISE::GraphicHandlerHeaderCommand_BALISE(QObject *parent)
    : GraphicHandlerCommand{parent}
{
    m_idCommands=T_BALISE;
    //  m_nameTab = "BALISE_tab";
    //  m_Ente="EBALISE";
    m_page=CreationScenario_page;
    m_currentGrpBalise=-1;
    m_currentSignleBalise=-1;
}

bool GraphicHandlerHeaderCommand_BALISE::initCommands()
{

    qDebug () << "GraphicHandlerHeaderCommand_BALISE  initCommands";
    if (m_mainWin_Ptr != nullptr) {
        qDebug () << "m_mainWin_Ptr is Valid";

        m_mainWin_Ptr->spinBox_HdrPosition->setMinimum(HDR_MINVALUE_POSITION);
        m_mainWin_Ptr->spinBox_HdrPosition->setMaximum(HDR_MAXVALUE_POSITION);
        m_mainWin_Ptr->spinBox_HdrPosition->setValue(HDR_MINVALUE_POSITION);


        m_mainWin_Ptr->spinBox_HdrBlCount->setMinimum(HDR_MINVALUE_BALCNT);
        m_mainWin_Ptr->spinBox_HdrBlCount->setMaximum(HDR_MAXVALUE_BALCNT);
        m_mainWin_Ptr->spinBox_HdrBlCount->setValue(HDR_MINVALUE_BALCNT);

        m_mainWin_Ptr->spinBox_HdrBlNidC->setMinimum(HDR_MINVALUE_NID_C);
        m_mainWin_Ptr->spinBox_HdrBlNidC->setMaximum(HDR_MAXVALUE_NID_C);
        m_mainWin_Ptr->spinBox_HdrBlNidC->setValue(HDR_MINVALUE_NID_C);

        m_mainWin_Ptr->spinBox_HdrBlNidBg->setMinimum(HDR_MINVALUE_NID_BG);
        m_mainWin_Ptr->spinBox_HdrBlNidBg->setMaximum(HDR_MAXVALUE_NID_BG);
        m_mainWin_Ptr->spinBox_HdrBlNidBg->setValue(HDR_MINVALUE_NID_BG);

        m_mainWin_Ptr->comboBox_HdrBlDir->addItem("0");
        m_mainWin_Ptr->comboBox_HdrBlDir->addItem("1");
        m_mainWin_Ptr->comboBox_HdrBlDir->setCurrentText("0");


        m_mainWin_Ptr->comboBox_HdrBlQLink->addItem("0");
        m_mainWin_Ptr->comboBox_HdrBlQLink->addItem("1");
        m_mainWin_Ptr->comboBox_HdrBlDir->setCurrentText("0");

        m_mainWin_Ptr->spinBox_HdrBlInternalDist->setMinimum(HDR_MINVALUE_INTER_DIS);
        m_mainWin_Ptr->spinBox_HdrBlInternalDist->setMaximum(HDR_MAXVALUE_INTER_DIS);
        m_mainWin_Ptr->spinBox_HdrBlInternalDist->setValue(HDR_MINVALUE_INTER_DIS);

        m_mainWin_Ptr->spinBox_HdrBlBaseLine->setMinimum(HDR_SINGLE_MINVALUE_BLINE);
        m_mainWin_Ptr->spinBox_HdrBlBaseLine->setMaximum(HDR_SINGLE_MAXVALUE_BLINE);
        m_mainWin_Ptr->spinBox_HdrBlBaseLine->setValue(HDR_SINGLE_MINVALUE_BLINE);


        m_mainWin_Ptr->spinBox_HdBlSingleNPig->setMinimum(HDR_SINGLE_MINVALUE_NPIG);
        m_mainWin_Ptr->spinBox_HdBlSingleNPig->setMaximum(HDR_SINGLE_MAXVALUE_NPIG);
        m_mainWin_Ptr->spinBox_HdBlSingleNPig->setValue(HDR_SINGLE_MINVALUE_NPIG);


        m_mainWin_Ptr->spinBox_HdBlSingleMDup->setMinimum(HDR_SINGLE_MINVALUE_MDUP);
        m_mainWin_Ptr->spinBox_HdBlSingleMDup->setMaximum(HDR_SINGLE_MAXVALUE_MDUP);
        m_mainWin_Ptr->spinBox_HdBlSingleMDup->setValue(HDR_SINGLE_MINVALUE_MDUP);

        m_mainWin_Ptr->spinBox_HdrBlSingleMCount->setMinimum(HDR_SINGLE_MINVALUE_MCOUNT);
        m_mainWin_Ptr->spinBox_HdrBlSingleMCount->setMaximum(HDR_SINGLE_MAXVALUE_MCOUNT);
        m_mainWin_Ptr->spinBox_HdrBlSingleMCount->setValue(HDR_SINGLE_MINVALUE_MCOUNT);

        // m_mainWin_Ptr->lineEdit_HdrBlName

        //        connect (m_mainWin_Ptr->lineEdit_HdrBlName,&QLineEdit::editingFinished, [this]() {

        //            qDebug () << "Finito Editing del campo nome ";
        //            //current balise.name = m_mainWin_Ptr->lineEdit_HdrBlName->text();

        //        });

        m_mainWin_Ptr->frame_BaliseHdrSingle->setEnabled(false);
        m_mainWin_Ptr->frame_BaliseHeader->setEnabled(false);

        connect ( m_mainWin_Ptr->pushButton_addPkdBalise,&QPushButton::clicked,this,&GraphicHandlerHeaderCommand_BALISE::addNewBaliseGrp_SL);
        connectDisconnect();
    }
    return true;

}
//Put data in Balise Data panel
void GraphicHandlerHeaderCommand_BALISE::handleBaliseSelected(qint16 numBalGrp, qint16 numSingleBal)
{
    qDebug () << "Balise Group Selected : "<< numBalGrp << " Single Balise Selected :" << numSingleBal;

    connectDisconnect(false);
    clearDataPanel();
    m_currentGrpBalise=numBalGrp;
    m_currentSignleBalise=numSingleBal;

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataGrpBalise_Cmd * grpBalise =outBalsCmd.grpBalise(numBalGrp);
    if (grpBalise != nullptr){

        m_mainWin_Ptr->lineEdit_HdrBlName->setText(grpBalise->nameGrpBalise);
        m_mainWin_Ptr->lineEdit_HdrBlDesc->setText(grpBalise->descGrpBalise);
        m_mainWin_Ptr->spinBox_HdrBlInternalDist->setValue(grpBalise->intDistGrpBalise);
        m_mainWin_Ptr->spinBox_HdrBlNidBg->setValue(grpBalise->nidBgGrpBalise);
        m_mainWin_Ptr->spinBox_HdrBlNidC->setValue(grpBalise->nidCGrpBalise);
        m_mainWin_Ptr->spinBox_HdrPosition->setValue(grpBalise->posGrpBalise);
        m_mainWin_Ptr->spinBox_HdrBlCount->setValue(grpBalise->numGrpBalise);
        m_mainWin_Ptr->comboBox_HdrBlDir->setCurrentText(QString::number(grpBalise->dirGrpBalise));
        m_mainWin_Ptr->comboBox_HdrBlQLink->setCurrentText(QString::number(grpBalise->qLink));

        if (numSingleBal >= 0){
            m_mainWin_Ptr->frame_BaliseHdrSingle->setEnabled(true);
            storageData::OutDataSingleBalise *singBal= outBalsCmd.singleBalise(m_currentGrpBalise,m_currentSignleBalise);
            if (singBal != nullptr){

//                if (! singBal->nameSingleBalise.size() ) {
//                    //set default name
//                    QString nameBaliseDef= QString ("%1%2").arg(NAME_BALISE_DEFAULT,QString::number(numSingleBal+1));
//                    singBal->nameSingleBalise=nameBaliseDef;
//                }

                m_mainWin_Ptr->lineEdit_HdrBlSingleName->setText(singBal->nameSingleBalise);
                m_mainWin_Ptr->lineEdit_HdrBlSingleDesc->setText(singBal->descSingleBalise);
                m_mainWin_Ptr->spinBox_HdrBlBaseLine->setValue(singBal->baseLineSingleBalise);
                m_mainWin_Ptr->spinBox_HdBlSingleNPig->setValue(singBal->nPig);
                m_mainWin_Ptr->spinBox_HdrBlSingleMCount->setValue(singBal->countSingleBalise);
                m_mainWin_Ptr->spinBox_HdBlSingleMDup->setValue(singBal->dupSingleBalise);
            }
        } else {
            m_mainWin_Ptr->frame_BaliseHdrSingle->setEnabled(false);
        }
    }

    connectDisconnect(true);

}

void GraphicHandlerHeaderCommand_BALISE::handleBaliseRemoved(qint16 numBalGrp,qint16 numSingleBalise,qint16 numPkg)
{
    if (numBalGrp != -1) {
        storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
        connectDisconnect(false);
        if (numPkg == -1 &&  numSingleBalise ==-1) {
            //outBalsCmd.removeGrpBalise(numBalGrp);
            clearDataPanel();
            if ( ! outBalsCmd.totGrpBalise() ) {
                m_mainWin_Ptr->frame_BaliseHeader->setEnabled(false);
                clearDataPanel();
            }
        } else {

            if (numSingleBalise != -1 && numPkg == -1) {
                //  outBalsCmd.removeSingleBalise(numBalGrp,numSingleBalise);
                qint16 maxBl = m_mainWin_Ptr->spinBox_HdrBlCount->value();
                maxBl--;
                m_mainWin_Ptr->spinBox_HdrBlCount->setValue(maxBl);
            }
        }
        connectDisconnect(true);


    }
}

void GraphicHandlerHeaderCommand_BALISE::addPkg(qint16 idPkg, QString baseLine)
{
    //TODO
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise package;
    package.idPkg=idPkg;
    package.balseLine=baseLine;

    outBalsCmd.addPkgToBalise(m_currentGrpBalise,m_currentSignleBalise,package);



}
//Slot Hendler  Update Signal Balise
void GraphicHandlerHeaderCommand_BALISE::changeValue_SL(int value)
{

    Q_UNUSED (value)
    qDebug () << "Value Integer Changed";
    updateDataBalise();


}
//Slot Hendler  Update Signal Balise
void GraphicHandlerHeaderCommand_BALISE::changeValue_SL(QString value)
{
    Q_UNUSED (value)
    qDebug () << "Value String Changed";
    updateDataBalise();
}
//Update Balise Data
void GraphicHandlerHeaderCommand_BALISE::updateDataBalise()
{
    qDebug () << "GraphicHandlerHeaderCommand_BALISE::updateDataBalise()";
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataGrpBalise_Cmd grpBalise;
    grpBalise.nameGrpBalise = m_mainWin_Ptr->lineEdit_HdrBlName->text();
    grpBalise.descGrpBalise = m_mainWin_Ptr->lineEdit_HdrBlDesc->text();
    grpBalise.intDistGrpBalise = m_mainWin_Ptr->spinBox_HdrBlInternalDist->value();
    grpBalise.nidBgGrpBalise = m_mainWin_Ptr->spinBox_HdrBlNidBg->value();
    grpBalise.nidCGrpBalise = m_mainWin_Ptr->spinBox_HdrBlNidC->value();
    grpBalise.posGrpBalise = m_mainWin_Ptr->spinBox_HdrPosition->value();
    grpBalise.numGrpBalise = m_mainWin_Ptr->spinBox_HdrBlCount->value();
    grpBalise.dirGrpBalise=m_mainWin_Ptr->comboBox_HdrBlDir->currentText().toInt();
    grpBalise.qLink= m_mainWin_Ptr->comboBox_HdrBlQLink->currentText().toInt();

    storageData::OutDataSingleBalise singBal;
    singBal.nameSingleBalise=m_mainWin_Ptr->lineEdit_HdrBlSingleName->text();
    singBal.descSingleBalise=    m_mainWin_Ptr->lineEdit_HdrBlSingleDesc->text();
    singBal.baseLineSingleBalise=m_mainWin_Ptr->spinBox_HdrBlBaseLine->value();
    singBal.countSingleBalise=m_mainWin_Ptr->spinBox_HdrBlSingleMCount->value();
    singBal.dupSingleBalise=m_mainWin_Ptr->spinBox_HdBlSingleMDup->value();
    singBal.nPig=m_mainWin_Ptr->spinBox_HdBlSingleNPig->value();

    storageData::OutDataSingleBalise *p_singBal = outBalsCmd.singleBalise(m_currentGrpBalise, m_currentSignleBalise);
    if (p_singBal != nullptr) {
        singBal.outPkgs4SingleBaliseVect = p_singBal->outPkgs4SingleBaliseVect;
    }

    outBalsCmd.addGrpBalise(grpBalise,m_currentGrpBalise);
    outBalsCmd.updSingleBalise(m_currentGrpBalise,m_currentSignleBalise,singBal);

}
//New Balise Group
void GraphicHandlerHeaderCommand_BALISE::addNewBaliseGrp_SL()
{
    connectDisconnect(false);
    clearDataPanel();
    m_mainWin_Ptr->frame_BaliseHeader->setEnabled(true);
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataGrpBalise_Cmd grpBalise;
    m_currentGrpBalise= outBalsCmd.totGrpBalise(); //E' la posizione (0) based del gruppo balise
    m_currentSignleBalise=DEFAUT_NUM_BALISE;
    QString baliseSting = QString::number(m_currentGrpBalise);
    QString baliseGrDefault = QString ("BG [%1]").arg(baliseSting);
    m_mainWin_Ptr->lineEdit_HdrBlName->setText(baliseGrDefault);
    m_mainWin_Ptr->spinBox_HdrBlCount->setValue(DEFAUT_NUM_BALISE);


    grpBalise.nameGrpBalise = baliseGrDefault;
    outBalsCmd.addGrpBalise(grpBalise,m_currentGrpBalise);
    outBalsCmd.removeAddSingleBalise(m_currentGrpBalise,m_currentSignleBalise);


    emit updNameBlGrp_SG (baliseGrDefault,m_currentGrpBalise);
     emit setDefaultNameBlalise_SG(m_currentSignleBalise,m_currentGrpBalise);
    updateDataBalise();
    connectDisconnect(true);


}

void GraphicHandlerHeaderCommand_BALISE::updateNameGrpBalise_SL()
{
    updateDataBalise();
    emit updNameBlGrp_SG (m_mainWin_Ptr->lineEdit_HdrBlName->text(),m_currentGrpBalise); //Aggiorna il Treeview
}

void GraphicHandlerHeaderCommand_BALISE::updNameSingleBalise_SL()
{

     emit  updNameSingleBalise_SG(m_currentGrpBalise,m_currentSignleBalise,m_mainWin_Ptr->lineEdit_HdrBlSingleName->text());

}
void GraphicHandlerHeaderCommand_BALISE::connectDisconnect(bool isConnect)
{

    if (isConnect) {
        connect (m_mainWin_Ptr->spinBox_HdrPosition,QOverload<int>::of(&QSpinBox::valueChanged),this ,QOverload<int>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL ));
        //  connect (m_mainWin_Ptr->spinBox_HdrBlCount,QOverload<int>::of(&QSpinBox::valueChanged),this ,QOverload<int>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL ));
        connect (m_mainWin_Ptr->spinBox_HdrBlCount,QOverload<int>::of(&QSpinBox::valueChanged),this ,&GraphicHandlerHeaderCommand_BALISE::updNunmberBlalise_SL);

        connect (m_mainWin_Ptr->spinBox_HdrBlNidC,QOverload<int>::of(&QSpinBox::valueChanged),this ,QOverload<int>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL ));
        connect (m_mainWin_Ptr->spinBox_HdrBlNidBg,QOverload<int>::of(&QSpinBox::valueChanged),this ,QOverload<int>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL ));
        connect (m_mainWin_Ptr->spinBox_HdrBlInternalDist,QOverload<int>::of(&QSpinBox::valueChanged),this ,QOverload<int>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL ));
        connect (m_mainWin_Ptr->comboBox_HdrBlDir,&QComboBox::currentTextChanged, this ,QOverload<QString>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL));
        connect (m_mainWin_Ptr->comboBox_HdrBlQLink,&QComboBox::currentTextChanged, this ,QOverload<QString>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL));
        connect (m_mainWin_Ptr->spinBox_HdrBlBaseLine,QOverload<int>::of(&QSpinBox::valueChanged), this ,QOverload<int>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL));
        connect (m_mainWin_Ptr->spinBox_HdBlSingleMDup,QOverload<int>::of(&QSpinBox::valueChanged), this ,QOverload<int>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL));
        connect (m_mainWin_Ptr->spinBox_HdrBlSingleMCount,QOverload<int>::of(&QSpinBox::valueChanged), this ,QOverload<int>::of(&GraphicHandlerHeaderCommand_BALISE::changeValue_SL));
        connect (m_mainWin_Ptr->lineEdit_HdrBlName,&QLineEdit::editingFinished,this,&GraphicHandlerHeaderCommand_BALISE::updateNameGrpBalise_SL);
        connect (m_mainWin_Ptr->lineEdit_HdrBlDesc,&QLineEdit::editingFinished,this,&GraphicHandlerHeaderCommand_BALISE::updateDataBalise);
        connect (m_mainWin_Ptr->lineEdit_HdrBlSingleName,&QLineEdit::editingFinished,this,&GraphicHandlerHeaderCommand_BALISE::updateDataBalise);
        connect (m_mainWin_Ptr->lineEdit_HdrBlSingleName,&QLineEdit::editingFinished,this,&GraphicHandlerHeaderCommand_BALISE::updNameSingleBalise_SL);
        connect (m_mainWin_Ptr->lineEdit_HdrBlSingleDesc,&QLineEdit::editingFinished,this,&GraphicHandlerHeaderCommand_BALISE::updateDataBalise);

    } else {
        m_mainWin_Ptr->spinBox_HdrPosition->disconnect();
        m_mainWin_Ptr->spinBox_HdrBlCount->disconnect();
        m_mainWin_Ptr->spinBox_HdrBlNidC->disconnect();
        m_mainWin_Ptr->spinBox_HdrBlNidBg->disconnect();
        m_mainWin_Ptr->spinBox_HdrBlInternalDist->disconnect();
        m_mainWin_Ptr->comboBox_HdrBlDir->disconnect();
        m_mainWin_Ptr->comboBox_HdrBlQLink->disconnect();
        m_mainWin_Ptr->spinBox_HdrBlBaseLine->disconnect();
        m_mainWin_Ptr->spinBox_HdBlSingleMDup->disconnect();
        m_mainWin_Ptr->spinBox_HdrBlSingleMCount->disconnect();
        m_mainWin_Ptr->lineEdit_HdrBlName->disconnect();
        m_mainWin_Ptr->lineEdit_HdrBlDesc->disconnect();
        m_mainWin_Ptr->lineEdit_HdrBlSingleName->disconnect();
        m_mainWin_Ptr->lineEdit_HdrBlSingleDesc->disconnect();
    }
}
void GraphicHandlerHeaderCommand_BALISE::clearDataPanel()
{

    m_mainWin_Ptr->spinBox_HdrPosition->setValue(HDR_MINVALUE_POSITION);
    m_mainWin_Ptr->spinBox_HdrBlCount->setValue(HDR_MINVALUE_BALCNT);
    m_mainWin_Ptr->spinBox_HdrBlNidC->setValue(HDR_MINVALUE_NID_C);
    m_mainWin_Ptr->spinBox_HdrBlNidBg->setValue(HDR_MINVALUE_NID_BG);
    m_mainWin_Ptr->spinBox_HdrBlInternalDist->setValue(HDR_MINVALUE_INTER_DIS);
    m_mainWin_Ptr->comboBox_HdrBlDir->setCurrentText("0");
    m_mainWin_Ptr->comboBox_HdrBlQLink->setCurrentText("0");

    m_mainWin_Ptr->spinBox_HdrBlSingleMCount->setValue(HDR_SINGLE_MINVALUE_MCOUNT);
    m_mainWin_Ptr->lineEdit_HdrBlName->clear();
    m_mainWin_Ptr->lineEdit_HdrBlDesc->clear();

    m_mainWin_Ptr->lineEdit_HdrBlSingleName->clear();
    m_mainWin_Ptr->lineEdit_HdrBlSingleDesc->clear();
    m_mainWin_Ptr->spinBox_HdrBlSingleMCount->setValue(HDR_SINGLE_MINVALUE_MCOUNT);
    m_mainWin_Ptr->spinBox_HdBlSingleMDup->setValue(HDR_SINGLE_MINVALUE_MDUP);
    m_mainWin_Ptr->spinBox_HdrBlBaseLine->setValue(HDR_SINGLE_MINVALUE_BLINE);

}


void GraphicHandlerHeaderCommand_BALISE::updatePackageView_SL(qint64 keyPkg)
{}

void GraphicHandlerHeaderCommand_BALISE::updNunmberBlalise_SL(qint16 blCnt)
{
    connectDisconnect(false);
    m_currentSignleBalise=blCnt;
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    outBalsCmd.removeAddSingleBalise(m_currentGrpBalise,m_currentSignleBalise);

   updateDataBalise();
    emit setDefaultNameBlalise_SG(blCnt,m_currentGrpBalise);
     connectDisconnect(true);

}

void GraphicHandlerHeaderCommand_BALISE::removePackageView_SL(qint64 keyPkt)
{

}
void GraphicHandlerHeaderCommand_BALISE::ridisponeWidget()
{


}

qint16 GraphicHandlerHeaderCommand_BALISE::currentSignleBalise() const
{
    return m_currentSignleBalise;
}

void GraphicHandlerHeaderCommand_BALISE::setCurrentSignleBalise(qint16 newCurrentSignleBalise)
{
    m_currentSignleBalise = newCurrentSignleBalise;
}

qint16 GraphicHandlerHeaderCommand_BALISE::currentGrpBalise() const
{
    return m_currentGrpBalise;
}
void GraphicHandlerHeaderCommand_BALISE::removeInternalData()
{

}

bool GraphicHandlerHeaderCommand_BALISE::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{


    return true;
}

bool GraphicHandlerHeaderCommand_BALISE::dataValidation()
{
    bool ret=true;

    return ret;

}


void GraphicHandlerHeaderCommand_BALISE::removeAllPkg(){

}


void GraphicHandlerHeaderCommand_BALISE::showCommand_SL(QString command, qint32 rowTable )
{
    /*

    */
    return ;
}
}
