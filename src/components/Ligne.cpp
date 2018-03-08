#include "Ligne.h"

Component::Ligne::Ligne()
{
    lineColor = ofColor();
    lineWidth = 2;
    lineLength = 100;
}

Component::Ligne::~Ligne()
{
}

void Component::Ligne::render()
{
    ofFill();
    ofSetColor(lineColor);
    ofSetLineWidth(lineWidth);
    float half = (float)lineLength / 2.0f;
    ofDrawLine(-half, 0, half, 0);
}

ofColor Component::Ligne::getLineColor()
{
    return lineColor;
}

unsigned int Component::Ligne::getLineWidth()
{
    return lineWidth;
}

unsigned int Component::Ligne::getLineLength()
{
    return lineLength;
}

void Component::Ligne::setLineColor(ofColor color)
{
    lineColor = color;
}

void Component::Ligne::setLineWidth(unsigned int width)
{
    lineWidth = width;
}

void Component::Ligne::setLineLength(unsigned int length)
{
    lineLength = length;
}
