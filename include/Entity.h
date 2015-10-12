#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <map>
#include <vector>
#include <ostream>

#include "CSceneNode.h"
#include "Inventory.h"

class Entity: public CSceneNode 
{
    private:
        unsigned int    life;
        Inventory*      inventory;

    public:

        static unsigned int ID;


        Entity();
        Entity(unsigned int i)                  : life(i), inventory(new Inventory){}, ID(+=1);
        Entity(Inventory* i)                    : life(10), Inventory(i){}, ID(+=1);
        Entity(unsigned int i, Inventory in)    : life(i), inventory(in), ID(+=1);
        Entity(Entity const&) = default;
        ~Entity() = default;

        Entity& operator =(Entity const&) = default;
        
        void setLife(int l)             { life = l; };
        void setInventory(Inventory* i) { inventory = i; };

        int getLife() const
        { return life; }


        void showInventory(Inventory*) const;
};

using namespace std;
ostream& operator <<(ostream&, Entity&);

#endif // __ENTITY_H__
