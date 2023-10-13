#ifndef HANDLERPACKAGE_5_VER340_H
#define HANDLERPACKAGE_5_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_5_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_5_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;
private slots:
    void show_nidC();
    void show_nidC_k();
    void handleIterateVariable_SL(QString nameVariable);
    void handleChangeIteration_SL();
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
    package::GraphicVariablePkg *m_dLinkVar;
    package::GraphicVariablePkg *m_qNewcountryVar;
    package::GraphicVariablePkg *m_nidCVar;
    package::GraphicVariablePkg *m_qLinkorientationVar;
    package::GraphicVariablePkg *m_nidBGVar;
    package::GraphicVariablePkg *m_qLinkreactionVar;
    package::GraphicVariablePkg *m_qLocaccVar;
    package::GraphicVariablePkg *m_nIterVar;

    package::GraphicVariablePkg *m_dLinkVar_k;
    package::GraphicVariablePkg *m_qNewcountryVar_k;
    package::GraphicVariablePkg *m_nidCVar_k;
    package::GraphicVariablePkg *m_qLinkorientationVar_k;
    package::GraphicVariablePkg *m_nidBGVar_k;
    package::GraphicVariablePkg *m_qLinkreactionVar_k;
    package::GraphicVariablePkg *m_qLocaccVar_k;
    package::GraphicVariablePkg *m_nIterVar_k;




};
}

#endif // HANDLERPACKAGE_5_VER340_H
