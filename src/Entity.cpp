#include "Entity.h"
#include <iostream>

Entity::ID = 0;

Entity::Entity()
{
    inventory = new Inventory;
    ID += 1;   
}



Entity::~Entity()
{
    ID -= 1;
}

ostream& operator <<(ostream& os, Entity& e)
{
    using namespace std;

    os  << "[Entity Debug]" 
        << "-Life: " << e.getLive() << endl;

    return os;
}
