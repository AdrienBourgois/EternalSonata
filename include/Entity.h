#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <map>
#include <vector>
#include <ostream>

#include "CSceneNode.h"


class Entity : public CSceneNode 
{
    private:
        unsigned int    life;

    public:

        static unsigned int ID;


        Entity();
        Entity(unsigned int entity_life);
        Entity(Entity const&) = default;
        ~Entity();

        Entity& operator =(Entity const&) = default;
        
        void setLife(int entity_life)                   { life = entity_life; };

        int getLife() const                             { return life; };
};

using namespace std;
ostream& operator <<(ostream&, Entity&);

#endif // __ENTITY_H__
