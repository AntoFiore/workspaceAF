#ifndef GRAPHICBTNPACKAGE_H
#define GRAPHICBTNPACKAGE_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QFrame>
#include <QMap>
#include "Define.h"

namespace pkg {

struct GraphicPropeties_T {
    QColor m_color;
    QColor m_backGroiund;

};


class GraphicBtnPackage : public QObject
{
    Q_OBJECT

public:
    explicit GraphicBtnPackage(QObject *parent = nullptr);

    QWidget *btnWidet() ;
    void setBtnWidet(QFrame *btnWidet);

    QWidget *parent() ;
    void setParent(QWidget *parent);
    int numbBtn();

    QAbstractButton *btnById(qint32 idBtn);

    virtual void addAction(QString text,  int actBtnId )=0;

    int currentFontSize() const;
    void setCurrentFontSize(int currentFontSize);

    void removeAllBtn();
    void removeBtn(int idBtn);
    virtual void init(QWidget *parent=nullptr);
    virtual void makeSizeBtn(){}
    virtual void rearrange(){}
    void showButtons (bool show);
    void setEnableBtn (qint32 idBtn, bool enable);


    void setGraphicProperties(qint32 idBtn,GraphicPropeties_T prop);
     GraphicPropeties_T graphicProperties(qint32 idBtn);

signals:
    void btnAction_SG(int,bool );

    void pkgAndBaseLine_SG(qint16 pkg);

public slots:

protected slots:
    virtual void handleActionToggled_SL (qint32 idAction,bool)=0;
    virtual void handleActionPush_SL (qint32 idAction)=0;

protected:
    QWidget          *m_btnAtcWidget;
    QWidget         *m_parent;
    QGridLayout     *m_glBtn;
    QButtonGroup    *m_grpAction;
    QMap<qint32,QAbstractButton*> _buttonMap;
    QMap<qint32,GraphicPropeties_T> m_graphicPropetiesMap;
    bool            m_isPressedBtn;
    qint32             _currentFontSize;
    qint32 m_row;
    qint32 m_column;
     bool m_first;
     QString m_style;

     BaseLine m_baseLine;



    QVector <qint32> m_package;
};
}
#endif // GRAPHICBTNPACKAGE_H
