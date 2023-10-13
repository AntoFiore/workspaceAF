#ifndef HANDLERPACKAGE_42_VER360_H
#define HANDLERPACKAGE_42_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_42_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_42_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

protected:
    virtual void loadPkg() override;
private:
    void showVariable();
    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qRbcVar;
    package::GraphicVariablePkg *m_nidCVar;
    package::GraphicVariablePkg *m_nidRbcVar;
    package::GraphicVariablePkg *m_nidRadioVar;
    package::GraphicVariablePkg *m_SleepSessionVar;

    qint16 m_currCol;
    qint16 m_row ;

private slots:




};
}

#endif // HANDLERPACKAGE_42_VER360_H
