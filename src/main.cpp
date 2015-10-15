#include <iostream>
#include "myIrrlicht.h"
#include "EventReceiver.h"
#include "menu.h"
#include "Hero.h"

using namespace irr;
using namespace std;

int main(int, char*[])
{
    EventReceiver event;
    Game game;

    event->setGame(game);

    IrrlichtDevice* device = createDevice(video::EDT_OPENGL, {640,480}, 16, false, false, false, &event);

    if (!device)
        return EXIT_FAILURE;

    device->setWindowCaption(L"Eternal Sonata");

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

    Menu menu;
    menu.setDevice(device);

    scene::ITerrainSceneNode* terrain = smgr->addTerrainSceneNode("assets/terrain-heightmap.bmp", 0, -1, {0.f,0.f,0.f}, {0.f,0.f,0.f}, {40.f,1.f,40.f}, {255,255,255,255}, 1);
    terrain->setMaterialFlag(video::EMF_LIGHTING, false);
    terrain->setMaterialTexture(0, driver->getTexture("assets/terrain-texture.jpg"));
    terrain->setMaterialTexture(1, driver->getTexture("assets/detailmap3.jpg"));
    terrain->setMaterialType(video::EMT_DETAIL_MAP);
    terrain->scaleTexture(1.0f, 20.0f);

    Hero* hero = new Hero;

    scene::IAnimatedMeshSceneNode* player = smgr->addAnimatedMeshSceneNode(smgr->getMesh("assets/ninja.b3d"));
    player->setPosition({1150,250,1150});
    player->setScale({7,7,7});
    player->setMaterialFlag(video::EMF_LIGHTING, false);
    player->setFrameLoop(206,250);

    hero->setNode(player);

    scene::ICameraSceneNode* camera = smgr->addCameraSceneNode();
    core::vector3df posPlayer = player->getPosition();
    core::vector3df posOffset(0.f,-100.f,100.f);
    core::vector3df lookOffset(0.f,-30.f,0.f);
    camera->setPosition(posPlayer - posOffset);
    camera->setTarget(posPlayer - lookOffset);

    while(device->run())
    {
        event.checkAndExec();

        menu.showMainMenu();

        driver->beginScene(true, true);

        smgr->drawAll();
        guienv->drawAll();

        driver->endScene();
    }

    device->drop();

    return EXIT_SUCCESS;
}
