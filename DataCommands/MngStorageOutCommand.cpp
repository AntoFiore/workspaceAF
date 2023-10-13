#include "MngStorageOutCommand.h"
namespace storageData{
MngStorageOutCommand* MngStorageOutCommand::mIstance;
MngStorageOutCommand::MngStorageOutCommand(QObject *parent)
    : QObject{parent}
{

}

StorageOutDataBaliseCommand &MngStorageOutCommand::storageBaliseCmd()
{
    return mStorageBaliseCmd;
}

MngStorageOutCommand *MngStorageOutCommand::istance()
{
    if (mIstance == nullptr)
    {
        mIstance = new MngStorageOutCommand;
    }

    return mIstance;

}
}
