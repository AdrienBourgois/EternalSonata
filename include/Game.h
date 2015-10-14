#ifndef __GAME_H__
#define __GAME_H__
#include <array>

#include "myIrrlicht.h"
#include "Hero.h"
#include "EventReceiver.h"
#include "Menu.h"

class Game
{
    private:
        irr::video::IVideoDriver*           driver;        /* Default: OPENGL */
        irr::scene::ISceneManager*          scene_manager;
        irr::IrrlichtDevice*                device;
        irr::gui::IGUIEnvironment*          environment;
        Menu                                menu;

        irr::scene::IMesh*                  terrain; 

        irr::scene::ICameraSceneNode*       camera;
        EventReceiver                       event_receiver;
        Hero*                               character1;
        scene::IAnimatedMeshSceneNode*      player;

    public:
        Game();
        ~Game()=default;
        
        Game(Game const&) = delete;
        Game& operator =(Game const&) = delete;
        /* No copy nor assigment allowed */
        
        void loadMap();
        void loadPlayer();
        void run();
        std::array<irr::SKeyMap, 6> getWASDControl();
        void end();

        void updateCamera();

        irr::video::IVideoDriver* getDriver() {return driver;}
        irr::IrrlichtDevice* getDevice() {return device;}
        irr::scene::ISceneManager* getScene_manager() {return scene_manager;}
        irr::gui::IGUIEnvironment* getEnvironment() {return environment;}


};

#endif
