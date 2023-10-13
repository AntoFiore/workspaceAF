#include "GraphicTitlePkg.h"
namespace package{
GraphicTitlePkg::GraphicTitlePkg(QFrame *parent)
    : QFrame{parent}
{
    m_nameTitltePkgLbl=nullptr;
    m_layout=nullptr;


}

void GraphicTitlePkg::init(QString namePackage)
{

    m_layout = new QGridLayout;
    setLayout(m_layout);
    m_nameTitltePkgLbl = new QLabel (namePackage,this);
    m_layout->addWidget(m_nameTitltePkgLbl);
    m_layout->setContentsMargins(1,1,1,1);
    m_layout->setMargin(2);

    QFont font = m_nameTitltePkgLbl->font();
    font.setBold(true);
    font.setPixelSize(FONT_SIZE_TITLE);
    m_nameTitltePkgLbl->setFont(font);


    this->setFrameShape(QFrame::Box);
    m_nameTitltePkgLbl->setMinimumHeight(HEIGHT_TITLE_LBL);
    m_nameTitltePkgLbl->setMaximumHeight(HEIGHT_TITLE_LBL);
    this->setMinimumHeight(HEIGHT_TITLE);
    this->setMaximumHeight(HEIGHT_TITLE);
    this->setMaximumWidth(WIDTH_TITLE);
    this->setMinimumWidth(WIDTH_TITLE);





}

void GraphicTitlePkg::setTitlePkg(QString title)
{
    if (m_nameTitltePkgLbl != nullptr) {
        m_nameTitltePkgLbl->setText(title);
    }

}
}
