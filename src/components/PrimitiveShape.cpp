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

void Components::PrimitiveShape::drawShape(bool useTexture) {

    if(useTexture) {
        ofMesh m = ofMesh();
        m.setMode(ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_FAN);
        for(unsigned int i = 0; i < points.size(); ++i) {
            m.addVertex(ofVec3f(points[i].getX(), points[i].getY(), points[i].getZ()));
            float x = 0, y = 0;
            if(dimension.getX() != 0) {
                x = (points[i].getX() - minX) / dimension.getX();
            }
            if(dimension.getY() != 0) {
                y = (points[i].getY() - minY) / dimension.getY();
            }
            m.addTexCoord(ofVec2f(x, y));
        }
        m.drawFaces();
    } else {
        ofBeginShape();

        for(unsigned int i = 0; i < this->points.size(); ++i) {
            ofVertex(this->points[i].getX(), this->points[i].getY(), this->points[i].getZ());
        }

        ofEndShape(true);
    }
}

void Components::PrimitiveShape::render(bool useTexture) {
    if (this->points.size() > 0) {
        ofSetPolyMode(ofPolyWindingMode::OF_POLY_WINDING_ODD);

        ofFill();
        ofSetColor(this->fillColor);
        drawShape(useTexture);

        ofNoFill();
        ofSetColor(this->drawColor);
        ofSetLineWidth(this->borderWidth);
        drawShape(false);
    }
}

unsigned int Components::PrimitiveShape::getPointCount() {
    return (unsigned int)this->points.size();
}

void Components::PrimitiveShape::setPointSize(unsigned int newSize) {
    this->points.resize(newSize);
    computeDimensions();
}

bool Components::PrimitiveShape::setPoint(unsigned int point, Vector3 position) {
    if (point < this->points.size()) {
        this->points[point] = position;
        computeDimensions();
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

void Components::PrimitiveShape::computeDimensions() {
    if(!points.empty()) {
        maxX = minX = points[0].getX();
        maxY = minY = points[0].getY();
        maxZ = minZ = points[0].getZ();

        for(int i = 1; i < points.size(); ++i) {
            if(points[i].getX() > maxX) { maxX = points[i].getX(); }
            if(points[i].getY() > maxY) { maxY = points[i].getY(); }
            if(points[i].getZ() > maxZ) { maxZ = points[i].getZ(); }

            if(points[i].getX() < minX) { minX = points[i].getX(); }
            if(points[i].getY() < minY) { minY = points[i].getY(); }
            if(points[i].getZ() < minZ) { minZ = points[i].getZ(); }
        }
        dimension = Vector3(maxX - minX,
                       maxY - minY,
                       maxZ - minZ);
    }
    else { dimension = Vector3(); }
}

Vector3 Components::PrimitiveShape::getDimensions() {
    return dimension;
}
