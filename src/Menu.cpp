#include <iostream>
#include "myIrrlicht.h"
#include "Menu.h"
#include "EventReceiver.h"

using namespace irr;

void Menu::showMainMenu()
{
    setWindowSize(driver->getScreenSize());
    this->env = this->device->getGUIEnvironment();
    if (!this->isMenuDisplay() || this->newSize)
    {
        env->clear();
        this->setResponsive();
        env->addButton({40 * window_width_100, 50 * window_height_100, 60 * window_width_100, 60 * window_height_100},
                0, GUI_ID_PLAY_BUTTON, L"Play");
        env->addButton({40 * window_width_100, 70 * window_height_100, 60 * window_width_100, 80 * window_height_100},
                0, GUI_ID_QUIT_BUTTON, L"Quit");

        this->menuDisplay = 1;
        this->newSize = false;
    }
}

void Menu::showPauseMenu()
{
    setWindowSize(driver->getScreenSize());
    this->env = this->device->getGUIEnvironment();
    if (!this->isMenuDisplay() || this->newSize)
    {
        env->clear();
        this->setResponsive();
        env->addButton({40 * window_width_100, 50 * window_height_100, 60 * window_width_100, 60 * window_height_100},
                0, GUI_ID_PLAY_BUTTON, L"Resume");
        env->addButton({40 * window_width_100, 70 * window_height_100, 60 * window_width_100, 80 * window_height_100},
                0, GUI_ID_QUIT_BUTTON, L"Quit");

        this->menuDisplay = 1;
        this->newSize = false;
    }
}

/*void Menu::showPlayerMenu()
{
    setWindowSize(driver->getScreenSize());
    this->env = this->device->getGUIEnvironment();
    if (!this->isMenuDisplay() || this->newSize)
    {
        env->clear();
        this->setResponsive();
        env->addStaticText("", {40 * window_width_100, 70 * window_height_100, 60 * window_width_100, 80 * window_height_100}, false, true, 0, -1, true);
        this->menuDisplay = 1;
        this->newSize = false;
    }
}

void Menu::quitMenu()
{
    menuToBeDisplay = 0;
    env->clear();
}*/
