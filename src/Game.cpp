#include "Game.h"
#include <cassert>
Game::Game()
{
    device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640u, 480u), 16, 0, 0, 0, &event_receiver);

    assert(device);

    driver = device->getVideoDriver();
    scene_manager = device->getSceneManager();
}

void Game::loadMap()
{
    device->getFileSystem()->addFileArchive("assets/map-20kdm2.pk3");
    irr::scene::IAnimatedMesh* map_mesh = scene_manager->getMesh("20kdm2.bsp");
    irr::scene::IMeshSceneNode* mesh_map_node = 0;

    if (map_mesh)
         mesh_map_node = scene_manager->addOctreeSceneNode(map_mesh->getMesh((0), 0, -1, 1024));

    irr::scene::ITriangleSelector* selector = 0;

    if (mesh_map_node)
    {
        mesh_map_node->setPosition(irr::core::vector3df(-1300.f, -144.f, -1249.f));
        selector = scene_manager->createOctreeTriangleSelector(mesh_map_node->getMesh(), mesh_map_node, 128);
        mesh_map_node->setTriangleSelector(selector);
    }

    loadPlayer(selector);

    
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

void Game::loadPlayer(irr::scene::ITriangleSelector* t)
{
    character1 = new Hero;

    character1->assertCharacter(static_cast<Character>(*character1));

    auto controls = getWASDControl();

    camera = scene_manager->addCameraSceneNodeFPS(0, 100.f, 0.5f, -1, controls.data(), 6, true, 3.f);
    camera->setPosition(irr::core::vector3df(50, 50, -60));

    if (t)
    {
        irr::scene::ISceneNodeAnimator* scene_node_animator = scene_manager->createCollisionResponseAnimator(t, camera, irr::core::vector3df(30.f, 50.f, 30.f), irr::core::vector3df(0.f, -10.f, 0.f), irr::core::vector3df(0.f, 30.f, 0.f));
        t->drop();

        camera->addAnimator(scene_node_animator);
        scene_node_animator->drop();
    }

    device->getCursorControl()->setVisible(false);
}

void Game::run()
{
    while (device->run())
    {
        execute_event(event_receiver);
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, irr::video::SColor(255, 28, 5, 0));
            scene_manager->drawAll();
            driver->endScene();
        }
        else
            device->yield();
    }
}

void Game::end()
{
    device->drop();
}


