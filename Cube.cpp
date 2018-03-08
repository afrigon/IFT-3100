#include "src\components\Cube.h"

Component::Cube::Cube()
{
    color = ofColor();
    size = Vector3(100, 100, 100);
}

Component::Cube::~Cube()
{
}

void Component::Cube::render()
{
    ofFill();
    ofSetColor(color);
    ofDrawBox(size.getX(), size.getY(), size.getZ());
}

ofColor Component::Cube::getColor()
{
    return color;
}

Vector3 Component::Cube::getSize()
{
    return size;
}

void Component::Cube::setColor(ofColor color)
{
    this->color = color;
}

void Component::Cube::setSize(Vector3 size)
{
    this->size = size;
}
