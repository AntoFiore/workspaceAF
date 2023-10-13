#include "GraphicHandlerCreateScenario.h"
#include <QDebug>

#include "Define.h"
#include "GraphicHandlerCommand.h"
#include "GraphicHandlerCommand_T_IO.h"
#include "GraphicHandlerCommand_T_SIM.h"
#include "GraphicHandlerCommand_T_APDM.h"
#include "GraphicHandlerCommand_MT_APDM.h"
#include "GraphicHandlerCommand_T_ODO.h"
#include "GraphicHandlerCommand_T_RADIO_HOLE.h"
#include "GraphicHandlerCommand_SINGLE.h"
#include "GraphicHandlerCommand_BALISE.h"
#include <QPushButton>
#include "ExportCsv.h"
//#include "ServiceCommand.h"
#include "StorageDataCommand.h"
namespace page{
GraphicHandlerCreateScenario::GraphicHandlerCreateScenario(QObject *parent)
    : GraphicHandlerPage{parent}
{

    m_page= CreationScenario_page;
}

GraphicHandlerCreateScenario::~GraphicHandlerCreateScenario()
{
    for (int i = 0;i<m_cmdTab.size();i++){

        if (nullptr != m_cmdTab.at(i)){
            delete m_cmdTab.at(i);
            //cmdTab[i]=nullptr;
        }
    }
    m_cmdTab.clear();
}

bool GraphicHandlerCreateScenario::initPage()
{
    bool ret = true;

    m_cmdTab.push_back(new hndcommand::GraphicHandlerCommand_T_IO);
    m_cmdTab.push_back(new hndcommand::GraphicHandlerCommand_T_SIM);
    m_cmdTab.push_back(new hndcommand::GraphicHandlerCommand_T_APDM);
    m_cmdTab.push_back(new hndcommand::GraphicHandlerCommand_T_ODO);
    m_cmdTab.push_back(new hndcommand::GraphicHandlerCommand_T_RADIO_HOLE);
    m_cmdTab.push_back(new hndcommand::GraphicHandlerCommand_MT_APDM);
    m_cmdTab.push_back(new hndcommand::GraphicHandlerCommand_SINGLE);
    m_cmdTab.push_back(new hndcommand::GraphicHandlerCommand_BALISE);
   // m_cmdTab.push_back(new hndcommand::GraphicHandlerCommand);


    ret =  m_servCmd.init(m_mainWin_Ptr);
    if (ret){
        // for  (qint32 idxTab=0 ;idxTab< MAX_TAB_CREATE_CMD;idxTab++ ){
        for  (qint32 idxTab=0 ;idxTab< m_cmdTab.size();idxTab++ ){
            if (nullptr != m_cmdTab.at(idxTab)){


                m_cmdTab.at(idxTab)->init(m_mainWin_Ptr);
                m_cmdTab.at(idxTab)->setTabId(idxTab);
                m_cmdTab.at(idxTab)->setCurrentTabSelected(0);
                m_servCmd.addGraphicHandlerCmd(m_cmdTab.at(idxTab));
                connect (m_cmdTab.at(idxTab),&hndcommand::GraphicHandlerCommand::addRemoveUpdateCommand_SG,[this](QString command,
                                                                                                                  ActionCommand_E actionCommand,
                                                                                                                  QString idTab,qint32 rowTabe){

                    switch (actionCommand) {
                    case add_command:
                        m_graphicStepSeq_Ptr->insertCommand(command,idTab);
                    break;
                    case remove_command:
                        m_graphicStepSeq_Ptr->removeCommand(/*command,idTab,*/rowTabe);
                    break;
                    case update_command:
                        m_graphicStepSeq_Ptr->updateCommand(command,rowTabe,idTab);
                    break;
                    default:
                        break;
                    }
                });

                //connessione per dati da step sequence a tab
                connect (m_graphicStepSeq_Ptr,& hndcommand::GraphicStepSequence::stepSelected_SG,
                         m_cmdTab.at(idxTab),&hndcommand::GraphicHandlerCommand::showCommand_SL);

            }
        }
        m_mainWin_Ptr->tabWidget_Commands->setCurrentIndex(0);
        //connessione per change tab
        connect (m_mainWin_Ptr->tabWidget_Commands, &QTabWidget::currentChanged,[this](int idx) {

            for  (qint32 idxTab=0 ;idxTab< m_cmdTab.size();idxTab++ ){
                if (nullptr !=  m_cmdTab.at(idxTab)){
                    m_cmdTab.at(idxTab)->setCurrentTabSelected(idx);
                }
            }
        });
        if (ret){
            storageData::Data_SubSet subSet =  storageData::StorageDataCommand::istance()->subSet();
            m_mainWin_Ptr->comboBox_Version->addItem("");
            foreach (QString issues, subSet.issues) {
                m_mainWin_Ptr->comboBox_Version->addItem(issues);
            }
            if (m_mainWin_Ptr->comboBox_Version->count() ){
                m_mainWin_Ptr->comboBox_Version->setCurrentIndex(0);
            } else {
                ret = false;
                qDebug () << "Subset version is empty";
            }
        }
        //connessione per export
        connect(m_mainWin_Ptr->pushButton_ExportScenario, &QPushButton::clicked,[this]() {
            qDebug () << "Go export ";

            if (nullptr != m_graphicStepSeq_Ptr){
                QVector <QString> prova =  m_graphicStepSeq_Ptr->extractAllRow();
                exportdata::ExportData *_expCsv = new exportdata::ExportCsv(this);
                foreach(auto row,prova) {
                    QVariant *v = new QVariant(row);
                    _expCsv->addData(v);
                }
                _expCsv->goExport();
                delete _expCsv;
            } else {
                qDebug () << "m_GrpStepSeq non Validi. Error ........";
            }
        });
    } else {
        qDebug () << "Error Service Command initialization";
        ret  = false ;
    }

    return ret;
}
}

