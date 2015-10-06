#ifndef __EVENTRECEIVER_H__
#define __EVENTRECEIVER_H__
#include "myIrrlicht.h"

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

    public:
        EventReceiver();
        ~EventReceiver() = default;

        EventReceiver(EventReceiver const&) = delete;
        EventReceiver& operator =(EventReceiver const&) = delete; 

        virtual bool OnEvent(const irr::SEvent&);

        const bool& isLMBD() const {return MouseState.LMBD;};
        const bool& isRMBD() const {return MouseState.RMBD;};
        const bool& GetKeyboardState(irr::EKEY_CODE keyCode) const {return KeyboardState.KeyDown[keyCode];};
};

#endif // __EVENTRECEIVER_H__
