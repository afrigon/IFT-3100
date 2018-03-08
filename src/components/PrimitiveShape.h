#pragma once

#include "components/Renderable.h"
#include "math/Vector3.h"
#include "ofMain.h"

#include <vector>

namespace Component
{

    class PrimitiveShape : public Renderable
    {
        ofColor fillColor;
        ofColor drawColor;
        unsigned int borderWidth;
        std::vector<Vector3> points;

        void drawShape();
    public:
        PrimitiveShape();
        ~PrimitiveShape();

        void render();
        unsigned int getPointCount();
        void setPointSize(unsigned int newSize);
        bool setPoint(unsigned int point, Vector3 position);
        ofColor getFillColor();
        ofColor getDrawColor();
        unsigned int getBorderWidth();
        vector<Vector3>& getPoints();
        void setFillColor(ofColor color);
        void setDrawColor(ofColor color);
        void setBorderWidth(unsigned int width);
    };
}
