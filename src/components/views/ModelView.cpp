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
    
    this->vertexView = Components::Views::Generator::numeric("Vertices:", this->model->getVertexCount());
    this->vertexView->decimalCount = 0;
    this->vertexView->setValue(this->model->getVertexCount());
    this->vertexView->valueLabel->isUserInteractionEnabled = false;
    this->contentView->addSubview(this->vertexView);
}

void Components::Views::Model::layoutSubviews() {
    int x = 0;
    this->filePicker->frame = UIKit::CGRect(0, x, this->frame.size.width, this->filePicker->height);
    x += this->filePicker->height;
    this->vertexView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->vertexView->height);
    x += this->vertexView->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Model::didPickFile(string path) {
    if (!this->model->loadModel(path)) {
        this->filePicker->pathLabel->text = "Could not load mesh!";
        this->filePicker->pathLabel->textColor = ofColor(244, 67, 54);
        this->vertexView->setValue(0);
    } else {
        this->filePicker->pathLabel->textColor = ofColor(20);
        this->vertexView->setValue(this->model->getVertexCount());
    }
}
