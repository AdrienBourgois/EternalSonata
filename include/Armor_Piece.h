#ifndef __ARMOR_PIECE_H__
#define __ARMOR_PIECE_H__
#include <iostream>
#include "myIrrlicht.h"

class Armor_Piece
{
    private:

        int phy_Defence;
        int mag_Defence;
        std::string name;

    public:
        Armor_Piece();

        Armor_Piece(int phyMagD)        
            :phy_Defence(phyMagD), mag_Defence(phyMagD), name("Magical Invisible Armor"){};
        
        Armor_Piece(int phyD, int magD) 
            :phy_Defence(phyD), mag_Defence(magD), name("Magical Invisible Armor"){};
        
        Armor_Piece(int phyMagD, std::string n)
            :phy_Defence(phyMagD), mag_Defence(phyMagD), name(n){};

        Armor_Piece(int phyD, int magD, std::string n)
            :phy_Defence(phyD), mag_Defence(magD), name(n){};

        Armor_Piece(Armor_Piece const&) = default;
        
        ~Armor_Piece() = default;

        Armor_Piece& operator =(Armor_Piece const&) = default;

        void setPhyDef(int pd)              {phy_Defence = pd;};
        void setMagDef(int md)              {mag_Defence = md;};
        void setName(std::string n)         {name = n;};

        int getPhyDef() const       {return phy_Defence;};
        int getMagDef() const       {return mag_Defence;};
        std::string getName() const {return name;};
};

#endif
