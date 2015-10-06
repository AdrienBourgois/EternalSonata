#include "CSceneNode.cpp"
#include <iostream>

CSceneNode::CSceneNode()
{
    std::cout << "Constructing CSceneNode..." << std::endl;
}

CSceneNode::~CSceneNode()
{
    std::cout << "Destructing CSceneNode..." << std::endl;
}
