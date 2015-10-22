#include "Chest.h"
#include <algorithm>

void Chest::giveItem(Character& character)
{
    auto it = chest_inventory.getStorage().begin();
    for ( ; it != chest_inventory.getStorage().end() ; ++it)
    {
        character.getInventory().addItem(it->second);
    }
}

void Chest::showChestInventory()
{
    chest_inventory.showInventory();
}

void Chest::addItemToChest(Item& item)
{
    chest_inventory.addItem(item);
}

