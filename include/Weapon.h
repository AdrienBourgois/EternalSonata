#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include "myIrrlicht.h"


class Weapon
{
    private:
        std::string name;
        int damage;

    public:
        Weapon();
        Weapon(int d)                   :damage(d){};
        Weapon(std::string n)           :name(n){};
        Weapon(std::string n, int d)    :name(n), damage(d){};
        Weapon(Weapon const&) = default;

        ~Weapon() = default;

        Weapon& operator =(Weapon const&) = default;

        void setDamage(int d)               {damage = d;};
        void setName(std::string n)         {name = n;};

        int getDamage() const {return damage;};
        auto& getName() const {return name;};
};

#endif
