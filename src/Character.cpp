#include "Character.h"
#include <cassert>


Character::Character()
{
    name = "Inideva";
    stats = new Sstats;
    weapon = new Weapon;
    armor = new Armor;

    level = 1;
    stats->strength = 10;
    stats->dexterity = 10;
    stats->intelligence = 10;
    stats->speed = 10;
    stats->resistance = 10;
    stats->luck = 10;
    stats->spirit = 10;
    stats->agility = 10;


}

std::ostream& operator <<(std::ostream& os, Character const& c)
{
    using namespace std;

    c.assertCharacter(c);

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
            << "-Weapon: " << c.getWeapon()->getName() << " (" << c.getWeapon()->getDamage() << ")" << endl
            << "-Armor: " << endl
            << "    -Head:      " << c.getArmor()->getHead()->getName() << " (RPhy: " << c.getArmor()->getHead()->getPhyDef() << ") (RMag: " << c.getArmor()->getHead()->getMagDef() << ")" << endl
            << "    -Torso:     " << c.getArmor()->getTorso()->getName() << " (RPhy: " << c.getArmor()->getTorso()->getPhyDef() << ") (RMag: " << c.getArmor()->getTorso()->getMagDef() << ")" << endl

            << "    -Gloves:    " << c.getArmor()->getGloves()->getName() << " (RPhy: " << c.getArmor()->getGloves()->getPhyDef() << ") (RMag: " << c.getArmor()->getGloves()->getMagDef() << ")" <<endl

            << "    -Pants:     " << c.getArmor()->getPants()->getName() << " (RPhy: " << c.getArmor()->getPants()->getPhyDef() << ") (RMag: " << c.getArmor()->getPants()->getMagDef() << ")" << endl

            << "    -Boots:     " << c.getArmor()->getBoots()->getName() << " (RPhy: " << c.getArmor()->getBoots()->getPhyDef() << ") (RMag: " << c.getArmor()->getBoots()->getMagDef() << ")" << endl << endl;


    return os;
}

void Character::assertCharacter(Character const& c) const
{
    assert( c.weapon && "WEAPON POINTER IS NULL !" );
    assert( c.armor && "ARMOR POINTER IS NULL !" );
    assert( c.armor->getHead() && "HEAD ARMOR POINTER IS NULL !");
    assert( c.armor->getTorso() && "TORSO ARMOR POINTER IS NULL !");
    assert( c.armor->getGloves() && "GLOVES ARMOR POINTER IS NULL !");
    assert( c.armor->getPants() && "PANTS ARMOR POINTER IS NULL !");
    assert( c.armor->getBoots() && "BOOTS ARMOR POINTER IS NULL !");

}


