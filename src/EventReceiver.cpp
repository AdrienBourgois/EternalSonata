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

    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
    {
        if (event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN)
                MouseState.LMBD = true;

        else if (event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP)
                MouseState.LMBD = false;

        if (event.MouseInput.Event == irr::EMIE_RMOUSE_PRESSED_DOWN)
                MouseState.RMBD = true;

        else if (event.MouseInput.Event == irr::EMIE_RMOUSE_LEFT_UP)
                MouseState.RMBD = false;
    }

    if (event.EventType == irr::EET_GUI_EVENT)
    {
        irr::s32 id = event.GUIEvent.Caller->getID();

        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
            idButton = id;
        else
            idButton = 0;
    }

    return false;
}

void EventReceiver::checkAndExec()
{
    if (GetKeyboardState(irr::KEY_KEY_A))
    {
        std::cout << "A press" << std::endl;
        game.character1->getNode()->setFrameLoop(0, 13);
    }

    if (GetKeyboardState(irr::KEY_KEY_B))
        std::cout << "B press" << std::endl;
}
