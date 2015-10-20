#ifndef __HERO_H__
#define __HERO_H__
#include "Character.h"

class Hero : public Character
{
    private:
        unsigned int xp;


    public:
        Hero();
        ~Hero() = default;
        Hero(Hero const&) = default;

        virtual void update() override;
};

#endif
