#ifndef __GAME_H__
#define __GAME_H__
#include <array>

#include "myIrrlicht.h"
#include "Hero.h"
#include "EventReceiver.h"

class Game
{
    private:
        irr::video::IVideoDriver*           driver;        /* Default: OPENGL */
        irr::scene::ISceneManager*          scene_manager;
        irr::IrrlichtDevice*                device;
        irr::scene::ICameraSceneNode*       camera;
        EventReceiver                       event_receiver;
        Hero*                               character1;

    public:
        Game();
        ~Game()=default;
        
        Game(Game const&) = delete;
        Game& operator =(Game const&) = delete;
        /* No copy nor assigment allowed */
        
        void loadMap();
        void loadPlayer(irr::scene::ITriangleSelector*);
        void run();
        std::array<irr::SKeyMap, 6> getWASDControl();
        void execute_event(EventReceiver&);
        void end();

};

#endif
