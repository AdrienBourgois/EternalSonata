#ifndef __XMLMANAGER_INCLUDE__
#define __XMLMANAGER_INCLUDE__

#include "myIrrlicht.h"

using namespace irr;

class PlayerManager
{
public:
    PlayerManager(const stringw& playerFilePath);
    bool load();
    bool save();

    setStat(const stringw& name, const stringw& value);
    setStat(const stringw& name, s32 value);

    getStat(const stringw& key) const;
    getSettingAsBoolean(const stringw& key ) const;

    getSettingAsInteger(const stringw& key) const;

    ~PlayerManager();

private:
    map<stringw, stringw> PlayerMap;

    stringw playerFilePath;
    IrrlichtDevice* NullDevice;
};

#endif
