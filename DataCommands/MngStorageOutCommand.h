#ifndef MNGSTORAGEOUTCOMMAND_H
#define MNGSTORAGEOUTCOMMAND_H

#include <QObject>
#include "StorageOutDataBaliseCommand.h"
namespace storageData{
class MngStorageOutCommand : public QObject
{
    Q_OBJECT
public:


     StorageOutDataBaliseCommand &storageBaliseCmd();

    static MngStorageOutCommand *istance();


signals:
private:
    explicit MngStorageOutCommand(QObject *parent = nullptr);
     static  MngStorageOutCommand* mIstance;

    StorageOutDataBaliseCommand mStorageBaliseCmd;

};
}

#endif // MNGSTORAGEOUTCOMMAND_H
