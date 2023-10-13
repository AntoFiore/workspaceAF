#ifndef HANDLERPACKAGE_21_VER340_H
#define HANDLERPACKAGE_21_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_21_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_21_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_dGradientVar;
    package::GraphicVariablePkg *m_qGdirVar;
    package::GraphicVariablePkg *m_GAVar;

    package::GraphicVariablePkg *m_nIterVar;

    /* elementi usati nella iterazione */
    package::GraphicVariablePkg *m_dGradient_k_Var;
    package::GraphicVariablePkg *m_qGdir_k_Var;
    package::GraphicVariablePkg *m_GA_k_Var;

private slots:
    void handleChangeIteration_SL();

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;

};
}

#endif // HANDLERPACKAGE_21_VER340_H
