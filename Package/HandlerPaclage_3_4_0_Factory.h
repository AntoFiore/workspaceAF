#ifndef HANDLERPACLAGE_3_4_0_FACTORY_H
#define HANDLERPACLAGE_3_4_0_FACTORY_H

#include <QObject>
#include "HandlerPackage.h"

namespace package{


class HandlerPaclage_3_4_0_Factory : public QObject
{
    Q_OBJECT
public:
    explicit HandlerPaclage_3_4_0_Factory(QObject *parent = nullptr);
    static HandlerPackage * createHandlerPackage (qint16 idPkg);

signals:

};
}
#endif // HANDLERPACLAGE_3_4_0_FACTORY_H
