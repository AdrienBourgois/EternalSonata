#ifndef __SAVE_INCLUDE__
#define __SAVE_INCLUDE__

#include <map>
#include "Armor.h"
#include "myIrrlicht.h"
#include "Hero.h"
#include "Weapon.h"

using namespace irr;

class SaveManager
{
public:
    SaveManager(const core::stringw& pathFile);
    SaveManager() = default;
    ~SaveManager() = default;

    void setPathFile(const core::stringw& newPathFile) {this->pathFile = newPathFile;}
    void savePlayer(Hero);
    Hero loadPlayer(Hero&);
    void loadArmorPiece(Armor_Piece&);
    //void loadConfig();
    //void saveConfig();

private:
    IrrlichtDevice* NullDevice;
    io::IXMLReader* xmlReader;
    io::IXMLWriter* xmlWriter;
    core::stringw pathFile;

    core::map<core::stringw, core::stringw> ConfigMap;
    core::map<core::stringw, core::stringw> KeyMap;
};

#endif
