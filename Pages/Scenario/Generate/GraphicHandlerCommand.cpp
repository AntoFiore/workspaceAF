#include "GraphicHandlerCommand.h"
#include <QDebug>
namespace hndcommand{


GraphicHandlerCommand::GraphicHandlerCommand(QObject *parent)
    : QObject{parent}
{
    m_mainWin_Ptr=nullptr;
    m_page=CreationScenario_page;
    m_nameTab = "";
    m_Ente="";
    m_currentRowTable-1;

}

bool GraphicHandlerCommand::init(Ui::MainWindow *mainWin_Ptr)
{
    bool ret = true;
    if ( mainWin_Ptr == nullptr){
        qDebug () << "Invalid pointer to MainWindow";
        ret= false;
    } else {
        m_mainWin_Ptr = mainWin_Ptr;
        m_currentTabSelectedId=0;
        m_TabId=0;
        ret=initCommands();
    }
    return ret;
}

void GraphicHandlerCommand::setCurrentTabSelected(qint32 newCurrentTabSelected)
{
    m_currentTabSelectedId = newCurrentTabSelected;
}

void GraphicHandlerCommand::setTabId(qint32 newTabId)
{
    m_TabId = newTabId;
}

bool GraphicHandlerCommand::isCurrentTab()
{
    return m_TabId==m_currentTabSelectedId;

}

void GraphicHandlerCommand::showCommand_SL(QString command, qint32 rowTable)
{
    // qDebug () << "GraphicHandlerCommand::showCommand_SL";

}

bool GraphicHandlerCommand::addRemoveUpdateCommand(ActionCommand_E actionCommand)
{

    //    if (isAddCommand ) {
    //        qDebug () << "GraphicHandlerCommand::addCommand()";
    //    } else {
    //        qDebug () << "GraphicHandlerCommand::remove()";
    //    }
    return true;
}


void GraphicHandlerCommand::removeInternalData()
{

}
}
