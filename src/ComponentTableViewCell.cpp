//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ComponentTableViewCell.h"

ComponentTableViewCell::ComponentTableViewCell(UIView* view): view(view) {
    delete this->label;
    this->subviews.pop_front();
    if (this->view) this->addSubview(this->view);
}

void ComponentTableViewCell::layoutSubviews() {
    this->frame.size.width = this->superview->frame.size.width;
    if (this->view) this->view->frame = UIKit::CGRect(UIKit::CGPoint(), this->frame.size);
    UIKit::UIView::layoutSubviews();
}
