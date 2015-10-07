#ifndef __ARMOR_PIECE_H__
#define __ARMOR_PIECE_H__

class Armor_Piece
{
    private:
        int Phy_Defence;
        int Mag_Defence;

    public:
        Armor_Piece();
        Armor_Piece(Armor_Piece const&);
        ~Armor_Piece();

        Armor_Piece& operator =(Armor_Piece const&);

        void setPhyDef(int pd): Phy_Defence(pd);
        void setMagDef(int md): Mag_Defence(md);

        int getPhyDef() const   {return Phy_Defence;};
        int getMagDef() const   {return Mag_Defence;};
}

#endif
