#pragma once

#include "UIView.h"
#include "UILabel.h"

namespace UIKit
{
    class UITextfield : public UIView {
        public:
        UILabel value;
        UIView background;

        UITextfield(std::string text = "");

        void draw(UIKit::CGRect) override;

        void click(UIKit::UIView &);
        void keyPressed(pair<UIKit::UIView, int> &);
    };
}
