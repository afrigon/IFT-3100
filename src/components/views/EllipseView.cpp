//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "EllipseView.h"

Components::Views::Ellipse::Ellipse(Components::Ellipse* ellipse): Base("Ellipse"), ellipse(ellipse) {
    if (!ellipse) return;
    this->fillColorView = Components::Views::Generator::color("Fill: ", this->ellipse->getFillColor());
    this->widthView = Components::Views::Generator::numeric("Width: ", this->ellipse->getWidth());
    this->heightView = Components::Views::Generator::numeric("Height: ", this->ellipse->getHeight());

    this->fillColorView->colorView->tag = 0;
    /*ofAddListener(this->fillColorView->onclick, this, &Components::Views::Ellipse::click);
    ofAddListener(this->fillColorView->onrightclick, this, &Components::Views::Ellipse::rightclick);*/
    this->widthView->valueLabel->tag = 1;
    ofAddListener(this->widthView->valueLabel->onclick, this, &Components::Views::Ellipse::click);
    ofAddListener(this->widthView->valueLabel->onrightclick, this, &Components::Views::Ellipse::rightclick);
    this->heightView->valueLabel->tag = 2;
    ofAddListener(this->heightView->valueLabel->onclick, this, &Components::Views::Ellipse::click);
    ofAddListener(this->heightView->valueLabel->onrightclick, this, &Components::Views::Ellipse::rightclick);

    this->contentView->addSubview(this->fillColorView);
    this->contentView->addSubview(this->widthView);
    this->contentView->addSubview(this->heightView);
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
        case 0: break;
        case 1: this->widthView->setValue(this->ellipse->getWidth());
        case 2: this->heightView->setValue(this->ellipse->getHeight());
        default: break;
    }
}

void Components::Views::Ellipse::click(UIView & view) {
    switch(view.tag) {
        case 0: break;
        case 1: this->ellipse->setWidth(this->ellipse->getWidth() + 5); break;
        case 2: this->ellipse->setHeight(this->ellipse->getHeight() + 5); break;
        default: break;
    }
    this->setText(view.tag);
}

void Components::Views::Ellipse::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: break;
        case 1: this->ellipse->setWidth(this->ellipse->getWidth() - 5); break;
        case 2: this->ellipse->setHeight(this->ellipse->getHeight() - 5); break;
        default: break;
    }
    this->setText(view.tag);
}
