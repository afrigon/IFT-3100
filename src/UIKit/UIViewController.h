//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UIVIEWCONTROLLER_H_
#define UIKIT_UIVIEWCONTROLLER_H_

#include "UIView.h"

namespace UIKit {
class UIViewController {
 public:
    UIView* view;

    UIViewController(): view(new UIView()) {
        this->view->backgroundColor = ofColor(0, 0, 0, 0);
    }
    ~UIViewController() { delete this->view; }
    void layoutSubviews();
    virtual void viewDidLoad() {}
    virtual void willLayoutSubviews() {}
    virtual void didLayoutSubviews() {}
    virtual void onKeyPressed(ofKeyEventArgs& e) {}
};
}  // namespace UIKit

#endif  // UIKIT_UIVIEWCONTROLLER_H_
