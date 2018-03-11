//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "RectangleView.h"

Components::Views::Rectangle::Rectangle(Components::Rectangle* rectangle): Base("Rectangle"), rectangle(rectangle) {
    if (!rectangle) return;
    this->fillColorView = Components::Views::Generator::color("Fill: ", &this->rectangle->fillColor);
    this->strokeColorView = Components::Views::Generator::color("Stroke: ", &this->rectangle->strokeColor);
    this->borderWidthView = Components::Views::Generator::numeric("Border: ", this->rectangle->getBorderWidth());
    this->widthView = Components::Views::Generator::numeric("Width: ", this->rectangle->getWidth());
    this->heightView = Components::Views::Generator::numeric("Height: ", this->rectangle->getHeight());

    this->fillColorView->colorView->tag = 0;
    this->strokeColorView->colorView->tag = 1;
    this->borderWidthView->valueLabel->tag = 2;
    ofAddListener(this->borderWidthView->valueLabel->onclick, this, &Components::Views::Rectangle::click);
    ofAddListener(this->borderWidthView->valueLabel->onrightclick, this, &Components::Views::Rectangle::rightclick);
    this->widthView->valueLabel->tag = 3;
    ofAddListener(this->widthView->valueLabel->onclick, this, &Components::Views::Rectangle::click);
    ofAddListener(this->widthView->valueLabel->onrightclick, this, &Components::Views::Rectangle::rightclick);
    this->heightView->valueLabel->tag = 4;
    ofAddListener(this->heightView->valueLabel->onclick, this, &Components::Views::Rectangle::click);
    ofAddListener(this->heightView->valueLabel->onrightclick, this, &Components::Views::Rectangle::rightclick);

    this->contentView->addSubview(this->fillColorView);
    this->contentView->addSubview(this->strokeColorView);
    this->contentView->addSubview(this->borderWidthView);
    this->contentView->addSubview(this->widthView);
    this->contentView->addSubview(this->heightView);
}


void Components::Views::Rectangle::layoutSubviews() {
    int x = 0;
    this->fillColorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->fillColorView->height);
    x += this->fillColorView->height;
    this->strokeColorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->strokeColorView->height);
    x += this->strokeColorView->height;
    this->borderWidthView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->borderWidthView->height);
    x += this->borderWidthView->height;
    this->widthView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->widthView->height);
    x += this->widthView->height;
    this->heightView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->heightView->height);
    x += this->heightView->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Rectangle::setText(int tag) {
    switch(tag) {
        case 0: break;
        case 1: break;
        case 2: this->borderWidthView->setValue(this->rectangle->getBorderWidth()); break;
        case 3: this->widthView->setValue(this->rectangle->getWidth()); break;
        case 4: this->heightView->setValue(this->rectangle->getHeight()); break;
        default: break;
    }
}

void Components::Views::Rectangle::click(UIView & view) {
    switch(view.tag) {
        case 0: break;
        case 1: break;
        case 2:
            {
                float x = this->rectangle->getBorderWidth();
                if(x < 9.5) { this->rectangle->setBorderWidth(x + 0.5); }
            }
            break;
        case 3: this->rectangle->setWidth(this->rectangle->getWidth() + 5); break;
        case 4: this->rectangle->setHeight(this->rectangle->getHeight() + 5); break;
        default: break;
    }
    setText(view.tag);
}

void Components::Views::Rectangle::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: break;
        case 1: break;
        case 2:
            {
                float x = this->rectangle->getBorderWidth();
                if(x < 9.5) { this->rectangle->setBorderWidth(x - 0.5); }
            }
            break;
        case 3: this->rectangle->setWidth(this->rectangle->getWidth() - 5); break;
        case 4: this->rectangle->setHeight(this->rectangle->getHeight() - 5); break;
        default: break;
    }
    setText(view.tag);
}

