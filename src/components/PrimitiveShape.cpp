#include "PrimitiveShape.h"

Component::PrimitiveShape::PrimitiveShape()
{
    fillColor = ofColor();
    drawColor = ofColor();
    borderWidth = 2;
    points.resize(0);
}

Component::PrimitiveShape::~PrimitiveShape()
{
}

void Component::PrimitiveShape::drawShape()
{
    ofBeginShape();

    for(unsigned int i = 0; i < points.size(); ++i)
    {
        ofVertex(points[i].getX(), points[i].getY(), points[i].getZ());
    }
    ofVertex(points[0].getX(), points[0].getY(), points[0].getZ());

    ofEndShape();
}

void Component::PrimitiveShape::render()
{
    if(points.size() > 0)
    {
        ofSetPolyMode(ofPolyWindingMode::OF_POLY_WINDING_ODD);

        ofFill();
        ofSetColor(fillColor);
        drawShape();

        ofNoFill();
        ofSetColor(drawColor);
        ofSetLineWidth(borderWidth);
        drawShape();
    }
}

unsigned int Component::PrimitiveShape::getPointCount()
{
    return (unsigned int)points.size();
}

void Component::PrimitiveShape::setPointSize(unsigned int newSize)
{
    points.resize(newSize);
}

bool Component::PrimitiveShape::setPoint(unsigned int point, Vector3 position)
{
    if(point < points.size())
    {
        points[point] = position;
        return true;
    }
    return false;
}

ofColor Component::PrimitiveShape::getFillColor()
{
    return fillColor;
}

ofColor Component::PrimitiveShape::getDrawColor()
{
    return drawColor;
}

unsigned int Component::PrimitiveShape::getBorderWidth()
{
    return borderWidth;
}

vector<Vector3>& Component::PrimitiveShape::getPoints()
{
    return points;
}

void Component::PrimitiveShape::setFillColor(ofColor color)
{
    fillColor = color;
}

void Component::PrimitiveShape::setDrawColor(ofColor color)
{
    drawColor = color;
}

void Component::PrimitiveShape::setBorderWidth(unsigned int width)
{
    borderWidth = width;
}
