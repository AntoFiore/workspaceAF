#include "GraphicHandlerTreeBalise.h"
#include <QDebug>
#include "Define.h"
namespace hndcommand{
GraphicHandlerTreeBalise::GraphicHandlerTreeBalise(QObject *parent)
    : QObject{parent}
{
    m_model=nullptr;

    m_deleteBlGrpAct = nullptr;
    m_actGroup=nullptr;
}

bool GraphicHandlerTreeBalise::init(Ui::MainWindow *mainWin_Ptr)
{

    bool ret = true;
    if ( mainWin_Ptr == nullptr){
        qDebug () << "Invalid pointer to MainWindow";
        ret= false;
    } else {
        m_mainWin_Ptr = mainWin_Ptr;
        m_model = new QStandardItemModel( 0,1 );

        m_mainWin_Ptr->treeView_Balise->setModel(m_model);

        connect (m_mainWin_Ptr->treeView_Balise,&QTreeView::clicked,this,&GraphicHandlerTreeBalise::handleTreeView_clicked_SL);
        m_deleteBlGrpAct = new QAction(DELETE_GRPBALSE_ACTNAME,m_mainWin_Ptr->treeView_Balise) ;

        //m_actGroup = new QActionGroup(m_mainWin_Ptr->treeView_Balise);
        m_mainWin_Ptr->treeView_Balise->setContextMenuPolicy(Qt::ActionsContextMenu);

       m_mainWin_Ptr->treeView_Balise->addAction(m_deleteBlGrpAct);
      m_actGroup= new QActionGroup( m_mainWin_Ptr->treeView_Balise);
       connect(m_actGroup,&QActionGroup::triggered,this,&GraphicHandlerTreeBalise::actionTriggered_SL);

       m_actGroup->addAction(m_deleteBlGrpAct);


      // m_actGroup->addAction(m_deleteBlGrpAct);




    }
    return ret;

}
void GraphicHandlerTreeBalise::getLevelTree (const QModelIndex &index, qint8 &level){

    if (index.parent().row() == -1) {
        return ;
    } else {
        level++;
        getLevelTree(index.parent(),level);
    }

}

void GraphicHandlerTreeBalise::getRowItem(qint8 &level, int *arr, const QModelIndex &index)
{

    if (level == 0 ){
        arr[level]=index.row();
        return;
    } else if (level > 0){
         arr[level]=index.row();
         level--;

         getRowItem(level,arr,index.parent());
         return;
    } else {
        return ;
    }
}
QVector <qint16> GraphicHandlerTreeBalise::getRowItem (const QModelIndex index){
     qint8 level = 0;
     getLevelTree(index,level);
     qint8 levelBck =level;
     int rowItem [level+1];

     for (int i =0; i < level+1;i++ ){
         rowItem[i]=-1;

     }
      QVector <qint16> retRowItem(15);
     for (int i=0;i < 15;i++){
         retRowItem[i]=-1;
     }


     getRowItem(level,rowItem,index);
     switch (levelBck) {
     case 0:
         retRowItem[0]=rowItem[0];
         break;

     case 1:
          retRowItem[0]=rowItem[0];
          retRowItem[1]=rowItem[1];

         break;
     case 2:
          retRowItem[0]=rowItem[0];
          retRowItem[1]=rowItem[1];
          retRowItem[2]=rowItem[2];

         break;
     default:
         break;
     }
     return retRowItem;


}

void GraphicHandlerTreeBalise::removePkg(qint16 numGrBalise, qint16 numSingleBalise, qint16 numPkg)
{
    qint32 sizeModel = m_model->rowCount();
    if (numGrBalise < sizeModel) {
        QStandardItem *itemBlGrp=nullptr;
        itemBlGrp = m_model->item(numGrBalise,0);
        if (itemBlGrp != nullptr){

            qint16 totBlInGroup =itemBlGrp->rowCount(); //Tot Balise in group
            if (numSingleBalise < totBlInGroup ) {
                QStandardItem *balise =  itemBlGrp->child(numSingleBalise,0);
                if (balise != nullptr){
                    qint16 totPkg = balise->rowCount();
                    if (numPkg < totPkg){
                        balise->removeRow(numPkg);
                    }
                }
            }
        }

    }

}

void GraphicHandlerTreeBalise::removeSingleBalise(qint16 numGrBalise, qint16 numSingleBalise)
{

    qint32 sizeModel = m_model->rowCount();
    if (numGrBalise < sizeModel) {
        QStandardItem *itemBlGrp=nullptr;
        itemBlGrp = m_model->item(numGrBalise,0);
        if (itemBlGrp != nullptr){
            qint16 totBlInGroup =itemBlGrp->rowCount(); //Tot Balise in group
              if (numSingleBalise < totBlInGroup ) {
                  itemBlGrp->removeRow(numSingleBalise);

              }

        }

    }

}
void GraphicHandlerTreeBalise::actionTriggered_SL(QAction *a)
{
    //Gestione da modificare quando si aggiungera il node package
    if (a == m_deleteBlGrpAct ){
        QModelIndexList index = m_mainWin_Ptr->treeView_Balise->selectionModel()->selectedIndexes();
        if (index.size()){
            QModelIndex nodeSelected = index.at(0);
            qint16 numBalGrp  = -1;
            qint16 numSingleBalise  = -1;
            qint16 numPkg=-1;
             QVector <qint16> rowsItem = getRowItem(nodeSelected);
             numBalGrp=rowsItem.at(0);
             numSingleBalise=rowsItem.at(1);
             numPkg=rowsItem.at(2);
             if (numBalGrp != -1) {
                 if (numPkg == -1 && numSingleBalise == -1) {
                    m_model->removeRow(numBalGrp);
                 } else {
                     if (numSingleBalise != -1 && numPkg == -1) {
                         removeSingleBalise(numBalGrp,numSingleBalise); //remove balise
                     } else {
                         removePkg(numBalGrp,numSingleBalise,numPkg);
                     }

                 }
             }
            emit itemBlGrpdeleted_SG(numBalGrp,numSingleBalise,numPkg);
            //find the new Selection
             index = m_mainWin_Ptr->treeView_Balise->selectionModel()->selectedIndexes();
             if (index.size()){
                 nodeSelected = index.at(0);
                 numBalGrp  = -1;
                 numSingleBalise  = -1;
                 numPkg=-1;
                 rowsItem.clear();
                 rowsItem = getRowItem(nodeSelected);
                 numBalGrp=rowsItem.at(0);
                 numSingleBalise=rowsItem.at(1);
                 numPkg=rowsItem.at(2);

                 qDebug () << "Balise Gr Selection = " << numBalGrp;
                 qDebug () << "Singol  Selection = " << numSingleBalise;
                  emit itemBaliseSelected_SG(numBalGrp,numSingleBalise,numPkg);

             }

        }
    }
}

void GraphicHandlerTreeBalise::selectionManuallyTreeView(qint16 currentGrBal,qint16 currentBal,qint16 currentPkg){

    if (-1 != currentGrBal) {
        QModelIndex idxGrBal = m_mainWin_Ptr->treeView_Balise->model()->index(currentGrBal,0);
        if ( -1 != currentBal) {
            QModelIndex idxBal = idxGrBal.child(currentBal,0);
            if (-1 != currentPkg) {
                QModelIndex idxPkg = idxBal.child(currentPkg,0);
                 m_mainWin_Ptr->treeView_Balise->setCurrentIndex(idxPkg);
            } else {
                 m_mainWin_Ptr->treeView_Balise->setCurrentIndex(idxBal);
            }
        }
    }
}
void GraphicHandlerTreeBalise::handleTreeView_clicked_SL(const QModelIndex &index)
{
    qint16 numBalGrp  = -1;
    qint16 numBalSingle=-1;
    qint16 numPkg = -1;
    QVector <qint16> rowsItem = getRowItem(index);
    numBalGrp=rowsItem.at(0);
    numBalSingle=rowsItem.at(1);
    numPkg=rowsItem.at(2);
   emit itemBaliseSelected_SG(numBalGrp,numBalSingle,numPkg);
}

void GraphicHandlerTreeBalise::updBaliseGrp(QString baliseGrp, qint16 rowBlGr)
{
    qint32 sizeModel = m_model->rowCount();
    if (! sizeModel || sizeModel==rowBlGr) {
        QStandardItem *itemBlGrp = new QStandardItem(baliseGrp );
         m_model->setItem(sizeModel,0,itemBlGrp);
    } else {
        //Update Name Balise Grp
        if (rowBlGr < sizeModel){

            QStandardItem *itemBlGrp=nullptr;
            itemBlGrp = m_model->item(rowBlGr,0);
            if (itemBlGrp != nullptr) {
               itemBlGrp->setText(baliseGrp);

               qint16 totSingleBalise= itemBlGrp->rowCount();
               for (int i =0 ; i < itemBlGrp->rowCount();i++) {

                  // itemBlGrp->child(i,0)->setText(new QStandardItem( QString("%1  - Balise N. %2").arg(itemBlGrp->text(),QString::number(i+1) )) );
                   itemBlGrp->child(i,0)->setText(QString("%1%2").arg(NAME_BALISE_DEFAULT,QString::number(i+1)));
               }

            }


        }
    }

}

//update default name

void GraphicHandlerTreeBalise::updNameBalise(qint16 rowBlGr , qint16 numberBalise, QString nameBalise){

     qint32 sizeModel = m_model->rowCount();
      if (rowBlGr < sizeModel){
          QStandardItem *itemBlGrp=nullptr;
          itemBlGrp = m_model->item(rowBlGr,0);
          if (itemBlGrp != nullptr) {
              qint16 totSingleBalise= itemBlGrp->rowCount();
              if (numberBalise  < totSingleBalise) {
                  itemBlGrp->child(numberBalise,0)->setText(nameBalise);

              }

          }

      }

}

void GraphicHandlerTreeBalise::updNamesBalise(qint16 numberBalise, qint16 rowBlGr)
{
    qint32 sizeModel = m_model->rowCount();
    if (rowBlGr < sizeModel){
        QStandardItem *itemBlGrp=nullptr;
        itemBlGrp = m_model->item(rowBlGr,0);
        if (itemBlGrp != nullptr) {

            qint16 totSingleBalise= itemBlGrp->rowCount();

            if (totSingleBalise < numberBalise) {
                for (int i =0 ; i < numberBalise-totSingleBalise;i++) {

                     itemBlGrp->appendRow( new QStandardItem( QString("%1%2").arg(NAME_BALISE_DEFAULT,QString::number(totSingleBalise+i+1) )) );

                }
            } else if (totSingleBalise > numberBalise ){

                qint16 numEraseSinglBal = totSingleBalise - numberBalise;
                for (int i =0 ; i < numEraseSinglBal;i++){
                    qint16 totSingleBl= itemBlGrp->rowCount();
                    itemBlGrp->removeRow(totSingleBl-1);
                }

            }
        }

    }

}

void GraphicHandlerTreeBalise::addPkg(qint16 numBlGrp, qint16 numSingleBalise, QString namePkg)
{

     qint32 sizeModel = m_model->rowCount();
      if (numBlGrp < sizeModel){

          QStandardItem *itemBlGrp=nullptr;
          itemBlGrp = m_model->item(numBlGrp,0);
           if (itemBlGrp != nullptr) {

                qint16 totSingleBalise= itemBlGrp->rowCount();
                 if (numSingleBalise < totSingleBalise) {
                     QStandardItem *balise = itemBlGrp->child(numSingleBalise,0);
                     balise->appendRow(new QStandardItem (namePkg));

                 }

           }

      }

}



}
