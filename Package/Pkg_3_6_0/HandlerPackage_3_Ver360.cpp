#include "HandlerPackage_3_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_3_Ver360::HandlerPackage_3_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;

    m_qScaleVar = nullptr;

    m_dValidnvVar = nullptr;
    m_nidCVar = nullptr;

    m_nIter_j_Var = nullptr;

    m_nidC_j_Var = nullptr;

    m_vNvshuntVar = nullptr;
    m_vNvstffVar = nullptr;
    m_vNvonsightVar = nullptr;
    m_vNvlimsupervVar = nullptr;
    m_vNvunfitVar = nullptr;
    m_vNvrelVar = nullptr;
    m_vNvRollVar = nullptr;

    m_qNvsbtsmpermVar = nullptr;
    m_qNvemrrlsVar = nullptr;
    m_qNvguipermVar = nullptr;
    m_qNvsbfbpermVar = nullptr;
    m_qNvnhsmicpermVar = nullptr;

    m_vNvallowovtrpVar = nullptr;
    m_vNvsupovtrpVar = nullptr;

    m_dNvovtrpVar = nullptr;
    m_tNvovtrpVar = nullptr;
    m_dNvpotrpVar = nullptr;
    m_mNvcontactVar = nullptr;
    m_tNvcontactVar = nullptr;
    m_mNvderunVar = nullptr;
    m_dNvstffVar = nullptr;

    m_qNvdriverAdhesVar = nullptr;
    m_aNvmaxredadh1Var = nullptr;
    m_aNvmaxredadh2Var = nullptr;
    m_aNvmaxredadh3Var = nullptr;

    m_qNvloaccVar = nullptr;
    m_mNvavadhVar = nullptr;
    m_mNvebclVar = nullptr;
    m_qNvkintVar = nullptr;

    m_qNvkvintsetVar = nullptr;
    m_aNvp12Var = nullptr;
    m_aNvp23Var = nullptr;

    m_vNvkvintVar = nullptr;
    m_mNvkvint_1_Var = nullptr;
    m_mNvkvint_2_Var = nullptr;

    m_nIter_n_Var = nullptr;

    m_vNvkvint_n_Var = nullptr;
    m_mNvkvint_n_1_Var = nullptr;
    m_mNvkvint_n_2_Var = nullptr;

    m_nIter_k_Var = nullptr;

    m_qNvkvintset_k_Var = nullptr;
    m_aNvp12_k_Var = nullptr;
    m_aNvp23_k_Var = nullptr;
    m_vNvkvint_k_Var = nullptr;
    m_mNvkvint_k_1_Var = nullptr;
    m_mNvkvint_k_2_Var = nullptr;

    m_nInter_k_m_Var = nullptr;

    m_vNvkvint_k_m_Var = nullptr;
    m_mNvkvint_k_m_1_Var = nullptr;
    m_mNvkvint_k_m_2_Var = nullptr;

    m_lNvkrintVar = nullptr;
    m_mNvkrintVar = nullptr;

    m_nIter_l_Var = nullptr;

    m_lNvkrint_l_Var = nullptr;
    m_mNvkrint_l_Var = nullptr;

    m_mNvktintVar = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg = 3;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_3_Ver360::creteView()
{
    QString nameItem;
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;

    bool ret = false;
    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 3 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);

        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_lenPkgVar = new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(100);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_qScaleVar = new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_dValidnvVar = new package::GraphicVariablePkg ;
        m_dValidnvVar->set_D_VALIDNV();
        m_VariableVect.push_back(m_dValidnvVar);
        connect (m_dValidnvVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_nidCVar = new package::GraphicVariablePkg ;
        m_nidCVar->set_NID_C();
        m_VariableVect.push_back(m_nidCVar);
        connect (m_nidCVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_nIter_j_Var = new package::GraphicVariablePkg ;
        m_nIter_j_Var->set_N_ITER();
        m_nIter_j_Var->setNameVariable("N_ITER_J");
        m_VariableVect.push_back(m_nIter_j_Var);
        connect (m_nIter_j_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::handleChangeIteration_nIter_j_SL );
        connect (m_nIter_j_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        for (int j = 0; j < numOfIteration; j++)
        {
            nameItem = QString ("NID_C_J_%1").arg(QString::number(j+1));
            m_nidC_j_Var = new package::GraphicVariablePkg;
            m_nidC_j_Var->set_NID_C();
            m_nidC_j_Var->setNameVariable(nameItem);
            m_nidC_j_Var->setInternalName(nameItem);
            m_nidC_j_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_nidC_j_Var);
            connect (m_nidC_j_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );
        }

        m_vNvshuntVar = new package::GraphicVariablePkg ;
        m_vNvshuntVar->set_V_NVSHUNT();
        m_VariableVect.push_back(m_vNvshuntVar);
        connect (m_vNvshuntVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_vNvstffVar = new package::GraphicVariablePkg ;
        m_vNvstffVar->set_V_NVSTFF();
        m_VariableVect.push_back(m_vNvstffVar);
        connect (m_vNvstffVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_vNvonsightVar = new package::GraphicVariablePkg ;
        m_vNvonsightVar->set_V_NVONSIGHT();
        m_VariableVect.push_back(m_vNvonsightVar);
        connect (m_vNvonsightVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_vNvlimsupervVar = new package::GraphicVariablePkg ;
        m_vNvlimsupervVar->set_V_NVLIMSUPERV();
        m_VariableVect.push_back(m_vNvlimsupervVar);
        connect (m_vNvlimsupervVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_vNvunfitVar = new package::GraphicVariablePkg ;
        m_vNvunfitVar->set_V_NVUNFIT();
        m_VariableVect.push_back(m_vNvunfitVar);
        connect (m_vNvunfitVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_vNvrelVar = new package::GraphicVariablePkg ;
        m_vNvrelVar->set_V_NVREL();
        m_VariableVect.push_back(m_vNvrelVar);
        connect (m_vNvrelVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_vNvRollVar = new package::GraphicVariablePkg ;
        m_vNvRollVar->set_D_NVROLL();
        m_VariableVect.push_back(m_vNvRollVar);
        connect (m_vNvRollVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );


        m_qNvsbtsmpermVar = new package::GraphicVariablePkg ;
        m_qNvsbtsmpermVar->set_Q_NVSBTSMPERM();
        m_VariableVect.push_back(m_qNvsbtsmpermVar);
        connect (m_qNvsbtsmpermVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_qNvemrrlsVar = new package::GraphicVariablePkg ;
        m_qNvemrrlsVar->set_Q_NVEMRRLS();
        m_VariableVect.push_back(m_qNvemrrlsVar);
        connect (m_qNvemrrlsVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_qNvguipermVar = new package::GraphicVariablePkg ;
        m_qNvguipermVar->set_Q_NVGUIPERM();
        m_VariableVect.push_back(m_qNvguipermVar);
        connect (m_qNvguipermVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_qNvsbfbpermVar = new package::GraphicVariablePkg ;
        m_qNvsbfbpermVar->set_Q_NVSBFBPERM();
        m_VariableVect.push_back(m_qNvsbfbpermVar);
        connect (m_qNvsbfbpermVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_qNvnhsmicpermVar = new package::GraphicVariablePkg ;
        m_qNvnhsmicpermVar->set_Q_NVINHSMICPERM();
        m_VariableVect.push_back(m_qNvnhsmicpermVar);
        connect (m_qNvnhsmicpermVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_vNvallowovtrpVar = new package::GraphicVariablePkg ;
        m_vNvallowovtrpVar->set_V_NVALLOWOVTRP();
        m_VariableVect.push_back(m_vNvallowovtrpVar);
        connect (m_vNvallowovtrpVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_vNvsupovtrpVar = new package::GraphicVariablePkg ;
        m_vNvsupovtrpVar->set_V_NVSUPOVTRP();
        m_VariableVect.push_back(m_vNvsupovtrpVar);
        connect (m_vNvsupovtrpVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_dNvovtrpVar = new package::GraphicVariablePkg ;
        m_dNvovtrpVar->set_D_NVOVTRP();
        m_VariableVect.push_back(m_dNvovtrpVar);
        connect (m_dNvovtrpVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_tNvovtrpVar = new package::GraphicVariablePkg ;
        m_tNvovtrpVar->set_T_NVOVTRP();
        m_VariableVect.push_back(m_tNvovtrpVar);
        connect (m_tNvovtrpVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_dNvpotrpVar = new package::GraphicVariablePkg ;
        m_dNvpotrpVar->set_D_NVPOTRP();
        m_VariableVect.push_back(m_dNvpotrpVar);
        connect (m_dNvpotrpVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_mNvcontactVar = new package::GraphicVariablePkg ;
        m_mNvcontactVar->set_M_NVCONTACT();
        m_VariableVect.push_back(m_mNvcontactVar);
        connect (m_mNvcontactVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_tNvcontactVar = new package::GraphicVariablePkg ;
        m_tNvcontactVar->set_T_NVCONTACT();
        m_VariableVect.push_back(m_tNvcontactVar);
        connect (m_tNvcontactVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_mNvderunVar = new package::GraphicVariablePkg ;
        m_mNvderunVar->set_M_NVDERUN();
        m_VariableVect.push_back(m_mNvderunVar);
        connect (m_mNvderunVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_dNvstffVar = new package::GraphicVariablePkg ;
        m_dNvstffVar->set_D_NVSTFF();
        m_VariableVect.push_back(m_dNvstffVar);
        connect (m_dNvstffVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );


        m_qNvdriverAdhesVar = new package::GraphicVariablePkg ;
        m_qNvdriverAdhesVar->set_Q_NVDRIVER_ADHES();
        m_VariableVect.push_back(m_qNvdriverAdhesVar);
        connect (m_qNvdriverAdhesVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_aNvmaxredadh1Var = new package::GraphicVariablePkg ;
        m_aNvmaxredadh1Var->set_A_NVMAXREDADH_X();
        m_aNvmaxredadh1Var->setNameVariable("A_NVMAXREDADH1");
        m_VariableVect.push_back(m_aNvmaxredadh1Var);
        connect (m_aNvmaxredadh1Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_aNvmaxredadh2Var = new package::GraphicVariablePkg ;
        m_aNvmaxredadh2Var->set_A_NVMAXREDADH_X();
        m_aNvmaxredadh2Var->setNameVariable("A_NVMAXREDADH2");
        m_VariableVect.push_back(m_aNvmaxredadh2Var);
        connect (m_aNvmaxredadh2Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_aNvmaxredadh3Var = new package::GraphicVariablePkg ;
        m_aNvmaxredadh3Var->set_A_NVMAXREDADH_X();
        m_aNvmaxredadh3Var->setNameVariable("A_NVMAXREDADH3");
        m_VariableVect.push_back(m_aNvmaxredadh3Var);
        connect (m_aNvmaxredadh3Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );


        m_qNvloaccVar = new package::GraphicVariablePkg ;
        m_qNvloaccVar->set_Q_NVLOCACC();
        m_VariableVect.push_back(m_qNvloaccVar);
        connect (m_qNvloaccVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_mNvavadhVar = new package::GraphicVariablePkg ;
        m_mNvavadhVar->set_M_NVAVADH();
        m_VariableVect.push_back(m_mNvavadhVar);
        connect (m_mNvavadhVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_mNvebclVar = new package::GraphicVariablePkg ;
        m_mNvebclVar->set_M_NVEBCL();
        m_VariableVect.push_back(m_mNvebclVar);
        connect (m_mNvebclVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        m_qNvkintVar = new package::GraphicVariablePkg ;
        m_qNvkintVar->set_Q_NVKINT();
        m_VariableVect.push_back(m_qNvkintVar);
        connect (m_qNvkintVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::show_qNvkint_SL );
        connect (m_qNvkintVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        {
            nameItem = QString ("Q_NVKVINTSET");
            m_qNvkvintsetVar = new package::GraphicVariablePkg ;
            m_qNvkvintsetVar->set_Q_NVKVINTSET();
            m_qNvkvintsetVar->setInternalName(nameItem);
            m_qNvkvintsetVar->setTobeVisible(false);
            m_VariableVect.push_back(m_qNvkvintsetVar);
            connect (m_qNvkvintsetVar,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_3_Ver360::show_aNVP_SL );
            connect (m_qNvkvintsetVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

            {
                m_aNvp12Var = new package::GraphicVariablePkg ;
                m_aNvp12Var->set_A_NVP_XX();
                m_aNvp12Var->setNameVariable("A_NVP12");
                m_aNvp12Var->setTobeVisible(false);
                m_VariableVect.push_back(m_aNvp12Var);
                connect (m_aNvp12Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                m_aNvp23Var = new package::GraphicVariablePkg ;
                m_aNvp23Var->set_A_NVP_XX();
                m_aNvp23Var->setNameVariable("A_NVP23");
                m_aNvp23Var->setTobeVisible(false);
                m_VariableVect.push_back(m_aNvp23Var);
                connect (m_aNvp23Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );
            }

            m_vNvkvintVar = new package::GraphicVariablePkg ;
            m_vNvkvintVar->set_V_NVKVINT();
            m_vNvkvintVar->setTobeVisible(false);
            m_VariableVect.push_back(m_vNvkvintVar);
            connect (m_vNvkvintVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

            nameItem = QString ("M_NVKVINT_a");
            m_mNvkvint_1_Var = new package::GraphicVariablePkg ;
            m_mNvkvint_1_Var->set_M_NVKVINT();
            m_mNvkvint_1_Var->setNameVariable(nameItem);
            m_mNvkvint_1_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_mNvkvint_1_Var);
            connect (m_mNvkvint_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

            {
                nameItem = QString ("M_NVKVINT_b");
                m_mNvkvint_2_Var = new package::GraphicVariablePkg ;
                m_mNvkvint_2_Var->set_M_NVKVINT();
                m_mNvkvint_2_Var->setNameVariable(nameItem);
                m_mNvkvint_2_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_mNvkvint_2_Var);
                connect (m_mNvkvint_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );
            }

            m_nIter_n_Var = new package::GraphicVariablePkg ;
            m_nIter_n_Var->set_N_ITER();
            m_nIter_n_Var->setNameVariable("N_ITER_N");
            m_nIter_n_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_nIter_n_Var);
            connect (m_nIter_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::handleChangeIteration_nIter_n_SL );
            connect (m_nIter_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

            for (int n = 0; n < numOfIteration; n++)
            {
                nameItem = QString ("V_NVKVINT_N_%1").arg(QString::number(n+1));
                m_vNvkvint_n_Var = new package::GraphicVariablePkg ;
                m_vNvkvint_n_Var->set_V_NVKVINT();
                m_vNvkvint_n_Var->setNameVariable(nameItem);
                m_vNvkvint_n_Var->setInternalName(nameItem);
                m_vNvkvint_n_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_vNvkvint_n_Var);
                connect (m_vNvkvint_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                nameItem = QString ("M_NVKVINT_a_N_%1").arg(QString::number(n+1));
                m_mNvkvint_n_1_Var = new package::GraphicVariablePkg ;
                m_mNvkvint_n_1_Var->set_M_NVKVINT();
                m_mNvkvint_n_1_Var->setNameVariable(nameItem);
                m_mNvkvint_n_1_Var->setInternalName(nameItem);
                m_mNvkvint_n_1_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_mNvkvint_n_1_Var);
                connect (m_mNvkvint_n_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                {
                    nameItem = QString ("M_NVKVINT_b_N_%1").arg(QString::number(n+1));
                    m_mNvkvint_n_2_Var = new package::GraphicVariablePkg ;
                    m_mNvkvint_n_2_Var->set_M_NVKVINT();
                    m_mNvkvint_n_2_Var->setNameVariable(nameItem);
                    m_mNvkvint_n_2_Var->setInternalName(nameItem);
                    m_mNvkvint_n_2_Var->setTobeVisible(false);
                    m_VariableVect.push_back(m_mNvkvint_n_2_Var);
                    connect (m_mNvkvint_n_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );
                }
            }


            m_nIter_k_Var = new package::GraphicVariablePkg ;
            m_nIter_k_Var->set_N_ITER();
            m_nIter_k_Var->setNameVariable("N_ITER_K");
            m_nIter_k_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_nIter_k_Var);
            connect (m_nIter_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::handleChangeIteration_nIter_k_SL );
            connect (m_nIter_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

            for (int k = 0; k < numOfIteration; k++)
            {
                nameItem = QString ("Q_NVKVINTSET_K_%1").arg(QString::number(k+1));
                m_qNvkvintset_k_Var = new package::GraphicVariablePkg ;
                m_qNvkvintset_k_Var->set_Q_NVKVINTSET();
                m_qNvkvintset_k_Var->setNameVariable(nameItem);
                m_qNvkvintset_k_Var->setInternalName(nameItem);
                m_qNvkvintset_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_qNvkvintset_k_Var);
                connect (m_qNvkvintset_k_Var,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_3_Ver360::handleIterateVariable_Q_NVKVINTSET_K_SL );
                connect (m_qNvkvintset_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                nameItem = QString ("A_NVP12_K_%1").arg(QString::number(k+1));
                m_aNvp12_k_Var = new package::GraphicVariablePkg ;
                m_aNvp12_k_Var->set_A_NVP_XX();
                m_aNvp12_k_Var->setNameVariable(nameItem);
                m_aNvp12_k_Var->setInternalName(nameItem);
                m_aNvp12_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_aNvp12_k_Var);
                connect (m_aNvp12_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                nameItem = QString ("A_NVP23_K_%1").arg(QString::number(k+1));
                m_aNvp23_k_Var = new package::GraphicVariablePkg ;
                m_aNvp23_k_Var->set_A_NVP_XX();
                m_aNvp23_k_Var->setNameVariable(nameItem);
                m_aNvp23_k_Var->setInternalName(nameItem);
                m_aNvp23_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_aNvp23_k_Var);
                connect (m_aNvp23_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                nameItem = QString ("V_NVKVINT_K_%1").arg(QString::number(k+1));
                m_vNvkvint_k_Var = new package::GraphicVariablePkg ;
                m_vNvkvint_k_Var->set_V_NVKVINT();
                m_vNvkvint_k_Var->setNameVariable(nameItem);
                m_vNvkvint_k_Var->setInternalName(nameItem);
                m_vNvkvint_k_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_vNvkvint_k_Var);
                connect (m_vNvkvint_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                nameItem = QString ("M_NVKVINT_a_K_%1").arg(QString::number(k+1));
                m_mNvkvint_k_1_Var = new package::GraphicVariablePkg ;
                m_mNvkvint_k_1_Var->set_M_NVKVINT();
                m_mNvkvint_k_1_Var->setNameVariable(nameItem);
                m_mNvkvint_k_1_Var->setInternalName(nameItem);
                m_mNvkvint_k_1_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_mNvkvint_k_1_Var);
                connect (m_mNvkvint_k_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                {
                    nameItem = QString ("M_NVKVINT_b_K_%1").arg(QString::number(k+1));
                    m_mNvkvint_k_2_Var = new package::GraphicVariablePkg ;
                    m_mNvkvint_k_2_Var->set_M_NVKVINT();
                    m_mNvkvint_k_2_Var->setNameVariable(nameItem);
                    m_mNvkvint_k_2_Var->setInternalName(nameItem);
                    m_mNvkvint_k_2_Var->setTobeVisible(false);
                    m_VariableVect.push_back(m_mNvkvint_k_2_Var);
                    connect (m_mNvkvint_k_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                }

                nameItem = QString ("N_ITER_K_M_%1").arg(QString::number(k+1));
                m_nInter_k_m_Var = new package::GraphicVariablePkg ;
                m_nInter_k_m_Var->set_N_ITER();
                m_nInter_k_m_Var->setNameVariable(nameItem);
                m_nInter_k_m_Var->setInternalName(nameItem);
                m_nInter_k_m_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_nInter_k_m_Var);
                connect (m_nInter_k_m_Var,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_3_Ver360::handleChangeIteration_nIter_k_m_SL );
                connect (m_nInter_k_m_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                for (int m = 0; m < numOfIteration; m++)
                {
                    nameItem = QString ("V_NVKVINT_K_M_%1_%2").arg(QString::number(k+1), QString::number(m+1));
                    m_vNvkvint_k_m_Var = new package::GraphicVariablePkg ;
                    m_vNvkvint_k_m_Var->set_V_NVKVINT();
                    m_vNvkvint_k_m_Var->setNameVariable(nameItem);
                    m_vNvkvint_k_m_Var->setInternalName(nameItem);
                    m_vNvkvint_k_m_Var->setTobeVisible(false);
                    m_VariableVect.push_back(m_vNvkvint_k_m_Var);
                    connect (m_vNvkvint_k_m_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                    nameItem = QString ("M_NVKVINT_a_K_M_%1_%2").arg(QString::number(k+1), QString::number(m+1));
                    m_mNvkvint_k_m_1_Var = new package::GraphicVariablePkg ;
                    m_mNvkvint_k_m_1_Var->set_M_NVKVINT();
                    m_mNvkvint_k_m_1_Var->setNameVariable(nameItem);
                    m_mNvkvint_k_m_1_Var->setInternalName(nameItem);
                    m_mNvkvint_k_m_1_Var->setTobeVisible(false);
                    m_VariableVect.push_back(m_mNvkvint_k_m_1_Var);
                    connect (m_mNvkvint_k_m_1_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                    {
                        nameItem = QString ("M_NVKVINT_b_K_M_%1_%2").arg(QString::number(k+1), QString::number(m+1));
                        m_mNvkvint_k_m_2_Var = new package::GraphicVariablePkg ;
                        m_mNvkvint_k_m_2_Var->set_M_NVKVINT();
                        m_mNvkvint_k_m_2_Var->setNameVariable(nameItem);
                        m_mNvkvint_k_m_2_Var->setInternalName(nameItem);
                        m_mNvkvint_k_m_2_Var->setTobeVisible(false);
                        m_VariableVect.push_back(m_mNvkvint_k_m_2_Var);
                        connect (m_mNvkvint_k_m_2_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                    }
                }

            }

            m_lNvkrintVar = new package::GraphicVariablePkg ;
            m_lNvkrintVar->set_L_NVKRINT();
            m_lNvkrintVar->setTobeVisible(false);
            m_VariableVect.push_back(m_lNvkrintVar);
            connect (m_lNvkrintVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

            m_mNvkrintVar = new package::GraphicVariablePkg ;
            m_mNvkrintVar->set_L_NVKRINT();
            m_mNvkrintVar->setTobeVisible(false);
            m_VariableVect.push_back(m_mNvkrintVar);
            connect (m_mNvkrintVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );


            m_nIter_l_Var = new package::GraphicVariablePkg ;
            m_nIter_l_Var->set_N_ITER();
            m_nIter_l_Var->setNameVariable("N_ITER_L");
            m_nIter_l_Var->setTobeVisible(false);
            m_VariableVect.push_back(m_nIter_l_Var);
            connect (m_nIter_l_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::handleChangeIteration_nIter_l_SL );
            connect (m_nIter_l_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

            for (int l = 0; l < numOfIteration; l++)
            {
                nameItem = QString ("L_NVKRINT_L_%1").arg(QString::number(l+1));
                m_lNvkrint_l_Var = new package::GraphicVariablePkg ;
                m_lNvkrint_l_Var->set_L_NVKRINT();
                m_lNvkrint_l_Var->setNameVariable(nameItem);
                m_lNvkrint_l_Var->setInternalName(nameItem);
                m_lNvkrint_l_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_lNvkrint_l_Var);
                connect (m_lNvkrint_l_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

                nameItem = QString ("M_NVKRINT_L_%1").arg(QString::number(l+1));
                m_mNvkrint_l_Var = new package::GraphicVariablePkg ;
                m_mNvkrint_l_Var->set_M_NVKRINT();
                m_mNvkrint_l_Var->setNameVariable(nameItem);
                m_mNvkrint_l_Var->setInternalName(nameItem);
                m_mNvkrint_l_Var->setTobeVisible(false);
                m_VariableVect.push_back(m_mNvkrint_l_Var);
                connect (m_mNvkrint_l_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

            }

            m_mNvktintVar = new package::GraphicVariablePkg ;
            m_mNvktintVar->set_M_NVKTINT();
            m_mNvktintVar->setTobeVisible(false);
            m_VariableVect.push_back(m_mNvktintVar);
            connect (m_mNvktintVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_3_Ver360::saveData );

        }

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();
        ret=saveData();

    }
    return ret;

}

void HandlerPackage_3_Ver360::show_qNvkint_SL()
{
    package::GraphicVariablePkg * p_variable = nullptr;
    int value = m_qNvkintVar->valueOfVariable().toInt();
    int value_Q_NVKVINTSET = m_qNvkvintsetVar->valueOfVariable().toInt();
    bool oldvisibleState;

    if (1 == value) {
        m_qNvkvintsetVar->setTobeVisible(true);
        m_vNvkvintVar->setTobeVisible(true);
        m_mNvkvint_1_Var->setTobeVisible(true);
        if (value_Q_NVKVINTSET == 1) {
            m_mNvkvint_2_Var->setTobeVisible(true);
        }

        m_nIter_n_Var->setTobeVisible(true);
        m_nIter_k_Var->setTobeVisible(true);

        m_lNvkrintVar->setTobeVisible(true);
        m_mNvkrintVar->setTobeVisible(true);

        m_nIter_l_Var->setTobeVisible(true);

        m_mNvktintVar->setTobeVisible(true);

    } else {
        m_qNvkvintsetVar->setTobeVisible(false);
        m_qNvkvintsetVar->setDefaultValue(0);

        m_vNvkvintVar->setTobeVisible(false);
        m_vNvkvintVar->setDefaultValue(0);

        m_mNvkvint_1_Var->setTobeVisible(false);
        m_mNvkvint_1_Var->setDefaultValue(0);

        m_mNvkvint_2_Var->setTobeVisible(false);
        m_mNvkvint_2_Var->setDefaultValue(0);

        m_nIter_n_Var->setTobeVisible(false);
        m_nIter_n_Var->setDefaultValue(0);

        m_nIter_k_Var->setTobeVisible(false);
        m_nIter_k_Var->setDefaultValue(0);

        m_lNvkrintVar->setTobeVisible(false);
        m_lNvkrintVar->setDefaultValue(0);

        m_mNvkrintVar->setTobeVisible(false);
        m_mNvkrintVar->setDefaultValue(0);

        m_nIter_l_Var->setTobeVisible(false);
        m_nIter_l_Var->setDefaultValue(0);

        m_mNvktintVar->setTobeVisible(false);
        m_mNvktintVar->setDefaultValue(0);
    }
    showVariable();
}

void HandlerPackage_3_Ver360::show_aNVP_SL()
{
    int value = m_qNvkvintsetVar->valueOfVariable().toInt();

    if (1 == value) {
        m_aNvp12Var->setTobeVisible(true);
        m_aNvp23Var->setTobeVisible(true);

        m_mNvkvint_2_Var->setTobeVisible(true);
    } else {
        m_aNvp12Var->setTobeVisible(false);
        m_aNvp12Var->setDefaultValue(0);

        m_aNvp23Var->setTobeVisible(false);
        m_aNvp23Var->setDefaultValue(0);

        m_mNvkvint_2_Var->setTobeVisible(false);
        m_mNvkvint_2_Var->setDefaultValue(0);
    }
    showVariable();
}

void HandlerPackage_3_Ver360::handleIterateVariable_aNVP_SL(QString nameVariable)
{
    package::GraphicVariablePkg * p_variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< p_variable->valueOfVariable();
    qint16 value = p_variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    qint16 variableIdx = -1;

    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString aNVP12_Var = QString ("A_NVP12_K_%1").arg(parseNameVar[parseNameVar.size()-1]);
        QString aNVP23_Var = QString ("A_NVP23_K_%1").arg(parseNameVar[parseNameVar.size()-1]);

        bool notUsed;
        if (1 == value){
            variableUpdVisibleState(aNVP12_Var,true,notUsed);

            variableUpdVisibleState(aNVP23_Var,true,notUsed);
        } else {
            variableIdx = variableUpdVisibleState(aNVP12_Var,false,notUsed);
            p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
            p_variable->setDefaultValue(0);

            variableIdx = variableUpdVisibleState(aNVP23_Var,false,notUsed);
            p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
            p_variable->setDefaultValue(0);
        }
    }

    showVariable();
}

void HandlerPackage_3_Ver360::handleIterateVariable_Q_NVKVINTSET_K_SL(QString nameVariable)
{
    package::GraphicVariablePkg * p_variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< p_variable->valueOfVariable();
    qint16 value = p_variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    qint16 variableIdx = -1;

    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString mNVKVINT_K_b_Var = QString ("M_NVKVINT_b_K_%1").arg(parseNameVar[parseNameVar.size()-1]);
        bool notUsed;
        if (1 == value){
            variableUpdVisibleState(mNVKVINT_K_b_Var,true,notUsed);
        } else {
            variableIdx = variableUpdVisibleState(mNVKVINT_K_b_Var,false,notUsed);
            p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
            p_variable->setDefaultValue(0);
        }

        /* get number of iteration for N_ITER_K_M */
        QString nIter_K_M_Name = QString ("N_ITER_K_M_%1").arg(parseNameVar[parseNameVar.size()-1]);
        p_variable = qobject_cast<package::GraphicVariablePkg *>(variableByName(nIter_K_M_Name));
        int numIteration = p_variable->valueOfVariable().toInt();

        /* Iteration for each variable in window K_M */
        for (int idx=0; idx < numIteration; idx++) {
            QString mNVKVINT_K_b_Var = QString ("M_NVKVINT_b_K_M_%1_%2").arg(parseNameVar[parseNameVar.size()-1], QString::number(idx + 1));
            if (1 == value){
                variableUpdVisibleState(mNVKVINT_K_b_Var,true,notUsed);
            } else {
                variableIdx = variableUpdVisibleState(mNVKVINT_K_b_Var,false,notUsed);
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }
        }
    }

    showVariable();
}

void HandlerPackage_3_Ver360::handleChangeIteration_nIter_j_SL()
{
    qint16 currentValue = m_nIter_j_Var->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("NID_C_J_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        bool notUsed;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("NID_C_J_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        bool oldvisibleState;
        for (int i=0;i< numberHideVariavble;i++){
            nameIterateVar = QString ("NID_C_J_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            numVisibile--;
        }
    }

    showVariable();
    return ;
}

void HandlerPackage_3_Ver360::handleChangeIteration_nIter_n_SL()
{
    qint16 currentValue = m_nIter_n_Var->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("V_NVKVINT_N_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;
    int value_Q_NVKVINTSET = m_qNvkvintsetVar->valueOfVariable().toInt();

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        bool notUsed;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("V_NVKVINT_N_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("M_NVKVINT_a_N_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            if (value_Q_NVKVINTSET == 1) {
                nameIterateVar = QString ("M_NVKVINT_b_N_%1").arg(QString::number(numVisibile + i + 1));
                //Marca l'item a visibile
                variableUpdVisibleState(nameIterateVar,true,notUsed);
            }
        }

    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        bool oldvisibleState;
        for (int i=0;i< numberHideVariavble;i++){
            nameIterateVar = QString ("V_NVKVINT_N_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("M_NVKVINT_N_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("M_NVKVINT_a_N_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("M_NVKVINT_b_N_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            numVisibile--;
        }
    }

    showVariable();
    return ;
}

void HandlerPackage_3_Ver360::handleChangeIteration_nIter_k_SL()
{
    qint16 currentValue = m_nIter_k_Var->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("Q_NVKVINTSET_K_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        bool notUsed;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("Q_NVKVINTSET_K_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("V_NVKVINT_K_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("M_NVKVINT_a_K_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("N_ITER_K_M_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }

    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        bool oldvisibleState;
        for (int i=0;i< numberHideVariavble;i++){
            nameIterateVar = QString ("Q_NVKVINTSET_K_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("V_NVKVINT_K_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("M_NVKVINT_K_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("N_ITER_K_M_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            numVisibile--;
        }
    }

    showVariable();
    return ;
}

void HandlerPackage_3_Ver360::handleChangeIteration_nIter_k_m_SL(QString nomeVariabile)
{
    package::GraphicVariablePkg * p_variable = qobject_cast<package::GraphicVariablePkg *>(variableByName(nomeVariabile));
    qDebug () << "nameVariable="<<nomeVariabile << "  Valore = "<< p_variable->valueOfVariable();
    QStringList parseNameVar = nomeVariabile.split("_");
    qint16 variableIdx = -1;

    QString k_value = parseNameVar.last();
    QString m_value ;

    qint16 currentValue = p_variable->valueOfVariable().toInt();
    QString countingVar = QString("V_NVKVINT_K_M_%1_").arg(k_value);
    qint16 numVisibile = countVariableIterateisVisible(countingVar);
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;

    /* Get value of Q_NVKVINTSET (k) */
    QString name_Q_NVKVINTSET_K = QString("Q_NVKVINTSET_K_%1").arg(k_value);
    p_variable = qobject_cast<package::GraphicVariablePkg *>(variableByName(name_Q_NVKVINTSET_K));
    int value_Q_NVKVINTSET_K = p_variable->valueOfVariable().toInt();

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;

        for (int i=0;i< numberShowVariavble;i++){
            m_value = QString::number(numVisibile + i + 1);
            nameIterateVar = QString ("V_NVKVINT_K_M_%1_%2").arg(k_value,m_value);
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("M_NVKVINT_a_K_M_%1_%2").arg(k_value,m_value);
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            if (value_Q_NVKVINTSET_K == 1) {
                nameIterateVar = QString ("M_NVKVINT_b_K_M_%1_%2").arg(k_value,m_value);
                //Marca l'item a visibile
                variableUpdVisibleState(nameIterateVar,true,notUsed);
            }
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            m_value = QString::number(numVisibile);
            nameIterateVar = QString ("V_NVKVINT_K_M_%1_%2").arg(k_value,numVisibile);
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("M_NVKVINT_a_K_M_%1_%2").arg(k_value,numVisibile);
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("M_NVKVINT_b_K_M_%1_%2").arg(k_value,numVisibile);
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            numVisibile--;
        }
    }
    showVariable();
}

void HandlerPackage_3_Ver360::handleChangeIteration_nIter_l_SL()
{
    qint16 currentValue = m_nIter_l_Var->valueOfVariable().toInt();
    qint16 numVisibile = countVariableIterateisVisible("L_NVKRINT_L_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        bool notUsed;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("L_NVKRINT_L_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("M_NVKRINT_L_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }

    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        bool oldvisibleState;
        for (int i=0;i< numberHideVariavble;i++){
            nameIterateVar = QString ("L_NVKRINT_L_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("M_NVKRINT_L_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            numVisibile--;
        }
    }

    showVariable();
    return ;
}

void HandlerPackage_3_Ver360::loadPkg()
{
    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise *pkg=outBalsCmd.pkgBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg);
    QString var;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (pkg != nullptr){
        m_isReload=false;
        QStringList dataList = pkg->dataPkg.split(INTERNAL_FIELD_SEPARATOR_PKG);

        if (dataList.size() >= m_VariableVect.size())
        {
            for (int idx = 0; idx < m_VariableVect.size(); idx++) {
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
                if (nullptr != p_variable){
                    var = dataList.at(idx);
                    if (var != EMPTY_VALUE){
                        p_variable->setDefaultValue(var.toInt());
                        p_variable->setTobeVisible(true);
                    } else {
                        p_variable->setTobeVisible(false);
                    }
                }
            }
        }

    }

}

void HandlerPackage_3_Ver360::showVariable()
{
    m_row=1;
    m_currCol=0;

    qint16 actualPktSize = this->countPacketBitSize();
    m_lenPkgVar->setDefaultValue(actualPktSize);

    removeSpacer();
    qint16 totVar = m_VariableVect.size();
    for (qint16 i =0; i < totVar;i++)
    {
        if (qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i))->tobeVisible()){
            m_layOutPkg->addWidget(m_VariableVect.at(i),m_row,m_currCol);
            m_VariableVect.at(i)->setVisible(true);
            if (m_currCol >m_maxColumnVariable )
            {
                m_currCol=0;
                m_row++;
            } else {
                m_currCol++;

            }
        } else {
            m_VariableVect.at(i)->setVisible(false);

        }
    }
    m_spaced = new QSpacerItem (40,80,QSizePolicy::Expanding,QSizePolicy::Expanding) ;
    m_layOutPkg->addItem(m_spaced, m_row+1,m_maxColumnVariable+1);

}

bool HandlerPackage_3_Ver360::saveData()
{

    QString data;
    package::GraphicVariablePkg * p_variable = nullptr;

    for (int idx = 0; idx < this->m_VariableVect.size(); idx++)
    {
        p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
        if (p_variable->tobeVisible()){
            data += p_variable->valueOfVariable();
        } else {
            data += EMPTY_VALUE;
        }
        data+=INTERNAL_FIELD_SEPARATOR_PKG;
    }

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;

    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;

}

void HandlerPackage_3_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}

}
