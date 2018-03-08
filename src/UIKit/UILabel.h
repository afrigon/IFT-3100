//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UILABEL_H_
#define UIKIT_UILABEL_H_

#include <iostream>
using std::string;

#include "UIView.h"

namespace UIKit {
    class UILabel: public UIView {
     public:
        string text = "Label";
        ofColor textColor = ofColor(0, 0, 0);
        double paddingX = 10;
        double paddingY = 10;
        
        UILabel();
        UILabel(string text): text(text) {}
        void draw(UIKit::CGRect) override;
    };
}

#endif  // UIKIT_UILABEL_H_
