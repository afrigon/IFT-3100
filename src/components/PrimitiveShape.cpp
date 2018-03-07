#include "PrimitiveShape.h"



PrimitiveShape::PrimitiveShape()
{
    fillColor = ofColor();
    drawColor = ofColor();
    lineWidth = 2;
    points.resize(0);
}


PrimitiveShape::~PrimitiveShape()
{
}

void PrimitiveShape::drawShape()
{
    ofBeginShape();

    for(unsigned int i = 0; i < points.size(); ++i)
    {
        ofVertex(points[i].getX(), points[i].getY(), points[i].getZ());
    }
    ofVertex(points[0].getX(), points[0].getY(), points[0].getZ());

    ofEndShape();
}

void PrimitiveShape::render()
{
    if(points.size() > 0)
    {
        ofSetPolyMode(ofPolyWindingMode::OF_POLY_WINDING_ODD);

        ofFill();
        ofSetColor(fillColor);
        drawShape();

        ofNoFill();
        ofSetColor(drawColor);
        ofSetLineWidth(lineWidth);
        drawShape();
    }
}

unsigned int PrimitiveShape::getPointCount()
{
    return (unsigned int)points.size();
}

void PrimitiveShape::setPointSize(unsigned int newSize)
{
    points.resize(newSize);
}

bool PrimitiveShape::setPoint(unsigned int point, Vector3 &position)
{
    if(point < points.size())
    {
        points[point] = position;
        return true;
    }
    return false;
}

void PrimitiveShape::setFillColor(ofColor &color)
{
    fillColor = color;
}

void PrimitiveShape::setDrawColor(ofColor &color)
{
    drawColor = color;
}

void PrimitiveShape::setLineWidth(unsigned int width)
{
    lineWidth = lineWidth;
}
