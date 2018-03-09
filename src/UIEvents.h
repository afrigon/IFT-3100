//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UIEVENTS_H_
#define UIKIT_UIEVENTS_H_

#include "UIView.h"

namespace UIKit {
class UIEvent {
    bool bubble = true;
    
 public:
    UIView* target;
    
    UIEvent(UIView* target): target(target) {}
    bool shouldBubble() { return this->bubble; }
    void stopPropagation() { this->bubble = false; }
};

class UIEvents {
    static ofEvent<UIEvent*> onUIClick;
    static ofEvent<UIEvent*> onUIMouseDown;
    static ofEvent<UIEvent*> onUIMouseUp;
};
}  // namespace UIKit

#endif  // UIKIT_UIEVENTS_H_
