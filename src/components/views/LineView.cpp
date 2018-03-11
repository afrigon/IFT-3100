//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "LineView.h"

Components::Views::Line::Line(Components::Line* line): Base("Line"), line(line) {
    if (!line) return;
    this->colorView = Components::Views::Generator::color("Color: ", &this->line->strokeColor);
    this->widthView = Components::Views::Generator::numeric("Width: ", this->line->getStrokeWidth());
    this->lengthView = Components::Views::Generator::numeric("Length: ", this->line->getLineLength());

    this->colorView->colorView->tag = 0;
    this->widthView->valueLabel->tag = 1;
    ofAddListener(this->widthView->valueLabel->onclick, this, &Components::Views::Line::click);
    ofAddListener(this->widthView->valueLabel->onrightclick, this, &Components::Views::Line::rightclick);
    this->lengthView->valueLabel->tag = 2;
    ofAddListener(this->lengthView->valueLabel->onclick, this, &Components::Views::Line::click);
    ofAddListener(this->lengthView->valueLabel->onrightclick, this, &Components::Views::Line::rightclick);

    this->contentView->addSubview(this->colorView);
    this->contentView->addSubview(this->widthView);
    this->contentView->addSubview(this->lengthView);
}

void Components::Views::Line::layoutSubviews() {
    int x = 0;
    this->colorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->colorView->height);
    x += this->colorView->height;
    this->widthView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->widthView->height);
    x += this->widthView->height;
    this->lengthView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->lengthView->height);
    x += this->lengthView->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Line::setText(int tag) {
    switch(tag) {
        case 0: break;
        case 1: this->widthView->setValue(this->line->getStrokeWidth()); break;
        case 2: this->lengthView->setValue(this->line->getLineLength()); break;
        default: break;
    }
}

void Components::Views::Line::click(UIView & view) {
    switch(view.tag) {
        case 0: break;
        case 1:
            {
                float x = this->line->getStrokeWidth();
                if(x < 9.5) { this->line->setStrokeWidth(x + 0.5); }
            }
            break;
        case 2: this->line->setLineLength(this->line->getLineLength() + 5); break;
        default: break;
    }
    this->setText(view.tag);
}

void Components::Views::Line::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: break;
        case 1:
            {
                float x = this->line->getStrokeWidth();
                if(x > 0.5) { this->line->setStrokeWidth(x - 0.5); }
            }
            break;
        case 2: this->line->setLineLength(this->line->getLineLength() - 5); break;
        default: break;
    }
    this->setText(view.tag);
}
