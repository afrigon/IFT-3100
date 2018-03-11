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
    ofSetColor(this->strokeColor);
    ofSetLineWidth(this->strokeWidth);
    float half = static_cast<float>(this->lineLength) / 2.0f;
    ofDrawLine(-half, 0, half, 0);
}

float Components::Line::getStrokeWidth() {
    return this->strokeWidth;
}

float Components::Line::getLineLength() {
    return this->lineLength;
}

void Components::Line::setStrokeWidth(float width) {
    this->strokeWidth = width;
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
