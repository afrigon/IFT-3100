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
    ofColor lineColor;
    unsigned int lineWidth = 2;
    unsigned int lineLength = 100;

 public:
    void render();
    ofColor getLineColor();
    unsigned int getLineWidth();
    unsigned int getLineLength();
    void setLineColor(ofColor color);
    void setLineWidth(unsigned int width);
    void setLineLength(unsigned int length);
};
}  // namespace Components

#endif  // COMPONENTS_LINE_H_
