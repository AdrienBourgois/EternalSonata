#ifndef __INVENTORY_H__
#define __INVENTORY_H__
#include <map>
#include <string>

struct Inventory 
{
    public:
        map<std::string, map<unsigned int, Entity>> item_tab;      /**     ----String---|---Map----     :Item tabs (Weapon, Armor...) [Name of the tab, Tab Inventory]  **/
        unsigned int next_id;                                      /**                       |                                                                          **/
                                                                   /**             ----Int---|---Entity----  :Entity Inventory [ID of entity, Entity itself]            **/
}

#endif
