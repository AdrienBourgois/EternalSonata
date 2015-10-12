#ifndef __SAVE_INCLUDE__
#define __SAVE_INCLUDE__

#include "myIrrlicht.h"

using namespace irr;

class SaveManager
{
public:
    SaveManager(const core::stringw& pathFile);
    ~SaveManager() = default;

    void setPathFile(const core::stringw& newPathFile) {this->pathFile = newPathFile;}
    //void savePlayer();
    bool loadPlayer();
    //void loadConfig();
    //void saveConfig();

    //core::stringw getStat(const core::stringw& key) const;
    //bool getStatAsBoolean(const core::stringw& key ) const;
    //s32 getStatAsInteger(const core::stringw& key) const;

private:
    IrrlichtDevice* NullDevice;
    io::IXMLReader* xmlReader;
    io::IXMLWriter* xmlWriter;
    core::stringw pathFile;

    core::map<core::stringw, core::stringw> PlayerMap;
    core::map<core::stringw, core::stringw> ConfigMap;
    core::map<core::stringw, core::stringw> KeyMap;
};

#endif
