#ifndef HANDLERPACKAGE_12_VER360_H
#define HANDLERPACKAGE_12_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_12_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_12_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_vMainVar;
    package::GraphicVariablePkg *m_vEmaVar;
    package::GraphicVariablePkg *m_tEmaVar;

    package::GraphicVariablePkg *m_nIterVar;

    package::GraphicVariablePkg *m_lEndSectionVar;
    package::GraphicVariablePkg *m_qSectionTimerVar;
    package::GraphicVariablePkg *m_tSectionTimerVar;
    package::GraphicVariablePkg *m_dSectionTimerStopLocVar;

    package::GraphicVariablePkg *m_qEndTimerVar;
    package::GraphicVariablePkg *m_tEndTimerVar;
    package::GraphicVariablePkg *m_dEndTimerStartLocVar;

    package::GraphicVariablePkg *m_qDangerPointVar;
    package::GraphicVariablePkg *m_dDpVar;
    package::GraphicVariablePkg *m_vReleaseDpVar;

    package::GraphicVariablePkg *m_qOverlapVar;
    package::GraphicVariablePkg *m_dStartOLVar;
    package::GraphicVariablePkg *m_tOLVar;
    package::GraphicVariablePkg *m_dOLVar;
    package::GraphicVariablePkg *m_vReleaseOLVar;

private slots:
    void show_qSectionTimer_SL();
    void show_qEndTimer_SL();
    void show_qDangerPoint_SL();
    void show_qOverlap_SL();

    void handleChangeIteration_SL();
    void handleIterateVariable_SL(QString nameVariable);

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;



};
}

#endif // HANDLERPACKAGE_12_VER360_H
