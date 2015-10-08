#include <iostream>
#include "myIrrlicht.h"
#include "XMLmanager.h"

#include <map>

using namespace irr;

PlayerManager::PlayerManager(const core::stringw& player_path_file): playerFilePath(player_path_file), NullDevice(0)
{
    NullDevice = createDevice(video::EDT_NULL);
    std::cout << "NULL Device created" << std::endl;

    PlayerMap.insert(L"agility", L"0");
    PlayerMap.insert(L"dexterity", L"0");
    PlayerMap.insert(L"intelligence", L"0");
    PlayerMap.insert(L"luck", L"0");
    PlayerMap.insert(L"name", L"");
    PlayerMap.insert(L"resistance", L"0");
    PlayerMap.insert(L"speed", L"0");
    PlayerMap.insert(L"spirit", L"0");
    PlayerMap.insert(L"strength", L"0");
    std::cout << "PlayerMap initialized" << std::endl;
}

PlayerManager::~PlayerManager()
{
    if (NullDevice)
    {
        NullDevice->closeDevice();
        NullDevice->drop();
        std::cout << "Destruct PlayerManager" << std::endl;
    }
}

bool PlayerManager::load()
{
    std::cout << "Load XML file" << std::endl;

    if (!NullDevice)
    {
        std::cout << "Any device !" << std::endl;
        return false;
    }

    io::IXMLReader* xml = NullDevice->getFileSystem()->createXMLReader(playerFilePath);
    if (!xml)
    {
        std::cout << "Can't create XMLReader !" << std::endl;
        return false;
    }

    const core::stringw statTag(L"stat");
    core::stringw currentSection;
    const core::stringw playerTag(L"player");

    while (xml->read())
    {
        switch (xml->getNodeType())
        {
            case io::EXN_ELEMENT:
            {
                if (currentSection.empty() && playerTag.equals_ignore_case(xml->getNodeName()))
                    currentSection = playerTag;

                else if (currentSection.equals_ignore_case(playerTag) && statTag.equals_ignore_case(xml->getNodeName() ))
                {
                    core::stringw key = xml->getAttributeValueSafe(L"name");
                    if(!key.empty())
                        PlayerMap[key] = xml->getAttributeValueSafe(L"value");
                }
            }break;

            case io::EXN_ELEMENT_END:
                currentSection = L"";
            break;

            default:
            break;
        }
    }

    xml->drop();

    std::cout << "File loaded" << std::endl;
    return true;
}

bool PlayerManager::save()
{
    std::cout << "Save file" << std::endl;

    if (!NullDevice)
        return false;

    io::IXMLWriter* xwriter = NullDevice->getFileSystem()->createXMLWriter(playerFilePath);
    if (!xwriter)
        return false;

    xwriter->writeXMLHeader();

    xwriter->writeElement(L"player");
    xwriter->writeLineBreak();

    core::map<core::stringw, core::stringw>::Iterator i = PlayerMap.getIterator();
    for(; !i.atEnd(); i++)
    {
        xwriter->writeElement(L"stat", true, L"name", i->getKey().c_str(), L"value", i->getValue().c_str() );
        xwriter->writeLineBreak();
    }
    xwriter->writeLineBreak();

    xwriter->writeClosingTag(L"player");

    xwriter->drop();

    std::cout << "File saved" << std::endl;
    return true;
}

void PlayerManager::setStat(const core::stringw& name, const core::stringw& value)
{
    PlayerMap[name] = value;
}

void PlayerManager::setStat(const core::stringw& name, s32 value)
{
    PlayerMap[name] = core::stringw(value);
}

core::stringw PlayerManager::getStat(const core::stringw& key) const
{
    core::map<core::stringw, core::stringw>::Node* n = PlayerMap.find(key);
    if (n)
        return n->getValue();
    else
        return L"";
}

bool PlayerManager::getStatAsBoolean(const core::stringw& key ) const
{
    core::stringw s = getStat(key);
    if (s.empty())
        return false;
    return s.equals_ignore_case(L"1");
}

s32 PlayerManager::getStatAsInteger(const core::stringw& key) const
{
    const core::stringc s = getStat(key);
    if (s.empty())
        return 0;
    
    return core::strtol10(s.c_str());
}


