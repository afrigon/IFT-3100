//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_CUBEVIEW_H_
#define COMPONENTS_VIEWS_CUBEVIEW_H_

#include "BaseView.h"
#include "Cube.h"

namespace Components {
namespace Views {
class Cube: public Components::Views::Base {
    Components::Cube* cube = nullptr;
    Components::Views::ColorView* colorView;
    Components::Views::Vector3View* sizeView;
    
public:
    Cube(Components::Cube*);
    ~Cube();
    void layoutSubviews() override;
    void click(UIView &);
    void rightclick(UIView &);
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_CUBEVIEW_H_

