#ifndef HANDLERPACKAGE_13_VER340_H
#define HANDLERPACKAGE_13_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_13_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_13_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_qNewcountry_1_Var;
    package::GraphicVariablePkg *m_nidC_1_Var;
    package::GraphicVariablePkg *m_nidBG_1_Var;

    package::GraphicVariablePkg *m_qNewcountry_2_Var;
    package::GraphicVariablePkg *m_nidC_2_Var;
    package::GraphicVariablePkg *m_nidBG_2_Var;
    package::GraphicVariablePkg *m_dSRVar;

    package::GraphicVariablePkg *m_nIterVar;
    /* elementi usati nella iterazione */
    package::GraphicVariablePkg *m_qNewcountry_k_Var;
    package::GraphicVariablePkg *m_nidC_k_Var;
    package::GraphicVariablePkg *m_nidBG_k_Var;
    package::GraphicVariablePkg *m_dSRV_k_ar;

private slots:
    void show_NIDc_1_SL();
    void show_NIDc_2_SL();

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

#endif // HANDLERPACKAGE_12_VER340_H
