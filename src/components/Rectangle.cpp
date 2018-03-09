#include "Rectangle.h"

Component::Rectangle::Rectangle()
{
    fillColor = drawColor = ofColor();
    borderWidth = 2;
    width = height = 100;
}

Component::Rectangle::~Rectangle()
{
}

void Component::Rectangle::render()
{
    ofFill();
    ofSetColor(fillColor);
    ofDrawRectRounded(0, 0, 0, width, height,1);
    //ofDrawRectangle(0, 0, 0, width, height); //0 0 0 car il est déjà positionné par le transform

    ofNoFill();
    ofSetColor(drawColor);
    ofSetLineWidth(borderWidth);
    ofDrawRectRounded(0, 0, 0, width, height,1);
    //ofDrawRectangle(0, 0, 0, width, height);
}

ofColor Component::Rectangle::getFillColor()
{
    return fillColor;
}

ofColor Component::Rectangle::getDrawColor()
{
    return drawColor;
}

unsigned int Component::Rectangle::getBorderWidth()
{
    return borderWidth;
}

unsigned int Component::Rectangle::getWidth()
{
    return width;
}

unsigned int Component::Rectangle::getHeight()
{
    return height;
}

void Component::Rectangle::setFillColor(ofColor color)
{
    fillColor = color;
}

void Component::Rectangle::setDrawColor(ofColor color)
{
    drawColor = color;
}

void Component::Rectangle::setBorderWidth(unsigned int width)
{
    borderWidth = width;
}

void Component::Rectangle::setWidth(unsigned int width)
{
    this->width = width;
}

void Component::Rectangle::setHeight(unsigned int height)
{
    this->height = height;
}
