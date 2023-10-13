#ifndef GRAPHICHANDLERCOMMAND_T_ODO_H
#define GRAPHICHANDLERCOMMAND_T_ODO_H

#include <GraphicHandlerCommand.h>
#include <QObject>
namespace hndcommand{


class GraphicHandlerCommand_T_ODO : public GraphicHandlerCommand
{
    Q_OBJECT
public:
    explicit GraphicHandlerCommand_T_ODO(QObject *parent = nullptr);
     bool initCommands();
     virtual void removeInternalData();
     virtual void showCommand_SL (QString command, qint32 rowTable) override;
      bool addRemoveUpdateCommand(ActionCommand_E actionCommand) override;
     enum InternalItemPos{
         page_positon =0,
         tab_position,
         distance_position,
         family_position,
         deleay_position,
         acc_position,
         speed_position ,
         all_item
     };

protected:


public slots:



private:



};

#endif // GRAPHICHANDLERCOMMAND_T_ODO_H
}
