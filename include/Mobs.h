#ifndef __MOBS_H__
#define __MOBS_H__

#include "Character.h"

class Mobs : public Character
{
    private:
        unsigned int enemy_ID;
    
    public:
        static unsigned int ID;
        
        Mobs();
        Mobs(Mobs const&) = default;
        ~Mobs() = default;

        auto getID()    {return enemy_ID;}
}

#endif
