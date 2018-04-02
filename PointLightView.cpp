#include "src\components\views\PointLightView.h"

Components::Views::PointLight::PointLight(Components::PointLight * pointLight) : Base(pointLight->name), pointLight(pointLight) {
    if(!pointLight) return;
    this->colorView = Components::Views::Generator::color("Color: ", &this->pointLight->color);
    this->constantView = Components::Views::Generator::numeric("Constant Attenuation: ", this->pointLight->getAttenuationConstant());
    this->linearView = Components::Views::Generator::numeric("Linear Attenuation: ", this->pointLight->getAttenuationLinear());
    this->quadraticView = Components::Views::Generator::numeric("Quadratic Attenuation: ", this->pointLight->getAttenuationQuadratic());

    this->constantView->valueLabel->tag = 0;
    ofAddListener(this->constantView->valueLabel->onclick, this, &Components::Views::PointLight::click);
    ofAddListener(this->constantView->valueLabel->onrightclick, this, &Components::Views::PointLight::rightclick);
    this->linearView->valueLabel->tag = 1;
    ofAddListener(this->linearView->valueLabel->onclick, this, &Components::Views::PointLight::click);
    ofAddListener(this->linearView->valueLabel->onrightclick, this, &Components::Views::PointLight::rightclick);
    this->quadraticView->valueLabel->tag = 2;
    ofAddListener(this->quadraticView->valueLabel->onclick, this, &Components::Views::PointLight::click);
    ofAddListener(this->quadraticView->valueLabel->onrightclick, this, &Components::Views::PointLight::rightclick);

    this->contentView->addSubview(this->colorView);
    this->contentView->addSubview(this->constantView);
    this->contentView->addSubview(this->linearView);
    this->contentView->addSubview(this->quadraticView);
}

Components::Views::PointLight::~PointLight() {
    ofRemoveListener(this->constantView->valueLabel->onclick, this, &Components::Views::PointLight::click);
    ofRemoveListener(this->constantView->valueLabel->onrightclick, this, &Components::Views::PointLight::rightclick);
    ofRemoveListener(this->linearView->valueLabel->onclick, this, &Components::Views::PointLight::click);
    ofRemoveListener(this->linearView->valueLabel->onrightclick, this, &Components::Views::PointLight::rightclick);
    ofRemoveListener(this->quadraticView->valueLabel->onclick, this, &Components::Views::PointLight::click);
    ofRemoveListener(this->quadraticView->valueLabel->onrightclick, this, &Components::Views::PointLight::rightclick);
}

void Components::Views::PointLight::layoutSubviews() {
    int x = 0;
    this->colorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->colorView->height);
    x += this->colorView->height;
    this->constantView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->constantView->height);
    x += this->constantView->height;
    this->linearView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->linearView->height);
    x += this->linearView->height;
    this->quadraticView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->quadraticView->height);
    x += this->quadraticView->height;

    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::PointLight::setText(int tag) {
    switch(tag) {
        case 0: this->constantView->setValue(this->pointLight->getAttenuationConstant()); break;
        case 1: this->linearView->setValue(this->pointLight->getAttenuationLinear()); break;
        case 2: this->quadraticView->setValue(this->pointLight->getAttenuationQuadratic()); break;
    }
}

void Components::Views::PointLight::click(UIView & view) {
    switch(view.tag) {
        case 0: this->pointLight->setAttenuationConstant(this->pointLight->getAttenuationConstant() + 0.1); break;
        case 1: this->pointLight->setAttenuationLinear(this->pointLight->getAttenuationLinear() + 0.01); break;
        case 2: this->pointLight->setAttenuationQuadratic(this->pointLight->getAttenuationQuadratic() + 0.00001); break;
    }
    this->setText(view.tag);
}

void Components::Views::PointLight::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: this->pointLight->setAttenuationConstant(this->pointLight->getAttenuationConstant() - 0.1); break;
        case 1: this->pointLight->setAttenuationLinear(this->pointLight->getAttenuationLinear() - 0.01); break;
        case 2: this->pointLight->setAttenuationQuadratic(this->pointLight->getAttenuationQuadratic() - 0.00001); break;
    }
    this->setText(view.tag);
}
