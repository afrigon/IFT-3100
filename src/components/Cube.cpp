//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Cube.h"
#include "views/CubeView.h"

Components::Cube::Cube() {
    this->name = "Box";
}

void Components::Cube::render(bool useTexture) {
    ofFill();
    ofSetColor(this->color);
    ofDrawBox(this->size.getX(), this->size.getY(), this->size.getZ());
}

UIKit::UIView* Components::Cube::getUIView() {
    return new Components::Views::Cube(this);
}

int Components::Cube::getUIViewHeight() {
    return 20 + 30 + 30;
}
