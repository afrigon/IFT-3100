#include "Sphere.h"

Component::Sphere::Sphere()
{
    color = ofColor();
    radius = 50;
}

Component::Sphere::~Sphere()
{
}

void Component::Sphere::render()
{
    ofFill();
    ofSetColor(color);
    ofDrawSphere(radius);
}

ofColor Component::Sphere::getColor()
{
    return color;
}

unsigned int Component::Sphere::getRadius()
{
    return radius;
}

void Component::Sphere::setColor(ofColor color)
{
    this->color = color;
}

void Component::Sphere::setRadius(unsigned int radius)
{
    this->radius = radius;
}
