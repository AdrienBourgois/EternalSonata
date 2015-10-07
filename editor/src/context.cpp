#include "myIrrlicht.h"
#include "context.h"

SAppContext::~SAppContext()
{
    if (Player)
        delete Player;

    if (Device)
    {
        Device->closeDevice();
        Device->drop();
    }
}
