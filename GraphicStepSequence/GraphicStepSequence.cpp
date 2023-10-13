#include "GraphicStepSequence.h"
#include <QDebug>
#include "Define.h"
#include <QHeaderView>
#include <QList>
#include <QMouseEvent>
namespace hndcommand{
GraphicStepSequence::GraphicStepSequence(QWidget *parent)    : QTableView(parent)
{


}

bool GraphicStepSequence::init()
{
    bool ret = true;
    if ( ! ret){
        qDebug () << "Invalid pointer to MainWindow";
        ret= false;
    } else {

        m_model = new QStandardItemModel(0, 1, this);
        m_model->setHeaderData(0, Qt::Horizontal,QString ("%1_%2").arg(NAME_COLUMN,QString::number(0)));


        //        for (int idx =0 ; idx < MAX_COLUMN_STEP_SEQ+5;idx++) {
        //             _model->setHeaderData(idx, Qt::Horizontal, NAME_COLUMNS[idx]);
        //        }
        auto h = this->horizontalHeader();
        h->setStyleSheet("QHeaderView::section  { background-color: rgb(202,250,255);color:black ;}");
        h->setDefaultAlignment(Qt::AlignCenter);
        this->setModel(m_model);
        this->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        this->horizontalHeader()->setStretchLastSection(true);
        this->setSelectionMode(QAbstractItemView::SingleSelection);
        this->setSelectionBehavior(QAbstractItemView::SelectRows);
        m_isActiveSelectionRow=true;
        this->m_rowCommandTab_map.clear();
        m_lastKey=-1;
        m_lastKeyPosition=0;


    }



    // this->horizontalHeader()->hide();
    return ret;

}



bool GraphicStepSequence::insertCommand(QString step,QString idTab)
{
    bool ret = true;

    //    QModelIndex currentIndex = this->selectionModel()->currentIndex();

    //    this->selectionModel()->select(currentIndex,QItemSelectionModel::Rows);
    //    this->setSelectionMode(QAbstractItemView::NoSelection);
    //    this->setSelectionBehavior(QAbstractItemView::SelectRows);


    // qint32 rowSelected = currentIndex.row();
    //  qDebug () << "Current Row Selected = " << rowSelected;
    QModelIndex currentIndex = this->selectionModel()->currentIndex();
    qint32 rowSelected = currentIndex.row();

    QStringList stepList = step.split(INTERNAL_SEPARATOR);
    qint32 sizeStep =stepList.size();
    qint32 currentNumberColumn =m_model->columnCount();
    if (currentNumberColumn < sizeStep) {
        currentNumberColumn=sizeStep;
        //   m_model->setColumnCount(sizeStep);
    }

    m_model->setColumnCount(currentNumberColumn);


    for (int idx =0 ; idx < currentNumberColumn;idx++) {
        m_model->setHeaderData(idx, Qt::Horizontal, QString ("%1_%2").arg(NAME_COLUMN,QString::number(idx)));
    }
    this->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->horizontalHeader()->setStretchLastSection(true);


    if (! m_isActiveSelectionRow || (rowSelected < 0 && m_isActiveSelectionRow )){
        qint32 sizeModel = m_model->rowCount();
        for (qint32 i =0 ;  i< sizeStep;i++){
            QStandardItem *item = new QStandardItem (stepList[i]);
            item->setEditable(false);
            item->setToolTip(stepList[i]);
            m_model->setItem(sizeModel,i,item);
        }
        m_RowIdTabVector.push_back(idTab);
    } else {

        QList <QStandardItem*> items;
        foreach (QString item, stepList) {
            items.push_back(new QStandardItem (item));
        }
        m_model->insertRow(rowSelected,items);
        m_RowIdTabVector.insert(rowSelected,idTab);
        qint16 columnCount = m_model->columnCount();
        qint16 rowCount = m_model->rowCount();



        QModelIndex topLeft= m_model->index(0, 0, QModelIndex());
        QModelIndex bottomRight = m_model->index(rowCount, columnCount, QModelIndex());
        QItemSelection selection(topLeft, bottomRight);
        selectionModel()->select(selection, QItemSelectionModel::Clear);
        topLeft= m_model->index(rowSelected, 0, QModelIndex());
        bottomRight = m_model->index(rowSelected, columnCount-1, QModelIndex());
        QItemSelection newselection(topLeft, bottomRight);

        selectionModel()->select(newselection, QItemSelectionModel::Select);


    }

}
qint64 GraphicStepSequence::getKey(QString field){
    qint64 key = -1;
    if (field.contains(INTERNAL_SEPARATOR_KEYBALISE)){
        QStringList keyList = field.split(INTERNAL_SEPARATOR_KEYBALISE);
        qint16 size = keyList.size();
        if (size > 1){
            key=keyList[size-1].toLongLong();
        }

    }

    return key;

}
bool GraphicStepSequence::updateCommand(QString command,qint32 rowTable,QString  tabAndKey){

    qDebug () << "Key = "<< tabAndKey;

    if (command == EMPTY_VALUE){
        m_lastKeyPosition=0;

    } else {
        if (""!= tabAndKey ){
            qint64 keyCmd = getKey(tabAndKey);
            bool found = false;

                qint16 sizeRow = m_RowIdTabVector.size();
                qint64 currentKeyCmd=-1;
                for (int idx =m_lastKeyPosition ; idx < sizeRow && !found;idx++){

                    currentKeyCmd = getKey(m_RowIdTabVector.at(idx));
                    if (currentKeyCmd==keyCmd){
                        m_lastKeyPosition=idx;
                        found=true;

                    } else {
                        m_lastKeyPosition=0;
                    }
                }
                if (found) {
                    qDebug () << "Aggiorno Data balise";
                    QStringList stepList = command.split(INTERNAL_SEPARATOR);
                    QList <QStandardItem*> items;
                    foreach (QString item, stepList) {
                        items.push_back(new QStandardItem (item));
                    }
                    m_model->insertRow(m_lastKeyPosition,items);
                    m_model->removeRow(m_lastKeyPosition+1);
                    if (m_lastKeyPosition+1< m_model->rowCount()){
                        m_lastKeyPosition++;
                    }
                }

        } else {

            m_lastKeyPosition=0;
            qDebug () << "Command = "<< command << " row = " << rowTable;
            QStringList stepList = command.split(INTERNAL_SEPARATOR);
            qint32 sizeCommand = stepList.size();
            if (rowTable >=0 &&  rowTable< m_model->rowCount()) {
                QList <QStandardItem *> row;
                qint32 columnCount = m_model->columnCount();
                for (int idxColModel=0;idxColModel<columnCount;idxColModel++) {
                    m_model->item(rowTable,idxColModel)->setText("");
                    row.push_back( m_model->item(rowTable,idxColModel));
                }
                if (sizeCommand <= row.size()) {
                    for (int idx =0;idx <sizeCommand;idx++ ) {
                        if (nullptr != row[idx]){

                            qDebug () << "Valore in Tabella = " << row[idx]->text();
                            qDebug () << "Valore da Tab  = " << stepList.at(idx);

                            row[idx]->setText(stepList.at(idx));
                            row[idx]->setToolTip(stepList.at(idx));
                        }
                    }

                }
            }

        }

    }




    return true;
}


bool GraphicStepSequence::removeCommand(/*QString command, QString idTaab,*/ qint32 rowTable)
{
    bool ret = true;

    if ( rowTable>=0 && rowTable < m_model->rowCount() && rowTable < m_RowIdTabVector.size()){

        m_model->removeRow(rowTable);
            m_RowIdTabVector.removeAt(rowTable);
        if (0 == m_model->rowCount() ){
            m_model->setColumnCount(1);
            m_model->setHeaderData(0, Qt::Horizontal,QString ("%1_%2").arg(NAME_COLUMN,QString::number(0)));
        }

    }
    return true;


//    QStringList commandList = command.split(INTERNAL_SEPARATOR);
//    quint32 sizeCommand =commandList.size();
//    quint32 sizeRowModel = m_model->rowCount();
//    quint32 sizeColumn = m_model->columnCount();
//    QStandardItem *itemModel=nullptr;
//    bool found = false;
//    qint32 rowTodelete= -1;

//    if (sizeCommand <= sizeColumn){
//        for (quint32 idxRowModel=0; idxRowModel<sizeRowModel;idxRowModel++){


//            for (quint32  idxCommand=0;idxCommand < sizeCommand ;idxCommand++ ){
//                itemModel= m_model->item(idxRowModel,idxCommand);
//                if (itemModel != nullptr){
//                    QString itemModelText= itemModel->text();
//                    if (itemModelText == commandList.at(idxCommand)){
//                        found=true;
//                    } else {
//                        found=false;
//                        break;

//                    }
//                }
//            }
//            if (! found){
//                continue;
//            } else {
//                rowTodelete =idxRowModel;
//                break;
//            }

//        }

//        if (found){
//            qDebug () << "Delete Command at row = "<< rowTodelete;
//            m_model->removeRow(rowTodelete);
//            // m_rowCommandTab_map.remove(idxRowModel);
//            if (rowTodelete < m_RowIdTabVector.size()){

//                m_RowIdTabVector.removeAt(rowTodelete);
//            }


//            if (0 == m_model->rowCount() ){
//                m_model->setColumnCount(1);
//                m_model->setHeaderData(0, Qt::Horizontal,QString ("%1_%2").arg(NAME_COLUMN,QString::number(0)));
//            }
//        } else {
//            ret = false;
//            qDebug() << "Command not found in Step sequence";

//        }

//    } else {
//        ret = false;
//        qDebug() << "Number  columns of command are greater of internal table";


//    }

//    return ret;
}


void GraphicStepSequence::removeAll()
{
    qint32 numColumn = m_model->columnCount();
    while (m_model->rowCount() > 0)
    {
        //        for (int idxCol = 0 ;idxCol < numColumn; idxCol++ ) {
        //            auto item = m_model->itemFromIndex(m_model->index(0,idxCol));
        //            if (item != nullptr) {
        //                delete item;
        //            }
        //        }
        m_model->removeRow(0);

    }
    m_model->setColumnCount(1);
    m_model->setHeaderData(0, Qt::Horizontal,QString ("%1_%2").arg(NAME_COLUMN,QString::number(0)));
    this->m_rowCommandTab_map.clear();
    //  m_rowCommandTab_map.clear();
    m_RowIdTabVector.clear();

}
QString GraphicStepSequence::extractSignleValue(qint32 row,qint32 column)
{
    QString value="";
    QStandardItem *item=nullptr;
    item = m_model->item(row,column);
    if (item != nullptr) {
        value=item->text();
    }
    return value;
}

QString GraphicStepSequence::extractSignleRow(qint32 currentRow)
{
    QString row;
    qint32 numRow = m_model->rowCount();
    qint32 numColumn = m_model->columnCount();
    if (row < numRow){
        for (qint32 idxCol = 0 ; idxCol< numColumn;idxCol++){
            row+=extractSignleValue(currentRow,idxCol);
            if (idxCol < numColumn-1){
                row+=INTERNAL_SEPARATOR;
            }
        }

    }
    return row;
}
QVector<QString> GraphicStepSequence::extractAllRow()
{
    QVector<QString> allRow;
    qint32 sizeRowModel = m_model->rowCount();
    for (qint32 idxRow =0; idxRow <sizeRowModel;idxRow++ ){
        allRow.push_back(extractSignleRow(idxRow));
    }
    return allRow;

}
void GraphicStepSequence::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    QTableView::selectionChanged(selected, deselected);
    QModelIndex currentIndex = this->selectionModel()->currentIndex();
    qint32 rowSelected = currentIndex.row();
    qint32 numberClm= m_model->columnCount();
    qint64 keyBalise = -1;


//    qDebug () << selected;
//    qDebug () << deselected;
//    if (this->selectionModel()->selectedIndexes().size()> 0 )
//    {

//     qDebug () << this->selectionModel()->selectedIndexes().size();
//     qint16 newRowSelected = this->selectionModel()->selectedIndexes().at(0).row();
//     qDebug () << "New Selection = " << newRowSelected;
//    }

    qDebug () << "Evento Selected  Row = "<< rowSelected;
    if (m_RowIdTabVector.size()==0 ) {
        qDebug () << "size Vector = 0" ;
        return ;
    } else {
        if ( rowSelected >= 0 && rowSelected < m_RowIdTabVector.size() ){


            qDebug () << "Row selected " <<  rowSelected;
            qDebug () << "size Vector = " << m_RowIdTabVector.size();


            QString value=m_RowIdTabVector.at(rowSelected);
            qDebug () << "Valore  = " << value;


            for (int idxCol =0; idxCol <numberClm;idxCol++ ){
                QString item= extractSignleValue(rowSelected,idxCol);
                if (item != ""){
                    value+=INTERNAL_SEPARATOR+item;
                }
            }

            //qDebug () << "value = " << value;
            emit stepSelected_SG(value,rowSelected);
        }
    }
}

void GraphicStepSequence::mousePressEvent(QMouseEvent *ev)
{

    //   QTableView::mousePressEvent(ev);
    //    return;
    if ( ev->button()==Qt::LeftButton){
        this->setSelectionMode(QAbstractItemView::SingleSelection);
        this->setSelectionBehavior(QAbstractItemView::SelectRows);
        m_isActiveSelectionRow=true;
    } else if (ev->button()==Qt::RightButton){
        QModelIndex currentIndex = this->selectionModel()->currentIndex();
        this->selectionModel()->select(currentIndex, QItemSelectionModel::Clear);
        this->setSelectionMode(QAbstractItemView::NoSelection);
        this->setSelectionBehavior(QAbstractItemView::SelectRows);
        m_isActiveSelectionRow=false;
    }

    QTableView::mousePressEvent(ev);
}





}
