#ifndef __MOBS_H__
#define __MOBS_H__

#include "Character.h"

class Mobs : public Character
{
    private:
        std::vector<Mobs> battleGroup;

    public:
//        static unsigned int ID;
        
        Mobs();
        Mobs(Mobs const&) = default;
        Mobs(std::vector<Mobs>& battleGroup);
        ~Mobs() { std::cout << "Destroyed mob" << std::endl;};

        virtual void update(){};
        std::vector<Mobs> getGroup() { return this->battleGroup; }
};

#endif
