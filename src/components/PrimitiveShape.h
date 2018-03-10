//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_PRIMITIVESHAPE_H_
#define COMPONENTS_PRIMITIVESHAPE_H_

#include <vector>

#include "components/RenderableComponent.h"
#include "math/Vector3.h"

namespace Components {
class PrimitiveShape: public RenderableComponent {
    ofColor fillColor;
    ofColor drawColor;
    unsigned int borderWidth = 2;
    std::vector<Vector3> points;

    void drawShape();

 public:
    PrimitiveShape();
    void render() override;
    unsigned int getPointCount();
    void setPointSize(unsigned int newSize);
    bool setPoint(unsigned int point, Vector3 position);
    ofColor getFillColor();
    ofColor getDrawColor();
    unsigned int getBorderWidth();
    vector<Vector3>& getPoints();
    void setFillColor(ofColor color);
    void setDrawColor(ofColor color);
    void setBorderWidth(unsigned int width);
    
//    UIKit::UIView* getUIView() override;
//    int getUIViewHeight() override;
};
}  // namespace Components

#endif  // COMPONENTS_PRIMITIVESHAPE_H_
