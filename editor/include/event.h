#ifndef __EVENT_INCLUDE__
#define __EVENT_INCLUDE__

class EventReceiver : public IEventReceiver
{
public:
    EventReceiver(SAppContext & a) : App(a) { }

    virtual bool OnEvent(const SEvent& event);

private:
    SAppContext & App;

}

#endif
