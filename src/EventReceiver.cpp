#include "EventReceiver.h"
#include <iostream>

EventReceiver::EventReceiver()
{
    for (irr::u32 i = 0 ; i < irr::KEY_KEY_CODES_COUNT ; ++i)
        KeyboardState.KeyDown[i] = false;
}

bool EventReceiver::OnEvent(const irr::SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        KeyboardState.KeyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    else if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
    {
        switch (event.MouseInput.Event)
        {
            case irr::EMIE_LMOUSE_PRESSED_DOWN:
                MouseState.LMBD = true;
                break;

            case irr::EMIE_LMOUSE_LEFT_UP:
                MouseState.LMBD = false;
                break;

            case irr::EMIE_RMOUSE_PRESSED_DOWN:
                MouseState.RMBD = true;
                break;

            case irr::EMIE_RMOUSE_LEFT_UP:
                MouseState.RMBD = false;
                break;

            default:
                break; /** Wheel not used **/
        }
    }

    else if (event.EventType == irr::EET_GUI_EVENT)
    {
        irr::s32 id = event.GUIEvent.Caller->getID();

        switch(event.GUIEvent.EventType)
        {
            case irr::gui::EGET_BUTTON_CLICKED:
                switch(id)
                {
                    /* Main Menu */
                    case GUI_ID_PLAY_BUTTON:
                        return true;

                    case GUI_ID_QUIT_BUTTON:
                        return true;

                    /* Pause Menu */

                    case GUI_ID_PAUSE_RESUME_BUTTON:
                        return true;

                    case GUI_ID_PAUSE_QUIT_BUTTON:
                        return true;

                    /* --------- */
                    default:
                        return false;
                }

            default:
                return false;
        }
    }

    return false;
}


