#include <iostream>
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
    Armor armor;
    Weapon weapon;

    Armor_Piece head   = armor.getHead(); 
    Armor_Piece torso  = armor.getTorso(); 
    Armor_Piece pants  = armor.getPants(); 
    Armor_Piece boots  = armor.getBoots(); 
    Armor_Piece gloves = armor.getGloves(); 

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
    const core::stringw armorTag(L"armor");
    const core::stringw weaponTag(L"weapon");

    core::stringc armorPieceName;
    core::stringc armorPiecePd;
    core::stringc armorPieceMd;
    core::stringc weaponName;
    core::stringc weaponDamage;

    while (xmlReader->read())
    {
        switch (xmlReader->getNodeType())
        {
            case io::EXN_ELEMENT:
            {
                if (playerTag.equals_ignore_case(xmlReader->getNodeName()))
                    currentSection = L"player";
                else if (armorTag.equals_ignore_case(xmlReader->getNodeName()))
                    currentSection = L"armor";
                else if (weaponTag.equals_ignore_case(xmlReader->getNodeName()))
                    currentSection = L"weapon";

                if (currentSection.equals_ignore_case(playerTag))
                {
                    core::stringw key = xmlReader->getAttributeValueSafe(L"name");
                    if(!key.empty())
                        PlayerMap[key] = xmlReader->getAttributeValueSafe(L"value");
                }

                else if (currentSection.equals_ignore_case(armorTag))
                {
                    if (((core::stringw)"head").equals_ignore_case(xmlReader->getNodeName()))
                    {
                        armorPieceName = xmlReader->getAttributeValueSafe(L"name");
                        armorPiecePd = xmlReader->getAttributeValueSafe(L"pd");
                        armorPieceMd = xmlReader->getAttributeValueSafe(L"md");
                        head.setName((std::string)armorPieceName.c_str());
                        head.setMagDef(core::strtol10(armorPieceMd.c_str()));
                        head.setPhyDef(core::strtol10(armorPiecePd.c_str()));
                    }
                    if (((core::stringw)"torso").equals_ignore_case(xmlReader->getNodeName()))
                    {
                        armorPieceName = xmlReader->getAttributeValueSafe(L"name");
                        armorPiecePd = xmlReader->getAttributeValueSafe(L"pd");
                        armorPieceMd = xmlReader->getAttributeValueSafe(L"md");
                        torso.setName((std::string)armorPieceName.c_str());
                        torso.setMagDef(core::strtol10(armorPieceMd.c_str()));
                        torso.setPhyDef(core::strtol10(armorPiecePd.c_str()));
                    }
                    if (((core::stringw)"pants").equals_ignore_case(xmlReader->getNodeName()))
                    {
                        armorPieceName = xmlReader->getAttributeValueSafe(L"name");
                        armorPiecePd = xmlReader->getAttributeValueSafe(L"pd");
                        armorPieceMd = xmlReader->getAttributeValueSafe(L"md");
                        pants.setName((std::string)armorPieceName.c_str());
                        pants.setMagDef(core::strtol10(armorPieceMd.c_str()));
                        pants.setPhyDef(core::strtol10(armorPiecePd.c_str()));
                    }
                    if (((core::stringw)"boots").equals_ignore_case(xmlReader->getNodeName()))
                    {
                        armorPieceName = xmlReader->getAttributeValueSafe(L"name");
                        armorPiecePd = xmlReader->getAttributeValueSafe(L"pd");
                        armorPieceMd = xmlReader->getAttributeValueSafe(L"md");
                        boots.setName((std::string)armorPieceName.c_str());
                        boots.setMagDef(core::strtol10(armorPieceMd.c_str()));
                        boots.setPhyDef(core::strtol10(armorPiecePd.c_str()));
                    }
                    if (((core::stringw)"gloves").equals_ignore_case(xmlReader->getNodeName()))
                    {
                        armorPieceName = xmlReader->getAttributeValueSafe(L"name");
                        armorPiecePd = xmlReader->getAttributeValueSafe(L"pd");
                        armorPieceMd = xmlReader->getAttributeValueSafe(L"md");
                        gloves.setName((std::string)armorPieceName.c_str());
                        gloves.setMagDef(core::strtol10(armorPieceMd.c_str()));
                        gloves.setPhyDef(core::strtol10(armorPiecePd.c_str()));
                    }
                }

                else if (currentSection.equals_ignore_case(weaponTag))
                {
                    std::cout << "Passe2" << std::endl;
                    weaponName = xmlReader->getAttributeValueSafe(L"name");
                    weaponDamage = xmlReader->getAttributeValueSafe(L"damage");
                    weapon.setName((std::string)weaponName.c_str());
                    weapon.setDamage(core::strtol10(weaponDamage.c_str()));
                }

            }break;

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

    armor.setHead(head);
    armor.setTorso(torso);
    armor.setPants(pants);
    armor.setBoots(boots);
    armor.setGloves(gloves);

    player.setArmor(armor);
    player.setWeapon(weapon);

    player.debugCharacter();


    std::cout << "File loaded" << std::endl;
    return player;
}

