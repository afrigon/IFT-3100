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
     static Scene generate1(); //PrimitiveShape
     static Scene generate2(); //Line
     static Scene generate3(); //Rectangle
     static Scene generate4(); //Ellipse
     static Scene generate5(); //Cube
     static Scene generate6(); //Sphere
     static Scene generate7(); //Model
     static Scene generate8(); //All previews
     static Scene generate9(); //Childens
};

#endif  // SCENE_DEMOSCENE_H_

