#pragma once

#include "components/Renderable.h"
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

namespace Component
{

    class Model : public Renderable
    {
        ofxAssimpModelLoader model;
    public:
        Model();
        ~Model();

        void render();
        void loadModel(std::string path);
    };
}
