#include "ExportData.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include "Define.h"
namespace exportdata{
ExportData::ExportData(QObject *parent) : QObject(parent)
{
    _parent=nullptr;

}

QString ExportData::selectionPath()
{

    QString fileName = QFileDialog::getSaveFileName(parent(),
                                                    tr ("Export Scenario"),
                                                    ".",
                                                    "*.csv",
                                                    nullptr,
                                                    QFileDialog::HideNameFilterDetails);
    return fileName;

}

bool ExportData::goExport()
{
    bool result = false;
    QString path = selectionPath();
    if (path.size() == 0) {
        return true;
    }

    result = exportData(path);
    if (result) {
        QMessageBox::information(parent(),EXPORT_TITLE,EXPORT_OK);
    } else {
        QMessageBox::critical(parent(),EXPORT_TITLE,EXPORT_KO);
    }
    return result;
}

void ExportData::addData(void *data)
{
    _dataVect.push_back(data);
}

int ExportData::totData()
{
    return _dataVect.size();
}

void * ExportData::data(int i)
{
    if (i >=0 && i < _dataVect.size() )
    {
        return _dataVect[i];
    }
    return nullptr;
}


void ExportData::setParent(QWidget *parent)
{
    _parent=parent;
}

bool ExportData::exportData(QString path)
{
    Q_UNUSED(path)
    return true;
}
QWidget *ExportData::parent() const
{
    return _parent;
}
}
