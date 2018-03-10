//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ModelView.h"

Components::Views::Model::Model(Components::Model* Model): Base("Model"), model(model) {
    if (!model) return;
}


void Components::Views::Model::layoutSubviews() {
    int x = 0;
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

