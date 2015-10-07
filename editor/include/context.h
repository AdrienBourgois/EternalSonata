#ifndef __CONTEXT_INCLUDE__
#define __CONTEXT_INCLUDE__

struct SAppContext
{
    SAppContext()
        : Device(0),Gui(0), Driver(0), Player(0), ShouldQuit(false),
        ButtonSave(0), ButtonExit(0)
    {
    }

    ~SAppContext();

    IrrlichtDevice* Device;
    IGUIEnvironment* Gui;
    IVideoDriver* Driver;
    PlayerManager* Player;
    bool ShouldQuit;

    IGUIButton* ButtonSave;
    IGUIButton* ButtonExit;

    IGUIEditBox* nameBox;
    IGUIEditBox* strengthBox;
    IGUIEditBox* dexterityBox;
    IGUIEditBox* intelligenceBox;
    IGUIEditBox* speedBox;
    IGUIEditBox* resistanceBox;
    IGUIEditBox* luckBox;
    IGUIEditBox* spiritBox;
    IGUIEditBox* agilityBox;
};

#endif
