//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_CUBE_H_
#define COMPONENTS_CUBE_H_

#include "components/Renderable.h"
#include "math/Vector3.h"

namespace Components {
class Cube: public Renderable {
    ofColor color;
    Vector3 size = Vector3(100, 100, 100);

 public:
    void render();
    ofColor getColor();
    Vector3 getSize();
    void setColor(ofColor color);
    void setSize(Vector3 size);
};
}  // namespace Components

#endif  // COMPONENTS_CUBE_H_
