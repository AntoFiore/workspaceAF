#ifndef HANDLERPACKAGE_3_VER360_H
#define HANDLERPACKAGE_3_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_3_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_3_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;

    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_dValidnvVar;
    package::GraphicVariablePkg *m_nidCVar;

    package::GraphicVariablePkg *m_nIter_j_Var;
    /* varible in window */
    package::GraphicVariablePkg *m_nidC_j_Var;

    package::GraphicVariablePkg *m_vNvshuntVar;
    package::GraphicVariablePkg *m_vNvstffVar;
    package::GraphicVariablePkg *m_vNvonsightVar;
    package::GraphicVariablePkg *m_vNvlimsupervVar;
    package::GraphicVariablePkg *m_vNvunfitVar;
    package::GraphicVariablePkg *m_vNvrelVar;
    package::GraphicVariablePkg *m_vNvRollVar;

    package::GraphicVariablePkg *m_qNvsbtsmpermVar;
    package::GraphicVariablePkg *m_qNvemrrlsVar;
    package::GraphicVariablePkg *m_qNvguipermVar;
    package::GraphicVariablePkg *m_qNvsbfbpermVar;
    package::GraphicVariablePkg *m_qNvnhsmicpermVar;

    package::GraphicVariablePkg *m_vNvallowovtrpVar;
    package::GraphicVariablePkg *m_vNvsupovtrpVar;

    package::GraphicVariablePkg *m_dNvovtrpVar;
    package::GraphicVariablePkg *m_tNvovtrpVar;
    package::GraphicVariablePkg *m_dNvpotrpVar;
    package::GraphicVariablePkg *m_mNvcontactVar;
    package::GraphicVariablePkg *m_tNvcontactVar;
    package::GraphicVariablePkg *m_mNvderunVar;
    package::GraphicVariablePkg *m_dNvstffVar;

    package::GraphicVariablePkg *m_qNvdriverAdhesVar;
    package::GraphicVariablePkg *m_aNvmaxredadh1Var;
    package::GraphicVariablePkg *m_aNvmaxredadh2Var;
    package::GraphicVariablePkg *m_aNvmaxredadh3Var;

    package::GraphicVariablePkg *m_qNvloaccVar;
    package::GraphicVariablePkg *m_mNvavadhVar;
    package::GraphicVariablePkg *m_mNvebclVar;
    package::GraphicVariablePkg *m_qNvkintVar;

    package::GraphicVariablePkg *m_qNvkvintsetVar;
    package::GraphicVariablePkg *m_aNvp12Var;
    package::GraphicVariablePkg *m_aNvp23Var;

    package::GraphicVariablePkg *m_vNvkvintVar;
    package::GraphicVariablePkg *m_mNvkvint_1_Var;
    package::GraphicVariablePkg *m_mNvkvint_2_Var;

    package::GraphicVariablePkg *m_nIter_n_Var;
    /* varible in window */
    package::GraphicVariablePkg *m_vNvkvint_n_Var;
    package::GraphicVariablePkg *m_mNvkvint_n_1_Var;
    package::GraphicVariablePkg *m_mNvkvint_n_2_Var;

    package::GraphicVariablePkg *m_nIter_k_Var;
    /* varible in window */
    package::GraphicVariablePkg *m_qNvkvintset_k_Var;
    package::GraphicVariablePkg *m_aNvp12_k_Var;
    package::GraphicVariablePkg *m_aNvp23_k_Var;
    package::GraphicVariablePkg *m_vNvkvint_k_Var;
    package::GraphicVariablePkg *m_mNvkvint_k_1_Var;
    package::GraphicVariablePkg *m_mNvkvint_k_2_Var;

    package::GraphicVariablePkg *m_nInter_k_m_Var;
    /* varible in window */
    package::GraphicVariablePkg *m_vNvkvint_k_m_Var;
    package::GraphicVariablePkg *m_mNvkvint_k_m_1_Var;
    package::GraphicVariablePkg *m_mNvkvint_k_m_2_Var;

    package::GraphicVariablePkg *m_lNvkrintVar;
    package::GraphicVariablePkg *m_mNvkrintVar;

    package::GraphicVariablePkg *m_nIter_l_Var;
    /* varible in window */
    package::GraphicVariablePkg *m_lNvkrint_l_Var;
    package::GraphicVariablePkg *m_mNvkrint_l_Var;

    package::GraphicVariablePkg *m_mNvktintVar;


private slots:
    void show_qNvkint_SL();
    void show_aNVP_SL();
    void handleIterateVariable_aNVP_SL(QString nameVariable);
    void handleIterateVariable_Q_NVKVINTSET_K_SL(QString nameVariable);

    void handleChangeIteration_nIter_j_SL();
    void handleChangeIteration_nIter_n_SL();
    void handleChangeIteration_nIter_k_SL();
    void handleChangeIteration_nIter_k_m_SL(QString nomeVariabile);
    void handleChangeIteration_nIter_l_SL();


private:
    void showVariable();

    const int numOfIteration = 31;
    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;

};
}

#endif // HANDLERPACKAGE_3_VER360_H
