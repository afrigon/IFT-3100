#include "UITextfield.h"

UIKit::UITextfield::UITextfield(std::string text) {
    value.text = (text);
    value.loadFont();
    value.backgroundColor = ofColor::black;

    backgroundColor = ofColor::white;
    background.backgroundColor = ofColor::white;
}

void UIKit::UITextfield::draw(UIKit::CGRect rect) {
    if(this->isHidden) return;
    UIKit::UIView::draw(rect);
    ofSetColor(this->background.backgroundColor);
    ofFill();
    ofDrawRectangle(rect.origin.x + 10, rect.origin.y, rect.size.width - 20, rect.size.height);
    this->value.draw(UIKit::CGRect(rect.origin.x + 10, rect.origin.y, rect.size.width - 20, rect.size.height));

    for(std::list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->draw(rect + this->frame);
    }
}

void UIKit::UITextfield::click(UIKit::UIView & view) {
    ofAddListener(this->onkeypressed, this, &UIKit::UITextfield::keyPressed);
}

void UIKit::UITextfield::keyPressed(pair<UIKit::UIView, int> & e) {
    if(!this->focus) {
        ofRemoveListener(this->onkeypressed, this, &UIKit::UITextfield::keyPressed);
    } else {
        if(e.second == OF_KEY_DEL || e.second == OF_KEY_BACKSPACE) {
            this->value.text = this->value.text.substr(0, this->value.text.length() - 1);
        } else if(e.second == OF_KEY_RETURN) {
            this->value.text += "\n";
        } else {
            if(value.text == "") {
                this->value.text.clear();
            }
            ofAppendUTF8(this->value.text, e.second);
        }
    }
}
