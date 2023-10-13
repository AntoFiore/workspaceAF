#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GraphicStepSequence.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool init();
private slots:
    void eventPage_SL (qint32 evtPage);

private:
    Ui::MainWindow *ui;

    void buildToolBar();

     QMenuBar* m_barRight;
     QMenu *m_HelpMenu;
     QAction * m_about;

     QMenuBar* m_barLeft;
     QMenu *m_File;
     QAction * m_startSession;
     QAction * m_stopSession;

     //ToolBar Action

     QAction *m_createScenario;
     QAction *m_convertScenario;
     QAction *m_Settings;
   //  QAction *m_CloseScenario;

     hndcommand::GraphicStepSequence *m_GraphStepSeq;



};
#endif // MAINWINDOW_H
