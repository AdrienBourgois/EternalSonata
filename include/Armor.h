#ifndef __ARMOR_H__
#define __ARMOR_H__

class Armor
{
    private:
        Armor_Piece head;
        Armor_Piece torso;
        Armor_Piece pants;
        Armor_Piece boots;
        Armor_Piece gloves;

    public:
        Armor();
        Armor(Armor const&) = default;
        ~Armor();

        Armor& operator =(Armor const&) = default;

        void setHead(Armor const& h)    :head(h);
        void setTorso(Armor const& t)   :torso(t);
        void setPants(Armor const& p)   :pants(p);
        void setBoots(Armor const& b)   :boots(b);
        void setGloves(Armor const& g)  :gloves(g);

        Armor_Piece& getHead() const    {return head;};
        Armor_Piece& getTorso() const   {return torso;};
        Armor_Piece& getPants() const   {return pants;};
        Armor_Piece& getBoots() const   {return boots;};
        Armor_Piece& getGloves() const  {return gloves;};



}

#endif
