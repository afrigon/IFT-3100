//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Ellipse.h"
#include "views/EllipseView.h"

Components::Ellipse::Ellipse() {
    this->name = "Circle / Ellipse";
}

void Components::Ellipse::render(bool useTexture) {
    ofFill();
    ofSetColor(fillColor);
    if(useTexture) {
        ofMesh m = ofMesh();
        m.setMode(ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_STRIP);
        unsigned int const triangleCount = 60;
        for(int i = 0; i <= triangleCount; i++) {
            m.addVertex(ofVec3f(0, 0, 0));
            m.addTexCoord(ofVec2f(0.5, 0.5));
            double x = width * std::cos(i * 6.2831853 / triangleCount) / 2;
            double y = height * std::sin(i * 6.2831853 / triangleCount) / 2;
            m.addVertex(ofVec3f(x, y));
            m.addTexCoord(ofVec2f((x + width / 2) / width, (y + height / 2) / height));
        }
        m.drawFaces();
    } else {
        ofDrawEllipse(0, 0, 0, width, height);
    }
}

unsigned int Components::Ellipse::getWidth() {
    return this->width;
}

unsigned int Components::Ellipse::getHeight() {
    return this->height;
}

void Components::Ellipse::setWidth(unsigned int width) {
    this->width = width;
}

void Components::Ellipse::setHeight(unsigned int height) {
    this->height = height;
}

UIKit::UIView* Components::Ellipse::getUIView() {
    return new Components::Views::Ellipse(this);
}

int Components::Ellipse::getUIViewHeight() {
    return 20 + 30 + 30 + 30;
}
