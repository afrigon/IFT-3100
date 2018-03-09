//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Ellipse.h"

void Components::Ellipse::render() {
    ofFill();
    ofSetColor(fillColor);
    ofDrawEllipse(0, 0, 0, width, height);

    ofNoFill();
    ofSetColor(drawColor);
    ofSetLineWidth(this->borderWidth);
    ofDrawEllipse(0, 0, 0, this->width, this->height);
}

ofColor Components::Ellipse::getFillColor() {
    return this->fillColor;
}

ofColor Components::Ellipse::getDrawColor() {
    return this->drawColor;
}

unsigned int Components::Ellipse::getBorderWidth() {
    return this->borderWidth;
}

unsigned int Components::Ellipse::getWidth() {
    return this->width;
}

unsigned int Components::Ellipse::getHeight() {
    return this->height;
}

void Components::Ellipse::setFillColor(ofColor color) {
    this->fillColor = color;
}

void Components::Ellipse::setDrawColor(ofColor color) {
    this->drawColor = color;
}

void Components::Ellipse::setBorderWidth(unsigned int width) {
    this->borderWidth = width;
}

void Components::Ellipse::setWidth(unsigned int width) {
    this->width = width;
}

void Components::Ellipse::setHeight(unsigned int height) {
    this->height = height;
}
