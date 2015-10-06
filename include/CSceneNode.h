#ifndef __C_SCENE_NODE_H__
#define __C_SCENE_NODE_H__

#include "myIrrlicht.h"

class CSceneNode: public irr::scene::ISceneNode
{
    irr::scene::IMesh mesh;
    irr::video::SMaterial material;

    public:
        CSceneNode();
        ~CSceneNode();

        void setMesh(irr::scene::IMesh mesh)
        { this->mesh = mesh; }

        void setMaterial(irr::video::SMaterial material)
        { this->material = material; }
};

#endif // __C_SCENE_NODE_H__
