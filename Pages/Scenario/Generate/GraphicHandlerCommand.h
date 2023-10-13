#ifndef GRAPHICHANDLERCOMMAND_H
#define GRAPHICHANDLERCOMMAND_H
#include "ui_mainwindow.h"
#include <QObject>
#include "Define.h"

namespace hndcommand{
class GraphicHandlerCommand : public QObject
{
    Q_OBJECT
public:
    explicit GraphicHandlerCommand(QObject *parent = nullptr);
    bool init(Ui::MainWindow *mainWin_Ptr);
    virtual bool initCommands() { return true;}
    virtual void removeInternalData();
    virtual bool addRemoveUpdateCommand(ActionCommand_E actionCommand);


     void setCurrentTabSelected(qint32 newCurrentTabSelected);

    void setTabId(qint32 newTabId);
    virtual bool isCurrentTab();

signals:
    void addRemoveUpdateCommand_SG (QString,ActionCommand_E,QString,qint32 );



public slots:
    virtual void showCommand_SL (QString command, qint32 rowTable);

private:
protected:
    virtual bool dataValidation() {return true;}

    Ui::MainWindow *m_mainWin_Ptr;
    Commands_E m_idCommands;
    QString m_nameTab;
    qint32 m_currentTabSelectedId;
    qint32 m_TabId;
    Page_E m_page;
    QString m_Ente;
    qint32 m_currentRowTable;




};
}

#endif // GRAPHICHANDLERCOMMAND_H
