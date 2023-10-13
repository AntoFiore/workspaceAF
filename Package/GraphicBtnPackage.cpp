#include "GraphicBtnPackage.h"
#include <QDebug>
#include <QFont>
#include <QCheckBox>

namespace pkg {
GraphicBtnPackage::GraphicBtnPackage(QObject *parent) : QObject(parent)
{
    _currentFontSize=7;
    m_btnAtcWidget=nullptr;
    m_glBtn=nullptr;
    m_baseLine = baseline_unknow;
}

QWidget *GraphicBtnPackage::btnWidet()
{
    return m_btnAtcWidget;
}

void GraphicBtnPackage::setBtnWidet(QFrame *btnWidet)
{
    m_btnAtcWidget = btnWidet;
}

QWidget *GraphicBtnPackage::parent()
{
    return m_parent;
}

void GraphicBtnPackage::setParent(QWidget*parent)
{
    m_parent = parent;
}

int GraphicBtnPackage::numbBtn()
{
    return _buttonMap.size();
}

QAbstractButton *GraphicBtnPackage::btnById(qint32 idBtn)
{
    QAbstractButton *btn=nullptr;
    auto it = _buttonMap.find(idBtn);
    if (it != _buttonMap.end()) {
        btn=it.value();
    }
    return btn;
}

void GraphicBtnPackage::init(QWidget *parent)
{
    m_first = true;
    m_parent = parent;
    m_grpAction = new QButtonGroup(m_parent);
    m_grpAction->setExclusive(false);
    m_btnAtcWidget = new QWidget(m_parent);
    m_glBtn = new QGridLayout;
    m_btnAtcWidget->setLayout(m_glBtn);
    m_style = "QPushButton {background:rgb(160,160,160);color:rgb(0,0,0)}";


    connect(m_grpAction, SIGNAL(buttonToggled( int,bool)), this, SLOT(handleActionToggled_SL(qint32,bool)));
    connect(m_grpAction, SIGNAL(buttonPressed(int)),this ,SLOT(handleActionPush_SL(qint32)));
    m_isPressedBtn=false;
}

void GraphicBtnPackage::showButtons(bool show)
{
    QMapIterator<int, QAbstractButton *> it(_buttonMap);
    while (it.hasNext()) {
        it.next();
        if (it.value() != nullptr) {
            it.value()->setVisible(show);
        }
    }

}

void GraphicBtnPackage::setEnableBtn(qint32 idBtn,bool enable)
{
    QMapIterator<int, QAbstractButton *> it(_buttonMap);
    while (it.hasNext()) {
        it.next();
        if (it.value() != nullptr) {
            it.value()->setEnabled(enable);
        }
    }


}




void GraphicBtnPackage::setGraphicProperties(qint32 idBtn, GraphicPropeties_T prop)
{
    bool isFound = m_graphicPropetiesMap.contains(idBtn);
    if (isFound){
        m_graphicPropetiesMap[idBtn] =prop;



        QString style = "QPushButton {";

         style+= QString ("color:rgb(%1,%2,%3)").arg(QString::number(m_graphicPropetiesMap.value(idBtn).m_color.toRgb().red()),
                                                    QString::number(m_graphicPropetiesMap.value(idBtn).m_color.toRgb().green()),
                                                    QString::number(m_graphicPropetiesMap.value(idBtn).m_color.toRgb().blue()));
         style+=";";
         style+= QString ("background:rgb(%1,%2,%3)").arg(QString::number(m_graphicPropetiesMap.value(idBtn).m_backGroiund.toRgb().red()),
                                                    QString::number(m_graphicPropetiesMap.value(idBtn).m_backGroiund.toRgb().green()),
                                                    QString::number(m_graphicPropetiesMap.value(idBtn).m_backGroiund.toRgb().blue()));

          style+=";";
         style+=" }";

         isFound = _buttonMap.contains(idBtn);
         if (isFound){
             _buttonMap[idBtn]->setStyleSheet(style);
         }
    }



}

GraphicPropeties_T GraphicBtnPackage::graphicProperties(qint32 idBtn)
{
    bool isFound = m_graphicPropetiesMap.contains(idBtn);
    if (isFound){
        return  m_graphicPropetiesMap[idBtn];
    }
    return GraphicPropeties_T();


}



void GraphicBtnPackage::removeAllBtn()
{
    QMapIterator<int, QAbstractButton *> it(_buttonMap);
    while (it.hasNext()) {
        it.next();
        if (it.value() != nullptr) {
            delete it.value();
        }
    }
    _buttonMap.clear();
}

void GraphicBtnPackage::removeBtn(int idBtn)
{
    auto it = _buttonMap.find(idBtn);
    if (it != _buttonMap.end() ) {
        if (it.value() != nullptr) {
            delete it.value();
        }
        _buttonMap.remove(idBtn);
    }
}

int GraphicBtnPackage::currentFontSize() const
{
    return _currentFontSize;
}

void GraphicBtnPackage::setCurrentFontSize(int currentFontSize)
{
    _currentFontSize = currentFontSize;

    QMapIterator<int, QAbstractButton *> it(_buttonMap);
    while (it.hasNext()) {
        it.next();
        if (it.value() != nullptr) {
            QFont f= it.value()->font();
            f.setPixelSize(_currentFontSize);
            it.value()->setFont(f);

        }
    }

}

}
