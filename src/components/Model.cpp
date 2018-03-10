//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Model.h"
#include "views/ModelView.h"

void Components::Model::render(bool useTexture) {
    if (model.hasAnimations()) model.update();
    if(model.hasMeshes()) {
        if(useTexture) {
            model.disableTextures();
            model.drawFaces();
            model.enableTextures();
        } else {
            model.drawFaces();
        }
    }
}

void Components::Model::loadModel(std::string path) {
    if(model.loadModel(path)) {
        this->path = path;
        model.playAllAnimations();
        model.setLoopStateForAllAnimations(ofLoopType::OF_LOOP_NORMAL);
    }
}

std::string Components::Model::getPath() {
    return path;
}

UIKit::UIView* Components::Model::getUIView() {
    return new Components::Views::Model(this);
}

int Components::Model::getUIViewHeight() {
    return 20 + 30;
}
