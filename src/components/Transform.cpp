//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Transform.h"
#include "views/TransformView.h"

Components::Transform::Transform(): position(Vector3()), scale(Vector3(1)), rotation(Vector3()) {
    this->name = "Transform";
}

Components::Transform::Transform(Vector3 position, Vector3 scale, Vector3 rotation):
    position(position),
    scale(scale),
    rotation(rotation) {
    this->name = "Transform";
}

UIKit::UIView* Components::Transform::getUIView() {
    return new Components::Views::Transform(this);
}

int Components::Transform::getUIViewHeight() {
    return 20 + 90;
}
