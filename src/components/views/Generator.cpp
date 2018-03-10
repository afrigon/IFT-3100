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

Components::Views::ColorView::ColorView() {
    this->addSubview(this->colorView);
}

void Components::Views::ColorView::setValue(ofColor c) {
    this->colorView->frame = UIKit::CGRect(135, 0, this->height, this->height);
    this->colorView->backgroundColor = c;
}

Components::Views::NumericView::NumericView() {
    this->valueLabel->textColor = ofColor(20);
    this->valueLabel->setFontSize(8);
    this->addSubview(this->valueLabel);
}

void Components::Views::NumericView::setValue(double value) {
    this->valueLabel->frame = UIKit::CGRect(125, 0, 75/*this->frame.size.width - 125*/, this->height);
    this->valueLabel->text = Components::Views::Generator::numericToString(value);
}

Components::Views::Vector3View* Components::Views::Generator::vector3(string name, Vector3 value) {
    Components::Views::Vector3View* view = new Components::Views::Vector3View();
    view->setName(name);
    view->setValue(value);
    return view;
}

Components::Views::ColorView* Components::Views::Generator::color(string name, ofColor value) {
    Components::Views::ColorView* view = new Components::Views::ColorView();
    view->setName(name);
    view->setValue(value);
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
