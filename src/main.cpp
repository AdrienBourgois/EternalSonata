#include "myIrrlicht.h"

int main(int, char*[])
{
    Game game;

    while (game->getDevice->run())
    {
        game.Update();
    }

    game.end();
}
