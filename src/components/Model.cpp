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
    if(!model.hasMeshes()) return;
    if (model.hasAnimations()) model.update();
    
    //Litteraly reusing the draw function of ofxassimp to adapt it using the shader
    ofPushStyle();

    ofPushMatrix();
    ofMultMatrix(model.getModelMatrix());

#ifndef TARGET_OPENGLES
    glPolygonMode(GL_FRONT_AND_BACK, ofGetGLPolyMode(OF_MESH_FILL));
#endif

    for(unsigned int i = 0; i < model.getMeshCount(); i++) {
        ofxAssimpMeshHelper & mesh = model.getMeshHelper(i);

        ofPushMatrix();
        ofScale(-1, 1, 1);
        ofMultMatrix(mesh.matrix);

        //Would need to set the flags
        if(mesh.hasTexture()) {
            mesh.getTextureRef().bind(1);
            mesh.getTextureRef().bind(2);
        }

        //Would set the shininess here
        /*if(bUsingMaterials) {
            mesh.material.begin();
        }*/

        if(mesh.twoSided) {
            glEnable(GL_CULL_FACE);
        } else {
            glDisable(GL_CULL_FACE);
        }

        ofEnableBlendMode(mesh.blendMode);

        mesh.vbo.drawElements(GL_TRIANGLES, mesh.indices.size());

        if(mesh.hasTexture()) {
            mesh.getTextureRef().unbind(1);
            mesh.getTextureRef().unbind(2);
        }

        ofPopMatrix();
    }

    ofPopMatrix();
    ofPopStyle();
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
    if (this->path == "") return 0;
    return static_cast<int>(verticesCount);
}

UIKit::UIView* Components::Model::getUIView() {
    return new Components::Views::Model(this);
}

int Components::Model::getUIViewHeight() {
    return 20 + 30 + 30;
}
