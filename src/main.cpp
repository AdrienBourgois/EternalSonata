#include <iostream>
#include "myIrrlicht.h"

using namespace irr;
using namespace std;

int main(int, char*[])
{
    IrrlichtDevice* device = createDevice(video::EDT_OPENGL, {640,480}, 16, false, false, false, 0);

    if (!device)
        return EXIT_FAILURE;

    device->setWindowCaption(L"Eternal Sonata");

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

    scene::ITerrainSceneNode* terrain = smgr->addTerrainSceneNode("assets/terrain-heightmap.bmp", 0, -1, {0.f,0.f,0.f}, {0.f,0.f,0.f}, {40.f,1.f,40.f}, {255,255,255,255}, 1);
    terrain->setMaterialFlag(video::EMF_LIGHTING, false);
    terrain->setMaterialTexture(0, driver->getTexture("assets/terrain-texture.jpg"));
    terrain->setMaterialTexture(1, driver->getTexture("assets/detailmap3.jpg"));
    terrain->setMaterialType(video::EMT_DETAIL_MAP);
    terrain->scaleTexture(1.0f, 20.0f);

    scene::ICameraSceneNode* camera = smgr->addCameraSceneNodeFPS(0,100.0f,3.f);
    camera->setPosition(core::vector3df(2700*2,255*2,2600*2));
    camera->setTarget(core::vector3df(2397*2,343*2,2700*2));
    camera->setFarValue(42000.0f);

    while(device->run())
    {
        driver->beginScene(true, true);

        smgr->drawAll();
        guienv->drawAll();

        driver->endScene();
    }

    device->drop();

    return EXIT_SUCCESS;
}
