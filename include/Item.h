#ifndef __ITEM_H__
#define __ITEM_H__

#include "ItemClass.h"
#include <iostream>

class Item
{
    private:
        int stat_modifier;
        unsigned int id;
        std::string name;
        std::string description;
        ItemClass itemClass;


    public:
        static unsigned int ID_count;
        
        Item();
        Item(Item const&) = default;
        ~Item() = default;

        Item& operator =(Item const&) = default;

        int getStatModifier()       {return stat_modifier;};
        auto getID() const          {return id;};
        auto getName() const        {return name;};
        auto getDescription() const {return description;};
        auto getItemClass() const   {return itemClass;};

        void setStatModifier(int new_statM_value)   {stat_modifier = new_statM_value;};
        void setName(std::string new_name)          {name = new_name;};
        void setDescription(std::string new_desc)   {description = new_desc;};
        void setItemClass(ItemClass new_itemClass)  {itemClass = new_itemClass;};
};

#endif
