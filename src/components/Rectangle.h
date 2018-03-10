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
    ofColor fillColor;
    ofColor drawColor;
    float borderWidth = 2;
    float width = 100;
    float height = 100;

 public:
    void render(bool useTexture);
    ofColor getFillColor();
    ofColor getDrawColor();
    float getBorderWidth();
    float getWidth();
    float getHeight();
    void setFillColor(ofColor color);
    void setDrawColor(ofColor color);
    void setBorderWidth(float width);
    void setWidth(float width);
    void setHeight(float height);
};
}  // namespace Components

#endif  // COMPONENTS_RECTANGLE_H_
