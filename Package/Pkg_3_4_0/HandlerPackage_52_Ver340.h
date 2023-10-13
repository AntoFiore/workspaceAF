#ifndef HANDLERPACKAGE_52_VER340_H
#define HANDLERPACKAGE_52_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_52_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_52_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_qTrackinitVar;
    package::GraphicVariablePkg *m_dTrackinitVar;

    package::GraphicVariablePkg *m_dPBDVar;
    package::GraphicVariablePkg *m_qGdirVar;
    package::GraphicVariablePkg *m_gPBDSRVar;
    package::GraphicVariablePkg *m_qPBDSRVar;
    package::GraphicVariablePkg *m_dPBDSRVar;
    package::GraphicVariablePkg *m_lPBDSRVar;

    package::GraphicVariablePkg *m_nIter_k_Var;
    /* elementi usati nella iterazione */
    package::GraphicVariablePkg *m_dPBD_k_Var;
    package::GraphicVariablePkg *m_qGdir_k_Var;
    package::GraphicVariablePkg *m_gPBDSR_k_Var;
    package::GraphicVariablePkg *m_qPBDSR_k_Var;
    package::GraphicVariablePkg *m_dPBDSR_k_Var;
    package::GraphicVariablePkg *m_lPBDSR_k_Var;

private slots:
    void show_qTrackinit_SL();

    void handleChangeIteration_k_SL();

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;



};
}

#endif // HANDLERPACKAGE_51_VER340_H
