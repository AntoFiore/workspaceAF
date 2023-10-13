#ifndef SERVICECOMMAND_H
#define SERVICECOMMAND_H

#include <QObject>
#include "ui_mainwindow.h"
#include <QVector>
#include "GraphicHandlerCommand.h"
namespace hndcommand{
class ServiceCommand : public QObject
{
    Q_OBJECT
public:
    explicit ServiceCommand(QObject *parent = nullptr);
     bool init(Ui::MainWindow *mainWin_Ptr);
     void addGraphicHandlerCmd(GraphicHandlerCommand*cmd);
     void clear();

signals:
private:

     Ui::MainWindow *m_mainWin_Ptr;

     QVector<GraphicHandlerCommand*> m_HandleCmdVector;

};
}
#endif // SERVICECOMMAND_H
