#ifndef HANDLERPACKAGE_27_VER340_H
#define HANDLERPACKAGE_27_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_27_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_27_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_dStaticVar;
    package::GraphicVariablePkg *m_vStaticVar;
    package::GraphicVariablePkg *m_qFrontVar;

    package::GraphicVariablePkg *m_nIter_n_Var;
    package::GraphicVariablePkg *m_nIter_k_Var;

    /* elementi usati nella iterazione */

    package::GraphicVariablePkg *m_qDiff_n_Var;
    package::GraphicVariablePkg *m_nc_cDdiff_n_Var;
    package::GraphicVariablePkg *m_nc_Diff_n_Var;
    package::GraphicVariablePkg *m_vDiff_n_Var;

    // elementi usati nella seconda iterazione

    package::GraphicVariablePkg *m_dStatic_k_Var;
    package::GraphicVariablePkg *m_vStatic_k_Var;
    package::GraphicVariablePkg *m_qFront_k_Var;
    package::GraphicVariablePkg *m_nIter_m_Var;

    //elementi usati per la doppia iterazione

    package::GraphicVariablePkg *m_qDiff_km_Var;
    package::GraphicVariablePkg *m_ncCddiff_km_Var;
    package::GraphicVariablePkg *m_ncDiff_km_Var;
    package::GraphicVariablePkg *m_vDiff_km_Var;


private slots:
    void handleChangeIteration_n_SL();
    void handleChangeIteration_k_SL();
    void handleIterateVariable_SL(QString nameVariable);
    void handleChangeIteration_k_m_SL(QString nameVariable);
    void handleIterateVariable_k_m_SL(QString nameVariable);

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;



};
}

#endif // HANDLERPACKAGE_27_VER340_H
