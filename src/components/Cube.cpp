//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Cube.h"

void Components::Cube::render() {
    ofFill();
    ofSetColor(this->color);
    ofDrawBox(this->size.getX(), this->size.getY(), this->size.getZ());
}

ofColor Components::Cube::getColor() {
    return this->color;
}

Vector3 Components::Cube::getSize() {
    return this->size;
}

void Components::Cube::setColor(ofColor color) {
    this->color = color;
}

void Components::Cube::setSize(Vector3 size) {
    this->size = size;
}
