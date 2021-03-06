//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "RectangleView.h"

Components::Views::Rectangle::Rectangle(Components::Rectangle* rectangle): Base(rectangle->name), rectangle(rectangle) {
    if (!rectangle) return;
    this->fillColorView = Components::Views::Generator::color("Fill: ", &this->rectangle->fillColor);
    this->strokeColorView = Components::Views::Generator::color("Stroke: ", &this->rectangle->strokeColor);
    this->borderWidthView = Components::Views::Generator::numeric("Border: ", this->rectangle->getBorderWidth());
    this->widthView = Components::Views::Generator::numeric("Width: ", this->rectangle->getWidth());
    this->heightView = Components::Views::Generator::numeric("Height: ", this->rectangle->getHeight());

    this->borderWidthView->valueLabel->tag = 0;
    ofAddListener(this->borderWidthView->valueLabel->onclick, this, &Components::Views::Rectangle::click);
    ofAddListener(this->borderWidthView->valueLabel->onrightclick, this, &Components::Views::Rectangle::rightclick);
    this->widthView->valueLabel->tag = 1;
    ofAddListener(this->widthView->valueLabel->onclick, this, &Components::Views::Rectangle::click);
    ofAddListener(this->widthView->valueLabel->onrightclick, this, &Components::Views::Rectangle::rightclick);
    this->heightView->valueLabel->tag = 2;
    ofAddListener(this->heightView->valueLabel->onclick, this, &Components::Views::Rectangle::click);
    ofAddListener(this->heightView->valueLabel->onrightclick, this, &Components::Views::Rectangle::rightclick);

    this->contentView->addSubview(this->fillColorView);
    this->contentView->addSubview(this->strokeColorView);
    this->contentView->addSubview(this->borderWidthView);
    this->contentView->addSubview(this->widthView);
    this->contentView->addSubview(this->heightView);
}

Components::Views::Rectangle::~Rectangle() {
    ofRemoveListener(this->borderWidthView->valueLabel->onclick, this, &Components::Views::Rectangle::click);
    ofRemoveListener(this->borderWidthView->valueLabel->onrightclick, this, &Components::Views::Rectangle::rightclick);
    ofRemoveListener(this->widthView->valueLabel->onclick, this, &Components::Views::Rectangle::click);
    ofRemoveListener(this->widthView->valueLabel->onrightclick, this, &Components::Views::Rectangle::rightclick);
    ofRemoveListener(this->heightView->valueLabel->onclick, this, &Components::Views::Rectangle::click);
    ofRemoveListener(this->heightView->valueLabel->onrightclick, this, &Components::Views::Rectangle::rightclick);
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
        case 0: this->borderWidthView->setValue(this->rectangle->getBorderWidth()); break;
        case 1: this->widthView->setValue(this->rectangle->getWidth()); break;
        case 2: this->heightView->setValue(this->rectangle->getHeight()); break;
    }
}

void Components::Views::Rectangle::click(UIView & view) {
    switch(view.tag) {
        case 0: this->rectangle->setBorderWidth(min((this->rectangle->getBorderWidth() + 0.5), 9.5)); break;
        case 1: this->rectangle->setWidth(this->rectangle->getWidth() + 5); break;
        case 2: this->rectangle->setHeight(this->rectangle->getHeight() + 5); break;
    }
    setText(view.tag);
}

void Components::Views::Rectangle::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: this->rectangle->setBorderWidth(max((this->rectangle->getBorderWidth() - 0.5), 0.5)); break;
        case 1: this->rectangle->setWidth(this->rectangle->getWidth() - 5); break;
        case 2: this->rectangle->setHeight(this->rectangle->getHeight() - 5); break;
        default: break;
    }
    setText(view.tag);
}

