//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UILABEL_H_
#define UIKIT_UILABEL_H_

#include <string>
#include <list>

#include "UIView.h"

namespace UIKit {
class UILabel: public UIView {
    ofTrueTypeFont font;
    int fontSize = 12;

 public:
    std::string text = "Label";
    ofColor textColor = ofColor(0, 0, 0);
    double padding = 10;

    UILabel();
    explicit UILabel(std::string);
    void setFontSize(int);
    void loadFont();
    void draw(UIKit::CGRect) override;
};
}  // namespace UIKit

#endif  // UIKIT_UILABEL_H_
