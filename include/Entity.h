#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "CSceneNode.h"
#include <map>
#include <vector>
class Entity: public CSceneNode 
{
    private:
        unsigned int life;
        std::map<>

    public:
        Entity();
        Entity(Entity const&) = default;
        ~Entity() = default;

        Entity& operator =(Entity const&) = default;

        int getLife() const
        { return life; }

        void setLife(int l)
        { life = l; }
};

#endif // __ENTITY_H__
