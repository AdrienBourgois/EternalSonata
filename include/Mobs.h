#ifndef __MOBS_H__
#define __MOBS_H__

#include "Character.h"

class Mobs : public Character
{
    private:

    public:
//        static unsigned int ID;
        
        Mobs();
        Mobs(Mobs const&) = default;
        ~Mobs() = default;


        virtual void update(){};
};

#endif
