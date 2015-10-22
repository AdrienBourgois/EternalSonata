#include "Mobs.h"
#include <iostream>

Mobs::Mobs()
{
};

Mobs::Mobs(std::vector<Mobs>& battleGroup)
    :battleGroup(battleGroup)
{
}
