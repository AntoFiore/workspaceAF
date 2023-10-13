#ifndef HANDLERPACKAGE_88_VER360_H
#define HANDLERPACKAGE_88_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_88_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_88_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;

    package::GraphicVariablePkg *m_qScaleVar;
    package::GraphicVariablePkg *m_nidLxVar;
    package::GraphicVariablePkg *m_dLxVar;
    package::GraphicVariablePkg *m_lLxVar;
    package::GraphicVariablePkg *m_qLxstatusVar;
    package::GraphicVariablePkg *m_vLxVar;
    package::GraphicVariablePkg *m_qStoplxVar;
    package::GraphicVariablePkg *m_lStoplxVar;

private slots:
    void show_VLX_QSTOPLX_SL();
    void show_LSTOPLX_SL();

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
