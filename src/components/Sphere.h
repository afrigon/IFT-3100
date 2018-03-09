//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_SPHERE_H_
#define COMPONENTS_SPHERE_H_

#include "components/Renderable.h"

namespace Components {
class Sphere: public Renderable {
    ofColor color;
    unsigned int radius = 50;

 public:
    void render();
    ofColor getColor();
    unsigned int getRadius();
    void setColor(ofColor color);
    void setRadius(unsigned int radius);
};
}  // namespace Components

#endif  // COMPONENTS_SPHERE_H_
