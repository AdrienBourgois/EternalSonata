#include "myIrrlicht.h"
#include "event.h"

virtual bool EventReceiver::OnEvent(const SEvent& event)
{
    if (event.EventType == EET_GUI_EVENT )
    {
        switch ( event.GUIEvent.EventType )
        {
            case EGET_BUTTON_CLICKED:
            {
                if ( event.GUIEvent.Caller == App.ButtonSave )
                {
                    App.Player->setStat(L"name", App.nameBox->getText());
                    App.Player->setStat(L"strength", App.strengthBox->getText());
                    App.Player->setStat(L"dexterity", App.dexterityBox->getText());
                    App.Player->setStat(L"intelligence", App.intelligenceBox->getText());
                    App.Player->setStat(L"speed", App.speedBox->getText());
                    App.Player->setStat(L"resistance", App.resistanceBox->getText());
                    App.Player->setStat(L"luck", App.luckBox->getText());
                    App.Player->setStat(L"spirit", App.spiritBox->getText());
                    App.Player->setStat(L"agility", App.agilityBox->getText());

                    if (App.Settings->save())
                        App.Gui->addMessageBox(L"Player saved",L"The player has been saved !","",true);
                }

                else if ( event.GUIEvent.Caller == App.ButtonExit)
                    App.ShouldQuit = true;
            }
            break;
        }
    }

    return false;
}
