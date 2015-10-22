#ifndef __CHEST_H__
#define __CHEST_H__
#include "Inventory.h"
#include "Character.h"

class Chest : public Entity
{
    private:
        Inventory chest_inventory;

    public:
        Chest() = default;
        Chest(Chest const&) = default;
        ~Chest() = default;

        Chest& operator =(Chest const&) = default;

        void giveItem(Character&); 
        void addItemToChest(Item&);
        void showChestInventory();
};

#endif
