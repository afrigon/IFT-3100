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
#include "components/RenderableComponent.h"

class Scene {
    ofEasyCam cam;
    list<GameObject*> gameObjects;
    GameObject* getGameObject(unsigned int& index);
    bool gridEnabled = true;

 public:
    Scene();
    Scene& addObject(GameObject* o);
    Scene& remove(GameObject* o);
    Scene& render();
    list<GameObject*>& getGameObjects() { return gameObjects; }
    unsigned int getGameObjectCount();
    GameObject* getGameObjectAt(unsigned int index);
    bool getGridEnabled() { return gridEnabled; }
    void setGridEnabled(bool value) { gridEnabled = value; }
    ofEasyCam& getCamera() { return cam; }
    void enableCam() { cam.enableMouseInput(); }
    void disableCam() { cam.disableMouseInput(); }
};

#endif  // SCENE_SCENE_H_

