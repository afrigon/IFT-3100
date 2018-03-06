//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef SCENE_DEMOSCENE_H_
#define SCENE_DEMOSCENE_H_

#include "Scene.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector3.h"

class DemoScene {
 public:
    static Scene& generate();
};

#endif  // SCENE_DEMOSCENE_H_

