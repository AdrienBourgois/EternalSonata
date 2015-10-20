#ifndef __EVENTRECEIVER_H__
#define __EVENTRECEIVER_H__
#include "myIrrlicht.h"

enum mainMenuButton
{
    GUI_ID_PLAY_BUTTON = 101,
    GUI_ID_QUIT_BUTTON,
};

enum pauseMenuButton
{
    GUI_ID_PAUSE_RESUME_BUTTON = 201,
    GUI_ID_PAUSE_QUIT_BUTTON,
};

class EventReceiver : public irr::IEventReceiver
{
    private:

        /** KEYBOARD EVENT MANAGER **/
        struct SKeyboardState
        {
            bool KeyDown[irr::KEY_KEY_CODES_COUNT];

        } KeyboardState;

        /** MOUSE EVENT MANAGER **/
        struct SMouseState
        {
            irr::core::vector2d<irr::f32> position;
            bool LMBD, RMBD;
            SMouseState() : LMBD(false), RMBD(false) {};
        } MouseState;

        irr::s32 idButton;

    public:
        EventReceiver();
        ~EventReceiver() = default;

        EventReceiver(EventReceiver const&) = delete;
        EventReceiver& operator =(EventReceiver const&) = default; 

        virtual bool OnEvent(const irr::SEvent&);

        const bool& isLMBD() const { return MouseState.LMBD; }
        const bool& isRMBD() const { return MouseState.RMBD; }
        const bool& GetKeyboardState(irr::EKEY_CODE keyCode) const { return KeyboardState.KeyDown[keyCode]; }
        const irr::s32& getIdButton() { return idButton; }
};

#endif // __EVENTRECEIVER_H__
