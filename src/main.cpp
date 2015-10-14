#include <iostream>
#include "myIrrlicht.h"
#include "EventReceiver.h"
#include "Menu.h"
#include "Game.h"

using namespace irr;
using namespace std;

int main(int, char*[])
{
    Game game;

    game.loadMap();
    game.loadPlayer();

    game.run();

    game.end();

    return EXIT_SUCCESS;
}
