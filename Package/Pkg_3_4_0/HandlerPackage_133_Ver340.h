#ifndef HANDLERPACKAGE_133_VER340_H
#define HANDLERPACKAGE_133_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_133_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_133_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;

    package::GraphicVariablePkg *m_qScaleVar;
    package::GraphicVariablePkg *m_qRiuVar;
    package::GraphicVariablePkg *m_nidC_1_Var;
    package::GraphicVariablePkg *m_nidRiuVar;
    package::GraphicVariablePkg *m_nidRadioVar;
    package::GraphicVariablePkg *m_dInfillVar;
    package::GraphicVariablePkg *m_nidC_2_Var;
    package::GraphicVariablePkg *m_nidBgVar;

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;



};
}

#endif // HANDLERPACKAGE_12_VER340_H
