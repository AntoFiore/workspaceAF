#ifndef GRAPHICHEADERCOMMAND_BALISE_H
#define GRAPHICHEADERCOMMAND_BALISE_H

#include <GraphicHandlerCommand.h>
#include <QObject>
#include <QStandardItemModel>
#include "GraphicEditBalise.h"
#include "GraphicViewPackage.h"
#include "GraphicBtnPackage_BL_3_4_0.h"
#include "GraphicBtnPackage_BL_3_6_0.h"
namespace hndcommand{


#define HDR_MAXVALUE_POSITION 1000 * 1000 //Position Header
#define HDR_MINVALUE_POSITION 0 //Position Header
#define HDR_MAXVALUE_BALCNT 7 //Balise Count Max
#define HDR_MINVALUE_BALCNT 0 //Balise Count Min

#define HDR_MAXVALUE_NID_C 1023 //NID-C Max
#define HDR_MINVALUE_NID_C 0 //NID-C Min
#define HDR_MAXVALUE_NID_BG 16382 //NID-BG Max
#define HDR_MINVALUE_NID_BG 0 //NID-BG Min
#define HDR_MAXVALUE_INTER_DIS 7 //Internal Distance Max
#define HDR_MINVALUE_INTER_DIS 0 //Internal Distance Min

#define HDR_SINGLE_MAXVALUE_BLINE 7 //SIngle Balise Bl Max
#define HDR_SINGLE_MINVALUE_BLINE 0 //SIngle Balise Bl Min

#define HDR_SINGLE_MAXVALUE_NPIG 7 //SIngle Balise NPIG Max
#define HDR_SINGLE_MINVALUE_NPIG 0 //SIngle Balise NPIG Min

#define HDR_SINGLE_MAXVALUE_MDUP 3 //SIngle Balise MDup Max
#define HDR_SINGLE_MINVALUE_MDUP 0 //SIngle Balise Mdup Min

#define HDR_SINGLE_MAXVALUE_MCOUNT 253 //SIngle Balise MCount Max
#define HDR_SINGLE_MINVALUE_MCOUNT 0 //SIngle Balise MCount Min
#define DEFAUT_NUM_BALISE 2


class GraphicHandlerHeaderCommand_BALISE : public GraphicHandlerCommand
{
    Q_OBJECT
public:
    explicit GraphicHandlerHeaderCommand_BALISE(QObject *parent = nullptr);
     bool initCommands();
     void handleBaliseSelected(qint16 numBalGrp,qint16 numSingleBal);
     void handleBaliseRemoved(qint16 numBalGrp, qint16 numSingleBalise, qint16 numPkg);
     void addPkg(qint16 idPkg, QString baseLine);



     virtual void removeInternalData();
     virtual void showCommand_SL (QString command, qint32 rowTable) override;
      bool addRemoveUpdateCommand(ActionCommand_E actionCommand) override;



      qint16 currentGrpBalise() const;

      void setCurrentSignleBalise(qint16 newCurrentSignleBalise);

      qint16 currentSignleBalise() const;

protected:
     virtual bool dataValidation() override;

signals:
      void updNameBlGrp_SG (QString,qint16); //Segnale per il TreeView (Nome Balise Group)
      void setDefaultNameBlalise_SG (qint16,qint16); //Segnale per il TreeView Singola Balise name dafault
      void updNameSingleBalise_SG(qint16,qint16,QString);

public slots:

private slots:

      void changeValue_SL (int value); //Slot che sono aggangiati ai campi testuali e e quelli numerici
      void changeValue_SL (QString value);

     void removePackageView_SL(qint64 keyPkt);
     void updatePackageView_SL(qint64 keyPkg);

     void updNunmberBlalise_SL (qint16 blCnt); //Slot per la gestione del Cambio Numero Balis
     void addNewBaliseGrp_SL(); //Slot per la gestione del pulsante nuovo Gruppo balise
     void updateNameGrpBalise_SL(); //Slot che aggiorna il nome del gruppo balise in treeView
     void updNameSingleBalise_SL(); //SLot che gestisce il nome della balise nel treeView




private:
     void connectDisconnect(bool isConnect=true);
     void clearDataPanel();
     void updateDataBalise();


     void ridisponeWidget();

     QFrame *m_containerPackageView ;
     QGridLayout *m_laytcontainerPackageView;

     QStandardItemModel *m_modelPackage;
     //GraphicEditBalise m_GraphicEditBalise;
     QMap<qint64,GraphicViewPackage*> m_graphicViewMap;
     // qint16 m_currentColumnPkg;
     //  qint16 m_currentRowPkg;

       QGridLayout *m_grid_BtnPackageBalise;
       //pkg::GraphicBtnPackage_BL_2 m_grPkgBl2;
       //pkg::GraphicBtnPackage_BL_3 m_grPkgBl3;
       qint16 m_currentGrpBalise;
       qint16 m_currentSignleBalise;



       void removeAllPkg();
};

#endif // GRAPHICHEADERCOMMAND_BALISE_H
}
