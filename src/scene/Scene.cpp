//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "scene/Scene.h"

Scene::Scene() {
    cam.setVFlip(true);
}

Scene& Scene::addObject(GameObject* o) {
    this->gameObjects.push_back(o);
    o->setParent(nullptr);
    return *this;
}

Scene& Scene::remove(GameObject* o) {
    this->gameObjects.remove(o);
    return *this;
}

Scene& Scene::render(ofShader shader) {
    cam.begin();

    ofPushMatrix();
    ofTranslate(-75, 100);
    ofRotateX(-25);
    ofRotateY(-30);

    if(gridEnabled) ofDrawGrid(100, 100, false, false, true, false);

    for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
        (*it)->draw(Vector3(0, 0, 0), shader);
    }
    ofPopMatrix();

    cam.end();
    return *this;
}

unsigned int Scene::getGameObjectCount() {
    unsigned int compteur = 0;
    for (auto it = gameObjects.cbegin(); it != gameObjects.cend(); ++it) {
        compteur += (*it)->getGameObjectCount();
    }
    return compteur;
}

GameObject* Scene::getGameObject(unsigned int& index) {
    for(auto it = gameObjects.cbegin(); it != gameObjects.cend(); ++it) {
        if(index == 0) return *it;
        GameObject* g = (*it)->getGameObjectAt(--index);
        if(g) return g;
    }
    return nullptr;
}

GameObject* Scene::getGameObjectAt(unsigned int index) {
    return getGameObject(index);
}

