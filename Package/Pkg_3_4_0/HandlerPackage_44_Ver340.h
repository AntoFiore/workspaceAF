#ifndef HANDLERPACKAGE_44_VER340_H
#define HANDLERPACKAGE_44_VER340_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_44_Ver340 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_44_Ver340(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

protected:
    virtual void loadPkg() override;
private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_NidXUserVar;
    package::GraphicVariablePkg *m_NidNtcVar;
private slots:
    void showNid_Ntc_SL();
private:
    void showVariable();
    qint16 m_currCol;
    qint16 m_row ;




};
}

#endif // HANDLERPACKAGE_44_VER340_H
