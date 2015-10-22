#include <iterator>
#include <iostream>

#include "Inventory.h"

void Inventory::addItem(Item new_item)
{
    storage[new_item.getID()] = new_item;
}

void Inventory::deleteItem(Item item_to_delete)
{   
    storage.erase(storage.find(item_to_delete.getID()));
}

void Inventory::deleteItem(unsigned int itemID)
{   
    storage.erase(storage.find(itemID));
}


void Inventory::showInventory()
{
    using namespace std;

    cout    << "[Inventory Debug]" << endl;

    for (std::map<unsigned int, Item>::iterator it = storage.begin() ; it != storage.end() ; ++it)
    {
        cout    << "-Name: " << it->second.getName()
                << " (" << it->second.getID() << ")" << endl
                << "    |Stat Modifier: " << it->second.getStatModifier() << endl
                << "    |Description:   " << it->second.getDescription() << endl
                << "    |Item class:    "; 
                switch(it->second.getItemClass())
                {
                    case HEAL: cout << "Heal Item"; break;
                    case DAMAGE: cout << "Damage Dealer Item"; break;
                    case STATM: cout << "Stat Modifier Item"; break;
                    case OTHER: cout << "Undefined Item"; break;
                    default: break;
                } 
                cout << endl << endl;
    }

}
