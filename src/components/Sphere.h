#pragma once

#include "components/Renderable.h"
#include "ofMain.h"

namespace Component
{

    class Sphere : public Renderable
    {
        ofColor color;
        unsigned int radius;
    public:
        Sphere();
        ~Sphere();

        void render();
        ofColor getColor();
        unsigned int getRadius();
        void setColor(ofColor color);
        void setRadius(unsigned int radius);
    };
}
