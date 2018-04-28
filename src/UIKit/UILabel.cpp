//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIKit/UILabel.h"

unordered_map<int, ofTrueTypeFont>* UIKit::UILabel::fonts = new unordered_map<int, ofTrueTypeFont>();

UIKit::UILabel::UILabel(string text): text(text) {
    this->loadFont();
    this->backgroundColor = ofColor(0, 0);
}

void UIKit::UILabel::setFontSize(int fontSize) {
    this->fontSize = fontSize;
    this->loadFont();
}

void UIKit::UILabel::loadFont() {
    unordered_map<int, ofTrueTypeFont>::iterator it = UIKit::UILabel::fonts->find(this->fontSize);
    if(it == UIKit::UILabel::fonts->end()) {
        this->font = new ofTrueTypeFont();
        this->font->load("Roboto-Regular.ttf", this->fontSize);
        UIKit::UILabel::fonts->insert(pair<int, ofTrueTypeFont>(this->fontSize, *(this->font)));
    } else {
        this->font = &(it->second);
    }
}

void UIKit::UILabel::draw(UIKit::CGRect rect) {
    if (this->isHidden) return;
    UIKit::UIView::draw(rect);
    ofSetColor(this->textColor);
    float x = 0;
    switch (this->textAlignment) {
        case TextAlignment::left: (x = rect.origin.x + this->frame.origin.x + this->padding); break;
        case TextAlignment::right:
            x = rect.origin.x + this->frame.origin.x + this->frame.size.width + this->font->stringWidth(this->text) - this->padding;
            break;
        case TextAlignment::center:
            x = rect.origin.x + this->frame.origin.x + this->frame.size.width / 2 - this->font->stringWidth(this->text) / 2;
            break;
    }
    float stringHeight = this->font->stringHeight(this->text);
    this->font->drawString(this->text, x, rect.origin.y + this->frame.origin.y + (this->frame.size.height - stringHeight) / 2 + stringHeight);

    for (std::list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->draw(rect + this->frame);
    }
}

double UIKit::UILabel::widthFor(string text) {
    return this->font->stringWidth(text) + (this->textAlignment == TextAlignment::center ? 0 : this->padding * 2);
}
