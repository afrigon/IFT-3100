//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_TRANSFORM_H_
#define COMPONENTS_TRANSFORM_H_

#include "components/UndeletableComponent.h"
#include "math/Vector3.h"

namespace Components {
class Transform: public UndeletableComponent {
 public:
    Vector3 position;
    Vector3 scale;
    Vector3 rotation;

    Transform();
    Transform* createInstance() override { return new Transform(); }
    Transform(Vector3, Vector3 = Vector3(1), Vector3 = Vector3());
    
    UIKit::UIView* getUIView() override;
    int getUIViewHeight() override;
};
}  // namespace Components

#endif  // COMPONENTS_TRANSFORM_H_
