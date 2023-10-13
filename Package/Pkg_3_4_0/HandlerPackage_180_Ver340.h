#ifndef HANDLERPACKAGE_180_VER340_H
#define HANDLERPACKAGE_180_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_180_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_180_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;

    package::GraphicVariablePkg *m_qLssmaVar;
    package::GraphicVariablePkg *m_tLssmaVar;

private slots:
    void show_qLssma_SL();

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;

};
}

#endif // HANDLERPACKAGE_180_VER340_H
