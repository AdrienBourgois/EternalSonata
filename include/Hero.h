#ifndef __HERO_H__
#define __HERO_H__
#include "Character.h"

class Hero : public Character
{
    private:
        unsigned int xp;
        bool inBattle;

    public:
        Hero();
        ~Hero() = default;
        Hero(Hero const&) = default;

        virtual void update() override;
        bool& isInBattle() { return this->inBattle; }
};

#endif
