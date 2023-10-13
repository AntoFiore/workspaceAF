#include "GraphicVariablePkg.h"
#include <QLineEdit>
#include <QFont>
#include <QDebug>
namespace package{
GraphicVariablePkg::GraphicVariablePkg(QFrame *parent)
    : QFrame{parent}
{
    m_nameVariableLbl=nullptr;
    m_typeVar=type_unknow;
    m_SpinBoxInt = nullptr;
    m_SpinBoxReal = nullptr;
    m_layout=nullptr;
    m_isOnlyRead = false;
    m_isItemIterate=false;
    m_tobeVisible =false;
    this->setVisible(false);

}

void GraphicVariablePkg::setResolution(qreal resolution)
{

    switch (m_typeVar) {
    case type_real:
    {


        QLineEdit* lineEdit = m_SpinBoxReal->findChild<QLineEdit*>();
        lineEdit->setReadOnly(true);
    }
        break;
    case type_integer:
    {
        m_SpinBoxInt->setSingleStep(static_cast<int>(resolution));
        QLineEdit* lineEdit = m_SpinBoxInt->findChild<QLineEdit*>();
        lineEdit->setReadOnly(true);
    }
        break;

    default:
        break;
    }

}

void GraphicVariablePkg::setRange(qreal min, qreal max)
{
     min = qMin(min,max);
    max = qMax(min,max);
    switch (m_typeVar) {
    case type_real:
        m_SpinBoxReal->setMaximum(max);
        m_SpinBoxReal->setMinimum(min);
        break;
    case type_integer:
        m_SpinBoxInt->setMaximum(static_cast <int>(max));
        m_SpinBoxInt->setMinimum(static_cast <int>(min));
        break;

    default:
        break;
    }

}

void GraphicVariablePkg::setStep(qreal step)
{
    switch (m_typeVar) {
    case type_real:
        m_SpinBoxReal->setSingleStep(step);
        break;
    case type_integer:
        m_SpinBoxInt->setSingleStep(static_cast<int>(step));
        break;

    default:
        break;
    }

}
void GraphicVariablePkg::setDefaultValue(QString defaultValue){

    switch (m_typeVar) {
    case type_real:
        m_SpinBoxReal->setValue(defaultValue.toDouble());
        break;
    case type_integer:
        m_SpinBoxInt->setValue(static_cast<int>(defaultValue.toInt()));
        break;
    case type_hexadecimal:
        m_line->setText(defaultValue);
     break;
    case type_text:
        m_line->setText(defaultValue);
     break;

    default:
        break;
    }

}
void GraphicVariablePkg::setDefaultValue(qreal defaultValue)
{
    switch (m_typeVar) {
    case type_real:
        m_SpinBoxReal->setValue(defaultValue);
        break;
    case type_integer:
        m_SpinBoxInt->setValue(static_cast<int>(defaultValue));
        break;
    case type_hexadecimal:
        m_line->setText("FFFFFFFFFFFFFFFF");
        break;

    default:
        break;
    }

}

QString GraphicVariablePkg::valueOfVariable()
{
    QString value;
    switch (m_typeVar) {
    case type_real:
        value=QString::number(m_SpinBoxReal->value());
        break;
    case type_integer:
         value=QString::number(m_SpinBoxInt->value());
        break;
    case type_hexadecimal:
        value = QString(m_line->text());
        break;
    case type_text:
        value = QString(m_line->text());
        break;
    default:
        break;
    }


    return value;
}

void GraphicVariablePkg::set_NID_PACKET(int NID)
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_PACKET");
    this->setRange(0, 255);
    this->setIsOnlyRead(true);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setDefaultValue(NID);
    this->m_variableBitSize = 8;
}

void GraphicVariablePkg::set_NID_C()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_C");
    this->setRange(0,1023);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 10;
}

void GraphicVariablePkg::set_NID_BG()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_BG");
    this->setRange(0,16383);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setDefaultValue(0);
    this->m_variableBitSize = 14;
}

void GraphicVariablePkg::set_NID_RIU()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_BG");
    this->setRange(0,16383);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setDefaultValue(0);
    this->m_variableBitSize = 14;
}

void GraphicVariablePkg::set_NID_RBC()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_RBC");
    this->setRange(0,16383);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setDefaultValue(0);
    this->m_variableBitSize = 14;
}

void GraphicVariablePkg::set_NID_NTC()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_NTC");
    this->setRange(0,255);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setDefaultValue(0);
    this->m_variableBitSize = 8;
}

void GraphicVariablePkg::set_NID_RADIO()
{
    // TODO
    this->init(GraphicVariablePkg::type_hexadecimal);
    this->setNameVariable("NID_RADIO");
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setDefaultValue("");
    this->m_variableBitSize = 64;
}


void GraphicVariablePkg::set_D_INFILL(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_INFILL");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;

}

void GraphicVariablePkg::set_Q_ASPECT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_ASPECT");
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_D_RBCTR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_RBCTR");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_Q_SLEEPSESSION()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_SLEEPSESSION");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_NID_LX(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_LX");
    this->setRange(0,255);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 8;

}

void GraphicVariablePkg::set_NID_VBCMK()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_VBCMK");
    this->setRange(0,63);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 6;
}

void GraphicVariablePkg::set_NID_TSR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_TSR");
    this->setRange(0,255);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 8;
}

void GraphicVariablePkg::set_A_NVMAXREDADH_X()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("A_NVMAXREDADH_X");
    this->setRange(0,63);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 6;
}

void GraphicVariablePkg::set_A_NVP_XX()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("A_NVP_XX");
    this->setRange(0,63);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 6;
}

void GraphicVariablePkg::set_D_LX(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_LX");
    this->setRange(0,32677);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;

}

void GraphicVariablePkg::set_D_TSR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_TSR");
    this->setRange(0,32677);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_L_LX(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_LX");
    this->setRange(0,127);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;

}

void GraphicVariablePkg::set_Q_LXSTATUS(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_LXSTATUS");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;

}

void GraphicVariablePkg::set_T_OL(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("T_OL");
    this->setRange(0,1023);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 10;
}

void GraphicVariablePkg::set_D_OL(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_OL");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_VALIDNV()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_VALIDNV");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_NVROLL()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_NVROLL");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_NVOVTRP()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_NVOVTRP");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_NVPOTRP()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_NVPOTRP");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_NVSTFF()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_NVSTFF");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_STARTOL(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_STARTOL");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_Q_OVERLAP(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_OVERLAP");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;

}

void GraphicVariablePkg::set_V_RELEASEDP(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_RELEASEDP");
    this->setRange(0,127);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_RELEASEOL(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_RELEASEOL");
    this->setRange(0,127);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;

}

void GraphicVariablePkg::set_D_ENDTIMERSTARTLOC(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_ENDTIMERSTARTLOC");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_T_ENDTIME(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("T_ENDTIME");
    this->setRange(0,1023);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 10;
}

void GraphicVariablePkg::set_Q_ENDTIMER(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_ENDTIME");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_D_DP(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_DP");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_Q_DANGERPOINT(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_DANGERPOINT");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_NVSBTSMPERM() {
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NVSBTSMPERM");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_NVEMRRLS() {
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NVEMRRLS");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_NVGUIPERM() {
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NVGUIPERM");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_NVSBFBPERM() {
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NVSBFBPERM");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_NVINHSMICPERM()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NVINHSMICPERM");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_NVDRIVER_ADHES()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NVDRIVER_ADHES");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_NVLOCACC()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NVLOCACC");
    this->setRange(0,63);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 6;
}

void GraphicVariablePkg::set_Q_NVKINT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NVKINT");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_NVKVINTSET()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NVKVINTSET");
    this->setRange(0,3);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 2;
}

void GraphicVariablePkg::set_L_ENDSECTION(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_ENDSECTION");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_SECTIONTIMERSTOPLOC()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_SECTIONTIMERSTOPLOC");
    this->setRange(0,32677);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_T_SECTIONTIMER(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("T_SECTIONTIMER");
    this->setRange(0,1023);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 10;
}

void GraphicVariablePkg::set_Q_SECTIONTIMER(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_SECTIONTIMER");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_L_SECTION(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_SECTION");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_T_EMA(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("T_EMA");
    this->setRange(0,1023);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 10;
}

void GraphicVariablePkg::set_V_EMA(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_EMA");
    this->setRange(0,127);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_LX(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_LX");
    this->setRange(0,127);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;

}

void GraphicVariablePkg::set_Q_STOPLX(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_STOPLX");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;

}

void GraphicVariablePkg::set_L_STOPLX(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_STOPLX");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;

}

void GraphicVariablePkg::set_D_AXLELOAD()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_AXLELOAD");
    this->setRange(0,16383);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 14;
}

void GraphicVariablePkg::set_D_SR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_SR");
    this->setRange(0,32767);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_TRACKINIT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_TRACKINIT");
    this->setRange(0,32767);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_PBD()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_PBD");
    this->setRange(0,32767);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_PBDSR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_PBDSR");
    this->setRange(0,32767);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_G_PBDSR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("G_PBDSR");
    this->setRange(0,255);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 8;
}

void GraphicVariablePkg::set_G_TSR(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("G_TSR");
    this->setRange(0,255);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 8;

}

void GraphicVariablePkg::set_Q_GDIR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_GDIR");
    this->setRange(0,1);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_PBDSR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_PBDSR");
    this->setRange(0,1);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_DIR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_DIR");
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setRange(0,3);
    this->setDefaultValue(0);
    this->m_variableBitSize = 2;
}

void GraphicVariablePkg::set_L_PACKET(int range_min, int range_max)
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_PACKET");
    this->setIsOnlyRead(true);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setRange(range_min,range_max);
    this->setDefaultValue(range_min);
    this->m_variableBitSize = 13;
}

void GraphicVariablePkg::set_L_AXLELOAD()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_AXLELOAD");
    this->setRange(0,32768);
    this->setDefaultValue(0);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_L_PBDSR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_PBDSR");
    this->setRange(0,32768);
    this->setDefaultValue(0);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_Q_SCALE()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_SCALE");
    this->setRange(0,3);
    this->setDefaultValue(0);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 2;
}

void GraphicVariablePkg::set_Q_TRACKINIT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_TRACKINIT");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_FRONT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_FRONT");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_D_LINK()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_LINK");
    this->setRange(0,32768);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_Q_NEWCOUNTRY()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_NEWCOUNTRY");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_N_ITER()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("N_ITER");
    this->setRange(0,31);
    this->setDefaultValue(0);
    this->setVisible(false);
    this->setTobeVisible(true);
    this->m_variableBitSize = 5;
}


void GraphicVariablePkg::set_D_STATIC()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_STATIC");
    this->setRange(0,32768);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_D_TEXTDISPLAY()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_TEXTDISPLAY");
    this->setRange(0,32768);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_V_STATIC()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_STATIC");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_NVSHUNT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_NVSHUNT");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_NVSTFF()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_NVSTFF");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_NVONSIGHT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_NVONSIGHT");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_NVLIMSUPERV()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_NVLIMSUPERV");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_NVUNFIT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_NVUNFIT");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_NVREL()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_NVREL");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_NVALLOWOVTRP()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_NVALLOWOVTRP");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_NVSUPOVTRP()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_NVSUPOVTRP");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_V_NVKVINT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_NVKVINT");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_Q_DIFF()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_DIFF");
    this->setRange(0,4);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 2;
}

void GraphicVariablePkg::set_Q_RIU()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_RIU");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_NC_CDDIFF()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NC_CDDIFF");
    this->setRange(0,15);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 4;
}

void GraphicVariablePkg::set_X_TEXT()
{
    this->init(GraphicVariablePkg::type_text);
    this->setNameVariable("X_TEXT");
    this->setRange(0,255);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 0;
}

void GraphicVariablePkg::set_NID_MN()
{
    this->init(GraphicVariablePkg::type_hexadecimal);
    this->setNameVariable("NID_MN");
    this->setVisible(false);
    this->setTobeVisible(true);
    this->setDefaultValue("");
    QString inputMask_nid_radio = ">HHHHHH;x";
    m_line->setInputMask(inputMask_nid_radio);
    m_line->setText("FFFFFF");

    this->m_variableBitSize = 6;
}

void GraphicVariablePkg::set_NC_DIFF()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NC_DIFF");
    this->setRange(0,15);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 4;
}

void GraphicVariablePkg::set_V_DIFF()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_DIFF");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}


void GraphicVariablePkg::set_NID_LOOP()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_LOOP");
    this->setRange(0,16384);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 14;
}

void GraphicVariablePkg::set_NID_OPERATIONAL(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_OPERATIONAL");
    this->setRange(0,4294967295);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 32;

}

void GraphicVariablePkg::set_NID_TEXTMESSAGE()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("NID_TEXTMESSAGE");
    this->setRange(0,255);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 8;
}

void GraphicVariablePkg::set_D_REVERSE(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_REVERSE");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;

}

void GraphicVariablePkg::set_V_REVERSE(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("V_REVERSE");
    this->setRange(0,127);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;

}

void GraphicVariablePkg::set_D_LOOP()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_LOOP");
    this->setRange(0,32780);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_L_LOOP()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_LOOP");
    this->setRange(0,32780);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_L_TEXTDISPLAY()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_TEXTDISPLAY");
    this->setRange(0,32780);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_L_TEXT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_TEXT");
    this->setRange(0,255);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 8;
}

void GraphicVariablePkg::set_L_TSR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_TSR");
    this->setRange(0,32677);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;
}

void GraphicVariablePkg::set_L_NVKRINT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_NVKRINT");
    this->setRange(0,31);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 5;
}

void GraphicVariablePkg::set_M_VERSION()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_VERSION");
    this->setRange(0,63);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_M_MODETEXTDISPLAY()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_MODETEXTDISPLAY");
    this->setRange(0,15);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 4;
}

void GraphicVariablePkg::set_M_LEVELTEXTDISPLAY()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_LEVELTEXTDISPLAY");
    this->setRange(0,7);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 3;
}

void GraphicVariablePkg::set_M_NVCONTACT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_NVCONTACT");
    this->setRange(0,3);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 2;
}

void GraphicVariablePkg::set_M_NVDERUN()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_NVDERUN");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_M_NVAVADH()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_NVAVADH");
    this->setRange(0,32);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 5;
}

void GraphicVariablePkg::set_M_NVEBCL()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_NVEBCL");
    this->setRange(0,15);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 4;
}

void GraphicVariablePkg::set_M_NVKVINT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_NVKVINT");
    this->setRange(0,128);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 7;
}

void GraphicVariablePkg::set_M_NVKRINT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_NVKRINT");
    this->setRange(0,31);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 5;
}

void GraphicVariablePkg::set_M_NVKTINT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("M_NVKTINT");
    this->setRange(0,31);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 5;
}

void GraphicVariablePkg::set_Q_LOOPDIR()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_LOOPDIR");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_SSCODE()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_SSCODE");
    this->setRange(0,15);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 4;
}

void GraphicVariablePkg::set_Q_SRSTOP(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_SRSTOP");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_TEXTCLASS()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_TEXTCLASS");
    this->setRange(0,3);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 2;
}

void GraphicVariablePkg::set_Q_TEXTDISPLAY()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_TEXTDISPLAY");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_TEXTCONFIRM()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_TEXTCONFIRM");
    this->setRange(0,3);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 2;
}

void GraphicVariablePkg::set_Q_TEXTREPORT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_TEXTREPORT");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_Q_CONFTEXTDISPLAY()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("Q_CONFTEXTDISPLAY");
    this->setRange(0,1);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 1;
}

void GraphicVariablePkg::set_T_TEXTDISPLAY()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("T_TEXTDISPLAY");
    this->setRange(0,1023);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 10;
}

void GraphicVariablePkg::set_T_NVOVTRP()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("T_NVOVTRP");
    this->setRange(0,1023);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 10;
}

void GraphicVariablePkg::set_T_NVCONTACT()
{
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("T_NVCONTACT");
    this->setRange(0,255);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 8;
}

void GraphicVariablePkg::set_D_STARTREVERSE(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("D_STARTREVERSE");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;

}

void GraphicVariablePkg::set_L_REVERSEAREA(){
    this->init(GraphicVariablePkg::type_integer);
    this->setNameVariable("L_REVERSEAREA");
    this->setRange(0,32767);
    this->setDefaultValue(0);
    this->setTobeVisible(true);
    this->setVisible(false);
    this->m_variableBitSize = 15;

}

void GraphicVariablePkg::init(Type_Variale typeVar)
{

    m_layout = new QGridLayout;
    setLayout(m_layout);
    m_nameVariableLbl = new QLabel (this);
    m_layout->addWidget(m_nameVariableLbl);
    m_layout->setContentsMargins(1,1,1,1);
    m_layout->setMargin(2);
    m_typeVar=typeVar;
    QString style = QString ("QAbstractSpinBox {selection-background-color:%1;selection-color:%2}").arg(BACK_SELECTION_COLOR_SPIN,SELECTION_COLOR_SPIN);

    QAbstractSpinBox * spinBox=nullptr;
    switch (typeVar) {
    case type_real:
    {
        m_SpinBoxReal = new QDoubleSpinBox(this);
        spinBox=m_SpinBoxReal;
        m_layout->addWidget(m_SpinBoxReal);
        connect (m_SpinBoxReal,QOverload<double>::of(&QDoubleSpinBox::valueChanged),[this] (double value) {
            emit updateData_SG();
            emit nameInernalVariable_SG(m_internalName);
         });
        break;
    }
    case type_integer:
    {
        m_SpinBoxInt = new QSpinBox(this);
        m_layout->addWidget(m_SpinBoxInt);
        spinBox=m_SpinBoxInt;
        connect (m_SpinBoxInt,QOverload<int>::of(&QSpinBox::valueChanged),[this] (int value) {
            emit updateData_SG();
            emit nameInernalVariable_SG(m_internalName);
         });
        break;
    }
    case type_hexadecimal: {
        m_line = new QLineEdit(this);
        QString inputMask_nid_radio = ">HHHHHHHHHHHHHHHH;x";
        m_line->setInputMask(inputMask_nid_radio);
        m_line->setText("FFFFFFFFFFFFFFFF");
        m_layout->addWidget(m_line);
        spinBox = m_SpinBoxInt;
        connect (m_line,&QLineEdit::textChanged,[this] (QString value) {
            emit updateData_SG();
            emit nameInernalVariable_SG(m_internalName);
        });
        break;
    }
    case type_text: {
        m_line = new QLineEdit(this);
        m_line->setText("");
        m_layout->addWidget(m_line);
        spinBox = m_SpinBoxInt;
        connect (m_line,&QLineEdit::textChanged,[this] (QString value) {
            emit updateData_SG();
            emit nameInernalVariable_SG(m_internalName);
        });
        break;
    }
    default:
        break;
    }
    QFont font ;
    if (spinBox != nullptr){
        spinBox->setStyleSheet(style);
        spinBox->setMinimumHeight(HEIGHT_SPIN);
        spinBox->setMaximumHeight(HEIGHT_SPIN);
        font =spinBox->font();
        font.setPixelSize(FONT_SIZE_VARIABLE);
        spinBox->setFont(font);
    }

    font =m_nameVariableLbl->font();
    font.setPixelSize(FONT_SIZE_VARIABLE);
    m_nameVariableLbl->setFont(font);

    this->setFrameShape(QFrame::Box);
    m_nameVariableLbl->setMinimumHeight(HEIGHT_LBL);
    m_nameVariableLbl->setMaximumHeight(HEIGHT_LBL);
    this->setMinimumHeight(HEIGHT_PKG);
    this->setMaximumHeight(HEIGHT_PKG);
    this->setMinimumWidth(WIDTH_PKG);
    this->setMaximumWidth(WIDTH_PKG);


    m_scale = -1;


}

void GraphicVariablePkg::setNameVariable(QString nameVar)
{
    if (m_nameVariableLbl != nullptr) {
        m_nameVariableLbl->setText(nameVar);
    }

}

qreal GraphicVariablePkg::scale() const
{
    return m_scale;
}

void GraphicVariablePkg::setScale(qreal newScale)
{
    m_scale = newScale;
}

bool GraphicVariablePkg::isOnlyRead() const
{
    return m_isOnlyRead;
}

void GraphicVariablePkg::setIsOnlyRead(bool newIsOnlyRead)
{
    m_isOnlyRead = newIsOnlyRead;


    QAbstractSpinBox * spinBox=nullptr;
    switch (m_typeVar) {
    case type_real:
    {
        spinBox=m_SpinBoxReal;
    }
        break;
    case type_integer:
    {
        spinBox=m_SpinBoxInt;

    }
        break;
    default:
        break;
    }
    if (spinBox != nullptr){
        spinBox->setReadOnly(newIsOnlyRead);
    }

}

bool GraphicVariablePkg::isItemIterate() const
{
    return m_isItemIterate;
}

void GraphicVariablePkg::setIsItemIterate(bool newIsItemIterate)
{
    m_isItemIterate = newIsItemIterate;
}

QString &GraphicVariablePkg::internalName()
{
    return m_internalName;
}

void GraphicVariablePkg::setInternalName( QString &newInternalName)
{
    m_internalName = newInternalName;
}

bool GraphicVariablePkg::tobeVisible() const
{
    return m_tobeVisible;
}

void GraphicVariablePkg::setTobeVisible(bool newTobeVisible)
{
    m_tobeVisible = newTobeVisible;
}

qint16 GraphicVariablePkg::variableBitSize() const
{
    return m_variableBitSize;
}

void GraphicVariablePkg::setVariableBitSize(qint16 newVariableBitSize)
{
    m_variableBitSize = newVariableBitSize;
}
}
