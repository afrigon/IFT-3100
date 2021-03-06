//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "SphereView.h"

Components::Views::Sphere::Sphere(Components::Sphere* sphere): Base(sphere->name), sphere(sphere) {
    if (!sphere) return;
    this->colorView = Components::Views::Generator::color("Color: ", &this->sphere->color);
    this->radiusView = Components::Views::Generator::numeric("Radius: ", this->sphere->radius);
    ofAddListener(this->radiusView->valueLabel->onclick, this, &Components::Views::Sphere::click);
    ofAddListener(this->radiusView->valueLabel->onrightclick, this, &Components::Views::Sphere::rightclick);

    this->contentView->addSubview(this->colorView);
    this->contentView->addSubview(this->radiusView);
}

Components::Views::Sphere::~Sphere() {
    ofRemoveListener(this->radiusView->valueLabel->onclick, this, &Components::Views::Sphere::click);
    ofRemoveListener(this->radiusView->valueLabel->onrightclick, this, &Components::Views::Sphere::rightclick);
}

void Components::Views::Sphere::layoutSubviews() {
    int x = 0;
    this->colorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->colorView->height);
    x += this->colorView->height;
    this->radiusView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->radiusView->height);
    x += this->radiusView->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Sphere::click(UIView & view) {
    this->sphere->radius += 5;
    this->radiusView->setValue(this->sphere->radius);
}

void Components::Views::Sphere::rightclick(UIView & view) {
    this->sphere->radius -= 5;
    this->radiusView->setValue(this->sphere->radius);
}
