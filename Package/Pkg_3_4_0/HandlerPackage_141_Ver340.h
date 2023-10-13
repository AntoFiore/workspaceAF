#ifndef HANDLERPACKAGE_141_VER340_H
#define HANDLERPACKAGE_141_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_141_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_141_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;

    package::GraphicVariablePkg *m_qGdirVar;
    package::GraphicVariablePkg *m_gTsrVar;


private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;



};
}

#endif // HANDLERPACKAGE_12_VER340_H