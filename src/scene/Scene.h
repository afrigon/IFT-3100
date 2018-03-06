//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include <iostream>
#include <list>
using std::list;

#include "GameObject.h"

class Scene {
    list<GameObject> gameObjects;
    
public:
    Scene& addObject(GameObject& o);
    Scene& remove(GameObject& o);
    void print() {
        std::cout << gameObjects.size() << std::endl;
    }
};

#endif  // SCENE_SCENE_H_

