//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIWindow.h"

UIKit::UIWindow::UIWindow() {
    ofAddListener(ofEvents().windowResized, this, &UIWindow::resize);
}

UIKit::UIWindow::~UIWindow() {
    ofRemoveListener(ofEvents().windowResized, this, &UIWindow::resize);
}

void UIKit::UIWindow::resize(ofResizeEventArgs & e) {
    this->size = UIKit::CGSize(e.width, e.height);
    this->rootViewController->view->frame = UIKit::CGRect(UIKit::CGPoint(), this->size);
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
