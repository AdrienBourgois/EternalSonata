#ifndef __INVENTORY_H__
#define __INVENTORY_H__
#include <map>
#include <string>
#include "Entity.h"

class Inventory 
{
    public:
        Inventory();
        Inventory(Inventory const&) = default;
        ~Inventory() = default;

        Inventory& operator =(Inventory const&) = default;
        

        map<std::string, map<unsigned int, Entity>> inventory;     /**     ----String---|---Map----     :Item tabs (Weapon, Armor...) [Name of the tab, Tab Inventory]  **/
        unsigned int next_id;                                      /**                       |                                                                          **/
                                                                   /**             ----Int---|---Entity----  :Entity Inventory [ID of Entity, Entity itself]            **/

        void insertItemInto(std::string const&, Entity const&);
        Item& retrieveItem(std::string const& i);
        Item& retrieveItemFrom(std::string const& cn, std::string const& in){return inventory[cn].value[in];};
        void deleteFromItem(std::string const& cn, std::string const& in){inventory[cn].erase(in);};

        void setInventory(Inventory const& i)   {inventory = i;}
        Inventory& getInventory() const         {return inventory;};

}

#endif
