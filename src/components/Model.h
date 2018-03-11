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
    std::string path;
    size_t verticesCount;

 public:
    void render(bool useTexture) override;
    void loadModel(std::string path);
    std::string getPath();
    size_t getVertexCount();
    unsigned int getAnimationCount();
    
    UIKit::UIView* getUIView() override;
    int getUIViewHeight() override;
};
}  // namespace Components

#endif  // COMPONENTS_MODEL_H_
