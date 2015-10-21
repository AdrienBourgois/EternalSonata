#include "Mobs.h"

//unsigned int Mobs::ID = 0;

Mobs::Mobs()
{
    Character::ID += 1;
    uniqueID = Character::ID;
};
