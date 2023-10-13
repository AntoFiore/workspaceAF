#ifndef HANDLERPACKAGE_H
#define HANDLERPACKAGE_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include "GraphicTitlePkg.h"
#include <QGridLayout>
#include "Define.h"

#define MAX_COLUMN_VARIABLE 3
#define MAX_ITERATION 31
namespace  package{
class HandlerPackage : public QObject
{
    Q_OBJECT
public:
    explicit HandlerPackage(QObject *parent = nullptr);
    virtual bool creteView()=0;
    virtual bool saveData();
    virtual void deleteView();
    void setWorkSpaceLayout(QGridLayout *lay);
    void set_GrBalise_Balise_Pkg(qint16 currentBaliseGrp, qint16 currentBalise, qint16 currentPkg);

    QVector<QWidget *> &VariableVect();

    GraphicTitlePkg *titlePkg() const;

    bool isReload() const;
    void setIsReload(bool newIsReload);

    void setprova (QFrame *p);

    qint16 variableUpdVisibleState(QString name, bool newvisibleState,bool &oldvisiblestate);

    qint16 countPacketBitSize();

signals:
  //  void addVaribleToWorkSpace_SG(QWidget *);
protected:
    virtual void loadPkg(){}
    void showVariable();

    QGridLayout *m_layOutPkg;
     QSpacerItem *m_spaced;
    QVector <QWidget*> m_VariableVect;

    GraphicTitlePkg *m_titlePkg;
    qint16 m_currentBaliseGrp;
    qint16 m_currentBalise;
    qint16 m_currentPkg;
    QString m_baseLine;
    qint16 m_idPkg;
    bool m_isReload;
    qint16 m_maxColumnVariable;

    qint16 countVariableIterate(QString name) ;




    void removeSpacer();
    qint16 countVariableIterateisVisible(QString name);

    QWidget * variableByName(QString& name);


};
}

#endif // HANDLERPACKAGE_H
