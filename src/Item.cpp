#include "Item.h"

unsigned int Item::ID_count = 0;

Item::Item()
{
    name = "Unknow Item";
    description = "You cannot say anything about it.";
    ++ID_count;
    id = ID_count;
    stat_modifier = 1;
    itemClass = OTHER;
}
