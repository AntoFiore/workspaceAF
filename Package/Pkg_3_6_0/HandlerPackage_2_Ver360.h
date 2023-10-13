#ifndef HANDLERPACKAGE_2_VER360_H
#define HANDLERPACKAGE_2_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_2_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_2_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

protected:
    virtual void loadPkg() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_versionVar;




};
}

#endif // HANDLERPACKAGE_2_VER360_H
