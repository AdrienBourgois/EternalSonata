#ifndef __XMLMANAGER_INCLUDE__
#define __XMLMANAGER_INCLUDE__

#include <map>
#include "myIrrlicht.h"

using namespace irr;

class PlayerManager
{
public:
    PlayerManager(const core::stringw& playerFilePath);
    bool load();
    bool save();

    void setStat(const core::stringw& name, const core::stringw& value);
    void setStat(const core::stringw& name, s32 value);

    core::stringw getStat(const core::stringw& key) const;
    bool getStatAsBoolean(const core::stringw& key ) const;

    s32 getStatAsInteger(const core::stringw& key) const;

    ~PlayerManager();

private:
    core::map<core::stringw, core::stringw> PlayerMap;

    core::stringw playerFilePath;
    IrrlichtDevice* NullDevice;
};

#endif
