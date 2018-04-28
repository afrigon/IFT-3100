//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "MaterialView.h"

void Components::Views::MapFilePickerDelegate::didPickFile(string path) {
    this->map->loadImage(path);
}

Components::Views::Material::Material(Components::Material* material): Base(material->name), material(material) {
    if (!material) return;
    this->ambientPicker = Components::Views::Generator::file("Ambient Map: ", this->material->ambient.getPath());
    this->contentView->addSubview(this->ambientPicker);
    this->diffusePicker = Components::Views::Generator::file("Diffuse Map: ", this->material->diffuse.getPath());
    this->contentView->addSubview(this->diffusePicker);
    this->specularPicker = Components::Views::Generator::file("Specular Map: ", this->material->specular.getPath());
    this->contentView->addSubview(this->specularPicker);
    this->normalPicker = Components::Views::Generator::file("Normal Map: ", this->material->normal.getPath());
    this->contentView->addSubview(this->normalPicker);
    this->reflectionPicker = Components::Views::Generator::file("Reflection Map: ", this->material->reflection.getPath());
    this->contentView->addSubview(this->reflectionPicker);
    
    this->ambientDelegate = Components::Views::MapFilePickerDelegate(&this->material->ambient);
    this->diffuseDelegate = Components::Views::MapFilePickerDelegate(&this->material->diffuse);
    this->specularDelegate = Components::Views::MapFilePickerDelegate(&this->material->specular);
    this->normalDelegate = Components::Views::MapFilePickerDelegate(&this->material->normal);
    this->reflectionDelegate = Components::Views::MapFilePickerDelegate(&this->material->reflection);
    this->ambientPicker->delegate = &this->ambientDelegate;
    this->diffusePicker->delegate = &this->diffuseDelegate;
    this->specularPicker->delegate = &this->specularDelegate;
    this->normalPicker->delegate = &this->normalDelegate;
    this->reflectionPicker->delegate = &this->reflectionDelegate;
    
    this->ambientColor = Components::Views::Generator::color("Ambient: ", &this->material->ambientColor);
    this->ambientColor->setShowAlpha(false);
    this->contentView->addSubview(this->ambientColor);
    this->diffuseColor = Components::Views::Generator::color("Diffuse: ", &this->material->diffuseColor);
    this->diffuseColor->setShowAlpha(false);
    this->contentView->addSubview(this->diffuseColor);
    this->specularColor = Components::Views::Generator::color("Specular: ", &this->material->specularColor);
    this->specularColor->setShowAlpha(false);
    this->contentView->addSubview(this->specularColor);
    
    this->brightness = Components::Views::Generator::numeric("Brightness: ", this->material->brightness);
    this->brightness->valueLabel->tag = 0;
    ofAddListener(this->brightness->valueLabel->onclick, this, &Components::Views::Material::click);
    ofAddListener(this->brightness->valueLabel->onrightclick, this, &Components::Views::Material::rightclick);
    this->contentView->addSubview(this->brightness);
    
    vector<string> data;
    data.push_back("Lambert");
    data.push_back("Phong");
    data.push_back("Blinn-Phong");
    this->illuminationMode = Components::Views::Generator::switchView("Illumination Type: ", data, 2);
    this->illuminationMode->valueLabel->tag = 1;
    ofAddListener(this->illuminationMode->valueLabel->onclick, this, &Components::Views::Material::click);
    ofAddListener(this->illuminationMode->valueLabel->onrightclick, this, &Components::Views::Material::rightclick);
    this->contentView->addSubview(this->illuminationMode);
}

Components::Views::Material::~Material() {
    ofRemoveListener(this->brightness->valueLabel->onclick, this, &Components::Views::Material::click);
    ofRemoveListener(this->brightness->valueLabel->onrightclick, this, &Components::Views::Material::rightclick);
    ofRemoveListener(this->brightness->valueLabel->onclick, this, &Components::Views::Material::click);
    ofRemoveListener(this->brightness->valueLabel->onrightclick, this, &Components::Views::Material::rightclick);
}

void Components::Views::Material::layoutSubviews() {
    int x = 0;
    
    this->illuminationMode->frame = UIKit::CGRect(0, x, this->frame.size.width, this->illuminationMode->height);
    x += this->illuminationMode->height;
    
    this->ambientColor->frame = UIKit::CGRect(0, x, this->frame.size.width, this->ambientColor->height);
    x += this->ambientColor->height;
    this->ambientPicker->frame = UIKit::CGRect(0, x, this->frame.size.width, this->ambientPicker->height);
    x += this->ambientPicker->height;
    
    this->diffuseColor->frame = UIKit::CGRect(0, x, this->frame.size.width, this->diffuseColor->height);
    x += this->diffuseColor->height;
    this->diffusePicker->frame = UIKit::CGRect(0, x, this->frame.size.width, this->diffusePicker->height);
    x += this->diffusePicker->height;
    
    this->specularColor->frame = UIKit::CGRect(0, x, this->frame.size.width, this->specularColor->height);
    x += this->specularColor->height;
    this->specularPicker->frame = UIKit::CGRect(0, x, this->frame.size.width, this->specularPicker->height);
    x += this->specularPicker->height;
    this->brightness->frame = UIKit::CGRect(0, x, this->frame.size.width, this->brightness->height);
    x += this->brightness->height;
    
    this->normalPicker->frame = UIKit::CGRect(0, x, this->frame.size.width, this->normalPicker->height);
    x += this->normalPicker->height;
    
    this->reflectionPicker->frame = UIKit::CGRect(0, x, this->frame.size.width, this->reflectionPicker->height);
    x += this->reflectionPicker->height;
    
    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::Material::setText(int tag) {
    switch(tag) {
        case 0: this->brightness->setValue(this->material->brightness); break;
        case 1:
            switch (this->material->getFlags() & 0b111) {
                case 1: this->illuminationMode->setValue(0); break;
                case 2: this->illuminationMode->setValue(1); break;
                case 4: this->illuminationMode->setValue(2); break;
            }
            break;
    }
}

void Components::Views::Material::click(UIView & view) {
    switch(view.tag) {
        case 0: this->material->brightness = min(this->material->brightness + 5.0, 300.0); break;
        case 1: this->material->illuminationTypeForward(); break;
    }
    this->setText(view.tag);
}

void Components::Views::Material::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: this->material->brightness = max(this->material->brightness - 5.0, 0.0); break;
        case 1: this->material->illuminationTypeBackward(); break;
    }
    this->setText(view.tag);
}
