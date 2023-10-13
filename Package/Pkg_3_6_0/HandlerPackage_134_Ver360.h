#ifndef HANDLERPACKAGE_134_VER360_H
#define HANDLERPACKAGE_134_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_134_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_134_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_nidLoopVar;
    package::GraphicVariablePkg *m_dLoopVar;
    package::GraphicVariablePkg *m_lLoopVar;
    package::GraphicVariablePkg *m_qLoopdirVar;

    package::GraphicVariablePkg *m_qSscodeVar;

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;



};
}

#endif // HANDLERPACKAGE_12_VER360_H
