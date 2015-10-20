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
    float w = 0;
    float a = 0;
    float s = 0;
    float d = 0;

    if (event_receiver.GetKeyboardState(irr::KEY_KEY_W))
        w = 1.f;
    else
        w = 0.f;
    
    if (event_receiver.GetKeyboardState(irr::KEY_KEY_A))
        a = 1.f;
    else
        a = 0.f;

    if (event_receiver.GetKeyboardState(irr::KEY_KEY_D))
        d = 1.f;
    else
        d = 0.f;
    
    if (event_receiver.GetKeyboardState(irr::KEY_KEY_S))
        s = 1.f;
    else
        s = 0.f;

    float speed = 4.f;

    if (event_receiver.GetKeyboardState(irr::KEY_LSHIFT))
        speed = 1.f;

    float directionKeys = w + a + s + d;
    float totalAngles = d * 90.f + s * 180.f + a * 270.f;
    float rotation = 0.f;
    
    if (a == 1.f && w == 1.f)
        totalAngles += 360.f;

    if (directionKeys != 0)
        rotation = totalAngles / directionKeys;

    irr::core::vector3df currentPos = character->getPosition();
    character->setPosition(currentPos + irr::core::vector3df(speed*(d-a), 0.f, speed*(w-s)));

    if (directionKeys > 0 && !playerWalk)
    {
        playerWalk = true;
        character->getNode()->setFrameLoop(0, 13);
        character->getNode()->setLoopMode(true);
    }
    else if (directionKeys == 0 && playerWalk)
    {
        playerWalk = false;
        character->getNode()->setFrameLoop(206,250);
        character->getNode()->setLoopMode(true);
    }
    else if (event_receiver.GetKeyboardState(irr::KEY_LSHIFT) && directionKeys > 0 && !playerStealth)
    {
        character->getNode()->setFrameLoop(14, 29);
        character->getNode()->setLoopMode(true);
        playerWalk = true;
        playerStealth = true;
    }
    else if (!event_receiver.GetKeyboardState(irr::KEY_LSHIFT) && directionKeys > 0 && playerStealth)
    {
        character->getNode()->setFrameLoop(0, 13);
        character->getNode()->setLoopMode(true);
        playerStealth = false;
    }

    if (event_receiver.GetKeyboardState(irr::KEY_SPACE) && !playerAttacked)
    {
        playerAttacked = true;
        character->getNode()->setFrameLoop(133, 144);  
        character->getNode()->setLoopMode(false);
    }

    if (!event_receiver.GetKeyboardState(irr::KEY_SPACE))
    {
        playerAttacked = false;
    }

    if (directionKeys > 0)
    {
        character->getNode()->setRotation(irr::core::vector3df(0.f, rotation, 0.f));
       character->setPosition(currentPos + irr::core::vector3df(0, 0, -2));
    }

    if (event_receiver.getIdButton() == GUI_ID_QUIT_BUTTON || event_receiver.getIdButton() == GUI_ID_PAUSE_QUIT_BUTTON)
        device->closeDevice();

    else if (event_receiver.getIdButton() == GUI_ID_PLAY_BUTTON || event_receiver.getIdButton() == GUI_ID_PAUSE_RESUME_BUTTON)
        menu.closeMenu();

    if (event_receiver.GetKeyboardState(irr::KEY_ESCAPE))
        menu.showPauseMenu();
}
