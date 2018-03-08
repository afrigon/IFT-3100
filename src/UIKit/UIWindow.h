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
        void resize(ofResizeEventArgs &);
        UIViewController* rootViewController;
        
     public:
        UIWindow();
        ~UIWindow();
        void draw();
        void setRootViewController(UIViewController*);
        void layoutSubviews();
    };
}

#endif  // UIKIT_UIWINDOW_H_
