#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <map>
#include <vector>
#include <ostream>
#include <string>
#include "CSceneNode.h"
#include "AnimationState.h"
#include "myIrrlicht.h"

class Entity 
{
    protected:
        unsigned int                        uniqueID;

    private:
        unsigned int                        life;
        unsigned int                        animationState;
        bool                                stealth;
        irr::scene::IAnimatedMeshSceneNode* node;
        
        void moveForward(float);
        void moveBackward(float);
        void moveLeft(float);
        void moveRight(float);
        void moveUpperRight(float);
        void moveUpperLeft(float);
        void moveDownRigth(float);
        void moveDownLeft(float);
        void idle();

    public:
        static unsigned int ID;


        Entity();
        Entity(unsigned int entity_life);
        Entity(Entity const&) = default;
        ~Entity();

        Entity& operator =(Entity const&) = default;
        
        void setLife(int entity_life)                           { life = entity_life; };
        void setNode(irr::scene::IAnimatedMeshSceneNode* node)  { this->node = node; }
        void setPosition(irr::core::vector3df position)         { this->node->setPosition(position); }
        void setStealth(bool is_stealth)                        { stealth = is_stealth;}

        int getLife() const                             { return life; };
        irr::scene::IAnimatedMeshSceneNode* getNode()   { return this->node; }
        const irr::core::vector3df getPosition()        { return this->node->getPosition(); }
        const irr::core::vector3df getCollideRadius();
        int getAnimationState() const                   { return animationState; }
        bool getStealth() const                         { return stealth; }
        auto getID() { return this->uniqueID; }

        void move(int, float);

};

using namespace std;
ostream& operator <<(ostream&, Entity&);

#endif // __ENTITY_H__
