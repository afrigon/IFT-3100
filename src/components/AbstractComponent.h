//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_ABSTRACTCOMPONENT_H_
#define COMPONENTS_ABSTRACTCOMPONENT_H_

#include "UIKit.h"

class AbstractComponent {
 public:
    virtual UIKit::UIView* getUIView() { return nullptr; }
    virtual int getUIViewHeight() { return 0; }
};

#endif  // COMPONENTS_ABSTRACTCOMPONENT_H_
