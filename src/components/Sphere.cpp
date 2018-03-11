//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Sphere.h"
#include "views/SphereView.h"

void Components::Sphere::render(bool useTexture) {
    ofFill();
    ofSetColor(this->color);
    ofDrawSphere(this->radius);
}

float Components::Sphere::getRadius() {
    return this->radius;
}

void Components::Sphere::setRadius(float radius) {
    this->radius = radius;
}

UIKit::UIView* Components::Sphere::getUIView() {
    return new Components::Views::Sphere(this);
}

int Components::Sphere::getUIViewHeight() {
    return 20 + 30 + 30;
}
