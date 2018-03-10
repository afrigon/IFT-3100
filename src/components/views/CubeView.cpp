//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "CubeView.h"

Components::Views::Cube::Cube(Components::Cube* cube): Base("Cube"), cube(cube) {
    if (!cube) return;
    this->colorView = Components::Views::Generator::color("Color: ", this->cube->getColor());
    this->sizeView = Components::Views::Generator::vector3("Size: ", this->cube->getSize());
    this->contentView->addSubview(this->colorView);
    this->contentView->addSubview(this->sizeView);
}


void Components::Views::Cube::layoutSubviews() {
    int x = 0;
    this->colorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->colorView->height);
    x += this->colorView->height;
    this->sizeView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->sizeView->height);
    x += this->sizeView->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}
