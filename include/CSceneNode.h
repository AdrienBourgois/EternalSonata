#ifndef __C_SCENE_NODE_H__
#define __C_SCENE_NODE_H__

#include "myIrrlicht.h"
//#include "AnimatorManager.h"

class CSceneNode: public irr::scene::IAnimatedMeshSceneNode
{
    irr::scene::IAnimatedMesh* mesh;
//    AnimatorManager animgr;
    irr::core::vector3df position;

    public:
        /* CONSTRUCTORS */
        CSceneNode(CSceneNode* parent, irr::scene::ISceneManager* mgr, irr::s32 id)
            : irr::scene::IAnimatedMeshSceneNode(parent, mgr, id) {}

        /* DESTRUCTORS */
        ~CSceneNode() = default;

        /* SETTERS */
        void setMesh(irr::scene::IAnimatedMesh* mesh) { this->mesh = mesh; }
//        void setAnimator(AnimatorManager* animgr) { this->animgr = animgr; }
        void setPosition(irr::core::vector3df position) { this->position = position; }

        /* GETTERS */
        /*const irr::scene::IAnimatedMesh* getMesh() { return this->mesh; }
        const irr::core::vector3df getPosition() { return this->position; }*/
};

#endif /* __C_SCENE_NODE_H__ */
