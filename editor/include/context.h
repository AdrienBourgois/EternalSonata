#ifndef __CONTEXT_INCLUDE__
#define __CONTEXT_INCLUDE__

#include "myIrrlicht.h"
#include "XMLmanager.h"

using namespace irr;

struct SAppContext
{
    SAppContext()
        : Device(0),Gui(0), Driver(0), Player(0), ShouldQuit(false),
        ButtonSave(0), ButtonExit(0)
    {
    }

    ~SAppContext();

    IrrlichtDevice* Device;
    gui::IGUIEnvironment* Gui;
    video::IVideoDriver* Driver;
    PlayerManager* Player;
    bool ShouldQuit;

    gui::IGUIButton* ButtonSave;
    gui::IGUIButton* ButtonExit;

    gui::IGUIEditBox* nameBox;
    gui::IGUIEditBox* strengthBox;
    gui::IGUIEditBox* dexterityBox;
    gui::IGUIEditBox* intelligenceBox;
    gui::IGUIEditBox* speedBox;
    gui::IGUIEditBox* resistanceBox;
    gui::IGUIEditBox* luckBox;
    gui::IGUIEditBox* spiritBox;
    gui::IGUIEditBox* agilityBox;

    void createPlayerDialog();
};

#endif
