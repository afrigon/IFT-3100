//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_SPHERE_H_
#define COMPONENTS_SPHERE_H_

#include "components/RenderableComponent.h"

namespace Components {
class Sphere: public RenderableComponent {
    ofColor color;
    unsigned int radius = 50;

 public:
    void render() override;
    ofColor getColor();
    unsigned int getRadius();
    void setColor(ofColor color);
    void setRadius(unsigned int radius);
    
    UIKit::UIView* getUIView() override;
    int getUIViewHeight() override;
};
}  // namespace Components

#endif  // COMPONENTS_SPHERE_H_
