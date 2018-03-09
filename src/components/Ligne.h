#pragma once

#include "components/Renderable.h"
#include "ofMain.h"

namespace Component
{

    class Ligne : public Renderable
    {
        ofColor lineColor;
        unsigned int lineWidth, lineLength;
    public:
        Ligne();
        ~Ligne();

        void render();
        ofColor getLineColor();
        unsigned int getLineWidth();
        unsigned int getLineLength();
        void setLineColor(ofColor color);
        void setLineWidth(unsigned int width);
        void setLineLength(unsigned int length);
    };
}
