#ifndef HANDLERPACKAGE_79_VER340_H
#define HANDLERPACKAGE_79_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_79_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_79_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_ScaleVar;


    package::GraphicVariablePkg *m_qNewCountryVar;
    package::GraphicVariablePkg *m_NidCVar;
    package::GraphicVariablePkg *m_nidBgVar;
    package::GraphicVariablePkg *m_dPosOffVar;
    package::GraphicVariablePkg *m_qMPositionVar;
    package::GraphicVariablePkg *m_MPositionVar;

    package::GraphicVariablePkg *m_nIterVar;

private slots:

    void handleChangeIteration_SL();
    void handleChangeScaleVariable_SL(QString nameVariable);
    void handleChangeQ_NewCountryVariable_SL(QString nameVariable);
    void handleChangeQ_NewCountryIterVariable_SL(QString nameVariable);

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;



};
}

#endif // HANDLERPACKAGE_79_VER340_H
