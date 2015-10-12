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
