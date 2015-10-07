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
        Armor() = default;
        Armor(Armor const&) = default;
        ~Armor() = default;

        Armor& operator =(Armor const&) = default;

        void setHead(Armor const& h)    :head(h);
        void setTorso(Armor const& t)   :torso(t);
        void setPants(Armor const& p)   :pants(p);
        void setBoots(Armor const& b)   :boots(b);
        void setGloves(Armor const& g)  :gloves(g);

        auto& getHead() const    {return head;};
        auto& getTorso() const   {return torso;};
        auto& getPants() const   {return pants;};
        auto& getBoots() const   {return boots;};
        auto& getGloves() const  {return gloves;};
}

#endif
