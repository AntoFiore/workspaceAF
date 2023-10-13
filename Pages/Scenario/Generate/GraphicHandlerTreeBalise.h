#ifndef GRAPHICHANDLERTREEBALISE_H
#define GRAPHICHANDLERTREEBALISE_H

#include <QObject>
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QAction>
#include <QActionGroup>
namespace hndcommand{
class GraphicHandlerTreeBalise : public QObject
{
    Q_OBJECT
public:
    explicit GraphicHandlerTreeBalise(QObject *parent = nullptr);
     bool init(Ui::MainWindow *mainWin_Ptr);

     void updBaliseGrp (QString baliseGrp, qint16 rowBlGr);
     void updNamesBalise (qint16 numberBalise, qint16 rowBlGr);
     void addPkg(qint16 numBlGrp,qint16 numSingleBalise, QString namePkg);

     void updNameBalise(qint16 rowBlGr, qint16 numberBalise, QString nameBalise);
     void selectionManuallyTreeView(qint16 currentGrBal=-1, qint16 currentBal=-1, qint16 currentPkg=-1);
private slots:
     void handleTreeView_clicked_SL(const QModelIndex &index);
     void actionTriggered_SL (QAction *a);
signals:
     void itemBaliseSelected_SG(qint16 ,qint16,qint16);
     void itemBlGrpdeleted_SG (qint16 numBlGrp,qint16 numSingleBalise,qint16 numPkg);
private:
     Ui::MainWindow *m_mainWin_Ptr;

     QStandardItemModel * m_model;

     QAction *m_deleteBlGrpAct;
     QActionGroup* m_actGroup;

     void getLevelTree(const QModelIndex &index, qint8 &level);
     void getRowItem(qint8& level,int *arr,const QModelIndex &index);
     QVector<qint16> getRowItem(const QModelIndex index);
     void removePkg(qint16 numGrBalise,qint16 numSingleBalise,qint16 numPkg);
     void removeSingleBalise(qint16 numGrBalise,qint16 numSingleBalise);
};
}

#endif // GRAPHICHANDLERTREEBALISE_H
