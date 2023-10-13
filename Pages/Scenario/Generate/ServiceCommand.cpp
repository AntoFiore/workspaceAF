#include "ServiceCommand.h"
#include <QDebug>
namespace hndcommand{

ServiceCommand::ServiceCommand(QObject *parent)
    : QObject{parent}
{

    m_mainWin_Ptr = nullptr;
}

bool ServiceCommand::init(Ui::MainWindow *mainWin_Ptr)
{

    bool ret = true;
    if ( mainWin_Ptr == nullptr){
        qDebug () << "Invalid pointer to MainWindow";
        ret= false;
    } else {
        m_mainWin_Ptr = mainWin_Ptr;

      connect(m_mainWin_Ptr->pushButton_addCommand,&QPushButton::clicked,[this]() {

           foreach (GraphicHandlerCommand *handlerCmd, m_HandleCmdVector) {

               if ( handlerCmd->isCurrentTab() ){
                   //bool isAddCommand = true;
                   handlerCmd->addRemoveUpdateCommand(add_command);
                   break;
               }
            }
        });
      connect(m_mainWin_Ptr->pushButton_removeCommand,&QPushButton::clicked,[this]() {

          foreach (GraphicHandlerCommand *handlerCmd, m_HandleCmdVector) {

              if ( handlerCmd->isCurrentTab() ){
                 // bool isAddCommand = false;
                  handlerCmd->addRemoveUpdateCommand(remove_command);
                  break;
              }
           }
      });
    }

    connect(m_mainWin_Ptr->pushButton_updateCommand,&QPushButton::clicked,[this]() {

        foreach (GraphicHandlerCommand *handlerCmd, m_HandleCmdVector) {

            if ( handlerCmd->isCurrentTab() ){
               // bool isAddCommand = false;
                handlerCmd->addRemoveUpdateCommand(update_command);
                break;
            }
         }
    });

    return ret;
}

void ServiceCommand::addGraphicHandlerCmd(GraphicHandlerCommand *cmd)
{
   m_HandleCmdVector.push_back(cmd);

}

void ServiceCommand::clear()
{
    m_HandleCmdVector.clear();

}
}
