#ifndef EXPORTDATA_H
#define EXPORTDATA_H

#include <QObject>
#include <QVector>

namespace exportdata{
#define CSV_SEP  ";"
class ExportData : public QObject
{
    Q_OBJECT

public:
    explicit ExportData(QObject *parent = nullptr);
    bool goExport();
    void addData(void *data);
    int totData();
    void * data (int i);
    virtual ~ExportData() override  {}
    void setParent(QWidget*parent=nullptr) ;
    QWidget *parent() const;

signals:

protected:
    QString selectionPath();
    bool virtual exportData(QString path);

    QWidget *_parent;
    QVector <void *> _dataVect;

    QString _nameFileExport;
};
}

#endif // EXPORTDATA_H
