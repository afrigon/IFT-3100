//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_BASEVIEW_H_
#define COMPONENTS_VIEWS_BASEVIEW_H_

#include <cmath>
#include <string>
using std::string;

#include "UIKit.h"
#include "Generator.h"

namespace Components {
namespace Views {
class Base: public UIKit::UIView {
 protected:
    UIKit::UILabel* label = new UIKit::UILabel();
    UIKit::UIView* contentView = new UIKit::UIView();
    
 public:
    Base(string text = "");
    void layoutSubviews() override;
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_BASEVIEW_H_

