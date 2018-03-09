//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Sphere.h"

void Components::Sphere::render() {
    ofFill();
    ofSetColor(this->color);
    ofDrawSphere(this->radius);
}

ofColor Components::Sphere::getColor() {
    return this->color;
}

unsigned int Components::Sphere::getRadius() {
    return this->radius;
}

void Components::Sphere::setColor(ofColor color) {
    this->color = color;
}

void Components::Sphere::setRadius(unsigned int radius) {
    this->radius = radius;
}