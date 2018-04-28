//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIButton.h"

UIKit::UIButton::UIButton(string text): UIKit::UILabel(text) {
    this->isUserInteractionEnabled = true;
    this->textColor = ofColor(66, 134, 244);
    ofAddListener(this->onmousedown, this, &UIKit::UIButton::mousedown);
    ofAddListener(this->onmouseup, this, &UIKit::UIButton::mouseup);
}

void UIKit::UIButton::mousedown(UIKit::UIView & view) {
    this->storedTextColor = this->textColor;
    this->textColor.setBrightness(min((this->textColor.getBrightness() + 60.0), 255.0));
}

void UIKit::UIButton::mouseup(UIKit::UIView & view) {
    this->textColor = this->storedTextColor;
}
