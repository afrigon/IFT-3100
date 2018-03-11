//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_COMPONENTTYPES_H_
#define COMPONENTS_COMPONENTTYPES_H_

#include <string>
using std::string;

#include "Components.h"

namespace Components {
enum class ComponentTypes {
    Line,
    Rectangle,
    Ellipse,
    PrimitiveShape,
    Cube,
    Sphere,
    Model,
    Texture,
    Cubemap,
    LAST
};

class ComponentStore {
 public:
    static AbstractComponent* generate(Components::ComponentTypes type) {
        switch (type) {
            case ComponentTypes::Line: return new Line();
            case ComponentTypes::Rectangle: return new Rectangle();
            case ComponentTypes::Ellipse: return new Ellipse();
            case ComponentTypes::PrimitiveShape: return new PrimitiveShape();
            case ComponentTypes::Cube: return new Cube();
            case ComponentTypes::Sphere: return new Sphere();
            case ComponentTypes::Model: return new Model();
            case ComponentTypes::Texture: return new Texture();
            case ComponentTypes::Cubemap: return new Cubemap();
            default: return nullptr;
        }
    }
};
}  // namespace Components

#endif  // COMPONENTS_COMPONENTTYPES_H_
