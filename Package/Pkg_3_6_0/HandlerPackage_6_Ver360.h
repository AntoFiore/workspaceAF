#ifndef HANDLERPACKAGE_6_VER360_H
#define HANDLERPACKAGE_6_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_6_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_6_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;
private slots:
    void showTVBC();

protected:
    virtual void loadPkg() override;

private:
    void showVariable();

    qint16 m_currCol;
    qint16 m_row ;

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_nidqVBCOVar;
    package::GraphicVariablePkg *m_nidVBCMKVar;
    package::GraphicVariablePkg *m_nidCVar;
    package::GraphicVariablePkg *m_TVBCVar;




};
}

#endif // HANDLERPACKAGE_6_VER360_H
