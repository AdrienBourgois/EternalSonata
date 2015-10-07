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

    this->Gui->addStaticText (L"Dexterity", core::rect< s32 >(10,90, 80, 110), false, true, windowSettings);
    this->Gui->addEditBox (this->Player->getStat("dexterity").c_str(), core::rect<s32>(100,90,200,110), true, windowSettings);

    this->Gui->addStaticText (L"Intelligence", core::rect< s32 >(10,120, 80, 140), false, true, windowSettings);
    this->Gui->addEditBox (this->Player->getStat("intelligence").c_str(), core::rect<s32>(100,120,200,140), true, windowSettings);

    this->Gui->addStaticText (L"Speed", core::rect< s32 >(10,150, 80, 170), false, true, windowSettings);
    this->Gui->addEditBox (this->Player->getStat("speed").c_str(), core::rect<s32>(100,150,200,170), true, windowSettings);

    this->Gui->addStaticText (L"Resistance", core::rect< s32 >(10,180, 80, 200), false, true, windowSettings);
    this->Gui->addEditBox (this->Player->getStat("resistance").c_str(), core::rect<s32>(100,180,200,200), true, windowSettings);

    this->Gui->addStaticText (L"Luck", core::rect< s32 >(10,210, 80, 230), false, true, windowSettings);
    this->Gui->addEditBox (this->Player->getStat("luck").c_str(), core::rect<s32>(100,210,200,230), true, windowSettings);

    this->Gui->addStaticText (L"Spirit", core::rect< s32 >(10,240, 80, 260), false, true, windowSettings);
    this->Gui->addEditBox (this->Player->getStat("spirit").c_str(), core::rect<s32>(100,240,200,260), true, windowSettings);

    this->Gui->addStaticText (L"Agility", core::rect< s32 >(10,270, 80, 290), false, true, windowSettings);
    this->Gui->addEditBox (this->Player->getStat("agility").c_str(), core::rect<s32>(100,270,200,290), true, windowSettings);

    this->ButtonSave = this->Gui->addButton(
            core::rect<s32>(80,350,150,370), windowSettings, 2, L"Save");

    this->ButtonExit = this->Gui->addButton(
            core::rect<s32>(160,350,240,370), windowSettings, 2, L"Cancel and exit");
}
