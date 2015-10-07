#include "myIrrlicht.h"
#include "dialog.h"

void createPlayerDialog(SAppContext& app)
{
    for (irr::s32 i=0; i<irr::gui::EGDC_COUNT ; ++i)
    {
        irr::video::SColor col = app.Gui->getSkin()->getColor((irr::gui::EGUI_DEFAULT_COLOR)i);
        col.setAlpha(255);
        app.Gui->getSkin()->setColor((irr::gui::EGUI_DEFAULT_COLOR)i, col);
    }

    gui::IGUIWindow* windowSettings = app.Gui->addWindow(rect<s32>(10,10,400,400),true,L"Player stats");

    app.Gui->addStaticText (L"Name", rect< s32 >(10,130, 200, 140), false, true, windowSettings);
    app.Gui->addEditBox (app.Player->getStat("name"), rect<s32>(210,130,240,140));

    app.Gui->addStaticText (L"Strength", rect< s32 >(10,150, 200, 160), false, true, windowSettings);
    app.Gui->addEditBox (app.Player->getStat("strength"), rect<s32>(210,150,240,160));

    app.ButtonSave = app.Gui->addButton(
            rect<s32>(80,250,150,270), windowSettings, 2, L"Save");

    app.ButtonExit = app.Gui->addButton(
            rect<s32>(160,250,240,270), windowSettings, 2, L"Cancel and exit");
}
