//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIKit/UIView.h"

UIKit::CGPoint UIKit::CGPoint::operator+(const UIKit::CGPoint & o) {
    return UIKit::CGPoint(this->x + o.x, this->y + o.y);
}

UIKit::CGPoint& UIKit::CGPoint::operator+=(const UIKit::CGPoint & o) {
    this->x += o.x;
    this->y += o.y;
    return *this;
}

UIKit::CGRect UIKit::CGRect::operator+(const UIKit::CGRect & o) {
    return UIKit::CGRect(this->origin.x + o.origin.x, this->origin.y + o.origin.y, this->size.width + o.size.width, this->size.height + o.size.width);
}

UIKit::CGRect& UIKit::CGRect::operator+=(const UIKit::CGRect & o) {
    this->origin.x += o.origin.x;
    this->origin.y += o.origin.y;
    this->size.width += o.size.width;
    this->size.height += o.size.height;
    return *this;
}

UIKit::CGRect UIKit::CGRect::operator+(const UIKit::CGPoint & o) {
    return UIKit::CGRect(this->origin.x + o.x, this->origin.y + o.y, this->size.width, this->size.height);
}

UIKit::CGRect& UIKit::CGRect::operator+=(const UIKit::CGPoint & o) {
    this->origin.x += o.x;
    this->origin.y += o.y;
    return *this;
}

UIKit::CGRect UIKit::CGRect::operator+(const UIKit::CGSize & o) {
    return UIKit::CGRect(this->origin.x, this->origin.y, this->size.width + o.width, this->size.height + o.width);
}

UIKit::CGRect& UIKit::CGRect::operator+=(const UIKit::CGSize & o) {
    this->size.width += o.width;
    this->size.height += o.height;
    return *this;
}

bool UIKit::CGRect::contains(const UIKit::CGPoint & o) {
    return (this->origin.x <= o.x && this->origin.x + this->size.width >= o.x) && (this->origin.y <= o.y && this->origin.y + this->size.height >= o.y);
}

UIKit::UIView::~UIView() {
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        delete (*it);
    }
    delete superview;
}

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
    if (this->isHidden) return;
    ofSetColor(this->backgroundColor);
    ofDrawRectangle(this->frame.origin.x + rect.origin.x, this->frame.origin.y + rect.origin.y, this->frame.size.width, this->frame.size.height);
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->draw(this->frame + rect.origin);
    }
}

void UIKit::UIView::layoutSubviews() {
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->layoutSubviews();
    }
}
