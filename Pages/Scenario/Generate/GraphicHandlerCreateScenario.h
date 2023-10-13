#ifndef GRAPHICHANDLERCREATESCENARIO_H
#define GRAPHICHANDLERCREATESCENARIO_H

#include <GraphicHandlerPage.h>
#include <QObject>
//#include "ui_mainwindow.h"
#include "GraphicHandlerCommand.h"
#include <QVector>
#include "ServiceCommand.h"
namespace page{
class GraphicHandlerCreateScenario : public GraphicHandlerPage
{
    Q_OBJECT
public:
    explicit GraphicHandlerCreateScenario(QObject *parent = nullptr);

     ~GraphicHandlerCreateScenario();

protected:

    virtual bool initPage() override;

private:
   QVector < hndcommand::GraphicHandlerCommand *> m_cmdTab;

   hndcommand::ServiceCommand m_servCmd;





};
}
#endif // GRAPHICHANDLERCREATESCENARIO_H
