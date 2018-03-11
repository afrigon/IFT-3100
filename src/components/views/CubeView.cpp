//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "CubeView.h"

Components::Views::Cube::Cube(Components::Cube* cube): Base(cube->name), cube(cube) {
    if (!cube) return;
    this->colorView = Components::Views::Generator::color("Color: ", &this->cube->color);
    this->sizeView = Components::Views::Generator::vector3("Size: ", this->cube->size);
    this->sizeView->valueLabels[0]->tag = 0;
    ofAddListener(this->sizeView->valueLabels[0]->onclick, this, &Components::Views::Cube::click);
    ofAddListener(this->sizeView->valueLabels[0]->onrightclick, this, &Components::Views::Cube::rightclick);
    this->sizeView->valueLabels[1]->tag = 1;
    ofAddListener(this->sizeView->valueLabels[1]->onclick, this, &Components::Views::Cube::click);
    ofAddListener(this->sizeView->valueLabels[1]->onrightclick, this, &Components::Views::Cube::rightclick);
    this->sizeView->valueLabels[2]->tag = 2;
    ofAddListener(this->sizeView->valueLabels[2]->onclick, this, &Components::Views::Cube::click);
    ofAddListener(this->sizeView->valueLabels[2]->onrightclick, this, &Components::Views::Cube::rightclick);
    this->contentView->addSubview(this->colorView);
    this->contentView->addSubview(this->sizeView);
}

Components::Views::Cube::~Cube() {
    ofRemoveListener(this->sizeView->valueLabels[0]->onclick, this, &Components::Views::Cube::click);
    ofRemoveListener(this->sizeView->valueLabels[0]->onrightclick, this, &Components::Views::Cube::rightclick);
    ofRemoveListener(this->sizeView->valueLabels[1]->onclick, this, &Components::Views::Cube::click);
    ofRemoveListener(this->sizeView->valueLabels[1]->onrightclick, this, &Components::Views::Cube::rightclick);
    ofRemoveListener(this->sizeView->valueLabels[2]->onclick, this, &Components::Views::Cube::click);
    ofRemoveListener(this->sizeView->valueLabels[2]->onrightclick, this, &Components::Views::Cube::rightclick);
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

void Components::Views::Cube::click(UIView & view) {
    switch (view.tag) {
        case 0: this->cube->size += Vector3(10, 0, 0); break;
        case 1: this->cube->size += Vector3(0, 10, 0); break;
        case 2: this->cube->size += Vector3(0, 0, 10); break;
    }
    this->sizeView->setValue(this->cube->size);
}

void Components::Views::Cube::rightclick(UIView & view) {
    switch (view.tag) {
        case 0: this->cube->size -= Vector3(10, 0, 0); break;
        case 1: this->cube->size -= Vector3(0, 10, 0); break;
        case 2: this->cube->size -= Vector3(0, 0, 10); break;
    }
    this->sizeView->setValue(this->cube->size);
}
