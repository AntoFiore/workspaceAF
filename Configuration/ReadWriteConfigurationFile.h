#ifndef READWRITE_CONFIGURATION_FILE_H
#define READWRITE_CONFIGURATION_FILE_H
#include <QString>
#include <QWidget>

namespace config{
class ReadWriteConfigurationFile : public QWidget
{
    Q_OBJECT
public:
    explicit ReadWriteConfigurationFile(QWidget *parent = 0);
    
    QString nameConfigFile() const;
    void setPathFileCommands(QString namePathCommands);
    bool loadCommandsFile();
    bool loadConfigFile();

    bool updateConfigFile();

signals:
    
public slots:

private:
    QString m_namePathCommands;
    
};
}

#endif // READWRITE_CONFIGURATION_FILE_H
