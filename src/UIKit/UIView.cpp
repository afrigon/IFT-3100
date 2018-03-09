//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIKit/UIView.h"

UIKit::UIView::~UIView() {
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        delete (*it);
    }
}

void UIKit::UIView::addSubview(UIView* view) {
    view->superview = this;
    this->subviews.push_back(view);
}

void UIKit::UIView::removeFromSuperView() {
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->removeFromSuperView();
    }
    if (this->superview) {  // probably handle uiwindow case
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

bool UIKit::UIView::hitTest(UIKit::CGPoint clickPosition, UIKit::CGPoint parentOrigin, UIKit::UIEvent event) {
    UIKit::CGRect absoluteFrame = UIKit::CGRect(parentOrigin + this->frame.origin, this->frame.size);
    if (!absoluteFrame.contains(clickPosition)) return false;
    bool bubble = false;
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        if ((*it)->hitTest(clickPosition, absoluteFrame.origin, event)) bubble = true;
    }
    if (this->subviews.size() != 0 && !bubble) return false;
    switch (event) {
        case UIEvent::click: ofNotifyEvent(this->onclick, this); break;
        case UIEvent::mousedown: ofNotifyEvent(this->onmousedown, this); break;
        case UIEvent::mouseup: ofNotifyEvent(this->onmouseup, this); break;
        default: return false;
    }
    return true;
}

