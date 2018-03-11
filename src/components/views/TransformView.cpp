//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "TransformView.h"

Components::Views::Transform::Transform(Components::Transform* transform): Base(transform->name), transform(transform) {
    if (!transform) return;
    this->views[0] = Components::Views::Generator::vector3("Position: ", this->transform->position);
    this->views[1] = Components::Views::Generator::vector3("Rotation: ", this->transform->rotation);
    this->views[2] = Components::Views::Generator::vector3("Scale: ", this->transform->scale);
    for (int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            this->views[i]->valueLabels[j]->tag = i * 3 + j;
            ofAddListener(this->views[i]->valueLabels[j]->onclick, this, &Components::Views::Transform::click);
            ofAddListener(this->views[i]->valueLabels[j]->onrightclick, this, &Components::Views::Transform::rightclick);
        }
        this->contentView->addSubview(this->views[i]);
    }
}

Components::Views::Transform::~Transform() {
    for (int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            ofRemoveListener(this->views[i]->valueLabels[j]->onclick, this, &Components::Views::Transform::click);
            ofRemoveListener(this->views[i]->valueLabels[j]->onrightclick, this, &Components::Views::Transform::rightclick);
        }
    }
}

void Components::Views::Transform::layoutSubviews() {
    for (int i = 0; i < 3; ++i) {
        this->views[i]->frame = UIKit::CGRect(0, this->views[i]->height * i, this->frame.size.width, this->views[i]->height);
    }
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, this->views[0]->height * 3);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Transform::click(UIView & view) {
    switch (view.tag) {
        case 0: this->transform->position += Vector3(10, 0, 0); break;
        case 1: this->transform->position += Vector3(0, 10, 0); break;
        case 2: this->transform->position += Vector3(0, 0, 10); break;
        case 3: this->transform->rotation += Vector3(5, 0, 0); break;
        case 4: this->transform->rotation += Vector3(0, 5, 0); break;
        case 5: this->transform->rotation += Vector3(0, 0, 5); break;
        case 6: this->transform->scale += Vector3(0.05, 0, 0); break;
        case 7: this->transform->scale += Vector3(0, 0.05, 0); break;
        case 8: this->transform->scale += Vector3(0, 0, 0.05); break;
    }
    this->setText(view.tag);
}

void Components::Views::Transform::rightclick(UIView & view) {
    switch (view.tag) {
        case 0: this->transform->position -= Vector3(10, 0, 0); break;
        case 1: this->transform->position -= Vector3(0, 10, 0); break;
        case 2: this->transform->position -= Vector3(0, 0, 10); break;
        case 3: this->transform->rotation -= Vector3(5, 0, 0); break;
        case 4: this->transform->rotation -= Vector3(0, 5, 0); break;
        case 5: this->transform->rotation -= Vector3(0, 0, 5); break;
        case 6: this->transform->scale -= Vector3(0.05, 0, 0); break;
        case 7: this->transform->scale -= Vector3(0, 0.05, 0); break;
        case 8: this->transform->scale -= Vector3(0, 0, 0.05); break;
    }
    this->setText(view.tag);
}

void Components::Views::Transform::setText(int tag) {
    switch (tag * 3 / 9) {
        case 0: this->views[0]->setValue(this->transform->position); break;
        case 1: this->views[1]->setValue(this->transform->rotation); break;
        case 2: this->views[2]->setValue(this->transform->scale); break;
    }
}
