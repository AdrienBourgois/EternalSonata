#include <iostream>
#include "myIrrlicht.h"
#include "Save.h"

using namespace irr;

SaveManager::SaveManager(const core::stringw& savePathFile)
{
    pathFile = savePathFile;
    NullDevice = createDevice(irr::video::EDT_NULL);
}

Hero SaveManager::loadPlayer()
{
    Hero player;

    core::map<core::stringc, core::stringc> PlayerMap;

    xmlReader = NullDevice->getFileSystem()->createXMLReader(pathFile);

    PlayerMap.insert(L"agility", L"0");
    PlayerMap.insert(L"dexterity", L"0");
    PlayerMap.insert(L"intelligence", L"0");
    PlayerMap.insert(L"luck", L"0");
    PlayerMap.insert(L"name", L"");
    PlayerMap.insert(L"resistance", L"0");
    PlayerMap.insert(L"speed", L"0");
    PlayerMap.insert(L"spirit", L"0");
    PlayerMap.insert(L"strength", L"0");
    
    if (!NullDevice)
    {
        std::cout << "Any device !" << std::endl;
        return player;
    }

    const core::stringw statTag(L"stat");
    core::stringw currentSection;
    const core::stringw playerTag(L"player");

    while (xmlReader->read())
    {
        switch (xmlReader->getNodeType())
        {
            case io::EXN_ELEMENT:
            {
                if (currentSection.empty() && playerTag.equals_ignore_case(xmlReader->getNodeName()))
                    currentSection = playerTag;

                else if (currentSection.equals_ignore_case(playerTag) && statTag.equals_ignore_case(xmlReader->getNodeName() ))
                {
                    core::stringw key = xmlReader->getAttributeValueSafe(L"name");
                    if(!key.empty())
                        PlayerMap[key] = xmlReader->getAttributeValueSafe(L"value");
                }
            }break;

            case io::EXN_ELEMENT_END:
                currentSection = L"";
            break;

            default:
            break;
        }
    }

    player.setAgility       (core::strtol10((PlayerMap.find(L"agility")->getValue()).c_str()));
    player.setDexterity     (core::strtol10((PlayerMap.find(L"dexterity")->getValue()).c_str()));
    player.setIntelligence  (core::strtol10((PlayerMap.find("intelligence")->getValue()).c_str()));
    player.setLuck          (core::strtol10((PlayerMap.find("luck")->getValue()).c_str()));
    player.setName          ((PlayerMap.find("name")->getValue()).c_str());
    player.setResistance    (core::strtol10((PlayerMap.find("resistance")->getValue()).c_str()));
    player.setSpeed         (core::strtol10((PlayerMap.find("speed")->getValue()).c_str()));
    player.setSpirit        (core::strtol10((PlayerMap.find("spirit")->getValue()).c_str()));
    player.setStrength      (core::strtol10((PlayerMap.find("strength")->getValue()).c_str()));

    player.debugCharacter();

    std::cout << "File loaded" << std::endl;
    return player;
}

//core::stringw SaveManager::getStat(const core::stringw& key) const
//{
//    core::map<core::stringw, core::stringw>::Node* n = PlayerMap.find(key);
//    if (n)
//        return n->getValue();
//    else
//        return L"";
//}
//
//bool SaveManager::getStatAsBoolean(const core::stringw& key ) const
//{
//    core::stringw s = getStat(key);
//    if (s.empty())
//        return false;
//    return s.equals_ignore_case(L"1");
//}
//
//s32 SaveManager::getStatAsInteger(const core::stringw& key) const
//{
//    const core::stringc s = getStat(key);
//    if (s.empty())
//        return 0;
//    
//    return core::strtol10(s.c_str());
//}

/*void SaveManager::savePlayer()
{
    xmlReader = NullDevice->getFileSystem()->createXMLReader(pathFile);

}*/
