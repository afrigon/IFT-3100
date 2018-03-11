//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Model.h"
#include "views/ModelView.h"

Components::Model::Model() {
    this->name = "Mesh 3D";
}

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

bool Components::Model::loadModel(std::string path) {
    if (!model.loadModel(path)) { this->path = ""; return false; }
    this->path = path;

    if (model.hasAnimations()) {
        model.playAllAnimations();
        model.setLoopStateForAllAnimations(ofLoopType::OF_LOOP_NORMAL);
    }
    
    verticesCount = 0;
    unsigned int modelMeshCount = model.getMeshCount();
    for (int i = 0; i < modelMeshCount; ++i) {
        ofMesh m = model.getMesh(i);
        verticesCount += m.getNumVertices();
    }
    return true;
}

string Components::Model::getPath() {
    return this->path;
}

int Components::Model::getVertexCount() {
    return static_cast<int>(verticesCount);
}

UIKit::UIView* Components::Model::getUIView() {
    return new Components::Views::Model(this);
}

int Components::Model::getUIViewHeight() {
    return 20 + 30;
}
