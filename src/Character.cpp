#include "Character.h"

Character::Character()
{
    stats.strength = 10;
    stats.dexterity = 10;
    stats.intelligence = 10;
    stats.speed = 10;
    stats.resistance = 10;
    stats.luck = 10;
    stats.spirit = 10;
    stats.agility = 10;

    weapon = new Weapon;
    Armor = new Armor;
}
