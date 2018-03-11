//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "Generator.h"

Components::Views::LabeledView::LabeledView() {
    this->label->setFontSize(8);
    this->label->textColor = ofColor(20);
    this->label->padding = 10;
    this->addSubview(this->label);
}

void Components::Views::LabeledView::setName(string name) {
    this->label->text = name;
    this->label->frame = UIKit::CGRect(10, 0, this->label->widthFor(name), this->height);
}

Components::Views::Vector3View::Vector3View() {
    for (int i = 0; i < 3; ++i) {
        this->valueLabels[i] = new UIKit::UILabel("0");
        this->valueLabels[i]->textColor = ofColor(20);
        this->valueLabels[i]->setFontSize(8);
        this->valueLabels[i]->textAlignment = UIKit::TextAlignment::center;
        this->addSubview(this->valueLabels[i]);
    }
}

void Components::Views::Vector3View::setValue(Vector3 v) {
    for (int i = 0; i < 3; ++i) {
        this->valueLabels[i]->frame = UIKit::CGRect(i * this->spacing + 125, 0, this->spacing, this->height);
    }
    this->valueLabels[0]->text = Components::Views::Generator::numericToString(v.getX());
    this->valueLabels[1]->text = Components::Views::Generator::numericToString(v.getY());
    this->valueLabels[2]->text = Components::Views::Generator::numericToString(v.getZ());
}

Components::Views::ColorView::ColorView(ofColor* color): color(color) {
    for (int i = 0; i < 4; ++i) {
        this->valueLabels[i] = new UIKit::UILabel("255");
        this->valueLabels[i]->textColor = ofColor(20);
        this->valueLabels[i]->setFontSize(8);
        this->valueLabels[i]->textAlignment = UIKit::TextAlignment::center;
        this->valueLabels[i]->tag = i;
        ofAddListener(this->valueLabels[i]->onclick, this, &ColorView::click);
        ofAddListener(this->valueLabels[i]->onrightclick, this, &ColorView::rightclick);
        this->addSubview(this->valueLabels[i]);
    }
    
    this->modeLabel->textColor = ofColor(20);
    this->modeLabel->setFontSize(7);
    this->modeLabel->padding = 0;
    this->addSubview(this->modeLabel);
    
    ofAddListener(this->modeLabel->onclick, this, &Components::Views::ColorView::switchMode);
    this->colorView->cornerRadius = 6;
    this->addSubview(this->colorView);
    this->setValue();
}

Components::Views::ColorView::~ColorView() {
    for (int i = 0; i < 4; ++i) {
        ofRemoveListener(this->valueLabels[i]->onclick, this, &ColorView::click);
        ofRemoveListener(this->valueLabels[i]->onrightclick, this, &ColorView::rightclick);
    }
    ofRemoveListener(this->modeLabel->onclick, this, &Components::Views::ColorView::switchMode);
}

void Components::Views::ColorView::setValue() {
    for (int i = 0; i < 4; ++i) {
        this->valueLabels[i]->frame = UIKit::CGRect(i * (this->spacing + (this->showAlpha ? 0 : 10)) + 125, 0, this->spacing + (this->showAlpha ? 0 : 10), this->height);
    }
    
    if (!this->showAlpha) {
        this->valueLabels[3]->isHidden = true;
    } else {
        this->valueLabels[3]->isHidden = false;
    }
    
    this->colorView->backgroundColor = *this->color;
    this->colorView->frame = UIKit::CGRect(60, 3, this->height - 6, this->height - 6);
    this->modeLabel->frame = UIKit::CGRect(100, 0, this->height, this->height);
    
    switch (this->mode) {
        case ColorMode::RGB:
            this->modeLabel->text = "RGB";
            this->valueLabels[0]->text = Components::Views::Generator::numericToIntString(this->color->r);
            this->valueLabels[1]->text = Components::Views::Generator::numericToIntString(this->color->g);
            this->valueLabels[2]->text = Components::Views::Generator::numericToIntString(this->color->b);
            break;
        case ColorMode::HSB:
            this->modeLabel->text = "HSB";
            this->valueLabels[0]->text = Components::Views::Generator::numericToIntString(this->color->getHueAngle()) + "º";
            this->valueLabels[1]->text = Components::Views::Generator::numericToIntString(this->color->getSaturation() * 100 / 255) + "%";
            this->valueLabels[2]->text = Components::Views::Generator::numericToIntString(this->color->getBrightness() * 100 / 255) + "%";
            break;
    }
    this->valueLabels[3]->text = Components::Views::Generator::numericToIntString(this->color->a);
}

void Components::Views::ColorView::switchMode(UIView & view) {
    switch (this->mode) {
        case ColorMode::RGB: this->mode = ColorMode::HSB; break;
        case ColorMode::HSB: this->mode = ColorMode::RGB; break;
        default: this->mode = ColorMode::RGB; break;
    }
    this->setValue();
}

void Components::Views::ColorView::setShowAlpha(bool showAlpha) {
    this->showAlpha = showAlpha;
    this->setValue();
}

void Components::Views::ColorView::click(UIView & view) {
    this->editColor(view.tag, 1);
}

void Components::Views::ColorView::rightclick(UIView & view) {
    this->editColor(view.tag, -1);
}

void Components::Views::ColorView::editColor(int tag, int direction) {
    const int amount = 5 * max(-1, min(direction, 1));
    if (tag == 3) { this->color->a += amount; return; }
    switch (this->mode) {
        case ColorMode::RGB:
            switch (tag) {
                case 0: this->color->r += amount; break;
                case 1: this->color->g += amount; break;
                case 2: this->color->b += amount; break;
            }
            break;
        case ColorMode::HSB:
            this->color->setHsb(this->color->getHue() + (tag == 0 ? amount : 0),
                                this->color->getSaturation() + (tag == 1 ? amount : 0),
                                this->color->getBrightness() + (tag == 2 ? amount : 0));
            break;
    }
    this->setValue();
}

Components::Views::NumericView::NumericView() {
    this->valueLabel->textColor = ofColor(20);
    this->valueLabel->setFontSize(8);
    this->valueLabel->textAlignment = UIKit::TextAlignment::center;
    this->addSubview(this->valueLabel);
}

void Components::Views::NumericView::setValue(double value) {
    this->valueLabel->frame = UIKit::CGRect(130, 0, 50, this->height);
    this->valueLabel->text = Components::Views::Generator::numericToString(value);
}

Components::Views::Vector3View* Components::Views::Generator::vector3(string name, Vector3 value) {
    Components::Views::Vector3View* view = new Components::Views::Vector3View();
    view->setName(name);
    view->setValue(value);
    return view;
}

Components::Views::ColorView* Components::Views::Generator::color(string name, ofColor* value) {
    Components::Views::ColorView* view = new Components::Views::ColorView(value);
    view->setName(name);
    return view;
}

Components::Views::NumericView* Components::Views::Generator::numeric(string name, double value) {
    Components::Views::NumericView* view = new Components::Views::NumericView();
    view->setName(name);
    view->setValue(value);
    return view;
}

string Components::Views::Generator::numericToString(double value) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << value;
    return ss.str();
}

string Components::Views::Generator::numericToIntString(double value) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(0) << value;
    return ss.str();
}
