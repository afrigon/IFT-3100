//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_TRANSFORMVIEW_H_
#define COMPONENTS_VIEWS_TRANSFORMVIEW_H_

#include "BaseView.h"
#include "Transform.h"

namespace Components {
namespace Views {
class Transform: public Components::Views::Base {
    Components::Transform* transform = nullptr;
    Components::Views::Vector3View* views [3];
    
 public:
    Transform(Components::Transform*);
    ~Transform();
    void layoutSubviews() override;
    void setText(int);
    
    void click(UIView & view);
    void rightclick(UIView & view);
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_TRANSFORMVIEW_H_
