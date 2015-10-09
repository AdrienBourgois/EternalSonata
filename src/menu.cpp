#include <iostream>
#include "myIrrlicht.h"
#include "menu.h"
#include "EventReceiver.h"

using namespace irr;

void Menu::showMainMenu()
{
    this->env = this->device->getGUIEnvironment();
    if (!this->isMenuDisplay())
    {
        this->setResponsive();
        gui::IGUIButton* playButton = env->addButton({40 * window_width_100, 50 * window_height_100, 60 * window_width_100, 60 * window_height_100},
                0, GUI_ID_PLAY_BUTTON, L"Play");
        gui::IGUIButton* quitButton = env->addButton({40 * window_width_100, 70 * window_height_100, 60 * window_width_100, 80 * window_height_100},
                0, GUI_ID_QUIT_BUTTON, L"Quit");

        (void)playButton;
        (void)quitButton;

        this->menuDisplay = 1;
    }
}
