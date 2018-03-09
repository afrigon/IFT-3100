//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Rectangle.h"

void Components::Rectangle::render() {
    ofFill();
    ofSetColor(this->fillColor);
    ofDrawRectRounded(0, 0, 0, this->width, this->height, 1);
    // ofDrawRectangle(0, 0, 0, this->width, this->height);  // 0 0 0 since it is already placed by the transform

    ofNoFill();
    ofSetColor(this->drawColor);
    ofSetLineWidth(this->borderWidth);
    ofDrawRectRounded(0, 0, 0, this->width, this->height, 1);
    // ofDrawRectangle(0, 0, 0, width, this->height);
}

ofColor Components::Rectangle::getFillColor() {
    return this->fillColor;
}

ofColor Components::Rectangle::getDrawColor() {
    return this->drawColor;
}

unsigned int Components::Rectangle::getBorderWidth() {
    return this->borderWidth;
}

unsigned int Components::Rectangle::getWidth() {
    return this->width;
}

unsigned int Components::Rectangle::getHeight() {
    return this->height;
}

void Components::Rectangle::setFillColor(ofColor color) {
    this->fillColor = color;
}

void Components::Rectangle::setDrawColor(ofColor color) {
    this->drawColor = color;
}

void Components::Rectangle::setBorderWidth(unsigned int width) {
    this->borderWidth = width;
}

void Components::Rectangle::setWidth(unsigned int width) {
    this->width = width;
}

void Components::Rectangle::setHeight(unsigned int height) {
    this->height = height;
}
