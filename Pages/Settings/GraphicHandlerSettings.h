#ifndef GRAPHICHANDLERSETTINGS_H
#define GRAPHICHANDLERSETTINGS_H

#include <GraphicHandlerPage.h>
#include <QObject>

#include "GraphicStepSequence.h"
#include "GraphicHandlerCommand.h"
#include <QVector>
#include "ServiceCommand.h"
namespace page{
class GraphicHandlerSettings : public GraphicHandlerPage
{
    Q_OBJECT
public:
    explicit GraphicHandlerSettings(QObject *parent = nullptr);

     ~GraphicHandlerSettings();

protected:

    virtual bool initPage() override;

private:
    void updateDataConfiguration();


    QString defaultPathCommon();
};
}
#endif // GraphicHandlerSettings
