#ifndef GRAPHICHANDLERCOMMAND_T_IO_H
#define GRAPHICHANDLERCOMMAND_T_IO_H

#include <GraphicHandlerCommand.h>
#include <QObject>
namespace hndcommand{


class GraphicHandlerCommand_T_IO : public GraphicHandlerCommand
{
    Q_OBJECT
public:
    explicit GraphicHandlerCommand_T_IO(QObject *parent = nullptr);
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
         rangeOrAction_position,
         channel_position,
         all_item
     };


protected:
     virtual bool dataValidation() override;

public slots:



private:
      bool m_isActiveRange;
      bool m_isActionActive;

};

#endif // GRAPHICHANDLERCOMMAND_T_IO_H
}
