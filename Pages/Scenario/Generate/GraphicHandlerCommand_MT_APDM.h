#ifndef GRAPHICHANDLERCOMMAND_MT_APDM_H
#define GRAPHICHANDLERCOMMAND_MT_APDM_H

#include <GraphicHandlerCommand.h>
#include <QObject>
namespace hndcommand{


class GraphicHandlerCommand_MT_APDM : public GraphicHandlerCommand
{
    Q_OBJECT
public:
    explicit GraphicHandlerCommand_MT_APDM(QObject *parent = nullptr);
     bool initCommands();
     virtual void removeInternalData();
     virtual void showCommand_SL (QString command, qint32 rowTable) override;
      bool addRemoveUpdateCommand(ActionCommand_E actionCommand) override;

     enum InternalItemPos{

         page_positon =0,
         tab_position,
         distance_position,
         family_position,
         action_positon,
         deleay_position,
         delaypressure_position,
         all_item
     };

protected:


public slots:



private:



};

#endif // GRAPHICHANDLERCOMMAND_MT_APDM_H
}
