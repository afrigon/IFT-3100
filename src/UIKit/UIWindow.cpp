//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIKit/UIWindow.h"

UIKit::UIWindow::UIWindow() {
    ofAddListener(ofEvents().windowResized, this, &UIWindow::resize);
    ofAddListener(ofEvents().mousePressed, this, &UIWindow::mousedown);
    ofAddListener(ofEvents().mouseReleased, this, &UIWindow::mouseup);
}

UIKit::UIWindow::~UIWindow() {
    ofRemoveListener(ofEvents().windowResized, this, &UIWindow::resize);
    ofRemoveListener(ofEvents().mousePressed, this, &UIWindow::mousedown);
    ofRemoveListener(ofEvents().mouseReleased, this, &UIWindow::mouseup);
    delete this->rootViewController;
}

void UIKit::UIWindow::resize(ofResizeEventArgs & e) {
    this->size = UIKit::CGSize(e.width, e.height);
    this->rootViewController->view->frame = UIKit::CGRect(UIKit::CGPoint(), this->size);
}

void UIKit::UIWindow:: mousedown(ofMouseEventArgs & e) {
    this->clickStartPosition = UIKit::CGPoint(e.x, e.y);
    this->rootViewController->view->hitTest(UIKit::CGPoint(e.x, e.y), CGPoint(), UIEvent::mousedown);
}

void UIKit::UIWindow:: mouseup(ofMouseEventArgs & e) {
    this->rootViewController->view->hitTest(UIKit::CGPoint(e.x, e.y), CGPoint(), UIEvent::mouseup);
    if (CGRect(this->clickStartPosition.x - this->clickThreshold,
               this->clickStartPosition.y - this->clickThreshold,
               this->clickThreshold * 2,
               this->clickThreshold * 2).contains(CGPoint(e.x, e.y))) {
        if (e.button == 0) {
            this->rootViewController->view->hitTest(UIKit::CGPoint(e.x, e.y), CGPoint(), UIEvent::click);
        } else if (e.button == 2) {
            this->rootViewController->view->hitTest(UIKit::CGPoint(e.x, e.y), CGPoint(), UIEvent::rightclick);
        }
        
    }
    this->clickStartPosition = CGPoint(-100, -100);
}

void UIKit::UIWindow::draw() {
    ofSetDepthTest(false);
    this->rootViewController->view->draw(UIKit::CGRect(UIKit::CGPoint(), this->size));
    ofSetDepthTest(true);
}

void UIKit::UIWindow::setRootViewController(UIViewController* vc) {
    this->rootViewController = vc;
    vc->view->frame = UIKit::CGRect(UIKit::CGPoint(), this->size);
    this->rootViewController->viewDidLoad();
}

void UIKit::UIWindow::layoutSubviews() {
    this->rootViewController->layoutSubviews();
}
