#include "HandlerPackage_27_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_27_Ver360::HandlerPackage_27_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;
    m_qScaleVar = nullptr;

    m_dStaticVar = nullptr;
    m_vStaticVar = nullptr;
    m_qFrontVar = nullptr;
    m_nIter_n_Var = nullptr;

    //variabili prima iterazione
    m_qDiff_n_Var = nullptr;
    m_nc_cDdiff_n_Var = nullptr;
    m_nc_Diff_n_Var = nullptr;
    m_vDiff_n_Var = nullptr;
    m_nIter_k_Var = nullptr;
    //variabili seconda iterazione
    m_dStatic_k_Var = nullptr;
    m_vStatic_k_Var = nullptr;
    m_qFront_k_Var = nullptr;
    m_nIter_m_Var = nullptr;
    //variabili doppia iterazione
    m_qDiff_km_Var = nullptr;
    m_ncCddiff_km_Var = nullptr;
    m_ncDiff_km_Var = nullptr;
    m_vDiff_km_Var = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg = 27;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_27_Ver360::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;
    bool ret = false;
    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 27 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(58, 17790);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

        m_qScaleVar = new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

        m_dStaticVar =  new package::GraphicVariablePkg;
        m_dStaticVar->set_D_STATIC();
        m_VariableVect.push_back(m_dStaticVar);
        connect (m_dStaticVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

        m_dStaticVar =  new package::GraphicVariablePkg;
        m_dStaticVar->set_D_STATIC();
        m_VariableVect.push_back(m_dStaticVar);
        connect (m_dStaticVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

        m_vStaticVar =  new package::GraphicVariablePkg;
        m_vStaticVar->set_V_STATIC();
        m_VariableVect.push_back(m_vStaticVar);
        connect (m_vStaticVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

        m_qFrontVar =  new package::GraphicVariablePkg;
        m_qFrontVar->set_Q_FRONT();
        m_VariableVect.push_back(m_qFrontVar);
        connect (m_qFrontVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

        m_nIter_n_Var =  new package::GraphicVariablePkg ;
        m_nIter_n_Var->set_N_ITER();
        m_nIter_n_Var->setNameVariable("N_ITER_n");
        m_VariableVect.push_back(m_nIter_n_Var);
        connect (m_nIter_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::handleChangeIteration_n_SL );
        connect (m_nIter_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

        qint16 maxValueVariableIter = 31;
        QString nameItem;

        for (int i = 0;i < maxValueVariableIter ;i++)
        {
            nameItem = QString ("Q_DIFF_N_%1").arg(QString::number(i+1));
            m_qDiff_n_Var=  new package::GraphicVariablePkg ;
            m_qDiff_n_Var ->set_Q_DIFF();
            m_qDiff_n_Var->setNameVariable(nameItem);
            m_qDiff_n_Var->setInternalName(nameItem);
            m_qDiff_n_Var->setTobeVisible(false);
            m_qDiff_n_Var->setVisible(false);
            m_VariableVect.push_back(m_qDiff_n_Var);
            connect (m_qDiff_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );
            connect (m_qDiff_n_Var,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_27_Ver360::handleIterateVariable_SL);

            {
                nameItem = QString ("NC_CDDIFF_N_%1").arg(QString::number(i+1));
                m_nc_cDdiff_n_Var =  new package::GraphicVariablePkg;
                m_nc_cDdiff_n_Var->set_NC_CDDIFF();
                m_nc_cDdiff_n_Var->setNameVariable(nameItem);
                m_nc_cDdiff_n_Var->setInternalName(nameItem);
                m_nc_cDdiff_n_Var->setTobeVisible(false);
                m_nc_cDdiff_n_Var->setVisible(false);
                m_VariableVect.push_back(m_nc_cDdiff_n_Var);
                connect (m_nc_cDdiff_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

                nameItem = QString ("NC_DIFF_N_%1").arg(QString::number(i+1));
                m_nc_Diff_n_Var =  new package::GraphicVariablePkg;
                m_nc_Diff_n_Var->set_NC_DIFF();
                m_nc_Diff_n_Var->setNameVariable(nameItem);
                m_nc_Diff_n_Var->setInternalName(nameItem);
                m_nc_Diff_n_Var->setTobeVisible(false);
                m_nc_Diff_n_Var->setVisible(false);
                m_VariableVect.push_back(m_nc_Diff_n_Var);
                connect (m_nc_Diff_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );
            }

            nameItem = QString ("V_DIFF_N_%1").arg(QString::number(i+1));
            m_vDiff_n_Var =  new package::GraphicVariablePkg;
            m_vDiff_n_Var->set_V_DIFF();
            m_vDiff_n_Var->setNameVariable(nameItem);
            m_vDiff_n_Var->setInternalName(nameItem);
            m_vDiff_n_Var->setTobeVisible(false);
            m_vDiff_n_Var->setVisible(false);
            m_VariableVect.push_back(m_vDiff_n_Var);
            connect (m_vDiff_n_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );


        }

        m_nIter_k_Var =  new package::GraphicVariablePkg ;
        m_nIter_k_Var->set_N_ITER();
        m_nIter_k_Var->setNameVariable("N_ITER_K");
        m_VariableVect.push_back(m_nIter_k_Var);
        connect (m_nIter_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::handleChangeIteration_k_SL );
        connect (m_nIter_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

        for (int i = 0;i < maxValueVariableIter ;i++)
        {
            nameItem = QString ("D_STATIC_K_%1").arg(QString::number(i+1));
            m_dStatic_k_Var =  new package::GraphicVariablePkg;
            m_dStatic_k_Var->set_D_STATIC();
            m_dStatic_k_Var->setNameVariable(nameItem);
            m_dStatic_k_Var->setInternalName(nameItem);
            m_dStatic_k_Var->setTobeVisible(false);
            m_dStatic_k_Var->setVisible(false);
            m_VariableVect.push_back(m_dStatic_k_Var);
            connect (m_dStatic_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

            nameItem = QString ("V_STATIC_K_%1").arg(QString::number(i+1));
            m_vStatic_k_Var =  new package::GraphicVariablePkg;
            m_vStatic_k_Var->set_V_STATIC();
            m_vStatic_k_Var->setNameVariable(nameItem);
            m_vStatic_k_Var->setInternalName(nameItem);
            m_vStatic_k_Var->setTobeVisible(false);
            m_vStatic_k_Var->setVisible(false);
            m_VariableVect.push_back(m_vStatic_k_Var);
            connect (m_vStatic_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

            nameItem = QString ("Q_FRONT_K_%1").arg(QString::number(i+1));
            m_qFront_k_Var =  new package::GraphicVariablePkg;
            m_qFront_k_Var->set_Q_FRONT();
            m_qFront_k_Var->setNameVariable(nameItem);
            m_qFront_k_Var->setInternalName(nameItem);
            m_qFront_k_Var->setTobeVisible(false);
            m_qFront_k_Var->setVisible(false);
            m_VariableVect.push_back(m_qFront_k_Var);
            connect (m_qFront_k_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );


            nameItem = QString ("N_ITER_M_%1").arg(QString::number(i+1));
            m_nIter_m_Var =  new package::GraphicVariablePkg;
            m_nIter_m_Var->set_N_ITER();
            m_nIter_m_Var->setNameVariable(nameItem);
            m_nIter_m_Var->setInternalName(nameItem);
            m_nIter_m_Var->setTobeVisible(false);
            m_nIter_m_Var->setVisible(false);
            m_VariableVect.push_back(m_nIter_m_Var);
            connect (m_nIter_m_Var,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_27_Ver360::handleChangeIteration_k_m_SL );
            connect (m_nIter_m_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );


            for (int j = 0;j < maxValueVariableIter ;j++)
            {
                nameItem = QString ("Q_DIFF_%1_%2").arg(QString::number(i+1),QString::number(j+1));
                m_qDiff_km_Var =  new package::GraphicVariablePkg;
                m_qDiff_km_Var->set_Q_DIFF();
                m_qDiff_km_Var->setNameVariable(nameItem);
                m_qDiff_km_Var->setInternalName(nameItem);
                m_qDiff_km_Var->setTobeVisible(false);
                m_qDiff_km_Var->setVisible(false);
                m_VariableVect.push_back(m_qDiff_km_Var);
                connect (m_qDiff_km_Var,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_27_Ver360::handleIterateVariable_k_m_SL);
                connect (m_qDiff_km_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

                {
                    nameItem = QString ("NC_CDDIFF_%1_%2").arg(QString::number(i+1),QString::number(j+1));
                    m_ncCddiff_km_Var =  new package::GraphicVariablePkg;
                    m_ncCddiff_km_Var->set_NC_CDDIFF();
                    m_ncCddiff_km_Var->setNameVariable(nameItem);
                    m_ncCddiff_km_Var->setInternalName(nameItem);
                    m_ncCddiff_km_Var->setTobeVisible(false);
                    m_ncCddiff_km_Var->setVisible(false);
                    m_VariableVect.push_back(m_ncCddiff_km_Var);
                    connect (m_ncCddiff_km_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );

                    nameItem = QString ("NC_DIFF_%1_%2").arg(QString::number(i+1),QString::number(j+1));
                    m_ncDiff_km_Var =  new package::GraphicVariablePkg;
                    m_ncDiff_km_Var->set_NC_DIFF();
                    m_ncDiff_km_Var->setNameVariable(nameItem);
                    m_ncDiff_km_Var->setInternalName(nameItem);
                    m_ncDiff_km_Var->setTobeVisible(false);
                    m_ncDiff_km_Var->setVisible(false);
                    m_VariableVect.push_back(m_ncDiff_km_Var);
                    connect (m_ncDiff_km_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );
                }

                nameItem = QString ("V_DIFF_%1_%2").arg(QString::number(i+1),QString::number(j+1));
                m_vDiff_km_Var =  new package::GraphicVariablePkg;
                m_vDiff_km_Var->set_V_DIFF();
                m_vDiff_km_Var->setNameVariable(nameItem);
                m_vDiff_km_Var->setInternalName(nameItem);
                m_vDiff_km_Var->setTobeVisible(false);
                m_vDiff_km_Var->setVisible(false);
                m_VariableVect.push_back(m_vDiff_km_Var);
                connect (m_vDiff_km_Var,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_27_Ver360::saveData );


            }

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
void HandlerPackage_27_Ver360::loadPkg()
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

void HandlerPackage_27_Ver360::handleChangeIteration_n_SL()
{
    qint16 currentValue = m_nIter_n_Var->valueOfVariable().toInt();

    qint16 numVisibile = countVariableIterateisVisible("Q_DIFF_N_");

    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;


    //Prima Iterazione
    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("Q_DIFF_N_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("NC_CDDIFF_N_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("NC_DIFF_N_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,false,notUsed);

            nameIterateVar = QString ("V_DIFF_N_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            nameIterateVar = QString ("Q_DIFF_N_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("NC_CDDIFF_N_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("NC_DIFF_N_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("V_DIFF_N_%1").arg(QString::number(numVisibile));
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

void HandlerPackage_27_Ver360::handleChangeIteration_k_SL()
{
    qint16 currentValue = m_nIter_k_Var->valueOfVariable().toInt();

    qint16 numVisibile = countVariableIterateisVisible("D_STATIC_K_");

    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;


    //Prima Iterazione
    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("D_STATIC_K_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("V_STATIC_K_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("Q_FRONT_K_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("N_ITER_M_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            nameIterateVar = QString ("D_STATIC_K_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("V_STATIC_K_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("Q_FRONT_K_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("N_ITER_M_%1").arg(QString::number(numVisibile));
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

void HandlerPackage_27_Ver360::handleChangeIteration_k_m_SL(QString nameVariable)
{
    package::GraphicVariablePkg * p_variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< p_variable->valueOfVariable();
    QStringList parseNameVar = nameVariable.split("_");
    qint16 variableIdx = -1;

    QString k_value = parseNameVar.last();
    QString m_value ;

    qint16 currentValue = p_variable->valueOfVariable().toInt();
    QString countingVar = QString("Q_DIFF_%1_").arg(k_value);
    qint16 numVisibile = countVariableIterateisVisible(countingVar);
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;

        for (int i=0;i< numberShowVariavble;i++){
            m_value = QString::number(numVisibile + i + 1);
            nameIterateVar = QString ("Q_DIFF_%1_%2").arg(k_value,m_value);
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("NC_CDDIFF_%1_%2").arg(k_value,m_value);
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);

            nameIterateVar = QString ("NC_DIFF_%1_%2").arg(k_value,m_value);
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,false,notUsed);

            nameIterateVar = QString ("V_DIFF_%1_%2").arg(k_value,m_value);
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            m_value = QString::number(numVisibile);
            nameIterateVar = QString ("Q_DIFF_%1_%2").arg(k_value,m_value);
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("NC_CDDIFF_%1_%2").arg(k_value,m_value);
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("NC_DIFF_%1_%2").arg(k_value,m_value);
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("V_DIFF_%1_%2").arg(k_value,m_value);
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }
            numVisibile--;
        }
    }

    m_lenPkgVar->setDefaultValue(updLen);

    showVariable();
    return ;
}

void HandlerPackage_27_Ver360::handleIterateVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * p_variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< p_variable->valueOfVariable();
    qint16 value = p_variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    qint16 variableIdx = -1;

    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString tSectionTimerVar = QString ("NC_CDDIFF_N_%1").arg(parseNameVar[parseNameVar.size()-1]);
        QString tSectionTimerVar2 = QString ("NC_DIFF_N_%1").arg(parseNameVar[parseNameVar.size()-1]);

        bool notUsed;
        if (0 == value){
            variableUpdVisibleState(tSectionTimerVar,true,notUsed);
            variableUpdVisibleState(tSectionTimerVar2,false,notUsed);
        } else if(1==value || 2==value){
            variableUpdVisibleState(tSectionTimerVar,false,notUsed);
            variableUpdVisibleState(tSectionTimerVar2,true,notUsed);
        }else{
            variableIdx = variableUpdVisibleState(tSectionTimerVar,false,notUsed);
            variableUpdVisibleState(tSectionTimerVar2,false,notUsed);
            p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
            p_variable->setDefaultValue(0);
        }
    }

    showVariable();
}

void HandlerPackage_27_Ver360::handleIterateVariable_k_m_SL(QString nameVariable)
{
    package::GraphicVariablePkg * p_variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< p_variable->valueOfVariable();
    qint16 value = p_variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    qint16 variableIdx = -1;
    QString m_value = parseNameVar.last();

    QString k_value = parseNameVar[2];
    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString tSectionTimerVar = QString ("NC_CDDIFF_%1_%2").arg(k_value,m_value);
        QString tSectionTimerVar2 = QString ("NC_DIFF_%1_%2").arg(k_value,m_value);

        bool notUsed;
        if (0 == value){
            variableUpdVisibleState(tSectionTimerVar,true,notUsed);
            variableUpdVisibleState(tSectionTimerVar2,false,notUsed);
        } else if(1==value || 2==value){
            variableUpdVisibleState(tSectionTimerVar,false,notUsed);
            variableUpdVisibleState(tSectionTimerVar2,true,notUsed);
        }else{
            variableIdx = variableUpdVisibleState(tSectionTimerVar,false,notUsed);
            variableUpdVisibleState(tSectionTimerVar2,false,notUsed);
            p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
            p_variable->setDefaultValue(0);
        }
    }

    showVariable();
}

void HandlerPackage_27_Ver360::showVariable()
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


bool HandlerPackage_27_Ver360::saveData()
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

void HandlerPackage_27_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}



}
