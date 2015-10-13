#ifndef __C_SCENE_NODE_H__
#define __C_SCENE_NODE_H__

#include "myIrrlicht.h"

class CSceneNode : public irr::scene::ISceneNode
{
    private:
        irr::scene::ISceneNode*         sceneNode;
        irr::scene::IMesh*              mesh;
        irr::video::SMaterial*          material;

    public:
        CSceneNode();
        ~CSceneNode();

        void setMesh(irr::scene::IMesh* mesh)               { this->mesh = mesh; };
        void setMaterial(irr::video::SMaterial* material)   { this->material = material; };
        void setSceneNode(auto* custom_sceneNode)           { this->sceneNode = custom_sceneNode ;};

        auto& getMesh()         {return mesh;};
        auto& getMaterial()     {return material;};
        auto& getSceneNode()    {return sceneNode;};
};

#endif // __C_SCENE_NODE_H__
