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

    game.loadMeshes();
    game.loadMap();
    game.loadPlayer();
    game.addMob({1150,1250,1500});
    game.addMob({1050,1250,1500});
    game.addMob({1250,1250,1500});

    game.getMenu().showMainMenu();

    game.getPlayer().debugCharacter();

    while (game.getDevice()->run())
    {
        game.update();
        if (game.getDevice()->isWindowActive())
        {
            game.updateCamera();
            game.getDriver()->beginScene(true, true);
            game.getScene_manager()->drawAll();
            game.getEnvironment()->drawAll();
            game.getDriver()->endScene();
        }
        else
            game.getDevice()->yield();
    }

    game.end();
    
    return EXIT_SUCCESS;
}
