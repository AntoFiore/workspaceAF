#ifndef HANDLERPACKAGE_65_VER340_H
#define HANDLERPACKAGE_65_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_65_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_65_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private slots:

protected:
    virtual void loadPkg() override;

private:
    void showVariable();
    qint16 m_currCol;
    qint16 m_row ;

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;
    package::GraphicVariablePkg *m_nidTSRVar;
    package::GraphicVariablePkg *m_dTSRVar;
    package::GraphicVariablePkg *m_lTSRVar;
    package::GraphicVariablePkg *m_qFrontVar;
    package::GraphicVariablePkg *m_vTSRVar;

};
}

#endif // HANDLERPACKAGE_65_VER340_H
