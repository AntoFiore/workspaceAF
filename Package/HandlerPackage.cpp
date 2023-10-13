#include "HandlerPackage.h"
#include "GraphicVariablePkg.h"
#include <QDebug>
    #include <QApplication>
namespace  package{
HandlerPackage::HandlerPackage(QObject *parent)
    : QObject{parent}
{
    m_titlePkg=nullptr;
    m_layOutPkg=nullptr;
     m_spaced=nullptr;
     m_currentBaliseGrp=-1;
     m_currentBalise=-1;
     m_currentPkg=-1;
     m_idPkg = -1;
     m_isReload=false;
     m_maxColumnVariable=MAX_COLUMN_VARIABLE;

}

//bool HandlerPackage::creteView()
//{

//    bool ret = true;


//    return ret;
//}

bool HandlerPackage::saveData()
{

    bool ret = true;
    return ret;

}

void HandlerPackage::deleteView()
{
           foreach (QWidget *variable, m_VariableVect) {
               if (nullptr != variable)
                  // delete variable;
                   variable->deleteLater();

   }
//           if (m_spaced != nullptr) {
//               delete m_spaced;
//               m_spaced=nullptr;
//           }
           m_VariableVect.clear();
           if (nullptr != m_titlePkg ){
             //  delete m_titlePkg;
             //  m_titlePkg=nullptr;
               m_titlePkg->deleteLater();
           }


           removeSpacer();

//           for (int i = 0; i < m_layOutPkg->count(); ++i) {
//               QLayoutItem *layoutItem = m_layOutPkg->itemAt(i);
//               if (layoutItem->spacerItem()) {
//                   m_layOutPkg->removeItem(layoutItem);
//                   // You could also use: layout->takeAt(i);
//                   delete layoutItem;
//                   --i;
//               }
//           }


}
void HandlerPackage::removeSpacer(){
    for (int i = 0; i < m_layOutPkg->count(); ++i) {
        QLayoutItem *layoutItem = m_layOutPkg->itemAt(i);
        if (layoutItem->spacerItem()) {
            m_layOutPkg->removeItem(layoutItem);
            // You could also use: layout->takeAt(i);
            delete layoutItem;
            --i;
        }
    }

}

void HandlerPackage::setWorkSpaceLayout(QGridLayout *lay)
{

    m_layOutPkg = lay;
}

void HandlerPackage::set_GrBalise_Balise_Pkg(qint16 currentBaliseGrp, qint16 currentBalise,qint16 currentPkg)
{
    m_currentBaliseGrp=currentBaliseGrp;
    m_currentBalise=currentBalise;
    m_currentPkg=currentPkg;

}

 QVector<QWidget *> &HandlerPackage::VariableVect()
{
    return m_VariableVect;
}

GraphicTitlePkg *HandlerPackage::titlePkg() const
{
    return m_titlePkg;
}

bool HandlerPackage::isReload() const
{
    return m_isReload;
}

void HandlerPackage::setIsReload(bool newIsReload)
{
    m_isReload = newIsReload;
}



qint16 HandlerPackage::countVariableIterate(QString name)
{
    qint16 count=0;

    qint16 size=m_VariableVect.size();
    QString nameIterationVariable;
    qint16 currentIteration=1;
    for (int i =0 ; i < size;i++) {
       nameIterationVariable = name + QString::number(currentIteration);
       package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
       if (nullptr != variable) {
           if (nameIterationVariable==variable->internalName()){
           count++;
           currentIteration++;
           }
       }
    }
    return count;

}



qint16 HandlerPackage::countVariableIterateisVisible(QString name)
{
    qint16 count=0;

    qint16 size=m_VariableVect.size();
    QString nameIterationVariable;
    qint16 currentIteration=1;
    for (int i =0 ; i < size;i++) {
        nameIterationVariable = name + QString::number(currentIteration);
        package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
        if (nullptr != variable) {
            if (nameIterationVariable==variable->internalName()){
                if (variable ->isVisible() ){
                    count++;
                }

                currentIteration++;
            }
        }
    }
    return count;

}

qint16 HandlerPackage::variableUpdVisibleState(QString name, bool newvisibleState, bool &oldvisiblestate)
{
    qint16 idxVect = -1;
    qint16 size=m_VariableVect.size();
    for (int i =0 ; i < size && idxVect == -1 ;i++) {

        package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
        if (nullptr != variable) {
            if (name==variable->internalName()){
                oldvisiblestate=variable->tobeVisible();
                variable->setTobeVisible(newvisibleState);
                idxVect=i;


            }
        }
    }
    return idxVect;

}

qint16 HandlerPackage::countPacketBitSize()
{
    qint16 packetSize = 0;
    package::GraphicVariablePkg * p_variable = nullptr;

    for (int idx = 0; idx < this->m_VariableVect.size(); idx++) {
        p_variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(idx));
        if (p_variable != nullptr) {
            if (p_variable->tobeVisible() == true) {
                packetSize += p_variable->variableBitSize();
            }
        }
    }

    return packetSize;
}

void HandlerPackage::showVariable()
{
    int m_row=1;
    int m_currCol=0;

    qint16 actualPktSize = this->countPacketBitSize();

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

QWidget *HandlerPackage::variableByName(QString &name)
{
    QWidget *retVariable= nullptr;
    qint16 size=m_VariableVect.size();
     for (int i =0 ; i < size;i++) {
         package::GraphicVariablePkg * variable = qobject_cast<package::GraphicVariablePkg *>(m_VariableVect.at(i));
          if (name==variable->internalName()){
              retVariable=m_VariableVect.at(i);
              break;
          }

     }

    return retVariable;

}

}
