#pragma once

#include "components/Renderable.h"
#include "ofMain.h"

namespace Component
{
    class Rectangle : public Renderable
    {
        ofColor fillColor;
        ofColor drawColor;
        unsigned int borderWidth, width, height;
    public:
        Rectangle();
        ~Rectangle();

        void render();

        ofColor getFillColor();
        ofColor getDrawColor();
        unsigned int getBorderWidth();
        unsigned int getWidth();
        unsigned int getHeight();
        void setFillColor(ofColor color);
        void setDrawColor(ofColor color);
        void setBorderWidth(unsigned int width);
        void setWidth(unsigned int width);
        void setHeight(unsigned int height);
    };
}
