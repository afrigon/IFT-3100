#pragma once

#include "UITextfield.h"

namespace UIKit
{
    class UINumericField : public UITextfield {
        public:
        void keyPressed(pair<UIKit::UIView, int> &);
    };
}
#pragma once
