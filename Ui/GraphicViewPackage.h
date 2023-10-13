#ifndef GRAPHICVIEWPACKAGE_H
#define GRAPHICVIEWPACKAGE_H

#include <QFrame>
#include <QStandardItemModel>

namespace Ui {
class GraphicViewPackage;
}

class GraphicViewPackage : public QFrame
{
    Q_OBJECT

public:
    explicit GraphicViewPackage(QWidget *parent = nullptr);
     bool init();
    ~GraphicViewPackage();

     void setModel(QStandardItemModel *newModel);

     qint64 keyPkt() const;
     void setKeyPkt(qint64 newKeyPkt);


     quint32 currentIdPkg() const;
     void setCurrentIdPkg(quint32 newCurrentIdPkg);
     QString getPackage() ;

     const QString &pkg() const;
     void setPkg(const QString &newPkg);

signals:
     void deleteMe_SG (qint32);
     void updateMe_SG (qint32);

private:
    Ui::GraphicViewPackage *ui;


    QStandardItemModel *m_model;
    QString m_pkg;
    quint32 m_currentIdPkg;

    qint64 m_keyPkt;
};

#endif // GRAPHICVIEWPACKAGE_H
