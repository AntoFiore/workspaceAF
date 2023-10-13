#ifndef GRAPHICTITLEPKG_H
#define GRAPHICTITLEPKG_H

#include <QObject>
#include <QFrame>

#include <QLabel>
#include<QSpinBox>
#include <QDoubleSpinBox>
#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QString>

#define HEIGHT_TITLE_TOLL 10
#define HEIGHT_TITLE_LBL 31
#define FONT_SIZE_TITLE 14
#define HEIGHT_TITLE HEIGHT_TITLE_LBL+HEIGHT_TITLE_TOLL
#define WIDTH_TITLE 150


namespace package{
class GraphicTitlePkg : public QFrame
{
    Q_OBJECT
public:
    explicit GraphicTitlePkg(QFrame *parent = nullptr);


    void setTitlePkg(QString nameVar);

    void init(QString namePackage);
signals:
private:
    QLabel *m_nameTitltePkgLbl;
    QGridLayout *m_layout;


};
}

#endif // GRAPHICTITLEPKG_H
