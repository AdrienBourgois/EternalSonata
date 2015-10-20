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

void Entity::moveRight(bool diagonalUP, bool diagonalDOWN)
{
    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(2.f, 0.f, 0.f) );
    
    if (diagonalUP)
        node->setRotation(irr::core::vector3d<irr::f32>(0.f, 45.f+360.f, 0.f));
    
    else if (diagonalDOWN)
        node->setRotation(irr::core::vector3d<irr::f32>(0.f, 135.f+360.f, 0.f));

    else
        node->setRotation(irr::core::vector3d<irr::f32>(0.f, 90.f+360.f, 0.f));
}

void Entity::moveLeft(bool diagonalUP, bool diagonalDOWN)
{
    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(-2.f, 0.f, 0.f));

    if (diagonalUP)
        node->setRotation(irr::core::vector3d<irr::f32>(0.f, 315.f, 0.f));
    
    else if (diagonalDOWN)
        node->setRotation(irr::core::vector3d<irr::f32>(0.f, 225.f, 0.f));

    else
        node->setRotation(irr::core::vector3d<irr::f32>(0.f, 270.f, 0.f));
}

void Entity::moveForward()
{
    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(0.f, 0.f, 2.f));
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, 0.f, 0.f));

}
void Entity::moveBackward()
{
    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(0.f, 0.f, -2.f));
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, 180.f, 0.f));

}

void Entity::idle()
{
    auto currentPos = node->getPosition();
    node->setPosition(currentPos);
}

const irr::core::vector3df Entity::getCollideRadius()
{
    const irr::core::aabbox3d<irr::f32> box = this->node->getTransformedBoundingBox();
    irr::core::vector3df radius = box.MaxEdge - box.getCenter();
    std::cout << radius.X << " " << radius.Y << " " << radius.Z << std::endl;

    return radius;
}
