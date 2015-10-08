#include "Character.h"
#include <iostream>

int main()
{
    using namespace std;

    Character player;
    cout << player;

    player.setName("Tayko");
    player.setStrength(150);
    player.setDexterity(200);
    player.setIntelligence(130);
    player.setSpeed(300);
    player.setResistance(100);
    player.setLuck(999);
    player.setSpirit(95);
    player.setAgility(230);

    Weapon w("Epic Potato", 999);
    Armor a;
    
    a.setHead(new Armor_Piece(5));
    a.setTorso(new Armor_Piece(15, 15, "WaterMelon Legendary Torso"));
    a.setPants(new Armor_Piece(10, 18));
    a.setGloves(new Armor_Piece(3, "Delicate Princesse Gloves"));
    a.setBoots(new Armor_Piece(999, 999, "Cheater's boots"));

    player.setArmor(&a);
    player.setWeapon(&w);

    cout << player;


    return 0;
}
