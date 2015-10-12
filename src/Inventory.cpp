#include "Inventory.h"
#include "Entity.h"

Inventory::Inventory()
{
    next_id = Entity::ID;
    inventory["Weapons"] = new map<unsigned int, Weapon>;
    inventory["Armors"] = new map<unsigned int, Armor_Piece>;
    inventory["Items"] = new map<unsigned int, Item>;
}

void insertItemInto(std::string const& s, Entity const& e)
{
    inventory[s] = i;
}

Item& retrieveItem(std::string const& i)
{
    auto return_value = std::find_if(inventory.begin(), inventory.end(), inventory.value.find(i));

    if (return_value != inventory.end())
        return *return_value;
    else
        return nullptr;
}

