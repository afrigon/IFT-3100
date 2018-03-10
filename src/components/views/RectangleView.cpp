//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "RectangleView.h"

Components::Views::Rectangle::Rectangle(Components::Rectangle* rectangle): Base("Rectangle"), rectangle(rectangle) {
    if (!rectangle) return;
    this->fillColorView = Components::Views::Generator::color("Fill: ", this->rectangle->getFillColor());
    this->strokeColorView = Components::Views::Generator::color("Stroke: ", this->rectangle->getDrawColor());
    this->borderWidthView = Components::Views::Generator::numeric("Border: ", this->rectangle->getBorderWidth());
    this->widthView = Components::Views::Generator::numeric("Width: ", this->rectangle->getWidth());
    this->heightView = Components::Views::Generator::numeric("Height: ", this->rectangle->getHeight());
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

