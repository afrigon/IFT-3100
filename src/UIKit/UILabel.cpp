//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UILabel.h"

void UIKit::UILabel::draw(UIKit::CGRect rect) {
    if (isHidden) return;
    ofSetColor(this->backgroundColor);
    ofDrawRectangle(this->frame.origin.x + rect.origin.x, this->frame.origin.y + rect.origin.y, this->frame.size.width, this->frame.size.height);
    ofSetColor(this->textColor);
    ofDrawBitmapString(this->text, rect.origin.x + this->frame.origin.x + this->paddingX, rect.origin.y + this->frame.origin.y + this->paddingY);
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->draw(rect + this->frame);
    }
}
