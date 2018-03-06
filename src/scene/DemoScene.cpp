//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "DemoScene.h"

Scene& DemoScene::generate() {
    Scene temp = Scene();
    
    GameObject* o = new GameObject();
    Transform t = o->addComponent(Transform(Vector3(10, 15, 20)));
    
    return temp.addObject(o);
}

