#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "Item.h"

#include <map>

class Inventory
{
    private:
        std::map<unsigned int, Item> storage;
    
    public:
        Inventory() = default;
        Inventory(Inventory const&) = default;
        ~Inventory() = default;

        Inventory& operator =(Inventory const&) = default;

        void setInventory(std::map<unsigned int, Item> const& new_storage)     {storage = new_storage;}

        auto& getStorage() const                                     {return storage;}
        auto getTotalSize() const                                   {return storage.size();}

        void addItem(Item);
        void deleteItem(Item);
        void deleteItem(unsigned int);
        void showInventory();
};

#endif
