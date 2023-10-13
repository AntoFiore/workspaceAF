#ifndef GRAPHICEDITBALISE_H
#define GRAPHICEDITBALISE_H

#include <QObject>
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QStandardItemModel>
namespace hndcommand{
class GraphicEditBalise : public QObject
{
    Q_OBJECT
public:
    explicit GraphicEditBalise(QObject *parent = nullptr);
    bool init(Ui::MainWindow *mainWin_Ptr);
    void setFormPkgWidget(QWidget *w);
     void removeFormPkgWidget();

     quint16 currentIdPkg() const;
     void setCurrentIdPkg(quint16 newCurrentIdPkg);

     qint64 keyPkt() const;
     void setKeyPkt(qint64 newKeyPkt);

     bool isUpdatePkg() const;
     void setIsUpdatePkg(bool newIsUpdatePkg);

     void handlePackageFromTable(QString listPkg);
signals:

    void addNewOrUpdatePackage_SG (QStandardItemModel* model,QString,qint32 idPkg, qint64 keyPkt);


private:
    Ui::MainWindow *m_mainWin_Ptr;
    QWidget *m_formPkgWidget;

    QGridLayout *m_editGridLayout;
    QFrame *m_EditPkgFrame;
    qint64 m_keyPkt;
    quint16 m_currentIdPkg;
    bool m_isUpdatePkg;



};
}

#endif // GRAPHICEDITBALISE_H
