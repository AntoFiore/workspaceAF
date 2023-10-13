#ifndef HANDLERPACKAGE_0_VER360_H
#define HANDLERPACKAGE_0_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_0_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_0_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

protected:
    virtual void loadPkg() override;

private:
    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row;

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_nidVBCMKVar;

};
}

#endif // HANDLERPACKAGE_2_VER360_H
