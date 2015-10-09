#ifndef __INVENTORY_H__
#define __INVENTORY_H__
#include <map>
#include <string>

#include "Item.h"

struct Inventory 
{
    public:
        map<std::string, map<unsigned int, Item>> item_tab;        /**     ----String---|---Map----     :Item tabs (Weapon, Armor...) [Name of the tab, Tab Inventory]  **/
        unsigned int next_id;                                      /**                       |                                                                          **/
                                                                   /**             ----Int---|---Item----  :Item Inventory [ID of Item, Item itself]                    **/
}

#endif
