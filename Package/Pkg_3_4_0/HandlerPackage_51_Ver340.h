#ifndef HANDLERPACKAGE_51_VER340_H
#define HANDLERPACKAGE_51_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_51_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_51_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_qTrackinitVar;
    package::GraphicVariablePkg *m_dTrackinitVar;
    package::GraphicVariablePkg *m_dAxleloadVar;
    package::GraphicVariablePkg *m_lAxleloadVar;
    package::GraphicVariablePkg *m_qFrontVar;

    package::GraphicVariablePkg *m_nIter_n_Var;
    /* elementi usati nella iterazione */
    package::GraphicVariablePkg *m_mAxleloadcat_n_Var;
    package::GraphicVariablePkg *m_vAxleload_n_Var;

    package::GraphicVariablePkg *m_nIter_k_Var;
    /* elementi usati nella iterazione */
    package::GraphicVariablePkg *m_dAxleload_k_Var;
    package::GraphicVariablePkg *m_lAxleload_k_Var;
    package::GraphicVariablePkg *m_qFront_k_Var;

    package::GraphicVariablePkg *m_nIter_k_m_Var;
    /* elementi usati nella iterazione */
    package::GraphicVariablePkg *m_mAxleloadCat_k_m_Var;
    package::GraphicVariablePkg *m_vAxleload_k_m_Var;

private slots:
    void show_qTrackinit_SL();

    void handleChangeIteration_n_SL();
    void handleChangeIteration_k_SL();
    void handleChangeIteration_k_m_SL(QString nameVariable);

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

#endif // HANDLERPACKAGE_51_VER340_H
