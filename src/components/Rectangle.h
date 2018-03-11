//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_RECTANGLE_H_
#define COMPONENTS_RECTANGLE_H_

#include "components/RenderableComponent.h"

namespace Components {
class Rectangle: public RenderableComponent {
    float borderWidth = 2;
    float width = 100;
    float height = 100;

 public:
    ofColor fillColor;
    ofColor strokeColor;
    
    Rectangle();
    Rectangle* createInstance() override { return new Rectangle(); }
    void render(bool useTexture) override;
    float getBorderWidth();
    float getWidth();
    float getHeight();
    void setBorderWidth(float width);
    void setWidth(float width);
    void setHeight(float height);
    
    UIKit::UIView* getUIView() override;
    int getUIViewHeight() override;
};
}  // namespace Components

#endif  // COMPONENTS_RECTANGLE_H_
