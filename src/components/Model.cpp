#include "Model.h"

Component::Model::Model()
{
}

Component::Model::~Model()
{
}

void Component::Model::render()
{
    if(model.hasAnimations())
    {
        model.update();
    }
    if(model.hasMeshes())
    {
        model.drawFaces();
    }
}

void Component::Model::loadModel(std::string path)
{
    model.loadModel(path);
    model.playAllAnimations();
    model.setLoopStateForAllAnimations(ofLoopType::OF_LOOP_NORMAL);
}
