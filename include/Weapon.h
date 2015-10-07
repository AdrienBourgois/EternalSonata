#ifndef __WEAPON_H__
#define __WEAPON_H__
#include "myIrrlicht.h"

class Weapon
{
    private:
        irr::core::stringw name;
        int damage;

    public:
        Weapon();
        Weapon(int d)                   :damage(d){};
        Weapon(irr::core::stringw n)    :name(n){};
        Weapon(irr::core::stringw n, int d) :name(n), damage(d){};
        Weapon(Weapon const&) = default;

        ~Weapon() = default;

        Weapon& operator =(Weapon const&) = default;

        void setDamage(int d)               {damage = d;};
        void setName(irr::core::stringw n)  {name = n;};

        int getDamage() {return damage;};
        auto& getName() {return name;};
};

#endif
