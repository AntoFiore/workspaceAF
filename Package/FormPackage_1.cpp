#include "FormPackage_1.h"
#include "ui_formpackage_1.h"

FormPackage_1::FormPackage_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPackage_1)
{
    ui->setupUi(this);
}

FormPackage_1::~FormPackage_1()
{
    delete ui;
}
