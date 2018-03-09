//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIKit/UIViewController.h"

void UIKit::UIViewController::layoutSubviews() {
    this->willLayoutSubviews();
    this->view->layoutSubviews();
    this->didLayoutSubviews();
}
