#include "Character.h"
#include <cassert>

Character::Character()
{
    name = "Inideva";

    level = 1;
    stats.strength = 10;
    stats.dexterity = 10;
    stats.intelligence = 10;
    stats.speed = 10;
    stats.resistance = 10;
    stats.luck = 10;
    stats.spirit = 10;
    stats.agility = 10;
}

std::ostream& operator <<(std::ostream& os, Character const& c)
{
    using namespace std;
    os      << "[Character Debug]" << endl
            << "-Name: " << c.getName() << endl
            << "-Level: " << c.getLevel() << endl
            << "-Strength: " << c.getStrength() << endl
            << "-Dexterity: " << c.getDexterity() << endl
            << "-Intelligence: " << c.getIntelligence() << endl
            << "-Speed: " << c.getSpeed() << endl
            << "-Resistance: " << c.getResistance() << endl
            << "-Luck: " << c.getLuck() << endl
            << "-Spirit: " << c.getSpirit() << endl
            << "-Agility: " << c.getAgility() << endl 
            << "-Weapon: " << c.getWeapon().getName() << " (" << c.getWeapon().getDamage() << ")" << endl
            << "-Armor: " << endl
            << "    -Head:      " << c.getArmor().getHead().getName() << " (RPhy: " << c.getArmor().getHead().getPhyDef() << ") (RMag: " << c.getArmor().getHead().getMagDef() << ")" << endl
            << "    -Torso:     " << c.getArmor().getTorso().getName() << " (RPhy: " << c.getArmor().getTorso().getPhyDef() << ") (RMag: " << c.getArmor().getTorso().getMagDef() << ")" << endl

            << "    -Gloves:    " << c.getArmor().getGloves().getName() << " (RPhy: " << c.getArmor().getGloves().getPhyDef() << ") (RMag: " << c.getArmor().getGloves().getMagDef() << ")" <<endl

            << "    -Pants:     " << c.getArmor().getPants().getName() << " (RPhy: " << c.getArmor().getPants().getPhyDef() << ") (RMag: " << c.getArmor().getPants().getMagDef() << ")" << endl

            << "    -Boots:     " << c.getArmor().getBoots().getName() << " (RPhy: " << c.getArmor().getBoots().getPhyDef() << ") (RMag: " << c.getArmor().getBoots().getMagDef() << ")" << endl;


    return os;
}


void Character::debugCharacter()
{
    using namespace std;

    cout    << "[Character Debug]" << endl
            << "-Name: " << getName() << endl
            << "-Level: " << getLevel() << endl
            << "-Strength: " << getStrength() << endl
            << "-Dexterity: " << getDexterity() << endl
            << "-Intelligence: " << getIntelligence() << endl
            << "-Speed: " << getSpeed() << endl
            << "-Resistance: " << getResistance() << endl
            << "-Luck: " << getLuck() << endl
            << "-Spirit: " << getSpirit() << endl
            << "-Agility: " << getAgility() << endl 
            << "-Weapon: " << getWeapon().getName() << " (" << getWeapon().getDamage() << ")" << endl
            << "-Armor: " << endl
            << "    -Head:      " << getArmor().getHead().getName() << " (RPhy: " << getArmor().getHead().getPhyDef() << ") (RMag: " << getArmor().getHead().getMagDef() << ")" << endl
            << "    -Torso:     " << getArmor().getTorso().getName() << " (RPhy: " << getArmor().getTorso().getPhyDef() << ") (RMag: " << getArmor().getTorso().getMagDef() << ")" << endl

            << "    -Gloves:    " << getArmor().getGloves().getName() << " (RPhy: " << getArmor().getGloves().getPhyDef() << ") (RMag: " << getArmor().getGloves().getMagDef() << ")" <<endl

            << "    -Pants:     " << getArmor().getPants().getName() << " (RPhy: " << getArmor().getPants().getPhyDef() << ") (RMag: " << getArmor().getPants().getMagDef() << ")" << endl

            << "    -Boots:     " << getArmor().getBoots().getName() << " (RPhy: " << getArmor().getBoots().getPhyDef() << ") (RMag: " << getArmor().getBoots().getMagDef() << ")" << endl;


    inventory.showInventory();
}

