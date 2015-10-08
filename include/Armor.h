#ifndef __ARMOR_H__
#define __ARMOR_H__

#include "Armor_Piece.h"

class Armor
{
    private:
        Armor_Piece* head;
        Armor_Piece* torso;
        Armor_Piece* pants;
        Armor_Piece* boots;
        Armor_Piece* gloves;

    public:
        Armor();
        Armor(Armor const&) = default;
        ~Armor() = default;

        Armor& operator =(Armor const&) = default;

        void setHead(Armor_Piece* h)    {head = h;};
        void setTorso(Armor_Piece* t)   {torso = t;};
        void setPants(Armor_Piece* p)   {pants = p;};
        void setBoots(Armor_Piece* b)   {boots = b;};
        void setGloves(Armor_Piece* g)  {gloves = g;};

        auto& getHead() const    {return head;};
        auto& getTorso() const   {return torso;};
        auto& getPants() const   {return pants;};
        auto& getBoots() const   {return boots;};
        auto& getGloves() const  {return gloves;};
};

#endif
