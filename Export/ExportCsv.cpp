#include "ExportCsv.h"
#include <QVariant>
#include <Define.h>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>
namespace exportdata{
ExportCsv::ExportCsv(QObject *parent) :ExportData(parent)
{
}

bool ExportCsv::exportData(QString path)
{
    bool ret = true;
    QFile file(path);
    ret=file.open(QIODevice::WriteOnly | QIODevice::Text);

    int step_number = 1;

    if (ret) {
        QTextStream out(&file);

        //TODO Intestazione varie
        /*
         *      SCN_TC_5.20.7.2_01
         *      Rev. 0.0
         *  Step    Distanza progressiva (m) 	Ente	Informazione acquisita
         */

        QString scenario_name = QString().append(CSV_SEP).append( QFileInfo(path).completeBaseName() );
        QString revision_number = QString().append(CSV_SEP).append("Rev. 0.0");
        QString name_columns = QString().append("Step")
                .append(CSV_SEP).append("Distanza progressiva (m)")
                .append(CSV_SEP).append("Ente")
                .append(CSV_SEP).append("Informazione acquisita");

        out << scenario_name << endl;
        out << revision_number << endl;
        out << name_columns << endl;
        out << CSV_SEP << endl;    // write empty line

        foreach (auto item , _dataVect){
            if (item != nullptr) {
                QString row = reinterpret_cast<QVariant*>(item)->toString();
                row.replace(INTERNAL_SEPARATOR,CSV_SEP);
                row.replace(INTERNAL_SEPARATOR_PKG,CSV_SEP);
                row.replace(INTERNAL_FIELD_SEPARATOR_PKG,CSV_SEP);

                // Add step number in rows
                row.prepend(QString::number(step_number) + CSV_SEP);
                step_number++;
                out << row << endl;
            }
        }
        file.close();
    } else {
        qDebug () << " Export  error. : " << path;
        ret = false;
    }
    return ret;
}

ExportCsv::~ExportCsv()
{   
    foreach (auto item, _dataVect){
        if (item != nullptr){
            delete (reinterpret_cast<QVariant*>(item));
        }
    }
    _dataVect.clear();
}

}
