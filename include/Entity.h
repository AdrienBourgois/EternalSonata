#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <map>
#include <vector>
#include <ostream>
#include <string>
#include "CSceneNode.h"
#include "myIrrlicht.h"

class Entity 
{
    private:
        unsigned int    life;
        irr::scene::IAnimatedMeshSceneNode* node;

    public:
        static unsigned int ID;


        Entity();
        Entity(unsigned int entity_life);
        Entity(Entity const&) = default;
        ~Entity();

        Entity& operator =(Entity const&) = default;
        
        void setLife(int entity_life)                   { life = entity_life; };

        int getLife() const                             { return life; };

        void setNode(irr::scene::IAnimatedMeshSceneNode* node) { this->node = node; }

        irr::scene::IAnimatedMeshSceneNode* getNode() { return this->node; }

        const irr::core::vector3df getPosition() { return this->node->getPosition(); }

        void setPosition(irr::core::vector3df position) { this->node->setPosition(position); }

};

using namespace std;
ostream& operator <<(ostream&, Entity&);

#endif // __ENTITY_H__
