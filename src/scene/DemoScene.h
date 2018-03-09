//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef SCENE_DEMOSCENE_H_
#define SCENE_DEMOSCENE_H_

#include "GameObject.h"
#include "math/Vector3.h"
#include "scene/Scene.h"
#include "components/Transform.h"
#include "components/PrimitiveShape.h"
#include "components/Line.h"
#include "components/Rectangle.h"
#include "components/Ellipse.h"
#include "components/Sphere.h"
#include "components/Cube.h"
#include "components/Model.h"

class DemoScene {
 public:
     static Scene generate1();
     static Scene generate2();
     static Scene generate3();
     static Scene generate4();
     static Scene generate5();
     static Scene generate6();
     static Scene generate7();
     static Scene generate8();
};

#endif  // SCENE_DEMOSCENE_H_

