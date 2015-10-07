#include "Character.h"

Character::Character()
{
    name = "Inideva";
    stats.strength = 10;
    stats.dexterity = 10;
    stats.intelligence = 10;
    stats.speed = 10;
    stats.resistance = 10;
    stats.luck = 10;
    stats.spirit = 10;
    stats.agility = 10;

    weapon = new Weapon;
    armor = new Armor;
}

std::ostream& operator <<(std::ostream& os, Character const& c)
{
    using namespace std;
    os      << "[Player Debug]" << endl
            << "-Name: " << c.getName() << endl
            << "-Strength: " << c.getStrength() << endl
            << "-Dexterity: " << c.getDexterity() << endl
            << "-Intelligence: " << c.getIntelligence() << endl
            << "-Speed: " << c.getSpeed() << endl
            << "-Resistance: " << c.getResistance() << endl
            << "-Luck: " << c.getLuck() << endl
            << "-Spirit: " << c.getSpirit() << endl
            << "-Agility: " << c.getAgility() << endl;

    return os;
}
