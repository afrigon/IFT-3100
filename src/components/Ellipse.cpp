#include "Ellipse.h"

Component::Ellipse::Ellipse()
{
    fillColor = drawColor = ofColor();
    width = height = 100;
}

Component::Ellipse::~Ellipse()
{
}

void Component::Ellipse::render()
{
    ofFill();
    ofSetColor(fillColor);
    ofDrawEllipse(0, 0, 0, width, height);

    ofNoFill();
    ofSetColor(drawColor);
    ofSetLineWidth(borderWidth);
    ofDrawEllipse(0, 0, 0, width, height);
}

ofColor Component::Ellipse::getFillColor()
{
    return fillColor;
}

ofColor Component::Ellipse::getDrawColor()
{
    return drawColor;
}

unsigned int Component::Ellipse::getBorderWidth()
{
    return borderWidth;
}

unsigned int Component::Ellipse::getWidth()
{
    return width;
}

unsigned int Component::Ellipse::getHeight()
{
    return height;
}

void Component::Ellipse::setFillColor(ofColor color)
{
    fillColor = color;
}

void Component::Ellipse::setDrawColor(ofColor color)
{
    drawColor = color;
}

void Component::Ellipse::setBorderWidth(unsigned int width)
{
    borderWidth = width;
}

void Component::Ellipse::setWidth(unsigned int width)
{
    this->width = width;
}

void Component::Ellipse::setHeight(unsigned int height)
{
    this->height = height;
}
