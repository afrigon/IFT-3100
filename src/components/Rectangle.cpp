//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Rectangle.h"
#include "views/RectangleView.h"

void Components::Rectangle::render(bool useTexture) {

    ofFill();
    ofSetColor(this->fillColor);
    if(useTexture) {
        ofMesh m = ofMesh();
        m.setMode(ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_FAN);
        m.addVertex(ofVec3f(-width / 2, -height / 2, 0));
        m.addVertex(ofVec3f(width / 2, -height / 2, 0));
        m.addVertex(ofVec3f(width / 2, height / 2, 0));
        m.addVertex(ofVec3f(-width / 2, height / 2, 0));

        m.addTexCoord(ofVec2f(0, 0));
        m.addTexCoord(ofVec2f(1, 0));
        m.addTexCoord(ofVec2f(1, 1));
        m.addTexCoord(ofVec2f(0, 1));

        m.drawFaces();
    } else {
        //ofDrawRectRounded(0, 0, 0, this->width, this->height, 1);
        ofDrawRectangle(-width / 2, -height / 2, 0, width, height);
    }

    ofNoFill();
    ofSetColor(this->drawColor);
    ofSetLineWidth(this->borderWidth);
    //ofDrawRectRounded(-width / 2, -height / 2, 0, this->width, this->height, 1);
    ofDrawRectangle(-width / 2, -height / 2, 0, width, height);
}

ofColor Components::Rectangle::getFillColor() {
    return this->fillColor;
}

ofColor Components::Rectangle::getDrawColor() {
    return this->drawColor;
}

float Components::Rectangle::getBorderWidth() {
    return this->borderWidth;
}

float Components::Rectangle::getWidth() {
    return this->width;
}

float Components::Rectangle::getHeight() {
    return this->height;
}

void Components::Rectangle::setFillColor(ofColor color) {
    this->fillColor = color;
}

void Components::Rectangle::setDrawColor(ofColor color) {
    this->drawColor = color;
}

void Components::Rectangle::setBorderWidth(float width) {
    this->borderWidth = width;
}

void Components::Rectangle::setWidth(float width) {
    this->width = width;
}

void Components::Rectangle::setHeight(float height) {
    this->height = height;
}

UIKit::UIView* Components::Rectangle::getUIView() {
    return new Components::Views::Rectangle(this);
}

int Components::Rectangle::getUIViewHeight() {
    return 20 + 30 + 30 + 30 + 30 + 30;
}
