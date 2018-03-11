//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "TextureView.h"

Components::Views::Texture::Texture(Components::Texture* texture): Base(texture->name), texture(texture) {
    if (!texture) return;
    this->filePicker = Components::Views::Generator::file("File: ", this->texture->getPath());
    this->filePicker->delegate = this;
    this->contentView->addSubview(this->filePicker);
}

void Components::Views::Texture::layoutSubviews() {
    int x = 0;
    this->filePicker->frame = UIKit::CGRect(0, x, this->frame.size.width, this->filePicker->height);
    x += this->filePicker->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Texture::didPickFile(string path) {
    if (!this->texture->loadTexture(path)) {
        this->filePicker->pathLabel->text = "Could not load texture!";
        this->filePicker->pathLabel->textColor = ofColor(244, 67, 54);
    } else {
        this->filePicker->pathLabel->textColor = ofColor(20);
    }
}

