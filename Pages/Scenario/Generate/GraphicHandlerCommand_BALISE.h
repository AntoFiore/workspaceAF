#ifndef GRAPHICCOMMAND_BALISE_H
#define GRAPHICCOMMAND_BALISE_H

#include <GraphicHandlerCommand.h>
#include <QObject>
#include <QStandardItemModel>
#include "GraphicEditBalise.h"
#include "GraphicViewPackage.h"
#include "GraphicBtnPackage_BL_3_2_0.h"
#include "GraphicBtnPackage_BL_3_4_0.h"
#include "GraphicBtnPackage_BL_3_6_0.h"
#include "GraphicHandlerHeaderCommand_BALISE.h"
#include "GraphicHandlerTreeBalise.h"
#include "HandlerPaclage_3_4_0_Factory.h"
#include "HandlerPaclage_3_6_0_Factory.h"
#include "HandlerPackage.h"

namespace hndcommand{



#define MAX_COLUMN_4_PKG 2 //0 based
#define PKG_FINISHING "255"
class GraphicHandlerCommand_BALISE : public GraphicHandlerCommand
{
    Q_OBJECT
public:

    explicit GraphicHandlerCommand_BALISE(QObject *parent = nullptr);
     bool initCommands();
     virtual void removeInternalData();
     virtual void showCommand_SL (QString command, qint32 rowTable) override;
      bool addRemoveUpdateCommand(ActionCommand_E actionCommand) override;

     enum InternalItemPos{

         page_positon =0,
         tab_position,
         distance_position,
         namebalise_position,
         direction_position,
         baseline_position,
         media_positon,
         npig_position,
         total_position,
         dup_position,
         m_count_position,
         nid_c_position,
         nid_bg_position,
         qlink_position,
         all_item
     };



protected:
     virtual bool dataValidation() override;


public slots:

private slots:

private:


     qint64 getKeyBaliseFromCommand(QString command);


     QFrame *m_containerPackageView ;
     QGridLayout *m_laytcontainerPackageView;

    // GraphicEditBalise m_GraphicEditBalise;
     QMap<qint64,GraphicViewPackage*> m_graphicViewMap;

       QGridLayout *m_grid_BtnPackageBalise;
       pkg::GraphicBtnPackage_BL_3_2_0 m_grPkgBl1;
       pkg::GraphicBtnPackage_BL_3_4_0 m_grPkgBl2;
       pkg::GraphicBtnPackage_BL_3_6_0 m_grPkgBl3;
       GraphicHandlerHeaderCommand_BALISE *m_grHandHeaderBal;
       GraphicHandlerTreeBalise *m_grTreeViewBl;




       void addPkgToBalise(QString pkg, QString baseLine, qint16 idPkg);

       package::HandlerPackage *m_HandlerCurrentPackage;

       qint16 m_currentBaliseGrp;
       qint16 m_currentBalise;
       qint16 m_currentPkg;

};

#endif // GRAPHICCOMMAND_BALISE_H
}
