//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_MODEL_H_
#define COMPONENTS_MODEL_H_

#include <string>

#include "components/RenderableComponent.h"
#include "ofxAssimpModelLoader.h"

namespace Components {
class Model: public RenderableComponent {
    ofxAssimpModelLoader model;

 public:
    void render();
    void loadModel(std::string path);
};
}  // namespace Components

#endif  // COMPONENTS_MODEL_H_
