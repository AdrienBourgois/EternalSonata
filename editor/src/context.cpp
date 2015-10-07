#include <iostream>
#include "myIrrlicht.h"
#include "context.h"


SAppContext::~SAppContext()
{
    std::cout << "Desctruct context" << std::endl;

    if (Player)
        delete Player;

    if (Device)
    {
        Device->closeDevice();
        Device->drop();
    }
}

void SAppContext::createPlayerDialog()
{
    std::cout << "Create the player dialog" << std::endl;
    for (irr::s32 i=0; i<irr::gui::EGDC_COUNT ; ++i)
    {
        irr::video::SColor col = this->Gui->getSkin()->getColor((irr::gui::EGUI_DEFAULT_COLOR)i);
        col.setAlpha(255);
        this->Gui->getSkin()->setColor((irr::gui::EGUI_DEFAULT_COLOR)i, col);
    }

    gui::IGUIWindow* windowSettings = this->Gui->addWindow(core::rect<s32>(10,10,400,400),true,L"Player stats");

    this->Gui->addStaticText (L"Name", core::rect< s32 >(10,30, 80, 50), false, true, windowSettings);
    this->Gui->addEditBox (this->Player->getStat("name").c_str(), core::rect<s32>(100,30,200,50), true, windowSettings);

    this->Gui->addStaticText (L"Strength", core::rect< s32 >(10,60, 80, 80), false, true, windowSettings);
    this->Gui->addEditBox (this->Player->getStat("strength").c_str(), core::rect<s32>(100,60,200,80), true, windowSettings);

    this->ButtonSave = this->Gui->addButton(
            core::rect<s32>(80,250,150,270), windowSettings, 2, L"Save");

    this->ButtonExit = this->Gui->addButton(
            core::rect<s32>(160,250,240,270), windowSettings, 2, L"Cancel and exit");
}
