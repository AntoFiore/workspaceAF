#ifndef GRAPHICHANDLERCOMMAND_T_RADIO_HOLE_H
#define GRAPHICHANDLERCOMMAND_T_RADIO_HOLE_H

#include <GraphicHandlerCommand.h>
#include <QObject>
namespace hndcommand{


class GraphicHandlerCommand_T_RADIO_HOLE : public GraphicHandlerCommand
{
    Q_OBJECT
public:
    explicit GraphicHandlerCommand_T_RADIO_HOLE(QObject *parent = nullptr);
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
         modem_position,
         holetype_position ,
         command_position ,
         all_item
     };

protected:
     virtual bool dataValidation() override;



public slots:



private:



};

#endif // GRAPHICHANDLERCOMMAND_T_RADIO_HOLE_H
}
