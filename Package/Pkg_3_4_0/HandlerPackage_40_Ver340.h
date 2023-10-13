#ifndef HANDLERPACKAGE_40_VER340_H
#define HANDLERPACKAGE_40_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_40_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_40_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;
    package::GraphicVariablePkg *m_dCurrent;
    package::GraphicVariablePkg *m_mCurrent;
protected:
    void loadPkg() override;
private slots:


private:
    void showVariable();
    qint16 m_currCol;
    qint16 m_row ;


};
}

#endif // HANDLERPACKAGE_2_VER340_H
