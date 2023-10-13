#ifndef GRAPHICHANDLERPAGE_H
#define GRAPHICHANDLERPAGE_H

#include <QObject>
#include "ui_mainwindow.h"
#include "GraphicStepSequence.h"
#include "Define.h"
namespace page{


class GraphicHandlerPage : public QObject
{
    Q_OBJECT
public:
    explicit GraphicHandlerPage(QObject *parent = nullptr);
     bool init(Ui::MainWindow *mainWin_Ptr);
     void setGraphicStepSeq_Ptr(hndcommand::GraphicStepSequence *newGraphicStepSeq_Ptr);
     virtual ~GraphicHandlerPage(){}


signals:

      void eventPage_SG(qint32 idPage);

protected:
     virtual bool initPage() ;
     Ui::MainWindow *m_mainWin_Ptr;

     hndcommand::GraphicStepSequence *m_graphicStepSeq_Ptr;
     Page_E m_page;

};
}
#endif // GRAPHICHANDLERPAGE_H
