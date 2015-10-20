#include "Game.h"
#include "EventReceiver.h"
#include <cassert>
#include <iostream>

Game::Game()
{
    device = irr::createDevice(irr::video::EDT_OPENGL, {640,480}, 16, false, false, false, &event_receiver);

    assert(device);

    device->setWindowCaption(L"Eternal Sonata");
    
    driver = device->getVideoDriver();
    scene_manager = device->getSceneManager();
    environment = device->getGUIEnvironment();

    menu.setDevice(device);
}

void Game::loadMap()
{
    terrainSceneNode = scene_manager->addTerrainSceneNode("assets/terrain-heightmap.bmp", 0, -1, {0.f,0.f,0.f}, {0.f,0.f,0.f}, {40.f,1.f,40.f}, {255,255,255,255}, 1);
    terrainSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);
    terrainSceneNode->setMaterialTexture(0, driver->getTexture("assets/terrain-texture.jpg"));
    terrainSceneNode->setMaterialTexture(1, driver->getTexture("assets/detailmap3.jpg"));
    terrainSceneNode->setMaterialType(video::EMT_DETAIL_MAP);
    terrainSceneNode->scaleTexture(1.0f, 20.0f);

    terrain = terrainSceneNode->getMesh();
}

std::array<irr::SKeyMap, 6> Game::getWASDControl()
{
    std::array<irr::SKeyMap, 6> controls;

    controls[0].Action =    irr::EKA_MOVE_FORWARD;
    controls[0].KeyCode =   irr::KEY_KEY_W;

    controls[1].Action =    irr::EKA_MOVE_BACKWARD;
    controls[1].KeyCode =   irr::KEY_KEY_S;

    controls[2].Action =    irr::EKA_STRAFE_RIGHT;
    controls[2].KeyCode =   irr::KEY_KEY_D;

    controls[3].Action =    irr::EKA_STRAFE_LEFT;
    controls[3].KeyCode =   irr::KEY_KEY_A;

    controls[4].Action =    irr::EKA_JUMP_UP;
    controls[4].KeyCode =   irr::KEY_SPACE;

    controls[5].Action =    irr::EKA_CROUCH;
    controls[5].KeyCode =   irr::KEY_KEY_C;

    return controls;

}

void Game::loadPlayer()
{
    this->character = new Hero;


    character->setNode(scene_manager->addAnimatedMeshSceneNode(scene_manager->getMesh("assets/ninja.b3d")));
    character->setPosition({1150,250,1150});
    character->getNode()->setScale({7,7,7});
    character->getNode()->setMaterialFlag(video::EMF_LIGHTING, false);
    character->getNode()->setFrameLoop(206,250);
    
    camera = scene_manager->addCameraSceneNode();

    irr::scene::ITriangleSelector* mapSelector = 0;

    mapSelector = scene_manager->createTerrainTriangleSelector(terrainSceneNode, 0);
    this->terrainSceneNode->setTriangleSelector(mapSelector);
    
    irr::scene::ISceneNodeAnimator* scene_node_animator = scene_manager->createCollisionResponseAnimator(mapSelector, character->getNode(), irr::core::vector3df(5,5,5));

    character->getNode()->addAnimator(scene_node_animator);
    scene_node_animator->drop();
    
}

void Game::end()
{
    device->drop();
}

void Game::updateCamera()
{
    core::vector3df posPlayer = character->getPosition();
    core::vector3df posOffset(0.f,-200.f,200.f);
    core::vector3df lookOffset(0.f,-30.f,0.f);
    camera->setPosition(posPlayer - posOffset);
    camera->setTarget(posPlayer - lookOffset);
}

void Game::update()
{
    if (event_receiver.GetKeyboardState(irr::KEY_KEY_W))
    {
        character->moveForward();
    }
    else
        character->idle();

    /**PLAYER MOVE LEFT OR LEFT + UP/DOWN **/
    {
        if (event_receiver.GetKeyboardState(irr::KEY_KEY_A))
            character->moveLeft(false, false);
        
        else if (event_receiver.GetKeyboardState(irr::KEY_KEY_A) && event_receiver.GetKeyboardState(irr::KEY_KEY_W))
            character->moveLeft(true, false);

        else if (event_receiver.GetKeyboardState(irr::KEY_KEY_A) && event_receiver.GetKeyboardState(irr::KEY_KEY_S))
            character->moveLeft(false, true);

        else
            character->idle();
    }

    /** PLAYER MOVING RIGHT OR RIGHT + UP/DOWN **/
    {
        if (event_receiver.GetKeyboardState(irr::KEY_KEY_D))
            character->moveRight(false, false);
        
        else if (event_receiver.GetKeyboardState(irr::KEY_KEY_D) && event_receiver.GetKeyboardState(irr::KEY_KEY_W))
            character->moveRight(true, false);

        else if (event_receiver.GetKeyboardState(irr::KEY_KEY_D) && event_receiver.GetKeyboardState(irr::KEY_KEY_S))
            character->moveRight(false, true);

        else
            character->idle();
    }
    
    if (event_receiver.GetKeyboardState(irr::KEY_KEY_S))
        character->moveBackward();
    else
        character->idle();

    if (event_receiver.getIdButton() == GUI_ID_QUIT_BUTTON || event_receiver.getIdButton() == GUI_ID_PAUSE_QUIT_BUTTON)
        device->closeDevice();

    else if (event_receiver.getIdButton() == GUI_ID_PLAY_BUTTON || event_receiver.getIdButton() == GUI_ID_PAUSE_RESUME_BUTTON)
        menu.closeMenu();

    if (event_receiver.GetKeyboardState(irr::KEY_ESCAPE))
        menu.showPauseMenu();
}
