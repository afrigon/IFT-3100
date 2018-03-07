#pragma once

#include "components/AbstractComponent.h"
#include "components/Renderable.h"
#include "math/Vector3.h"
#include "ofMain.h"

#include <vector>

class PrimitiveShape : public Renderable
{
    ofColor fillColor;
    ofColor drawColor;
    unsigned int lineWidth;
    std::vector<Vector3> points;

    void drawShape();

public:
    PrimitiveShape();
    ~PrimitiveShape();

    void render();
    unsigned int getPointCount();
    void setPointSize(unsigned int newSize);
    bool setPoint(unsigned int point, Vector3& position);
    void setFillColor(ofColor& color);
    void setDrawColor(ofColor& color);
    void setLineWidth(unsigned int width);
    std::vector<Vector3>& getPoints()
    {
        return points;
    };
    ofColor& getFillColor()
    {
        return fillColor;
    };
    ofColor& getDrawColor()
    {
        return drawColor;
    };
    unsigned int getLineWidth()
    {
        return lineWidth;
    }
};

