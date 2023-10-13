#ifndef HANDLERPACKAGE_64_VER360_H
#define HANDLERPACKAGE_64_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_64_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_64_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private slots:

protected:
    virtual void loadPkg() override;

private:
    void showVariable();
    qint16 m_currCol;
    qint16 m_row ;

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;


};
}

#endif // HANDLERPACKAGE_64_VER360_H
