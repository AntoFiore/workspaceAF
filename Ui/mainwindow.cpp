#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Define.h"
#include <QToolBar>
#include "GraphicHandlerCommand_T_IO.h"
#include "GraphicHandlerCommand_T_SIM.h"
#include <QTabWidget>
#include <QDebug>
#include <QDateTime>
#include <StorageDataCommand.h>
#include "GraphicHandlerCreateScenario.h"


#include "GraphicHandlerSettings.h"

page::GraphicHandlerPage *pages[MAX_NUMBER_PAG] = { new page::GraphicHandlerCreateScenario,
                                                    new page::GraphicHandlerSettings};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui-> pushButton_addPkdBalise->setIcon(QIcon(":/insertBaliseGrp.png"));
    ui-> pushButton_addCommand->setIcon(QIcon(":/plus.png"));
    ui-> pushButton_removeCommand->setIcon(QIcon(":/less.png"));
    ui-> pushButton_updateCommand->setIcon(QIcon(":/update.png"));
    QString  styleTree = "";
}

MainWindow::~MainWindow()
{
    for (int i = 0;i<MAX_NUMBER_PAG;i++){
        if (nullptr != pages[i]){
            delete pages[i];
            pages[i]=nullptr;
        }
    }

    delete ui;

}

bool MainWindow::init()
{



    bool ret = true;

    buildToolBar();
    ui->pushButton_addCommand->setToolTip(tr (TOOL_TIP_ADD_CMD));
    ui->pushButton_removeCommand->setToolTip(tr (TOOL_TIP_REMOVE_CMD));
    ui->pushButton_ExportScenario->setToolTip(tr (TOOL_TIP_EXPORT_CMD));
    ui->pushButton_updateCommand->setToolTip(tr (TOOL_TIP_UPDATE_CMD));


    addDockWidget(Qt::BottomDockWidgetArea,ui->dockWidget_TrainLocator);
    addDockWidget(Qt::BottomDockWidgetArea,ui->dockWidget_StepSequence);
    for (int idx =0 ; idx < CreationScenario_page_all;idx++){
        ui->stackedWidget_MainContenitor->widget(idx)->setVisible(false);
    }

    m_GraphStepSeq = new  hndcommand::GraphicStepSequence(this);

    if (nullptr == m_GraphStepSeq){
        ret=false;
    } else {
            ret = m_GraphStepSeq->init();
            if (ret){
                ui->dockWidget_StepSequence->setWidget(m_GraphStepSeq);
            } else {
                qDebug () << "Error Initialization in Step Sequence ";
            }
       // }
    }
    if ( ret ) {
        for (int idxPage = 0 ; idxPage < MAX_NUMBER_PAG;idxPage++){
            if (nullptr != pages[idxPage]){
                pages[idxPage]->setGraphicStepSeq_Ptr(this->m_GraphStepSeq);
                ret = pages[idxPage]->init(ui);
                if (! ret){
                    qDebug () << "Error page initialization";
                    break;
                } else {
                  connect(pages[idxPage],&page::GraphicHandlerPage::eventPage_SG,this,&MainWindow::eventPage_SL);
                }
            }

        }
    }
    return ret;
}

void MainWindow::eventPage_SL(qint32 evtPage)
{
    switch (evtPage) {
    case envent_create_page:
        qDebug () << "Event create page";
    break;
    case event_settings_page:
        this->m_createScenario->setEnabled(true);
        this->m_Settings->setEnabled(true);
        qDebug () << "Event settings_pag ";
        break;

    default:
        break;
    }
}

void MainWindow::buildToolBar()
{
    QToolBar *mainToolBar = addToolBar("ToolBar Principale");
    m_createScenario = new QAction(tr(ACTION_TOOLBAR_CREATE), this);
    mainToolBar->addAction(m_createScenario);
    m_createScenario->setEnabled(true);

    m_convertScenario = new QAction(tr(ACTION_TOOLBAR_CONVERT), this);
    mainToolBar->addAction(m_convertScenario);
    m_convertScenario->setEnabled(true);

    connect (m_createScenario,&QAction::triggered,[this](){
        auto createScenario = ui->stackedWidget_MainContenitor->widget(CreationScenario_page);
        ui->stackedWidget_MainContenitor->setCurrentWidget(createScenario);
        createScenario->setVisible(true);

    });

    connect (m_convertScenario,&QAction::triggered,[this](){
        auto convertScenario = ui->stackedWidget_MainContenitor->widget(ConvertScenario_page);
        ui->stackedWidget_MainContenitor->setCurrentWidget(convertScenario);
        convertScenario->setVisible(true);

    });



    mainToolBar->addSeparator();
    m_Settings = new QAction(tr(ACTION_TOOLBAR_SETTINGS), this);
    m_Settings->setEnabled(true);
    mainToolBar->addAction(m_Settings);


    connect (m_Settings,&QAction::triggered,[this](){

       auto settings =  ui->stackedWidget_MainContenitor->widget(Settings_page);
        ui->stackedWidget_MainContenitor->setCurrentWidget(settings);
        settings->setVisible(true);

    });


}

