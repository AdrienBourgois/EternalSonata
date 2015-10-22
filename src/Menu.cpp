#include <iostream>
#include "Menu.h"

using namespace irr;

void Menu::showMainMenu()
{
    setWindowSize(driver->getScreenSize());
    this->env = this->device->getGUIEnvironment();
    if (!this->isMainDisplay() || this->newSize)
    {
        env->clear();
        this->setResponsive();
        env->addButton({40 * w_w_100, 50 * w_h_100, 60 * w_w_100, 60 * w_h_100},
                0, GUI_ID_PLAY_BUTTON, L"Play");
        env->addButton({40 * w_w_100, 70 * w_h_100, 60 * w_w_100, 80 * w_h_100},
                0, GUI_ID_QUIT_BUTTON, L"Quit");

        this->mainDisplay = 1;
        this->newSize = false;
    }
}

void Menu::showPauseMenu()
{
    setWindowSize(driver->getScreenSize());
    this->env = this->device->getGUIEnvironment();
    if (!this->isPauseDisplay() || this->newSize)
    {
        env->clear();
        this->setResponsive();
        env->addButton({40 * w_w_100, 50 * w_h_100, 60 * w_w_100, 60 * w_h_100},
                0, GUI_ID_PLAY_BUTTON, L"Resume");
        env->addButton({40 * w_w_100, 70 * w_h_100, 60 * w_w_100, 80 * w_h_100},
                0, GUI_ID_QUIT_BUTTON, L"Quit");

        this->pauseDisplay = 1;
        this->newSize = false;
    }
}

void Menu::showPlayerMenu(Hero player)
{
    setWindowSize(driver->getScreenSize());
    this->env = this->device->getGUIEnvironment();
    if (!this->isPlayerDisplay() || this->newSize)
    {
        env->clear();
        this->setResponsive();
        env->addStaticText(L"", {10 * w_w_100, 10 * w_h_100, 30 * w_w_100, 50 * w_h_100}, false, false, 0, -1, true);

        showStat(L"Life :", player.getLife(), 11, 11);
        showStat(L"Strength :", player.getStrength(), 11, 15);
        showStat(L"Dexterity :", player.getDexterity(), 11, 19);
        showStat(L"Intelligence :", player.getIntelligence(), 11, 23);
        showStat(L"Speed :", player.getSpeed(), 11, 27);
        showStat(L"Resistance :", player.getResistance(), 11, 31);
        showStat(L"Luck :", player.getLuck(), 11, 35);
        showStat(L"Spirit :", player.getSpirit(), 11, 39);
        showStat(L"Agility :", player.getAgility(), 11, 43);

        this->playerDisplay = 1;
        this->newSize = false;
    }
}

void Menu::showStat(const wchar_t * text, int value, int w, int h)
{
    env->addStaticText(text, {w * w_w_100, h * w_h_100, (w+10) * w_w_100, (h+2) * w_h_100});
    env->addStaticText((core::stringw(value).c_str()), {(w+10) * w_w_100, h * w_h_100, (w+20) * w_w_100, (h+2) * w_h_100});
}

void Menu::showFightMenu()
{
    setWindowSize(driver->getScreenSize());
    this->env = this->device->getGUIEnvironment();
    if (!this->isFightDisplay() || this->newSize)
    {
        env->clear();
        this->setResponsive();

        env->addButton({5 * w_w_100, 80 * w_h_100, 25 * w_w_100, 95 * w_h_100},
                0, GUI_ID_FIGHT_ATTACK, L"Attack !");
        env->addButton({30 * w_w_100, 80 * w_h_100, 50 * w_w_100, 95 * w_h_100},
                0, GUI_ID_FIGHT_MAGIC, L"Magic !");
        env->addButton({55 * w_w_100, 80 * w_h_100, 75 * w_w_100, 95 * w_h_100},
                0, GUI_ID_FIGHT_INVENTORY, L"Inventory");
        env->addButton({80 * w_w_100, 80 * w_h_100, 100 * w_w_100, 95 * w_h_100},
                0, GUI_ID_FIGHT_RUN, L"Run !");

        this->fightDisplay = 1;
        this->newSize = false;
    }
    
}

void Menu::quitMenu()
{
    mainDisplay = 0;
    pauseDisplay = 0;
    playerDisplay = 0;
    fightDisplay = 0;
    menuToBeDisplay = 0;
    env->clear();
}
