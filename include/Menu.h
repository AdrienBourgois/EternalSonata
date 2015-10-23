#ifndef __MENU_INCLUDE__
#define __MENU_INCLUDE__

#include "myIrrlicht.h"
#include "EventReceiver.h"
#include "Hero.h"

using namespace irr;

class Menu
{
public:
    Menu() = default;
    ~Menu() = default;

    void showMainMenu();
    void showPauseMenu();
    void showPlayerMenu(Hero);
    void showStat(const wchar_t *, int, int, int);
    void showFightMenu();
    void quitMenu();

    void setWindowSize(core::dimension2d<u32> size) { if (this->windowSize != size) 
                                                        {windowSize = size;
                                                        this->newSize = true;}}

    void setResponsive() { this->window_width = this->windowSize.Width;
                           this->window_height = this->windowSize.Height;
                           this->w_w_100 = this->window_width / 100;
                           this->w_h_100 = this->window_height / 100; }

    void setDevice(IrrlichtDevice* device) {this->device = device;
                                            this->driver = device->getVideoDriver();
                                            this->env = device->getGUIEnvironment();}

    bool isMainDisplay() {if (this->mainDisplay) return true;
                          else return false;}
    bool isPauseDisplay() {if (this->pauseDisplay) return true;
                          else return false;}
    bool isPlayerDisplay() {if (this->playerDisplay) return true;
                          else return false;}
    bool isFightDisplay() {if (this->fightDisplay) return true;
                          else return false;}

    void updateMenu(Hero);

private:
    IrrlichtDevice* device;
    video::IVideoDriver* driver;
    gui::IGUIEnvironment* env;
    core::dimension2d<u32> windowSize;
    bool newSize;
    int window_height;
    int window_width;
    int w_h_100;
    int w_w_100;
    int mainDisplay = 0;
    int pauseDisplay = 0;
    int playerDisplay = 0;
    int fightDisplay = 0;
    int menuToBeDisplay = 0;
};

#endif
