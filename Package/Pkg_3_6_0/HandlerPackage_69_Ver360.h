#ifndef HANDLERPACKAGE_69_VER360_H
#define HANDLERPACKAGE_69_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_69_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_69_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_ScaleVar;


    package::GraphicVariablePkg *m_qTrackInitVar;
    package::GraphicVariablePkg *m_dTrackInitVar;
    package::GraphicVariablePkg *m_dTrackCondVar;

    package::GraphicVariablePkg *m_lTrackCondVar;
    package::GraphicVariablePkg *m_mPlatformVar;
    package::GraphicVariablePkg *m_qPlatformVar;




    package::GraphicVariablePkg *m_nIterVar;



private slots:

    void handleChangeIteration_SL();
    void handleChangeScaleVariable_SL(QString nameVariable);
    void handleChangeQ_TrackInitVariable_SL(QString nameVariable);

private:
    void showVariable();

    qint16 m_currentIteration;
    qint16 m_currCol;
    qint16 m_row ;
protected:
    void loadPkg() override;



};
}

#endif // HANDLERPACKAGE_69_VER360_H
