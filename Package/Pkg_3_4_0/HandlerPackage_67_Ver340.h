#ifndef HANDLERPACKAGE_67_VER340_H
#define HANDLERPACKAGE_67_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_67_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_67_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_ScaleVar;
    package::GraphicVariablePkg *m_dTrackCond;
    package::GraphicVariablePkg *m_lTrackCond;

    package::GraphicVariablePkg *m_nIterVar;



private slots:

    void handleChangeIteration_SL();
    void handleIterateVariable_SL(QString nameVariable);
private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;



};
}

#endif // HANDLERPACKAGE_67_VER340_H
