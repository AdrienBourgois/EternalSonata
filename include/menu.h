#ifndef __MENU_INCLUDE__
#define __MENU_INCLUDE__

#include "myIrrlicht.h"

using namespace irr;

class Menu
{
public:
    Menu() = default;
    ~Menu() = default;

    void showMainMenu();
    void showPauseMenu();

    void setWindowSize(const int width, const int height) { this->window_width = width;
                                                       this->window_height = height; }

    void setResponsive() { window_width_100 = window_width / 100;
                      window_height_100 = window_height / 100; }

    void setDevice(IrrlichtDevice* device) {this->device = device;
                                            this->driver = device->getVideoDriver();
                                            this->env = device->getGUIEnvironment();}

    bool isMenuDisplay() {if (this->menuDisplay) return true;
                          else return false;}

private:
    IrrlichtDevice* device;
    video::IVideoDriver* driver;
    gui::IGUIEnvironment* env;
    int window_height;
    int window_width;
    int window_height_100;
    int window_width_100;
    int menuDisplay = 0;
};

#endif
