//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Line.h"
#include "views/LineView.h"

void Components::Line::render(bool useTexture) {
    ofFill();
    ofSetColor(this->lineColor);
    ofSetLineWidth(this->lineWidth);
    float half = static_cast<float>(this->lineLength) / 2.0f;
    ofDrawLine(-half, 0, half, 0);
}

ofColor Components::Line::getLineColor() {
    return this->lineColor;
}

float Components::Line::getLineWidth() {
    return this->lineWidth;
}

float Components::Line::getLineLength() {
    return this->lineLength;
}

void Components::Line::setLineColor(ofColor color) {
    this->lineColor = color;
}

void Components::Line::setLineWidth(float width) {
    this->lineWidth = width;
}

void Components::Line::setLineLength(float length) {
    this->lineLength = length;
}

UIKit::UIView* Components::Line::getUIView() {
    return new Components::Views::Line(this);
}

int Components::Line::getUIViewHeight() {
    return 20 + 30 + 30 + 30;
}
