//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "LineView.h"

Components::Views::Line::Line(Components::Line* line): Base("Line"), line(line) {
    if (!line) return;
    this->colorView = Components::Views::Generator::color("Color: ", this->line->getLineColor());
    this->widthView = Components::Views::Generator::numeric("Width: ", this->line->getLineWidth());
    this->lengthView = Components::Views::Generator::numeric("Length: ", this->line->getLineLength());
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
