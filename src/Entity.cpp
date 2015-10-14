#include "Entity.h"
#include <iostream>

unsigned int Entity::ID = 0;

Entity::Entity()
{
    ID += 1;   
}

Entity::Entity(unsigned int entity_life)
{
    life = entity_life;
    ID += 1;
}


Entity::~Entity()
{
    ID -= 1;
}

ostream& operator <<(ostream& os, Entity& given_entity)
{
    using namespace std;

    os  << "[Entity Debug]" 
        << "-Life: " << given_entity.getLife() << endl;

    return os;
}
