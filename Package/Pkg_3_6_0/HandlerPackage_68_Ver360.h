#ifndef HANDLERPACKAGE_68_VER360_H
#define HANDLERPACKAGE_68_VER360_H

#include <HandlerPackage.h>
#include <QObject>
#include "GraphicVariablePkg.h"

namespace package {
class HandlerPackage_68_Ver360 : public HandlerPackage
{
    Q_OBJECT
public:
    explicit HandlerPackage_68_Ver360(QObject *parent = nullptr);

    virtual bool creteView() override;
    virtual bool saveData()  override;
    virtual void deleteView() override;
    enum VariablePkg_E {
        nid_packet,
        q_dir,
        l_packet,
        q_scale,
        q_trackinit,
        d_trackinit,
        d_trackcond,
        l_trackcond,
        m_trackcond,
        n_iter,
        iteration_var,

    };

private:

    package::GraphicVariablePkg *m_nidPkgVar;
    package::GraphicVariablePkg *m_qDirVar;
    package::GraphicVariablePkg *m_lenPkgVar;
    package::GraphicVariablePkg *m_ScaleVar;


    package::GraphicVariablePkg *m_qTrackInitVar;
    package::GraphicVariablePkg *m_dTrackInitVar;

    package::GraphicVariablePkg *m_dTrackCondVar;
    package::GraphicVariablePkg *m_lTrackCondVar;
    package::GraphicVariablePkg *m_mTrackCondVar;
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

#endif // HANDLERPACKAGE_68_VER360_H
