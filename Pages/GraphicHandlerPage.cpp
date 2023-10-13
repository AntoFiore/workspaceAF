#include "GraphicHandlerPage.h"
#include <QDebug>

namespace page{
GraphicHandlerPage::GraphicHandlerPage(QObject *parent)
    : QObject{parent}
{

    m_mainWin_Ptr=nullptr;
    m_graphicStepSeq_Ptr=nullptr;
    m_page= CreationScenario_page_all;

}

bool GraphicHandlerPage::init(Ui::MainWindow *mainWin_Ptr)
{

    bool ret = true;
    m_mainWin_Ptr=mainWin_Ptr;

    if ( mainWin_Ptr == nullptr){
        qDebug () << "Invalid pointer to MainWindow";
        ret= false;
    } else {
         this->initPage();
    }
    return ret;


}

bool GraphicHandlerPage::initPage()
{

    bool ret = true;

  return ret;

}

void GraphicHandlerPage::setGraphicStepSeq_Ptr(hndcommand::GraphicStepSequence *newGraphicStepSeq_Ptr)
{
    m_graphicStepSeq_Ptr = newGraphicStepSeq_Ptr;
}
}
