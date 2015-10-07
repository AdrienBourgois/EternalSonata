#include "myIrrlicht.h"
#include "XMLmanager.h"

PlayerManager::PlayerManager(const stringw& playerFilePath): playerFilePath(player_path_file), NullDevice(0)
{
    NullDevice = createDevice(video::EDT_NULL);

    PlayerMap.insert(L"name", L"");
    PlayerMap.insert(L"strength", L"0");
    PlayerMap.insert(L"dexterity", L"0");
    PlayerMap.insert(L"intelligence", L"0");
    PlayerMap.insert(L"speed", L"0");
    PlayerMap.insert(L"resistance", L"0");
    PlayerMap.insert(L"luck", L"0");
    PlayerMap.insert(L"spirit", L"0");
    PlayerMap.insert(L"agility", L"0");
}

~PlayerManager::~PlayerManager()
{
    if (NullDevice)
    {
        NullDevice->closeDevice();
        NullDevice->drop();
    }
}

bool PlayerManager::load()
{
    if (!NullDevice)
        return false;

    io::IXMLReader* xml = NullDevice->getFileSystem()->createXMLReader(playerFilePath);
    if (!xml)
        return false;

    const stringw statTag(L"stat");
    stringw currentSection;
    const stringw playerTag(L"player");

    while (xml->read())
    {
        switch (xml->getNodeType())
        {
            case io::EXN_ELEMENT:
            {
                if (currentSection.empty && videoTag.equal_ignore_case(xml->getNodeName()))
                    currentSection = playerTag;

                else if (currentSection.equal_ignore_case(playerTag) && statTag.equal_ignore_case(xml->getNodeName() ))
                {
                    stringw key = xml->getAttributeValueSafe(L"name");
                    if(!key.empty())
                        PlayerMap[key] = xml->getAttributeValueSafe(L"value");
                }
            }break;

            case io::EXN_ELEMENT_END:
                currentSection = L"";
            break;
        }
    }

    xml->drop();

    return true;
}

bool PlayerManager::save()
{
    if (!NullDevice)
        return false;

    io::IXMLWriter* xwriter = NullDevice->getFileSystem()->createXMLWriter(playerFilePath);
    if (!xwriter)
        return false;

    xwriter->writeXMLHeader();

    xwriter->writeElement(L"player");
    xwriter->writeLineBreak();

    map<stringw, stringw>::Iterator i = PlayerMap.getIterator();
    for(; !i.atEnd(); ++i)
    {
        xwriter->writeElement(L"stats", true, L"name", i->getKey().c_str(), L"value", i->getValue().c_str() );
        xwriter->writeLineBreak();
    }
    xwriter->writeLineBreak();

    xwriter->writeClosingTag(L"player");

    xwriter->drop();

    return true;
}

void PlayerManager::setStat(const stringw& name, const stringw& value)
{
    PlayerMap[name] = value;
}

void PlayerManager::setStat(const stringw& name, s32 value)
{
    PlayerMap[name] = stringw(value);
}

stringw PlayerManager::getStat(const stringw& key) const
{
    map<stringw, stringw>::Node* n = PlayerMap.find(key);
    if (n)
        return n->getValue();
    else
        return L"";
}

bool PlayerManager::getSettingAsBoolean(const stringw& key ) const
{
    stringw s = getSetting(key);
    if (s.empty())
        return false;
    return s.equals_ignore_case(L"1");
}

s32 PlayerManager::getSettingAsInteger(const stringw& key) const
{
        const stringc s = getSetting(key);
        if (s.empty())
            return 0;
        
        return strtol10(s.c_str());
}


