#ifndef GRAPHICSTEPSEQUENCE_H
#define GRAPHICSTEPSEQUENCE_H

#include <QTableView>
#include <QStandardItemModel>
#include <QMap>
#include <QVector>
#include <QEvent>
namespace hndcommand{
class GraphicStepSequence : public QTableView
{
    Q_OBJECT
public:
    explicit GraphicStepSequence(QWidget *parent = nullptr);
     bool init();

    bool insertCommand(QString step, QString idTab);
    bool removeCommand(qint32 rowTable);
    QVector<QString> extractAllRow();
    void removeAll();
    bool updateCommand(QString command, qint32 rowTable, QString tabAndKey="");
signals:
    void stepSelected_SG (QString,qint32);
protected:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected) override;
    void mousePressEvent(QMouseEvent *ev) override;

private:


    QString extractSignleValue(qint32 row,qint32 column);
    QString extractSignleRow(qint32 currentRow);
     QStandardItemModel *m_model;
     QMap<qint32,QString> m_rowCommandTab_map;
    QVector <QString> m_RowIdTabVector;
    bool m_isActiveSelectionRow;
    qint64 m_lastKey;
    qint16 m_lastKeyPosition;


    qint64 getKey(QString field);
};
}

#endif // GRAPHICSTEPSEQUENCE_H
