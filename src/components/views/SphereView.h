//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_SPHEREVIEW_H_
#define COMPONENTS_VIEWS_SPHEREVIEW_H_

#include "BaseView.h"
#include "Sphere.h"

namespace Components {
namespace Views {
class Sphere: public Components::Views::Base {
    Components::Sphere* sphere = nullptr;
    Components::Views::ColorView* colorView;
    Components::Views::NumericView* radiusView;
    
public:
    Sphere(Components::Sphere*);
    ~Sphere();
    void layoutSubviews() override;

    void click(UIView & view);
    void rightclick(UIView & view);
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_SPHEREVIEW_H_


