#include "Mobs.h"

int Mobs::ID = 0;

Mobs::Mobs()
{
    ID += 1;
    enemy_ID = ID;
}
