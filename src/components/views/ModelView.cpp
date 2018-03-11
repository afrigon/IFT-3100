//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ModelView.h"

Components::Views::Model::Model(Components::Model* model): Base(model->name), model(model) {
    if (!model) return;
    this->filePicker = Components::Views::Generator::file("File: ", this->model->getPath());
    this->filePicker->delegate = this;
    this->contentView->addSubview(this->filePicker);
}

void Components::Views::Model::layoutSubviews() {
    int x = 0;
    this->filePicker->frame = UIKit::CGRect(0, x, this->frame.size.width, this->filePicker->height);
    x += this->filePicker->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Model::didPickFile(string path) {
    if (!this->model->loadModel(path)) {
        //show error
    }
}
