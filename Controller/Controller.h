#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "ReadWriteConfigurationFile.h"
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    bool init_All();

signals:

private:

    bool init_MainWindow();
    bool init_CommandFile();

    MainWindow mMainWin;

   config::ReadWriteConfigurationFile  m_ReadConfigurationFile;

};

#endif // CONTROLLER_H
