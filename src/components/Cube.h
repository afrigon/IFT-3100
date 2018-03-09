#pragma once

#include "components/Renderable.h"
#include "math/Vector3.h"
#include "ofMain.h"

namespace Component
{

    class Cube : public Renderable
    {
        ofColor color;
        Vector3 size;
    public:
        Cube();
        ~Cube();

        void render();

        ofColor getColor();
        Vector3 getSize();
        void setColor(ofColor color);
        void setSize(Vector3 size);
    };
}
