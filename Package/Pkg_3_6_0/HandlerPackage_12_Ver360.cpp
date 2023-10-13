#include "HandlerPackage_12_Ver360.h"
#include <QDebug>
#include "GraphicVariablePkg.h"
#include "MngStorageOutCommand.h"
namespace package {

HandlerPackage_12_Ver360::HandlerPackage_12_Ver360(QObject *parent)
    : HandlerPackage{parent}
{
    m_nidPkgVar = nullptr;
    m_qDirVar = nullptr;
    m_lenPkgVar = nullptr;
    m_qScaleVar = nullptr;

    m_vMainVar = nullptr;
    m_vEmaVar = nullptr;
    m_tEmaVar = nullptr;

    m_nIterVar = nullptr;

    m_lEndSectionVar = nullptr;
    m_qSectionTimerVar = nullptr;
    m_tSectionTimerVar = nullptr;
    m_dSectionTimerStopLocVar = nullptr;

    m_qEndTimerVar = nullptr;
    m_tEndTimerVar = nullptr;
    m_dEndTimerStartLocVar = nullptr;

    m_qDangerPointVar = nullptr;
    m_dDpVar = nullptr;
    m_vReleaseDpVar = nullptr;

    m_qOverlapVar = nullptr;
    m_dStartOLVar = nullptr;
    m_tOLVar = nullptr;
    m_dOLVar = nullptr;
    m_vReleaseOLVar = nullptr;

    m_baseLine = QString ("%1 %2").arg(BASE_LINE_NAME,BASELINE_3_6_0);
    m_idPkg = 12;
    m_maxColumnVariable=6;
    m_isReload=false;
}

bool HandlerPackage_12_Ver360::creteView()
{
    m_currentIteration=0;
    m_currCol=0;
    m_row =0;

    if (nullptr != m_layOutPkg){

        m_titlePkg = new package::GraphicTitlePkg;
        m_titlePkg->init("Packet 12 - " + QString(BASELINE_3_6_0));

        m_nidPkgVar= new package::GraphicVariablePkg;
        m_nidPkgVar->set_NID_PACKET(m_idPkg);
        m_VariableVect.push_back(m_nidPkgVar);


        m_qDirVar = new package::GraphicVariablePkg;
        m_qDirVar->set_Q_DIR();
        m_VariableVect.push_back(m_qDirVar);
        connect (m_qDirVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        m_lenPkgVar =  new package::GraphicVariablePkg ;
        m_lenPkgVar->set_L_PACKET(72, 1462);
        m_VariableVect.push_back(m_lenPkgVar);
        connect (m_lenPkgVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        m_qScaleVar =  new package::GraphicVariablePkg ;
        m_qScaleVar->set_Q_SCALE();
        m_VariableVect.push_back(m_qScaleVar);
        connect (m_qScaleVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        m_vMainVar = new package::GraphicVariablePkg ;
        m_vMainVar->init(GraphicVariablePkg::type_integer);
        m_vMainVar->setNameVariable("V_MAIN");
        m_vMainVar->setRange(0,600);
        m_vMainVar->setDefaultValue(0);
        m_vMainVar->setVisible(false);
        m_vMainVar->setTobeVisible(true);
        m_vMainVar->setVariableBitSize(7);
        m_VariableVect.push_back(m_vMainVar);
        connect (m_vMainVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        m_vEmaVar =  new package::GraphicVariablePkg ;
        m_vEmaVar->init(GraphicVariablePkg::type_integer);
        m_vEmaVar->setNameVariable("V_EMA");
        m_vEmaVar->setRange(0,600);
        m_vEmaVar->setDefaultValue(0);
        m_vEmaVar->setVisible(false);
        m_vEmaVar->setTobeVisible(true);
        m_vEmaVar->setVariableBitSize(7);
        m_VariableVect.push_back(m_vEmaVar);
        connect (m_vEmaVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        m_tEmaVar =  new package::GraphicVariablePkg ;
        m_tEmaVar->init(GraphicVariablePkg::type_integer);
        m_tEmaVar->setNameVariable("T_EMA");
        m_tEmaVar->setRange(0,600);
        m_tEmaVar->setDefaultValue(0);
        m_tEmaVar->setVisible(false);
        m_tEmaVar->setTobeVisible(true);
        m_tEmaVar->setVariableBitSize(10);
        m_VariableVect.push_back(m_tEmaVar);
        connect (m_tEmaVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        m_nIterVar =  new package::GraphicVariablePkg ;
        m_nIterVar->set_N_ITER();
        m_VariableVect.push_back(m_nIterVar);
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::handleChangeIteration_SL );
        connect (m_nIterVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        qint16 maxValueVariableIter = 31;
        package::GraphicVariablePkg * p_lSectionVar_k = nullptr;
        package::GraphicVariablePkg * p_qSectionTimerVar_k = nullptr;
        package::GraphicVariablePkg * p_tSectionTimerVar_k = nullptr;
        package::GraphicVariablePkg * p_dSectionTimerStopLocVar_k = nullptr;
        QString nameItem;

        for (int i = 0;i < maxValueVariableIter ;i++)
        {
            p_lSectionVar_k = new package::GraphicVariablePkg ;
            p_lSectionVar_k->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("L_SECTION_%1").arg(QString::number(i+1));
            p_lSectionVar_k->setNameVariable(nameItem);
            p_lSectionVar_k->setInternalName(nameItem);
            p_lSectionVar_k->setRange(0,4);
            p_lSectionVar_k->setDefaultValue(0);
            p_lSectionVar_k->setVisible(false);
            p_lSectionVar_k->setTobeVisible(false);
            p_lSectionVar_k->setVariableBitSize(15);
            m_VariableVect.push_back(p_lSectionVar_k);
            connect (p_lSectionVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );


            p_qSectionTimerVar_k = new package::GraphicVariablePkg ;
            p_qSectionTimerVar_k->init(GraphicVariablePkg::type_integer);
            nameItem = QString ("Q_SECTIONTIMER_%1").arg(QString::number(i+1));
            p_qSectionTimerVar_k->setNameVariable(nameItem);
            p_qSectionTimerVar_k->setInternalName(nameItem);
            p_qSectionTimerVar_k->setRange(0,255);
            p_qSectionTimerVar_k->setDefaultValue(0);
            p_qSectionTimerVar_k->setVisible(false);
            p_qSectionTimerVar_k->setTobeVisible(false);
            p_qSectionTimerVar_k->setVariableBitSize(1);
            m_VariableVect.push_back(p_qSectionTimerVar_k);
            connect (p_qSectionTimerVar_k,&GraphicVariablePkg::nameInernalVariable_SG,this,&HandlerPackage_12_Ver360::handleIterateVariable_SL );
            connect (p_qSectionTimerVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

            {
                p_tSectionTimerVar_k = new package::GraphicVariablePkg ;
                p_tSectionTimerVar_k->init(GraphicVariablePkg::type_integer);
                nameItem = QString ("T_SECTIONTIMER_%1").arg(QString::number(i+1));
                p_tSectionTimerVar_k->setNameVariable(nameItem);
                p_tSectionTimerVar_k->setInternalName(nameItem);
                p_tSectionTimerVar_k->setRange(0,255);
                p_tSectionTimerVar_k->setDefaultValue(0);
                p_tSectionTimerVar_k->setVisible(false);
                p_tSectionTimerVar_k->setTobeVisible(false);
                p_tSectionTimerVar_k->setVariableBitSize(10);
                m_VariableVect.push_back(p_tSectionTimerVar_k);
                connect (p_tSectionTimerVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

                p_dSectionTimerStopLocVar_k = new package::GraphicVariablePkg ;
                p_dSectionTimerStopLocVar_k->init(GraphicVariablePkg::type_integer);
                nameItem = QString ("D_SECTIONTIMERSTOPLOC_%1").arg(QString::number(i+1));
                p_dSectionTimerStopLocVar_k->setNameVariable(nameItem);
                p_dSectionTimerStopLocVar_k->setInternalName(nameItem);
                p_dSectionTimerStopLocVar_k->setRange(0,255);
                p_dSectionTimerStopLocVar_k->setDefaultValue(0);
                p_dSectionTimerStopLocVar_k->setVisible(false);
                p_dSectionTimerStopLocVar_k->setTobeVisible(false);
                p_dSectionTimerStopLocVar_k->setVariableBitSize(15);
                m_VariableVect.push_back(p_dSectionTimerStopLocVar_k);
                connect (p_dSectionTimerStopLocVar_k,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );
            }
        }

        m_lEndSectionVar = new package::GraphicVariablePkg ;
        m_lEndSectionVar->init(GraphicVariablePkg::type_integer);
        m_lEndSectionVar->setNameVariable("L_ENDSECTION");
        m_lEndSectionVar->setRange(0,32767);
        m_lEndSectionVar->setDefaultValue(0);
        m_lEndSectionVar->setVisible(false);
        m_lEndSectionVar->setTobeVisible(true);
        m_lEndSectionVar->setVariableBitSize(15);
        m_VariableVect.push_back(m_lEndSectionVar);
        connect (m_lEndSectionVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );


        m_qSectionTimerVar = new package::GraphicVariablePkg ;
        m_qSectionTimerVar->init(GraphicVariablePkg::type_integer);
        m_qSectionTimerVar->setNameVariable("Q_SECTIONTIMER");
        m_qSectionTimerVar->setRange(0,1);
        m_qSectionTimerVar->setDefaultValue(0);
        m_qSectionTimerVar->setVisible(false);
        m_qSectionTimerVar->setTobeVisible(true);
        m_qSectionTimerVar->setVariableBitSize(1);
        m_VariableVect.push_back(m_qSectionTimerVar);
        connect (m_qSectionTimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::show_qSectionTimer_SL );
        connect (m_qSectionTimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        {   /* window for L_ENDSECTION */
            m_tSectionTimerVar = new package::GraphicVariablePkg ;
            m_tSectionTimerVar->init(GraphicVariablePkg::type_integer);
            m_tSectionTimerVar->setNameVariable("T_SECTIONTIMER");
            m_tSectionTimerVar->setRange(0,1023);
            m_tSectionTimerVar->setDefaultValue(0);
            m_tSectionTimerVar->setVisible(false);
            m_tSectionTimerVar->setTobeVisible(false);
            m_tSectionTimerVar->setVariableBitSize(10);
            m_VariableVect.push_back(m_tSectionTimerVar);
            connect (m_tSectionTimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

            m_dSectionTimerStopLocVar = new package::GraphicVariablePkg ;
            m_dSectionTimerStopLocVar->init(GraphicVariablePkg::type_integer);
            m_dSectionTimerStopLocVar->setNameVariable("D_SECTIONTIMERSTOPLOC");
            m_dSectionTimerStopLocVar->setRange(0,32767);
            m_dSectionTimerStopLocVar->setDefaultValue(0);
            m_dSectionTimerStopLocVar->setVisible(false);
            m_dSectionTimerStopLocVar->setTobeVisible(false);
            m_dSectionTimerStopLocVar->setVariableBitSize(15);
            m_VariableVect.push_back(m_dSectionTimerStopLocVar);
            connect (m_dSectionTimerStopLocVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );
        }


        m_qEndTimerVar = new package::GraphicVariablePkg ;
        m_qEndTimerVar->init(GraphicVariablePkg::type_integer);
        m_qEndTimerVar->setNameVariable("Q_ENDTIMER");
        m_qEndTimerVar->setRange(0,1);
        m_qEndTimerVar->setDefaultValue(0);
        m_qEndTimerVar->setVisible(false);
        m_qEndTimerVar->setTobeVisible(true);
        m_qEndTimerVar->setVariableBitSize(1);
        m_VariableVect.push_back(m_qEndTimerVar);
        connect (m_qEndTimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::show_qEndTimer_SL );
        connect (m_qEndTimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        {   /* window for Q_ENDTIMER */
            m_tEndTimerVar = new package::GraphicVariablePkg ;
            m_tEndTimerVar->init(GraphicVariablePkg::type_integer);
            m_tEndTimerVar->setNameVariable("T_ENDTIMER");
            m_tEndTimerVar->setRange(0,1023);
            m_tEndTimerVar->setDefaultValue(0);
            m_tEndTimerVar->setVisible(false);
            m_tEndTimerVar->setTobeVisible(false);
            m_tEndTimerVar->setVariableBitSize(10);
            m_VariableVect.push_back(m_tEndTimerVar);
            connect (m_tEndTimerVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

            m_dEndTimerStartLocVar = new package::GraphicVariablePkg ;
            m_dEndTimerStartLocVar->init(GraphicVariablePkg::type_integer);
            m_dEndTimerStartLocVar->setNameVariable("D_ENDTIMERSTARTLOC");
            m_dEndTimerStartLocVar->setRange(0,32767);
            m_dEndTimerStartLocVar->setDefaultValue(0);
            m_dEndTimerStartLocVar->setVisible(false);
            m_dEndTimerStartLocVar->setTobeVisible(false);
            m_dEndTimerStartLocVar->setVariableBitSize(15);
            m_VariableVect.push_back(m_dEndTimerStartLocVar);
            connect (m_dEndTimerStartLocVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );
        }


        m_qDangerPointVar = new package::GraphicVariablePkg ;
        m_qDangerPointVar->init(GraphicVariablePkg::type_integer);
        m_qDangerPointVar->setNameVariable("Q_DANGERPOINT");
        m_qDangerPointVar->setRange(0,1);
        m_qDangerPointVar->setDefaultValue(0);
        m_qDangerPointVar->setVisible(false);
        m_qDangerPointVar->setTobeVisible(true);
        m_qDangerPointVar->setVariableBitSize(1);
        m_VariableVect.push_back(m_qDangerPointVar);
        connect (m_qDangerPointVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::show_qDangerPoint_SL );
        connect (m_qDangerPointVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        {   /* window for Q_DANGERPOINT */
            m_dDpVar = new package::GraphicVariablePkg ;
            m_dDpVar->init(GraphicVariablePkg::type_integer);
            m_dDpVar->setNameVariable("D_DP");
            m_dDpVar->setRange(0,32767);
            m_dDpVar->setDefaultValue(0);
            m_dDpVar->setVisible(false);
            m_dDpVar->setTobeVisible(false);
            m_dDpVar->setVariableBitSize(15);
            m_VariableVect.push_back(m_dDpVar);
            connect (m_dDpVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

            m_vReleaseDpVar = new package::GraphicVariablePkg ;
            m_vReleaseDpVar->init(GraphicVariablePkg::type_integer);
            m_vReleaseDpVar->setNameVariable("V_RELEASEDP");
            m_vReleaseDpVar->setRange(0,600);
            m_vReleaseDpVar->setDefaultValue(0);
            m_vReleaseDpVar->setVisible(false);
            m_vReleaseDpVar->setTobeVisible(false);
            m_vReleaseDpVar->setVariableBitSize(7);
            m_VariableVect.push_back(m_vReleaseDpVar);
            connect (m_vReleaseDpVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );
        }


        m_qOverlapVar = new package::GraphicVariablePkg ;
        m_qOverlapVar->init(GraphicVariablePkg::type_integer);
        m_qOverlapVar->setNameVariable("Q_OVERLAP");
        m_qOverlapVar->setRange(0,1);
        m_qOverlapVar->setDefaultValue(0);
        m_qOverlapVar->setVisible(false);
        m_qOverlapVar->setTobeVisible(true);
        m_qOverlapVar->setVariableBitSize(1);
        m_VariableVect.push_back(m_qOverlapVar);
        connect (m_qOverlapVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::show_qOverlap_SL );
        connect (m_qOverlapVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

        {   /* window for Q_DANGERPOINT */
            m_dStartOLVar = new package::GraphicVariablePkg ;
            m_dStartOLVar->init(GraphicVariablePkg::type_integer);
            m_dStartOLVar->setNameVariable("D_STARTOL");
            m_dStartOLVar->setRange(0,32767);
            m_dStartOLVar->setDefaultValue(0);
            m_dStartOLVar->setVisible(false);
            m_dStartOLVar->setTobeVisible(false);
            m_dStartOLVar->setVariableBitSize(15);
            m_VariableVect.push_back(m_dStartOLVar);
            connect (m_dStartOLVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

            m_tOLVar = new package::GraphicVariablePkg ;
            m_tOLVar->init(GraphicVariablePkg::type_integer);
            m_tOLVar->setNameVariable("T_OL");
            m_tOLVar->setRange(0,1023);
            m_tOLVar->setDefaultValue(0);
            m_tOLVar->setVisible(false);
            m_tOLVar->setTobeVisible(false);
            m_tOLVar->setVariableBitSize(10);
            m_VariableVect.push_back(m_tOLVar);
            connect (m_tOLVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

            m_dOLVar = new package::GraphicVariablePkg ;
            m_dOLVar->init(GraphicVariablePkg::type_integer);
            m_dOLVar->setNameVariable("D_OL");
            m_dOLVar->setRange(0,32767);
            m_dOLVar->setDefaultValue(0);
            m_dOLVar->setVisible(false);
            m_dOLVar->setTobeVisible(false);
            m_dOLVar->setVariableBitSize(15);
            m_VariableVect.push_back(m_dOLVar);
            connect (m_dOLVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );

            m_vReleaseOLVar = new package::GraphicVariablePkg ;
            m_vReleaseOLVar->init(GraphicVariablePkg::type_integer);
            m_vReleaseOLVar->setNameVariable("V_RELEASEOL");
            m_vReleaseOLVar->setRange(0,600);
            m_vReleaseOLVar->setDefaultValue(0);
            m_vReleaseOLVar->setVisible(false);
            m_vReleaseOLVar->setTobeVisible(false);
            m_vReleaseOLVar->setVariableBitSize(7);
            m_VariableVect.push_back(m_vReleaseOLVar);
            connect (m_vReleaseOLVar,&GraphicVariablePkg::updateData_SG,this,&HandlerPackage_12_Ver360::saveData );
        }

        m_layOutPkg->addWidget(m_titlePkg,m_row,m_currCol);
        if (m_layOutPkg){
            loadPkg();
        }
        showVariable();
        saveData();

    }
    return true;

}
void HandlerPackage_12_Ver360::loadPkg()
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

//        if (size >= 6 ){
//            m_nidPkgVar->setDefaultValue( dataList.at(0).toInt());
//            m_qDirVar->setDefaultValue( dataList.at(1).toInt());
//            m_lenPkgVar->setDefaultValue( dataList.at(2).toInt());
//            m_qScaleVar->setDefaultValue( dataList.at(3).toInt() );
//            m_vMainVar->setDefaultValue( dataList.at(4).toInt() );
//            m_vEmaVar->setDefaultValue( dataList.at(5).toInt() );
//            m_tEmaVar->setDefaultValue( dataList.at(6).toInt() );
//            m_nIterVar->setDefaultValue( dataList.at(7).toInt() );

//            qint16 numIteration = m_nIterVar->valueOfVariable().toInt();
//            const qint16 windowSize = 4;
//            const qint16 startIndexWindow = 8;
//            qint16 stopIndex = (numIteration * windowSize) + startIndexWindow;
//            // check if varible in iterate window is present in data list AND in vector of variable widget
//            if ( (numIteration * 4 >= dataList.size()) && (numIteration + 8 < m_VariableVect.size()) ) {
//                for (int idx = 8; idx < stopIndex; idx++) {

//                    package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
//                    if (nullptr != variable){
//                        var = dataList.pop_front();
//                        if (var != EMPTY_VALUE){
//                            variable->setDefaultValue(var.toInt());
//                            variable->setTobeVisible(true);
//                        } else {
//                            variable->setTobeVisible(false);
//                        }
//                    }
//                }
//            }

//            m_lEndSectionVar->setDefaultValue( dataList.pop_front().toInt() );
//            m_qSectionTimerVar->setDefaultValue( dataList.pop_front().toInt() );


//        }
    }

}

void HandlerPackage_12_Ver360::show_qSectionTimer_SL()
{
    qDebug () <<  m_qSectionTimerVar->valueOfVariable().toInt();
    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    if (1 == m_qSectionTimerVar->valueOfVariable().toInt()){
        m_tSectionTimerVar->setTobeVisible(true);
        updLen = updLen + 10;

        m_dSectionTimerStopLocVar->setTobeVisible(true);
        updLen = updLen + 15;
    } else {
        m_tSectionTimerVar->setTobeVisible(false);
        updLen = updLen - 10;

        m_dSectionTimerStopLocVar->setTobeVisible(false);
        updLen = updLen - 15;
    }
    m_lenPkgVar->setDefaultValue(updLen);

    showVariable();
}

void HandlerPackage_12_Ver360::show_qEndTimer_SL()
{
    qDebug () <<  m_qEndTimerVar->valueOfVariable().toInt();
    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    if (1 == m_qEndTimerVar->valueOfVariable().toInt()){
        m_tEndTimerVar->setTobeVisible(true);
        updLen = updLen + 10;

        m_dEndTimerStartLocVar->setTobeVisible(true);
        updLen = updLen + 15;
    } else {
        m_tEndTimerVar->setTobeVisible(false);
        updLen = updLen - 10;

        m_dEndTimerStartLocVar->setTobeVisible(false);
        updLen = updLen - 15;
    }
    m_lenPkgVar->setDefaultValue(updLen);

    showVariable();
}

void HandlerPackage_12_Ver360::show_qDangerPoint_SL()
{
    qDebug () << m_qDangerPointVar->valueOfVariable().toInt();
    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    if (1 == m_qDangerPointVar->valueOfVariable().toInt()){
        m_dDpVar->setTobeVisible(true);
        updLen = updLen + 15;

        m_vReleaseDpVar->setTobeVisible(true);
        updLen = updLen + 7;
    } else {
        m_dDpVar->setTobeVisible(false);
        updLen = updLen - 15;

        m_vReleaseDpVar->setTobeVisible(false);
        updLen = updLen - 7;
    }
    m_lenPkgVar->setDefaultValue(updLen);

    showVariable();
}

void HandlerPackage_12_Ver360::show_qOverlap_SL()
{
    qDebug () << m_qOverlapVar->valueOfVariable().toInt();
    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    if (1 == m_qOverlapVar->valueOfVariable().toInt()){
        m_dStartOLVar->setTobeVisible(true);
        updLen = updLen + 15;

        m_tOLVar->setTobeVisible(true);
        updLen = updLen + 10;

        m_dOLVar->setTobeVisible(true);
        updLen = updLen + 15;

        m_vReleaseOLVar->setTobeVisible(true);
        updLen = updLen + 7;
    } else {
        m_dStartOLVar->setTobeVisible(false);
        updLen = updLen - 15;

        m_tOLVar->setTobeVisible(false);
        updLen = updLen - 10;

        m_dOLVar->setTobeVisible(false);
        updLen = updLen - 15;

        m_vReleaseOLVar->setTobeVisible(false);
        updLen = updLen - 7;
    }
    m_lenPkgVar->setDefaultValue(updLen);

    showVariable();
}

void HandlerPackage_12_Ver360::handleChangeIteration_SL()
{
    qint16 currentValue = m_nIterVar->valueOfVariable().toInt();

//    /* index from 1 to current number of iterations */
//    for (int i = 1; i <= currentValue; i++)
//    {
//        // trovo l'item da selezionare
//        QString nameIterateVar = QString ("L_SECTION_%1").arg(QString::number(i + 1));
//        // Marca l'item a visibile
//        bool notUsed;
//        variableUpdVisibleState(nameIterateVar,true,notUsed);
//        qint16 updLen = m_lenPkgVar->valueOfVariable().toInt()+ 3;
//        m_lenPkgVar->setDefaultValue(updLen);
//    }

    qint16 numVisibile = countVariableIterateisVisible("L_SECTION_");
    qDebug () << "currentValue = " << currentValue;
    qDebug () << "numVisibile = " << numVisibile;

    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    QString nameIterateVar;
    package::GraphicVariablePkg * p_variable = nullptr;

    if (numVisibile < currentValue){
        qint16 numberShowVariavble = currentValue - numVisibile;
        for (int i=0;i< numberShowVariavble;i++){
            nameIterateVar = QString ("L_SECTION_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            bool notUsed;
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = updLen + 15;

            nameIterateVar = QString ("Q_SECTIONTIMER_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,true,notUsed);
            updLen = updLen + 1;

            nameIterateVar = QString ("T_SECTIONTIMER_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,false,notUsed);

            nameIterateVar = QString ("D_SECTIONTIMERSTOPLOC_%1").arg(QString::number(numVisibile + i + 1));
            //Marca l'item a visibile
            variableUpdVisibleState(nameIterateVar,false,notUsed);
        }
    } else {
        qint16 numberHideVariavble = numVisibile-currentValue;
        qint16 variableIdx = -1;
        for (int i=0;i< numberHideVariavble;i++){
            bool oldvisibleState;
            nameIterateVar = QString ("L_SECTION_%1").arg(QString::number(numVisibile));
            //Marca l'item a non visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("Q_SECTIONTIMER_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("T_SECTIONTIMER_%1").arg(QString::number(numVisibile));
            //Marca l'item a visibile
            variableIdx = variableUpdVisibleState(nameIterateVar,false,oldvisibleState);
            if (oldvisibleState){
                p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
                p_variable->setDefaultValue(0);
            }

            nameIterateVar = QString ("D_SECTIONTIMERSTOPLOC_%1").arg(QString::number(numVisibile));
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

void HandlerPackage_12_Ver360::handleIterateVariable_SL(QString nameVariable)
{
    package::GraphicVariablePkg * p_variable= qobject_cast<package::GraphicVariablePkg *>(variableByName(nameVariable));
    qDebug () << "nameVariable="<<nameVariable << "  Valore = "<< p_variable->valueOfVariable();
    qint16 value = p_variable->valueOfVariable().toInt();
    QStringList parseNameVar = nameVariable.split("_");
    qint16 updLen = m_lenPkgVar->valueOfVariable().toInt();
    qint16 variableIdx = -1;

    if (parseNameVar.size() ){
        qint16 numberIteration = parseNameVar[1].toInt();
        QString tSectionTimerVar = QString ("T_SECTIONTIMER_%1").arg(parseNameVar[parseNameVar.size()-1]);
        QString dSectionTimerStopLocVar = QString ("D_SECTIONTIMERSTOPLOC_%1").arg(parseNameVar[parseNameVar.size()-1]);

        bool notUsed;
        if (1 == value){
            variableUpdVisibleState(tSectionTimerVar,true,notUsed);

            variableUpdVisibleState(dSectionTimerStopLocVar,true,notUsed);
        } else {
            variableIdx = variableUpdVisibleState(tSectionTimerVar,false,notUsed);
            p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
            p_variable->setDefaultValue(0);

            variableIdx = variableUpdVisibleState(dSectionTimerStopLocVar,false,notUsed);
            p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(variableIdx));
            p_variable->setDefaultValue(0);
        }
        m_lenPkgVar->setDefaultValue(updLen);
    }

    showVariable();
}

void HandlerPackage_12_Ver360::showVariable()
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


bool HandlerPackage_12_Ver360::saveData()
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
//    //= m_nidPkgVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qDirVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_lenPkgVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qScaleVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_vMainVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_vEmaVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_tEmaVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_nIterVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;

//    qint16 numIteration = m_nIterVar->valueOfVariable().toInt();
//    qint16 sizeIterate = ( numIteration * 4);
//    if (sizeIterate+6 <=m_VariableVect.size()){
//        for (int i =0; i < sizeIterate;i++ ){
//            package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i+6));
//            data+=INTERNAL_FIELD_SEPARATOR_PKG;
//            if (variable->tobeVisible()){
//                data+=variable->valueOfVariable();
//            } else {
//                data+=EMPTY_VALUE;
//            }
//        }
//    }

//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_lEndSectionVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qSectionTimerVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_tSectionTimerVar->isVisible()){
//        data+=m_tSectionTimerVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dSectionTimerStopLocVar->isVisible()){
//        data+=m_dSectionTimerStopLocVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }

//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qEndTimerVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_tEndTimerVar->isVisible()){
//        data+=m_tEndTimerVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dEndTimerStartLocVar->isVisible()){
//        data+=m_dEndTimerStartLocVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }

//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qDangerPointVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dDpVar->isVisible()){
//        data+=m_dDpVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_vReleaseDpVar->isVisible()){
//        data+=m_vReleaseDpVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }

//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    data+=m_qOverlapVar->valueOfVariable();
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dStartOLVar->isVisible()){
//        data+=m_dStartOLVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_tOLVar->isVisible()){
//        data+=m_tOLVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_dOLVar->isVisible()){
//        data+=m_dOLVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }
//    data+=INTERNAL_FIELD_SEPARATOR_PKG;
//    if (m_vReleaseOLVar->isVisible()){
//        data+=m_vReleaseOLVar->valueOfVariable();
//    } else{
//        data+=EMPTY_VALUE;
//    }

    storageData::StorageOutDataBaliseCommand &outBalsCmd=storageData::MngStorageOutCommand::istance()->storageBaliseCmd();
    storageData::OutDataPkgSingleBalise pkg ;
    pkg.idPkg=m_idPkg;
    pkg.balseLine=m_baseLine;
    pkg.dataPkg = data;

    outBalsCmd.updPkgToBalise(m_currentBaliseGrp,m_currentBalise,m_currentPkg,pkg);
    return true;

}

void HandlerPackage_12_Ver360::deleteView()
{
    HandlerPackage::deleteView();
}


}
