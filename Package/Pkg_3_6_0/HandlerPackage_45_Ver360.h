#ifndef HANDLERPACKAGE_45_VER360_H
#define HANDLERPACKAGE_45_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_45_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_45_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;
protected:
virtual void loadPkg() override;
private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_Nid_MnVar;

    void showVariable();
    qint16 m_currCol;
    qint16 m_row ;




};
}

#endif // HANDLERPACKAGE_45_VER360_H
