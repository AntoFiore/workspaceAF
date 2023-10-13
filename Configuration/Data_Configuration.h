#ifndef DATA_CONFIGURATION_H
#define DATA_CONFIGURATION_H
#include <QMap>
#include <QString>
namespace config{
struct ItemConfiguration{

    QString m_nameTag;
    QMap <QString,QString> m_keyValueAttribMap;
};

struct ConfigurationFile {

   QVector <ItemConfiguration> m_configItems;
};

}
#endif // DATA_CONFIGURATION_H
