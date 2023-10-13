#ifndef HANDLERPACKAGE_39_VER360_H
#define HANDLERPACKAGE_39_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_39_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_39_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

protected:
    virtual void loadPkg() override;

private slots:
    void showNidCtraction();

private:
    void showVariable();
    qint16 m_currCol;
    qint16 m_row;

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_qScaleVar;

    package::GraphicVariablePkg *m_dTractionVar;
    package::GraphicVariablePkg *m_mVoltageVar;
    package::GraphicVariablePkg *m_nidCtractionVar;

};
}

#endif // HANDLERPACKAGE_39_VER360_H
