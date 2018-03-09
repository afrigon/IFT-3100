//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/PrimitiveShape.h"

Components::PrimitiveShape::PrimitiveShape() {
    this->points.resize(0);
}

void Components::PrimitiveShape::drawShape() {
    ofBeginShape();

    for (unsigned int i = 0; i < this->points.size(); ++i) {
        ofVertex(this->points[i].getX(), this->points[i].getY(), this->points[i].getZ());
    }

    ofVertex(this->points[0].getX(), this->points[0].getY(), this->points[0].getZ());
    ofEndShape();
}

void Components::PrimitiveShape::render() {
    if (this->points.size() > 0) {
        ofSetPolyMode(ofPolyWindingMode::OF_POLY_WINDING_ODD);

        ofFill();
        ofSetColor(this->fillColor);
        drawShape();

        ofNoFill();
        ofSetColor(this->drawColor);
        ofSetLineWidth(this->borderWidth);
        drawShape();
    }
}

unsigned int Components::PrimitiveShape::getPointCount() {
    return (unsigned int)this->points.size();
}

void Components::PrimitiveShape::setPointSize(unsigned int newSize) {
    this->points.resize(newSize);
}

bool Components::PrimitiveShape::setPoint(unsigned int point, Vector3 position) {
    if (point < this->points.size()) {
        this->points[point] = position;
        return true;
    }
    return false;
}

ofColor Components::PrimitiveShape::getFillColor() {
    return this->fillColor;
}

ofColor Components::PrimitiveShape::getDrawColor() {
    return this->drawColor;
}

unsigned int Components::PrimitiveShape::getBorderWidth() {
    return this->borderWidth;
}

vector<Vector3>& Components::PrimitiveShape::getPoints() {
    return this->points;
}

void Components::PrimitiveShape::setFillColor(ofColor color) {
    this->fillColor = color;
}

void Components::PrimitiveShape::setDrawColor(ofColor color) {
    this->drawColor = color;
}

void Components::PrimitiveShape::setBorderWidth(unsigned int width) {
    this->borderWidth = width;
}
