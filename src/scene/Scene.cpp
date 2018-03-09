//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "Scene.h"

Scene& Scene::addObject(GameObject* o) {
    this->gameObjects.push_back(o);
    return *this;
}

Scene& Scene::remove(GameObject* o) {
    this->gameObjects.remove(o);
    return *this;
}
Scene& Scene::render()
{
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    ofDrawGrid(100, 100, false, false, true, false);
    for(auto it = gameObjects.begin(); it != gameObjects.end(); ++it)
    {
        (*it)->draw();
    }
    ofPopMatrix();
    return *this;
}

