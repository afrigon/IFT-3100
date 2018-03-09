//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIKit/UIView.h"

void UIKit::UIView::addSubview(UIView* view) {
    view->superview = this;
    this->subviews.push_back(view);
}

void UIKit::UIView::removeFromSuperView() {
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->removeFromSuperView();
    }
    if (this->superview != nullptr) {  // probably handle uiwindow case
        this->superview->subviews.remove(this);
    }
    delete this;
}

void UIKit::UIView::draw(CGRect rect) {
    if (isHidden) return;
    ofSetColor(this->backgroundColor);
    ofDrawRectangle(this->frame.origin.x + rect.origin.x, this->frame.origin.y + rect.origin.y, this->frame.size.width, this->frame.size.height);
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->draw(rect + this->frame);
    }
}

void UIKit::UIView::layoutSubviews() {
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->layoutSubviews();
    }
}
