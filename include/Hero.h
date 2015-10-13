#ifndef __HERO_H__
#define __HERO_H__
#include "Character.h"

class Hero : public Character
{
    private:
        unsigned int xp;


    public:
        Hero() = default;
        ~Hero() = default;
        Hero(Hero const&) = default;
        //void /*virtual*/ attack(Character&) /*override*/;
};

#endif
