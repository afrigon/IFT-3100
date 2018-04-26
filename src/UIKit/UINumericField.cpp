#include "UINumericField.h"

void UIKit::UINumericField::keyPressed(pair<UIKit::UIView, int>& e) {
    if(!this->focus) {
        ofRemoveListener(this->onkeypressed, this, &UIKit::UINumericField::keyPressed);
    } else {
        if(e.second == OF_KEY_DEL || e.second == OF_KEY_BACKSPACE) {
            this->value.text = this->value.text.substr(0, this->value.text.length() - 1);
        } else if(e.second == OF_KEY_RETURN) {
            this->value.text += "\n";
        } else if(e.second >= 48 && e.second <= 57) {
            if(value.text == "") {
                this->value.text.clear();
            }
            ofAppendUTF8(this->value.text, e.second);
        }
    }
}
