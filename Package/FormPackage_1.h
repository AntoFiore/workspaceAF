#ifndef FORMPACKAGE_1_H
#define FORMPACKAGE_1_H

#include <QWidget>

namespace Ui {
class FormPackage_1;
}

class FormPackage_1 : public QWidget
{
    Q_OBJECT

public:
    explicit FormPackage_1(QWidget *parent = nullptr);
    ~FormPackage_1();

private:
    Ui::FormPackage_1 *ui;
};

#endif // FORMPACKAGE_1_H
