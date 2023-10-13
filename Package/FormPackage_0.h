#ifndef FORMPACKAGE_0_H
#define FORMPACKAGE_0_H

#include <QFrame>
#include <QString>
#include <QStandardItem>
namespace Ui {
class FormPackage_0;
}

class FormPackage_0 : public QFrame
{
    Q_OBJECT

public:
    explicit FormPackage_0(QWidget *parent = nullptr);
    bool init();
    QString pkg();
    bool isValid();


    ~FormPackage_0();

    QStandardItemModel *model() const;

    void setPkg(const QString &newPkg);

private:
    Ui::FormPackage_0 *ui;
    QStandardItemModel *m_model;
    qint16 m_idPkg;
    QString m_pkg;
};

#endif // FORMPACKAGE_0_H
