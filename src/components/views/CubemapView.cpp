//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "CubemapView.h"

Components::Views::Cubemap::Cubemap(Components::Cubemap* cubemap): Base(cubemap->name), cubemap(cubemap) {
    if (!cubemap) return;
    this->filePicker = Components::Views::Generator::file("File: ", this->cubemap->getPath());
    this->filePicker->delegate = this;
    this->contentView->addSubview(this->filePicker);
    
    this->distanceView = Components::Views::Generator::numeric("Distance: ", this->cubemap->distance);
    this->contentView->addSubview(this->distanceView);
    ofAddListener(this->distanceView->valueLabel->onclick, this, &Components::Views::Cubemap::click);
    ofAddListener(this->distanceView->valueLabel->onrightclick, this, &Components::Views::Cubemap::rightclick);
}

Components::Views::Cubemap::~Cubemap() {
    ofRemoveListener(this->distanceView->valueLabel->onclick, this, &Components::Views::Cubemap::click);
    ofRemoveListener(this->distanceView->valueLabel->onrightclick, this, &Components::Views::Cubemap::rightclick);
}

void Components::Views::Cubemap::layoutSubviews() {
    int x = 0;
    this->filePicker->frame = UIKit::CGRect(0, x, this->frame.size.width, this->filePicker->height);
    x += this->filePicker->height;
    this->distanceView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->distanceView->height);
    x += this->distanceView->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Cubemap::didPickFile(string path) {
    if (!this->cubemap->loadMap(path)) {
        this->filePicker->pathLabel->text = "Could not load cubemap!";
        this->filePicker->pathLabel->textColor = ofColor(244, 67, 54);
    } else {
        this->filePicker->pathLabel->textColor = ofColor(20);
    }
}

void Components::Views::Cubemap::click(UIKit::UIView & view) {
    this->cubemap->distance += 100;
    this->distanceView->setValue(this->cubemap->distance);
}

void Components::Views::Cubemap::rightclick(UIKit::UIView & view) {
    this->cubemap->distance -= 100;
    this->distanceView->setValue(this->cubemap->distance);
}
