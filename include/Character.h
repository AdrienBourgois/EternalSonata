#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "myIrrlicht.h"

class Character : public Entity
{
    private:
        irr::core:stringw   name;

        int                 strength,
                            dexterity,
                            intelligence,
                            speed,
                            resistance,
                            luck,
                            spirit,
                            agility;

        Weapon              weapons;
        Armor               armor;

    public:
        Character();
        Character(Character const&) = default; /** Copy Allowed **/
        ~Character();

        Character& operator =(Character const&) const = default;

        void setStrength(int s)         :strength(s);
        void setDexterity(int d)        :dexterity(d);
        void setIntelligence(int i)     :intelligence(i);
        void setSpeed(int s)            :speed(s);
        void setResistance(int r)       :resistance(r);
        void setLuck(int l)             :luck(l);
        void setSpirit(int s)           :spirit(s);
        void setAgility(int a)          :agility(a);
        void setWeapon(Weapon const& w) :weapons(w);
        void setArmor(Armor const& a)   :armor(a);

        int getStrength() const         {return strength;};
        int getDexterity() const        {return dexterity;};
        int getIntelligence() const     {return intelligence;};
        int getSpeed() const            {return speed;};
        int getResistance() const       {return resistance;};
        int getLuck() const             {return luck;};
        int getSpirit() const           {return spirit;};
        int getAgility() const          {return agility;};
        auto& getWeapons() const        {return weapon;};
        auto& getArmor() const          {return armor;};
}

#endif
