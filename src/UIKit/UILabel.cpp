//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIKit/UILabel.h"


UIKit::UILabel::UILabel() {
    this->loadFont();
}

UIKit::UILabel::UILabel(std::string text): text(text) {
    this->loadFont();
    this->backgroundColor = ofColor(0, 0);
}

void UIKit::UILabel::setFontSize(int fontSize) {
    this->fontSize = fontSize;
    this->loadFont();
    this->backgroundColor = ofColor(0, 0);
}

void UIKit::UILabel::loadFont() {
    this->font.load("nunito.ttf", this->fontSize);
}

void UIKit::UILabel::draw(UIKit::CGRect rect) {
    if (isHidden) return;
    ofSetColor(this->backgroundColor);
    ofDrawRectangle(this->frame.origin.x + rect.origin.x,
                    this->frame.origin.y + rect.origin.y,
                    this->frame.size.width,
                    this->frame.size.height);
    ofSetColor(this->textColor);
    float stringHeight = this->font.stringHeight(this->text);
    this->font.drawString(this->text,
                          rect.origin.x + this->frame.origin.x + this->padding,
                          rect.origin.y + this->frame.origin.y + (this->frame.size.height - stringHeight) / 2 + stringHeight);
    
    for (std::list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->draw(rect + this->frame);
    }
}
