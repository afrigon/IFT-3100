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
    static UIWindow* instance;
    CGSize size = UIKit::CGSize(ofGetWidth(), ofGetHeight());
    UIViewController* rootViewController;
    UIKit::CGPoint clickStartPosition;
    int clickThreshold = 3;
    bool needLayout = true;
    
    void resize(ofResizeEventArgs &);
    void mousedown(ofMouseEventArgs &);
    void mouseup(ofMouseEventArgs &);
    void keyPressed(ofKeyEventArgs&);

 public:
    ofEasyCam* mainCamera;
    
    UIWindow();
    ~UIWindow();
    static UIWindow* shared();
    void draw();
    void setRootViewController(UIViewController*);
    void layoutIfNeeded();
    void setNeedsLayout();
    void layoutSubviews();
};
}  // namespace UIKit

#endif  // UIKIT_UIWINDOW_H_
