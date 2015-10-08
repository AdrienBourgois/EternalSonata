#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>

#include "myIrrlicht.h"
#include "Weapon.h"
#include "Armor.h"
#include "Sstats.h"
//#include "entity.h"

class Character /**: public Entity **/
{
    private:
        std::string         name;
        Sstats*             stats;
        
        Weapon*             weapon;
        Armor*              armor;

    public:
        Character();
        Character(Character const&) = default;
        Character(Sstats* s)  :name("Inideva" ), stats(s), weapon(new Weapon), armor(new Armor) {};
        ~Character() = default;

        Character& operator =(Character const&) = default;

        void setName(std::string n)         {name = n;};
        void setStrength(int s)             {stats->strength = s;};
        void setDexterity(int d)            {stats->dexterity = d;};
        void setIntelligence(int i)         {stats->intelligence = i;};
        void setSpeed(int s)                {stats->speed = s;};
        void setResistance(int r)           {stats->resistance = r;};
        void setLuck(int l)                 {stats->luck = l;};
        void setSpirit(int s)               {stats->spirit = s;};
        void setAgility(int a)              {stats->agility = a;};
        void setWeapon(Weapon* w)           {weapon = w;};
        void setArmor(Armor* a)             {armor = a;};

        auto& getName() const       {return name;};
        int getStrength() const     {return stats->strength;};
        int getDexterity() const    {return stats->dexterity;};
        int getIntelligence() const {return stats->intelligence;};
        int getSpeed() const        {return stats->speed;};
        int getResistance() const   {return stats->resistance;};
        int getLuck() const         {return stats->luck;};
        int getSpirit() const       {return stats->spirit;};
        int getAgility() const      {return stats->agility;};
        auto& getWeapon() const     {return weapon;};
        auto& getArmor() const      {return armor;};
};

std::ostream& operator <<(std::ostream& os, Character const&);
#endif
