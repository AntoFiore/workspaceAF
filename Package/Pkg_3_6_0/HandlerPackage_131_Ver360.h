#ifndef HANDLERPACKAGE_131_VER360_H
#define HANDLERPACKAGE_131_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_131_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_131_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;

    package::GraphicVariablePkg *m_qScaleVar;
    package::GraphicVariablePkg *m_dRbctrVar;
    package::GraphicVariablePkg *m_nidCVar;
    package::GraphicVariablePkg *m_nidRbcVar;
    package::GraphicVariablePkg *m_nidRadioVar;
    package::GraphicVariablePkg *m_qSleepsessionVar;
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
