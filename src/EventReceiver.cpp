#include "EventReceiver.h"

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

    return false;
}


