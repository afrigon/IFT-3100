//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "scene/Scene.h"

Scene& Scene::addObject(GameObject* o) {
    this->gameObjects.push_back(o);
    return *this;
}

Scene& Scene::remove(GameObject* o) {
    this->gameObjects.remove(o);
    return *this;
}

Scene& Scene::render() {
    ofPushMatrix();
    ofTranslate(-75, 100);
    ofRotateX(-25);
    ofRotateY(-30);

    ofDrawGrid(100, 100, false, false, true, false);
    for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
        (*it)->draw();
    }
    ofPopMatrix();
    return *this;
}

unsigned int Scene::getGameObjectCount() {
    unsigned int compteur = 0;
    for (auto it = gameObjects.cbegin(); it != gameObjects.cend(); ++it) {
        compteur += (*it)->getGameObjectCount();
    }
    return compteur;
}

GameObject* Scene::getGameObjectAt(unsigned int index) {
    if (!gameObjects.empty()) {
        int i = 0;
        for (auto it = gameObjects.cbegin(); it != gameObjects.cend(); ++it) {
            if (i == index) {
                return *it;
            } else {
                unsigned int count = (*it)->getGameObjectCount();
                i += count;
                if (i > index) {
                    return (*it)->getGameObjectAt(index + count - i - 1);
                }
            }
        }
    }
    return nullptr;
}

