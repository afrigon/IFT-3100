//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_CUBE_H_
#define COMPONENTS_CUBE_H_

#include "components/RenderableComponent.h"
#include "math/Vector3.h"

namespace Components {
class Cube: public RenderableComponent {
 public:
    ofColor color = ofColor(255);
    Vector3 size = Vector3(100, 100, 100);
    
    Cube();
    Cube* createInstance() override { return new Cube(); }
    void render(bool useTexture) override;
    
    UIKit::UIView* getUIView() override;
    int getUIViewHeight() override;
};
}  // namespace Components

#endif  // COMPONENTS_CUBE_H_
