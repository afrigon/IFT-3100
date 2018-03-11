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
enum class TextAlignment {
    left,
    center,
    right
};
    
class UILabel: public UIView {
    ofTrueTypeFont font;
    int fontSize = 12;

 public:
    std::string text = "Label";
    ofColor textColor = ofColor(0, 0, 0);
    TextAlignment textAlignment = TextAlignment::left;
    double padding = 0;

    UILabel();
    explicit UILabel(std::string);
    void setFontSize(int);
    void loadFont();
    void draw(UIKit::CGRect) override;
    double widthFor(string text);
};
}  // namespace UIKit

#endif  // UIKIT_UILABEL_H_
