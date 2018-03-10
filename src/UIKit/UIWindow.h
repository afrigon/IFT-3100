//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UIWINDOW_H_
#define UIKIT_UIWINDOW_H_

#include "ofMain.h"
#include "UIView.h"
#include "UIViewController.h"

namespace UIKit {
class UIWindow {
    CGSize size = UIKit::CGSize(ofGetWidth(), ofGetHeight());
    UIViewController* rootViewController;
    UIKit::CGPoint clickStartPosition;
    int clickThreshold = 3;
    
    void resize(ofResizeEventArgs &);
    void mousedown(ofMouseEventArgs &);
    void mouseup(ofMouseEventArgs &);

 public:
    UIWindow();
    ~UIWindow();
    void draw();
    void setRootViewController(UIViewController*);
    void layoutSubviews();
};
}  // namespace UIKit

#endif  // UIKIT_UIWINDOW_H_
