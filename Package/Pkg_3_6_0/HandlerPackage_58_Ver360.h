#ifndef HANDLERPACKAGE_58_VER360_H
#define HANDLERPACKAGE_58_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_58_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_58_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;

    package::GraphicVariablePkg *m_qScaleVar;
    package::GraphicVariablePkg *m_tCyclocVar;
    package::GraphicVariablePkg *m_dCyclocVar;
    package::GraphicVariablePkg *m_mLocVar;

    package::GraphicVariablePkg *m_nIterVar;
    /* iteration variables */
    package::GraphicVariablePkg *m_dLoc_k_Var;
    package::GraphicVariablePkg *m_qLgtloc_k_Var;

private slots:
    void handleChangeIteration_SL();

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;

};
}

#endif // HANDLERPACKAGE_57_VER360_H
