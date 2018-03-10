//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_ELLIPSE_H_
#define COMPONENTS_ELLIPSE_H_

#include "components/RenderableComponent.h"

namespace Components {
class Ellipse: public RenderableComponent {
    ofColor fillColor;
    ofColor drawColor;
    unsigned int borderWidth;
    unsigned int width = 100;
    unsigned int height = 100;

 public:
    void render(bool useTexture);
    ofColor getFillColor();
    ofColor getDrawColor();
    unsigned int getBorderWidth();
    unsigned int getWidth();
    unsigned int getHeight();
    void setFillColor(ofColor color);
    void setDrawColor(ofColor color);
    void setBorderWidth(unsigned int width);
    void setWidth(unsigned int width);
    void setHeight(unsigned int height);
    
    UIKit::UIView* getUIView() override;
    int getUIViewHeight() override;
};
}  // namespace Components

#endif  // COMPONENTS_ELLIPSE_H_
