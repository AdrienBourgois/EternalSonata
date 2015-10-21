#include "Entity.h"
#include "Direction.h"
#include <iostream>

unsigned int Entity::ID = 0;

Entity::Entity()
{
    ID += 1;
    uniqueID = ID;
    life = 10;
    animationState = NONE;
    stealth = false;
}

Entity::Entity(unsigned int entity_life)
{
    life = entity_life;
    ID += 1;
    animationState = NONE;
    stealth = false;
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

void Entity::moveForward(float speed)
{
    if (stealth)
        animationState = STEALTH;
    else
        animationState = WALKING;

    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(0.f, 0.f, speed));
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, 0.f, 0.f));
}

void Entity::moveBackward(float speed)
{
    if (stealth)
        animationState = STEALTH;
    else
        animationState = WALKING;

    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(0.f, 0.f, -speed));
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, 180.f, 0.f));
}

void Entity::moveLeft(float speed)
{
    if (stealth)
        animationState = STEALTH;
    else
        animationState = WALKING;

    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(-speed, 0.f, 0.f));
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, -90.f, 0.f));
}

void Entity::moveRight(float speed)
{
    if (stealth)
        animationState = STEALTH;
    else
        animationState = WALKING;

    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(speed, 0.f, 0.f) );
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, 90.f, 0.f));
}

void Entity::moveUpperLeft(float speed)
{
    if (stealth)
        animationState = STEALTH;
    else
        animationState = WALKING;

    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(-speed, 0.f, speed) );
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, -45.f, 0.f));
}

void Entity::moveUpperRight(float speed)
{
    if (stealth)
        animationState = STEALTH;
    else
        animationState = WALKING;

    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(speed, 0.f, speed) );
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, 45.f, 0.f));
}

void Entity::moveDownLeft(float speed)
{
    if (stealth)
        animationState = STEALTH;
    else
        animationState = WALKING;

    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(-speed, 0.f, -speed) );
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, -135.f, 0.f));
}

void Entity::moveDownRigth(float speed)
{
    if (stealth)
        animationState = STEALTH;
    else
        animationState = WALKING;

    auto currentPos = node->getPosition();
    node->setPosition(currentPos + irr::core::vector3d<irr::f32>(speed, 0.f, -speed) );
    node->setRotation(irr::core::vector3d<irr::f32>(0.f, 135.f, 0.f));
}

void Entity::idle()
{
    auto currentPos = node->getPosition();
    node->setPosition(currentPos);
    animationState = IDLE;

}

void Entity::move(int direction, float speed)
{
    switch (direction)
    {
        case NONE:           idle();
                             break;

        case UP:             moveForward(speed);
                             break;

        case DOWN:           moveBackward(speed);
                             break;

        case LEFT:           moveLeft(speed);
                             break;

        case RIGHT:          moveRight(speed);
                             break;

        case UPPER_RIGHT:    moveUpperRight(speed);
                             break;

        case UPPER_LEFT:     moveUpperLeft(speed);
                             break;

        case DOWN_RIGHT:     moveDownRigth(speed);
                             break;

        case DOWN_LEFT:      moveDownLeft(speed);
                             break;

        default:             break;
    }
}

const irr::core::vector3df Entity::getCollideRadius()
{
    const irr::core::aabbox3d<irr::f32> box = this->node->getTransformedBoundingBox();
    irr::core::vector3df radius = box.MaxEdge - box.getCenter();
    std::cout << radius.X << " " << radius.Y << " " << radius.Z << std::endl;

    return radius;
}
