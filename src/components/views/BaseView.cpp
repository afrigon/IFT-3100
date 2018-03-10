//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "BaseView.h"

Components::Views::Base::Base(string text) {
    this->backgroundColor = ofColor(175);
    
    this->label->text = text;
    this->label->setFontSize(10);
    this->addSubview(this->label);
    
    this->addSubview(this->contentView);
}

void Components::Views::Base::layoutSubviews() {
    this->label->frame = UIKit::CGRect(0, 0, this->frame.size.width, 20);
    this->contentView->frame.origin.y = 20;
    UIView::layoutSubviews();
}
