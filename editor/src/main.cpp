#include <iostream>
#include "myIrrlicht.h"

#include "context.h"
#include "XMLmanager.h"
#include "event.h"

using namespace irr;

int main (int, char*[])
{
    SAppContext app;

    app.Player = new PlayerManager("player.xml");
    if (!app.Player->load())
        return EXIT_FAILURE;

    app.Device = createDevice(video::EDT_SOFTWARE, {640,480});

    if (app.Device == 0)
        return EXIT_FAILURE;

    app.Device->setWindowCaption(L"XML Editor");
    app.Driver = app.Device->getVideoDriver();
    app.Gui = app.Device->getGUIEnvironment();

    app.createPlayerDialog();

    EventReceiver receiver(app);
    app.Device->setEventReceiver(&receiver);

    while (!app.ShouldQuit && app.Device->run())
    {
        if (app.Device->isWindowActive())
        {
            app.Driver->beginScene(true, true, video::SColor(0,200,200,200));
            app.Gui->drawAll();
            app.Driver->endScene();

            app.Device->sleep(10);
        }
    }

    return EXIT_SUCCESS;
}
