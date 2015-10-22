#ifndef __GAME_H__
#define __GAME_H__
#include <array>

#include "myIrrlicht.h"
#include "Hero.h"
#include "EventReceiver.h"
#include "Menu.h"
#include "Mobs.h"
#include "Save.h"

class Game
{
    private:
        irr::video::IVideoDriver*                           driver;        /* Default: OPENGL */
        irr::scene::ISceneManager*                          scene_manager;
        irr::IrrlichtDevice*                                device;
        irr::gui::IGUIEnvironment*                          environment;
        Menu                                                menu;

        irr::scene::IMesh*                                  terrain; 
        scene::ITerrainSceneNode*                           terrainSceneNode;
        scene::ITerrainSceneNode*                           battleSceneNode;
        Hero                                                character;
        scene::IAnimatedMeshSceneNode*                      player;

        irr::scene::ICameraSceneNode*                       camera;
        EventReceiver                                       event_receiver;
        std::vector<Mobs>                                   mobs;
        std::map<std::string, irr::scene::IAnimatedMesh*>   meshes;
        irr::scene::IMetaTriangleSelector* mapSelector;

        bool                                                game_set;

    public:
        Game();
        Game(EventReceiver event);
        ~Game()=default;
        
        Game(Game const&) = delete;
        Game& operator =(Game const&) = delete;
        /* No copy nor assigment allowed */
        
        void loadMap();
        void loadPlayer();
        void loadMeshes();
        void addMob(irr::core::vector3df pos);
        std::array<irr::SKeyMap, 6> getWASDControl();
        void startBattle(std::vector<Mobs> battleGroup);
        bool _checkCollision(Entity& e, Entity& f);
        void end();

        void updateCamera();

        irr::video::IVideoDriver* getDriver()           {return driver;}
        irr::IrrlichtDevice* getDevice()                {return device;}
        irr::scene::ISceneManager* getScene_manager()   {return scene_manager;}
        irr::gui::IGUIEnvironment* getEnvironment()     {return environment;}
        Hero& getPlayer()                               {return this->character; }
        Menu getMenu()                                  {return this->menu;}

        void update();
};

#endif
