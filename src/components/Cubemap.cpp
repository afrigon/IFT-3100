//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Cubemap.h"
#include "views/CubemapView.h"

Components::Cubemap::Cubemap() {
    this->name = "Cubemap";
    this->textures.resize(6);
    this->meshes.resize(6);
}

string Components::Cubemap::getPath() {
    return this->path;
}

void Components::Cubemap::render(bool useTexture) {
    ofPushMatrix();
    bool light = ofGetLightingEnabled();
    if (light) { ofDisableLighting(); }
    ofScale(distance, distance, distance);
    ofSetColor(255);
    for (int i = 0; i < 6; ++i) {
        textures[i].bind();
        meshes[i].drawFaces();
        textures[i].unbind();
    }
    if (light) { ofEnableLighting(); }
    ofPopMatrix();
}

//void Components::Cubemap::loadMap(std::string path[6]) {
//    for (int i = 0; i < 6; ++i) {
//        if (!ofLoadImage(textures[i], path[i])) {
//            ofLogError("LoadCubemap", "Image failed to load : " + i);
//        }
//    }
//}
//
//void Components::Cubemap::loadMap(std::string image1, std::string image2, std::string image3, std::string image4, std::string image5, std::string image6) {
//    if (!ofLoadImage(textures[0], image1)) ofLogError("LoadCubemap", "Image failed to load : 1");
//    if (!ofLoadImage(textures[1], image2)) ofLogError("LoadCubemap", "Image failed to load : 2");
//    if (!ofLoadImage(textures[2], image3)) ofLogError("LoadCubemap", "Image failed to load : 3");
//    if (!ofLoadImage(textures[3], image4)) ofLogError("LoadCubemap", "Image failed to load : 4");
//    if (!ofLoadImage(textures[4], image5)) ofLogError("LoadCubemap", "Image failed to load : 5");
//    if (!ofLoadImage(textures[5], image6)) ofLogError("LoadCubemap", "Image failed to load : 6");
//}

bool Components::Cubemap::loadMap(string path) {
    ofImage image = ofImage(path);
    if (image.getImageType() == ofImageType::OF_IMAGE_UNDEFINED) return false;
    this->path = path;
    
    for (int i = 0; i < 6; ++i) {
        this->textures[i] = ofTexture();
        this->meshes[i] = ofMesh();
        this->textures[i].setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
    }
    this->generateMeshes();

    ofImage tmp = ofImage();
    float width = image.getWidth();
    float height = image.getHeight();
    float w = width / 4;
    float h = height / 3;
    //LEFT
    tmp.cropFrom(image, 0, height / 3, w, h);
    textures[0] = tmp.getTexture();
    tmp.clear();

    //RIGHT
    tmp.cropFrom(image, width / 2, height / 3, w, h);
    textures[1] = tmp.getTexture();
    tmp.clear();

    //TOP
    tmp.cropFrom(image, width / 4, height * 2 / 3, w, h);
    textures[2] = tmp.getTexture();
    tmp.clear();

    //DOWN
    tmp.cropFrom(image, width / 4, 0, w, h);
    textures[3] = tmp.getTexture();
    tmp.clear();

    //FRONT
    tmp.cropFrom(image, width / 4, height / 3, w, h);
    textures[4] = tmp.getTexture();
    tmp.clear();

    //BACK
    tmp.cropFrom(image, width * 3 / 4, height / 3, w, h);
    textures[5] = tmp.getTexture();
    tmp.clear();
    
    return true;
}

//void Components::Cubemap::loadMap(ofImage images[6]) {
//    try {
//        for (int i = 0; i < 6; ++i) {
//            textures[i] = images[i].getTexture();
//        }
//    } catch (const std::exception& e) {
//        ofLogError("LoadCubemap", e.what());
//    }
//}
//
//void Components::Cubemap::loadMap(ofImage image1, ofImage image2, ofImage image3, ofImage image4, ofImage image5, ofImage image6) {
//    try {
//        textures[0] = image1.getTexture();
//        textures[1] = image2.getTexture();
//        textures[2] = image3.getTexture();
//        textures[3] = image4.getTexture();
//        textures[4] = image5.getTexture();
//        textures[5] = image6.getTexture();
//    } catch (const std::exception& e) {
//        ofLogError("LoadCubemap", e.what());
//    }
//}

void Components::Cubemap::generateMeshes() {
    ofMesh m = ofMesh();
    m.setMode(ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_FAN);

    //LEFT
    m.addVertex(ofVec3f(-1, -1, 1));
    m.addTexCoord(ofVec2f(0, 0));

    m.addVertex(ofVec3f(-1, -1, -1));
    m.addTexCoord(ofVec2f(1, 0));

    m.addVertex(ofVec3f(-1, 1, -1));
    m.addTexCoord(ofVec2f(1, 1));

    m.addVertex(ofVec3f(-1, 1, 1));
    m.addTexCoord(ofVec2f(0, 1));

    meshes[0] = m;
    m.clear();

    //RIGHT
    m.addVertex(ofVec3f(1, -1, -1));
    m.addTexCoord(ofVec2f(0, 0));

    m.addVertex(ofVec3f(1, -1, 1));
    m.addTexCoord(ofVec2f(1, 0));

    m.addVertex(ofVec3f(1, 1, 1));
    m.addTexCoord(ofVec2f(1, 1));

    m.addVertex(ofVec3f(1, 1, -1));
    m.addTexCoord(ofVec2f(0, 1));

    meshes[1] = m;
    m.clear();

    //UP
    m.addVertex(ofVec3f(-1, 1, -1));
    m.addTexCoord(ofVec2f(0, 0));

    m.addVertex(ofVec3f(1, 1, -1));
    m.addTexCoord(ofVec2f(1, 0));

    m.addVertex(ofVec3f(1, 1, 1));
    m.addTexCoord(ofVec2f(1, 1));

    m.addVertex(ofVec3f(-1, 1, 1));
    m.addTexCoord(ofVec2f(0, 1));

    meshes[2] = m;
    m.clear();

    //DOWN
    m.addVertex(ofVec3f(-1, -1, 1));
    m.addTexCoord(ofVec2f(0, 0));

    m.addVertex(ofVec3f(1, -1, 1));
    m.addTexCoord(ofVec2f(1, 0));

    m.addVertex(ofVec3f(1, -1, -1));
    m.addTexCoord(ofVec2f(1, 1));

    m.addVertex(ofVec3f(-1, -1, -1));
    m.addTexCoord(ofVec2f(0, 1));

    meshes[3] = m;
    m.clear();

    //FRONT
    m.addVertex(ofVec3f(-1, -1, -1));
    m.addTexCoord(ofVec2f(0, 0));

    m.addVertex(ofVec3f(1, -1, -1));
    m.addTexCoord(ofVec2f(1, 0));

    m.addVertex(ofVec3f(1, 1, -1));
    m.addTexCoord(ofVec2f(1, 1));

    m.addVertex(ofVec3f(-1, 1, -1));
    m.addTexCoord(ofVec2f(0, 1));

    meshes[4] = m;
    m.clear();

    //BACK
    m.addVertex(ofVec3f(1, 1, 1));
    m.addTexCoord(ofVec2f(0, 1));

    m.addVertex(ofVec3f(-1, 1, 1));
    m.addTexCoord(ofVec2f(1, 1));

    m.addVertex(ofVec3f(-1, -1, 1));
    m.addTexCoord(ofVec2f(1, 0));

    m.addVertex(ofVec3f(1, -1, 1));
    m.addTexCoord(ofVec2f(0, 0));

    meshes[5] = m;
    m.clear();
}

UIKit::UIView* Components::Cubemap::getUIView() {
    return new Components::Views::Cubemap(this);
}

int Components::Cubemap::getUIViewHeight() {
    return 20 + 30 + 30;
}
