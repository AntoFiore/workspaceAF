#include "GraphicBtnPackage_BL_3_2_0.h"
#include <QPushButton>
#include <QFont>
#include <QDebug>
#include <QLabel>
#include "Define.h"
namespace pkg{
GraphicBtnPackage_BL_3_2_0::GraphicBtnPackage_BL_3_2_0(QObject *parent)
    : GraphicBtnPackage{parent}
{

}

void GraphicBtnPackage_BL_3_2_0::init(QWidget *parent)
{


    m_baseLine = baseline_320;
    GraphicBtnPackage::init(parent);
    m_package.push_back(2);
    m_package.push_back(3);
    m_package.push_back(5);
    m_package.push_back(6);
    m_package.push_back(12);
    m_package.push_back(15);
    m_package.push_back(16);
    m_package.push_back(21);
    m_package.push_back(27);
    m_package.push_back(39);
    m_package.push_back(41);
    m_package.push_back(42);
    m_package.push_back(44);
    m_package.push_back(45);
    m_package.push_back(46);
    m_package.push_back(49);
    m_package.push_back(51);
    m_package.push_back(57);
    m_package.push_back(58);
    m_package.push_back(63);
    m_package.push_back(65);
    m_package.push_back(66);
    m_package.push_back(67);
    m_package.push_back(68);
    m_package.push_back(70);
    m_package.push_back(71);
    m_package.push_back(72);
    m_package.push_back(79);
    m_package.push_back(80);
    m_package.push_back(90);
    m_package.push_back(131);
    m_package.push_back(132);
    m_package.push_back(133);
    m_package.push_back(134);
    m_package.push_back(135);
    m_package.push_back(136);
    m_package.push_back(137);
    m_package.push_back(138);
    m_package.push_back(139);
    m_package.push_back(140);
    m_package.push_back(141);
    m_package.push_back(145);
    m_package.push_back(200);
    m_package.push_back(206);
    m_package.push_back(207);
    m_package.push_back(239);
    m_package.push_back(254);

    m_row=0;
    m_column=0;

    GraphicPropeties_T propGraphic;
    propGraphic.m_backGroiund=defaultBackColorBL_3_2_0;
    propGraphic.m_color=defaultColorBL_3_2_0;

    foreach (qint32 idpkg, m_package) {
        addAction(QString::number(idpkg),idpkg);
        setGraphicProperties(idpkg,propGraphic);


    }

}

void GraphicBtnPackage_BL_3_2_0::addAction(QString text, int actBtnId)
{
    if (m_first){
        m_first = false;
        QLabel *bl_label = new QLabel ("BL 1",m_parent);
        m_glBtn->addWidget(bl_label,m_row,m_column);
        auto font =bl_label->font();
        font.setPixelSize(11);
        font.setBold(true);
        bl_label->setFont(font);
        bl_label->setMinimumSize(25,25);
        bl_label->setMaximumSize(25,25);
        m_column++;

    }

    QAbstractButton *btn = new QPushButton(m_parent);
    btn->setText(text);
    btn->setToolTip(text);
    auto font = btn->font();
    font.setPixelSize(9);
    btn->setMinimumSize(25,25);
    btn->setMaximumSize(25,25);
    btn->setStyleSheet(m_style);

    btn->setFont(font);
     _buttonMap.insert(actBtnId,btn);
     m_glBtn->addWidget(btn,m_row,m_column);
     m_grpAction->addButton(btn,actBtnId);
     m_column++;

     GraphicPropeties_T grProp;
     grProp.m_color=defaultColorBL_3_2_0;
     grProp.m_backGroiund=defaultBackColorBL_3_2_0;

    m_graphicPropetiesMap.insert(actBtnId,grProp);

}
void GraphicBtnPackage_BL_3_2_0::handleActionToggled_SL(int idAction, bool checked)
{
    Q_UNUSED(idAction)
    Q_UNUSED(checked)

    qDebug () << "handleActionToggled_SL";
}

void GraphicBtnPackage_BL_3_2_0::handleActionPush_SL(int idAction)
{
    emit pkgAndBaseLine_SG (idAction);

}

}
