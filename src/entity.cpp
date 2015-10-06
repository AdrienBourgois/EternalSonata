#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    std::cout << "Constructing Entity..." << std::endl;
}

Entity::~Entity()
{
    std::cout << "Destructing Entity..." << std::endl;
}
