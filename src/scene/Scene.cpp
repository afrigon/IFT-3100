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

