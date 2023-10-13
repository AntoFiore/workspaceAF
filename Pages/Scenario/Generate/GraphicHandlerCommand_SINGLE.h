#ifndef GRAPHICCOMMAND_SINGLE_H
#define GRAPHICCOMMAND_SINGLE_H

#include <GraphicHandlerCommand.h>
#include <QObject>
namespace hndcommand{


class GraphicHandlerCommand_SINGLE : public GraphicHandlerCommand
{
    Q_OBJECT
public:
    explicit GraphicHandlerCommand_SINGLE(QObject *parent = nullptr);
     bool initCommands();
     virtual void removeInternalData();
     virtual void showCommand_SL (QString command, qint32 rowTable) override;
      bool addRemoveUpdateCommand(ActionCommand_E actionCommand) override;

     enum InternalItemPos{

         page_positon =0,
         tab_position,
         distance_position,
         ente_position,
         deleay_positon,
         valuecommand_position,
         command_position,
         all_item
     };

protected:
     virtual bool dataValidation() override;


public slots:

private slots:
     void currentCommandChangedCmd_SL(QString cmd);
     void currentValueChangedCmd_SL(QString valueCmd);


private:



};

#endif // GRAPHICCOMMAND_SINGLE_H
}
