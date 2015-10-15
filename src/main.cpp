#include <iostream>
#include "myIrrlicht.h"
#include "EventReceiver.h"
#include "Menu.h"
#include "Game.h"
#include "Hero.h"

using namespace irr;
using namespace std;

int main(int, char*[])
{
    EventReceiver event;
    Game game;

    event->setGame(game);

    game.loadMap();
    game.loadPlayer();

    game.run();

    game.end();
    
    return EXIT_SUCCESS;
}
