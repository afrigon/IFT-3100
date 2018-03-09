//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Line.h"

void Components::Line::render() {
    ofFill();
    ofSetColor(this->lineColor);
    ofSetLineWidth(this->lineWidth);
    float half = static_cast<float>this->lineLength / 2.0f;
    ofDrawLine(-half, 0, half, 0);
}

ofColor Components::Line::getLineColor() {
    return this->lineColor;
}

unsigned int Components::Line::getLineWidth() {
    return this->lineWidth;
}

unsigned int Components::Line::getLineLength() {
    return this->lineLength;
}

void Components::Line::setLineColor(ofColor color) {
    this->lineColor = color;
}

void Components::Line::setLineWidth(unsigned int width) {
    this->lineWidth = width;
}

void Components::Line::setLineLength(unsigned int length) {
    this->lineLength = length;
}
