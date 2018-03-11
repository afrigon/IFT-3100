//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_LINE_H_
#define COMPONENTS_LINE_H_

#include "components/RenderableComponent.h"

namespace Components {
class Line: public RenderableComponent {
    float strokeWidth = 2;
    float lineLength = 100;

 public:
    ofColor strokeColor;
    
    Line();
    Line* createInstance() override { return new Line(); }
    void render(bool useTexture) override;
    float getStrokeWidth();
    float getLineLength();
    void setStrokeWidth(float width);
    void setLineLength(float length);
    
    UIKit::UIView* getUIView() override;
    int getUIViewHeight() override;
};
}  // namespace Components

#endif  // COMPONENTS_LINE_H_
