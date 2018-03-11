//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UIBUTTON_H_
#define UIKIT_UIBUTTON_H_

#include <cmath>

#include "UILabel.h"

namespace UIKit {
class UIButton: public UIKit::UILabel {
    ofColor storedTextColor;
    
 public:
    UIButton(string text = "Button");
    ~UIButton();
    void mousedown(UIView&);
    void mouseup(UIView&);
};
}  // namespace UIKit

#endif  // UIBuUIKIT_UIBUTTON_H_tton_hpp
