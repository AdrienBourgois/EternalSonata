#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "myIrrlicht.h"

class Character : public Entity
{
    private:
        irr::core:stringw   name;

        struct Sstats
        {
            int                 strength,
                                dexterity,
                                intelligence,
                                speed,
                                resistance,
                                luck,
                                spirit,
                                agility;
        }stats;

        Weapon*             weapon;
        Armor*              armor;

    public:
        Character();
        Character(Character const&) = default;
        ~Character() = default;

        Character& operator =(Character const&) const = default;

        void setStrength(int s)         :stats.strength(s);
        void setDexterity(int d)        :stats.dexterity(d);
        void setIntelligence(int i)     :stats.intelligence(i);
        void setSpeed(int s)            :stats.speed(s);
        void setResistance(int r)       :stats.resistance(r);
        void setLuck(int l)             :stats.luck(l);
        void setSpirit(int s)           :stats.spirit(s);
        void setAgility(int a)          :stats.agility(a);
        void setWeapon(Weapon const& w) :stats.weapons(w);
        void setArmor(Armor const& a)   :stats.armor(a);

        int getStrength() const         {return stats.strength;};
        int getDexterity() const        {return stats.dexterity;};
        int getIntelligence() const     {return stats.intelligence;};
        int getSpeed() const            {return stats.speed;};
        int getResistance() const       {return stats.resistance;};
        int getLuck() const             {return stats.luck;};
        int getSpirit() const           {return stats.spirit;};
        int getAgility() const          {return stats.agility;};
        auto& getWeapon() const         {return weapon;};
        auto& getArmor() const          {return armor;};
}

#endif
