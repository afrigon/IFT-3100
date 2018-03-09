//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Model.h"

void Components::Model::render() {
    if (model.hasAnimations()) this->model.update();
    if (model.hasMeshes()) this->model.drawFaces();
}

void Components::Model::loadModel(std::string path) {
    model.loadModel(path);
    model.playAllAnimations();
    model.setLoopStateForAllAnimations(ofLoopType::OF_LOOP_NORMAL);
}