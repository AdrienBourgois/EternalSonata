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
    Game game;

    game.loadMap();
    game.loadPlayer();

    while (game.getDevice()->run())
    {
        game.checkAndExec();
        if (game.getDevice()->isWindowActive())
        {
            //updateCamera();
            game.getDriver()->beginScene(true, true);
            game.getScene_manager()->drawAll();
            game.getDriver()->endScene();
        }
        else
            game.getDevice()->yield();
    }

    game.end();
    
    return EXIT_SUCCESS;
}
