#ifndef HANDLERPACKAGE_72_VER340_H
#define HANDLERPACKAGE_72_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_72_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_72_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;

    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_qTextclassVar;
    package::GraphicVariablePkg *m_qTextdisplayVar;
    package::GraphicVariablePkg *m_dTextdisplayVar;
    package::GraphicVariablePkg *m_mModeltextdisplay_1_Var;
    package::GraphicVariablePkg *m_mLeveltextdisplay_1_Var;
    package::GraphicVariablePkg *m_nidNtc_1_Var;

    package::GraphicVariablePkg *m_lTextdisplayVar;
    package::GraphicVariablePkg *m_tTextdisplayVar;
    package::GraphicVariablePkg *m_mModeltextdisplay_2_Var;
    package::GraphicVariablePkg *m_mLeveltextdisplay_2_Var;
    package::GraphicVariablePkg *m_nidNtc_2_Var;

    package::GraphicVariablePkg *m_qTextconfirmVar;
    package::GraphicVariablePkg *m_qConftextdisplayVar;
    package::GraphicVariablePkg *m_qTextreportVar;
    package::GraphicVariablePkg *m_nidTextmessageVar;
    package::GraphicVariablePkg *m_nidCVar;
    package::GraphicVariablePkg *m_nidRBCVar;

    package::GraphicVariablePkg *m_lTextVar;
    package::GraphicVariablePkg *m_xTextVar;

private slots:
    void show_nidNtc_1_SL();
    void show_nidNtc_2_SL();
    void show_qTextConfirm_SL();

    void update_text_SL();

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;

};
}

#endif // HANDLERPACKAGE_57_VER340_H
