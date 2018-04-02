#include "SpotLightView.h"

Components::Views::SpotLight::SpotLight(Components::SpotLight* spotlight) : Base(spotlight->name), spotLight(spotlight) {
    if(!spotLight) return;
    this->colorView = Components::Views::Generator::color("Color: ", &this->spotLight->color);
    this->orientationView = Components::Views::Generator::vector3("Orientation: ", this->spotLight->getOrientation());
    this->cutoffView = Components::Views::Generator::numeric("Cutoff: ", this->spotLight->getCutOff());
    this->concentrationView = Components::Views::Generator::numeric("Concentration: ", this->spotLight->getConcentration());

    this->orientationView->valueLabels[0]->tag = 0;
    ofAddListener(this->orientationView->valueLabels[0]->onclick, this, &Components::Views::SpotLight::click);
    ofAddListener(this->orientationView->valueLabels[0]->onrightclick, this, &Components::Views::SpotLight::rightclick);
    this->orientationView->valueLabels[1]->tag = 1;
    ofAddListener(this->orientationView->valueLabels[1]->onclick, this, &Components::Views::SpotLight::click);
    ofAddListener(this->orientationView->valueLabels[1]->onrightclick, this, &Components::Views::SpotLight::rightclick);
    this->orientationView->valueLabels[2]->tag = 2;
    ofAddListener(this->orientationView->valueLabels[2]->onclick, this, &Components::Views::SpotLight::click);
    ofAddListener(this->orientationView->valueLabels[2]->onrightclick, this, &Components::Views::SpotLight::rightclick);

    this->cutoffView->valueLabel->tag = 3;
    ofAddListener(this->cutoffView->valueLabel->onclick, this, &Components::Views::SpotLight::click);
    ofAddListener(this->cutoffView->valueLabel->onrightclick, this, &Components::Views::SpotLight::rightclick);

    this->concentrationView->valueLabel->tag = 4;
    ofAddListener(this->concentrationView->valueLabel->onclick, this, &Components::Views::SpotLight::click);
    ofAddListener(this->concentrationView->valueLabel->onrightclick, this, &Components::Views::SpotLight::rightclick);

    this->contentView->addSubview(this->colorView);
    this->contentView->addSubview(this->orientationView);
    this->contentView->addSubview(this->cutoffView);
    this->contentView->addSubview(this->concentrationView);
}

Components::Views::SpotLight::~SpotLight() {
    ofRemoveListener(this->orientationView->valueLabels[0]->onclick, this, &Components::Views::SpotLight::click);
    ofRemoveListener(this->orientationView->valueLabels[0]->onrightclick, this, &Components::Views::SpotLight::rightclick);
    ofRemoveListener(this->orientationView->valueLabels[1]->onclick, this, &Components::Views::SpotLight::click);
    ofRemoveListener(this->orientationView->valueLabels[1]->onrightclick, this, &Components::Views::SpotLight::rightclick);
    ofRemoveListener(this->orientationView->valueLabels[2]->onclick, this, &Components::Views::SpotLight::click);
    ofRemoveListener(this->orientationView->valueLabels[2]->onrightclick, this, &Components::Views::SpotLight::rightclick);
    ofRemoveListener(this->cutoffView->valueLabel->onclick, this, &Components::Views::SpotLight::click);
    ofRemoveListener(this->cutoffView->valueLabel->onrightclick, this, &Components::Views::SpotLight::rightclick);
    ofRemoveListener(this->concentrationView->valueLabel->onclick, this, &Components::Views::SpotLight::click);
    ofRemoveListener(this->concentrationView->valueLabel->onrightclick, this, &Components::Views::SpotLight::rightclick);
}

void Components::Views::SpotLight::layoutSubviews() {
    int x = 0;
    this->colorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->colorView->height);
    x += this->colorView->height;
    this->orientationView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->orientationView->height);
    x += this->orientationView->height;
    this->cutoffView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->cutoffView->height);
    x += this->cutoffView->height;
    this->concentrationView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->concentrationView->height);
    x += this->concentrationView->height;

    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::SpotLight::setText(int tag) {
    switch(tag) {
        case 0: 
        case 1:
        case 2: this->orientationView->setValue(this->spotLight->getOrientation()); break;
        case 3: this->cutoffView->setValue(this->spotLight->getCutOff()); break;
        case 4: this->concentrationView->setValue(this->spotLight->getConcentration()); break;
    }
}

void Components::Views::SpotLight::click(UIView & view) {
    switch(view.tag) {
        case 0: this->spotLight->setOrientation(this->spotLight->getOrientation() + Vector3(10, 0, 0)); break;
        case 1: this->spotLight->setOrientation(this->spotLight->getOrientation() + Vector3(0, 10, 0)); break;
        case 2: this->spotLight->setOrientation(this->spotLight->getOrientation() + Vector3(0, 0, 10)); break;
        case 3: this->spotLight->setCutOff(this->spotLight->getCutOff() + 5); break;
        case 4: this->spotLight->setConcentration(this->spotLight->getConcentration() + 0.5f); break;
    }
    this->setText(view.tag);
}

void Components::Views::SpotLight::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: this->spotLight->setOrientation(this->spotLight->getOrientation() - Vector3(10, 0, 0)); break;
        case 1: this->spotLight->setOrientation(this->spotLight->getOrientation() - Vector3(0, 10, 0)); break;
        case 2: this->spotLight->setOrientation(this->spotLight->getOrientation() - Vector3(0, 0, 10)); break;
        case 3: this->spotLight->setCutOff(this->spotLight->getCutOff() - 5); break;
        case 4: this->spotLight->setConcentration(this->spotLight->getConcentration() - 0.5f); break;
    }
    this->setText(view.tag);
}
