#ifndef GRAPHICVARIABLEPKG_H
#define GRAPHICVARIABLEPKG_H

#include <QObject>
#include <QFrame>

#include <QLabel>
#include<QSpinBox>
#include <QDoubleSpinBox>
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QString>

#define HEIGHT_TOLL 10
#define HEIGHT_SPIN 26
#define HEIGHT_LBL 21
#define FONT_SIZE_VARIABLE 12
#define HEIGHT_PKG HEIGHT_SPIN+HEIGHT_SPIN+HEIGHT_TOLL
#define WIDTH_PKG 150
#define BACK_SELECTION_COLOR_SPIN "rgb(255, 255, 255)"
#define SELECTION_COLOR_SPIN "rgb(0, 0, 0)"

namespace package{


class GraphicVariablePkg : public QFrame
{
    Q_OBJECT
public:
    explicit GraphicVariablePkg(QFrame *parent = nullptr);
    void setResolution (qreal resolution);
    void setRange (qreal min,qreal max);
    void setStep (qreal step);
    void setDefaultValue(qreal defaultValue);
    QString valueOfVariable();
     void setDefaultValue(QString defaultValue);

    void set_NID_PACKET(int NID);
    void set_NID_C();
    void set_NID_BG();
    void set_NID_RIU();
    void set_NID_RBC();
    void set_NID_NTC();
    void set_NID_RADIO();
    void set_NID_LOOP();
    void set_NID_OPERATIONAL();
    void set_NID_TEXTMESSAGE();
    void set_NID_LX();
    void set_NID_VBCMK();
    void set_NID_TSR();

    void set_A_NVMAXREDADH_X();
    void set_A_NVP_XX();

    void set_D_AXLELOAD();
    void set_D_SR();
    void set_D_TRACKINIT();
    void set_D_PBD();
    void set_D_STARTREVERSE();
    void set_D_REVERSE();
    void set_D_LOOP();
    void set_D_PBDSR();
    void set_D_STATIC();
    void set_D_TEXTDISPLAY();
    void set_D_INFILL();
    void set_D_RBCTR();
    void set_D_LX();
    void set_D_TSR();
    void set_D_SECTIONTIMERSTOPLOC();
    void set_D_DP();
    void set_Q_ENDTIMER();
    void set_Q_OVERLAP();
    void set_D_ENDTIMERSTARTLOC();
    void set_D_STARTOL();
    void set_D_OL();
    void set_D_VALIDNV();
    void set_D_NVROLL();
    void set_D_NVOVTRP();
    void set_D_NVPOTRP();
    void set_D_NVSTFF();

    void set_G_PBDSR();
    void set_G_TSR();

    void set_L_LX();
    void set_L_SECTION();
    void set_L_ENDSECTION();
    void set_L_STOPLX();
    void set_L_REVERSEAREA();
    void set_L_PACKET(int range_min, int range_max = 8191);
    void set_L_AXLELOAD();
    void set_L_PBDSR();
    void set_L_LOOP();
    void set_L_TEXTDISPLAY();
    void set_L_TEXT();
    void set_L_TSR();
    void set_L_NVKRINT();

    void set_M_VERSION();
    void set_M_MODETEXTDISPLAY();
    void set_M_LEVELTEXTDISPLAY();
    void set_M_NVCONTACT();
    void set_M_NVDERUN();
    void set_M_NVAVADH();
    void set_M_NVEBCL();
    void set_M_NVKVINT();
    void set_M_NVKRINT();
    void set_M_NVKTINT();

    void set_N_ITER();

    void set_Q_DIR();
    void set_D_LINK();
    void set_Q_NEWCOUNTRY();
    void set_Q_SCALE();
    void set_Q_TRACKINIT();
    void set_Q_FRONT();
    void set_Q_GDIR();
    void set_Q_PBDSR();
    void set_Q_DIFF();
    void set_Q_RIU();
    void set_Q_SSCODE();
    void set_Q_LOOPDIR();    
    void set_Q_SRSTOP();
    void set_Q_TEXTCLASS();
    void set_Q_TEXTDISPLAY();
    void set_Q_TEXTCONFIRM();
    void set_Q_TEXTREPORT();
    void set_Q_CONFTEXTDISPLAY();
    void set_Q_ASPECT();
    void set_Q_SLEEPSESSION();
    void set_Q_STOPLX();
    void set_Q_LXSTATUS();
    void set_Q_SECTIONTIMER();
    void set_Q_DANGERPOINT();
    void set_Q_NVSBTSMPERM();
    void set_Q_NVEMRRLS();
    void set_Q_NVGUIPERM();
    void set_Q_NVSBFBPERM();
    void set_Q_NVINHSMICPERM();
    void set_Q_NVDRIVER_ADHES();
    void set_Q_NVLOCACC();
    void set_Q_NVKINT();
    void set_Q_NVKVINTSET();

    void set_T_EMA();
    void set_T_SECTIONTIMER();
    void set_T_ENDTIME();
    void set_T_OL();
    void set_T_TEXTDISPLAY();
    void set_T_NVOVTRP();
    void set_T_NVCONTACT();

    void set_V_LX();
    void set_V_RELEASEDP();
    void set_V_EMA();
    void set_V_RELEASEOL();
    void set_V_REVERSE();
    void set_V_DIFF();
    void set_V_STATIC();
    void set_V_NVSHUNT();
    void set_V_NVSTFF();
    void set_V_NVONSIGHT();
    void set_V_NVLIMSUPERV();
    void set_V_NVUNFIT();
    void set_V_NVREL();
    void set_V_NVALLOWOVTRP();
    void set_V_NVSUPOVTRP();
    void set_V_NVKVINT();

    void set_NC_DIFF();
    void set_NC_CDDIFF();

    void set_X_TEXT();

    void set_NID_MN();

    enum Type_Variale{
        type_unknow,
        type_real,
        type_integer,
        type_hexadecimal,
        type_text
    };

    void init (Type_Variale typeVar = type_unknow);
    void setNameVariable(QString nameVar);

    qreal scale() const;
    void setScale(qreal newScale);

    bool isOnlyRead() const;
    void setIsOnlyRead(bool newIsOnlyRead=false);

    bool isItemIterate() const;
    void setIsItemIterate(bool newIsItemIterate);

     QString &internalName() ;
    void setInternalName(QString &newInternalName);

    bool tobeVisible() const;
    void setTobeVisible(bool newTobeVisible);

    qint16 variableBitSize() const;
    void setVariableBitSize(qint16 newVariableBitSize);


signals:

    void updateData_SG();
    void nameInernalVariable_SG(QString);

private:
    QLabel *m_nameVariableLbl;
    QSpinBox *m_SpinBoxInt;
    QDoubleSpinBox* m_SpinBoxReal;
    QLineEdit *m_line;

    QGridLayout *m_layout;
    qreal m_scale;
    bool m_isOnlyRead;
    QString m_internalName;
    bool m_isItemIterate;
    qint16 m_variableBitSize;

    Type_Variale m_typeVar;
    bool m_tobeVisible;


};
}

#endif // GRAPHICVARIABLEPKG_H
