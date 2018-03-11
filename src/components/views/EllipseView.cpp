//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "EllipseView.h"

Components::Views::Ellipse::Ellipse(Components::Ellipse* ellipse): Base(ellipse->name), ellipse(ellipse) {
    if (!ellipse) return;
    this->fillColorView = Components::Views::Generator::color("Fill: ", &this->ellipse->fillColor);
    this->widthView = Components::Views::Generator::numeric("Width: ", this->ellipse->getWidth());
    this->heightView = Components::Views::Generator::numeric("Height: ", this->ellipse->getHeight());

    this->widthView->valueLabel->tag = 0;
    ofAddListener(this->widthView->valueLabel->onclick, this, &Components::Views::Ellipse::click);
    ofAddListener(this->widthView->valueLabel->onrightclick, this, &Components::Views::Ellipse::rightclick);
    this->heightView->valueLabel->tag = 1;
    ofAddListener(this->heightView->valueLabel->onclick, this, &Components::Views::Ellipse::click);
    ofAddListener(this->heightView->valueLabel->onrightclick, this, &Components::Views::Ellipse::rightclick);

    this->contentView->addSubview(this->fillColorView);
    this->contentView->addSubview(this->widthView);
    this->contentView->addSubview(this->heightView);
}

Components::Views::Ellipse::~Ellipse() {
    ofRemoveListener(this->widthView->valueLabel->onclick, this, &Components::Views::Ellipse::click);
    ofRemoveListener(this->widthView->valueLabel->onrightclick, this, &Components::Views::Ellipse::rightclick);
    ofRemoveListener(this->heightView->valueLabel->onclick, this, &Components::Views::Ellipse::click);
    ofRemoveListener(this->heightView->valueLabel->onrightclick, this, &Components::Views::Ellipse::rightclick);
}

void Components::Views::Ellipse::layoutSubviews() {
    int x = 0;
    this->fillColorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->fillColorView->height);
    x += this->fillColorView->height;
    this->widthView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->widthView->height);
    x += this->widthView->height;
    this->heightView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->heightView->height);
    x += this->heightView->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Ellipse::setText(int tag) {
    switch(tag) {
        case 0: this->widthView->setValue(this->ellipse->getWidth());
        case 1: this->heightView->setValue(this->ellipse->getHeight());
    }
}

void Components::Views::Ellipse::click(UIView & view) {
    switch(view.tag) {
        case 0: this->ellipse->setWidth(this->ellipse->getWidth() + 5); break;
        case 1: this->ellipse->setHeight(this->ellipse->getHeight() + 5); break;
    }
    this->setText(view.tag);
}

void Components::Views::Ellipse::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: this->ellipse->setWidth(this->ellipse->getWidth() - 5); break;
        case 1: this->ellipse->setHeight(this->ellipse->getHeight() - 5); break;
    }
    this->setText(view.tag);
}
