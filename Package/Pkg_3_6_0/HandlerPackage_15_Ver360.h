#ifndef HANDLERPACKAGE_15_VER360_H
#define HANDLERPACKAGE_15_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_15_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_15_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_vEmaVar;
    package::GraphicVariablePkg *m_tEmaVar;

    package::GraphicVariablePkg *m_nIterVar;

    package::GraphicVariablePkg *m_lEndsectionVar;
    package::GraphicVariablePkg *m_qSectiontimerVar;
    package::GraphicVariablePkg *m_tSectiontimerVar;
    package::GraphicVariablePkg *m_dSectiontimerstoplocVar;
    package::GraphicVariablePkg *m_qEndtimerVar;
    package::GraphicVariablePkg *m_tEndtimerVar;
    package::GraphicVariablePkg *m_dEndtimerstartlocVar;
    package::GraphicVariablePkg *m_qDangerpointVar;
    package::GraphicVariablePkg *m_dDpVar;
    package::GraphicVariablePkg *m_vReleasedpVar;
    package::GraphicVariablePkg *m_qOverlapVar;
    package::GraphicVariablePkg *m_dStartolVar;
    package::GraphicVariablePkg *m_tOlVar;
    package::GraphicVariablePkg *m_dOlVar;
    package::GraphicVariablePkg *m_vReleaseolVar;


    /* elementi usati nella iterazione */

    package::GraphicVariablePkg *m_lSection_n_Var;
    package::GraphicVariablePkg *m_qSectiontimer_n_Var;
    package::GraphicVariablePkg *m_tSectiontimer_n_Var;
    package::GraphicVariablePkg *m_dSectiontierstoploc_n_Var;

private slots:
    void handleChangeIteration_SL();
    void show_SECTION_SL();
    void show_ENDTIMER_SL();
    void show_DP_SL();
    void show_OL_SL();
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

#endif // HANDLERPACKAGE_15_VER360_H
