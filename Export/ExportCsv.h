#ifndef EXPORTCSV_H
#define EXPORTCSV_H

#include <QObject>
#include "ExportData.h"


namespace exportdata{
/*
const QVector <QString> Header = {DETAIL_INFO_PARTNUM_COLUMN,
                                 DETAIL_INFO_SERNUM_COLUMN,
                                 DETAIL_INFO_PROGRAM_COLUMN,
                                 DETAIL_INFO_TESTNAME_COLUMN,
                                 DETAIL_INFO_STATION_COLUMN,
                                 DETAIL_INFO_MEASURE_COLUMN,
                                 DETAIL_INFO_TYPETEST_COLUMN,
                                 DETAIL_INFO_BEGINDATE_COLUMN,
                                 DETAIL_INFO_ENDDATE_COLUMN,
                                 DETAIL_INFO_RESULT_COLUMN,
                                 DETAIL_INFO_TRACEFILE_COLUMN,
                                 //DETAIL_INFO_IDGRAPH_COLUMN, // spostata in coda
                                 DETAIL_INFO_MIN_COLUMN,
                                 DETAIL_INFO_MAX_COLUMN,
                                 DETAIL_INFO_AVG_COLUMN,
                                 DETAIL_INFO_VAR_COLUMN,
                                 DETAIL_INFO_STDDEV_COLUMN,
                                 DETAIL_INFO_IDGRAPH_COLUMN
                                 };
const QVector<QString> Header_Time_Coordinates = {INFO_TIME,
                                 INFO_VALUE};
const QVector<QString> Header_Freq_Coordinates = {INFO_FFT_X,
                                 INFO_VALUE};

const QString ID_NEWPLOT = QString ("%1NEWPLOT%2").arg(FIELD_SEPARATOR,FIELD_SEPARATOR);
*/
class ExportCsv : public ExportData
{
public:
     ExportCsv(QObject *parent = nullptr);
     bool virtual exportData(QString path) override;
     ~ExportCsv() override;

signals:

private:



};
}

#endif // ExportCsv_H
