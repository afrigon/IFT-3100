#include "DirectionalLightView.h"

Components::Views::DirectionalLight::DirectionalLight(Components::DirectionalLight * directionalLight) : Base(directionalLight->name), directionalLight(directionalLight) {
    if(!directionalLight) return;
    this->colorView = Components::Views::Generator::color("Color: ", &this->directionalLight->color);
    this->directionView = Components::Views::Generator::vector3("Direction: ", this->directionalLight->getDirection());

    this->directionView->valueLabels[0]->tag = 0;
    ofAddListener(this->directionView->valueLabels[0]->onclick, this, &Components::Views::DirectionalLight::click);
    ofAddListener(this->directionView->valueLabels[0]->onrightclick, this, &Components::Views::DirectionalLight::rightclick);
    this->directionView->valueLabels[1]->tag = 1;
    ofAddListener(this->directionView->valueLabels[1]->onclick, this, &Components::Views::DirectionalLight::click);
    ofAddListener(this->directionView->valueLabels[1]->onrightclick, this, &Components::Views::DirectionalLight::rightclick);
    this->directionView->valueLabels[2]->tag = 2;
    ofAddListener(this->directionView->valueLabels[2]->onclick, this, &Components::Views::DirectionalLight::click);
    ofAddListener(this->directionView->valueLabels[2]->onrightclick, this, &Components::Views::DirectionalLight::rightclick);

    this->contentView->addSubview(this->colorView);
    this->contentView->addSubview(this->directionView);
}

Components::Views::DirectionalLight::~DirectionalLight() {
    ofRemoveListener(this->directionView->valueLabels[0]->onclick, this, &Components::Views::DirectionalLight::click);
    ofRemoveListener(this->directionView->valueLabels[0]->onrightclick, this, &Components::Views::DirectionalLight::rightclick);
    ofRemoveListener(this->directionView->valueLabels[1]->onclick, this, &Components::Views::DirectionalLight::click);
    ofRemoveListener(this->directionView->valueLabels[1]->onrightclick, this, &Components::Views::DirectionalLight::rightclick);
    ofRemoveListener(this->directionView->valueLabels[2]->onclick, this, &Components::Views::DirectionalLight::click);
    ofRemoveListener(this->directionView->valueLabels[2]->onrightclick, this, &Components::Views::DirectionalLight::rightclick);
}

void Components::Views::DirectionalLight::layoutSubviews() {
    int x = 0;
    this->colorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->colorView->height);
    x += this->colorView->height;
    this->directionView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->directionView->height);
    x += this->directionView->height;

    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::DirectionalLight::click(UIView & view) {
    switch(view.tag) {
        case 0: this->directionalLight->setDirection(this->directionalLight->getDirection() + Vector3(10, 0, 0)); break;
        case 1: this->directionalLight->setDirection(this->directionalLight->getDirection() + Vector3(0, 10, 0)); break;
        case 2: this->directionalLight->setDirection(this->directionalLight->getDirection() + Vector3(0, 0, 10)); break;
    }
    this->directionView->setValue(this->directionalLight->getDirection());
}

void Components::Views::DirectionalLight::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: this->directionalLight->setDirection(this->directionalLight->getDirection() - Vector3(10, 0, 0)); break;
        case 1: this->directionalLight->setDirection(this->directionalLight->getDirection() - Vector3(0, 10, 0)); break;
        case 2: this->directionalLight->setDirection(this->directionalLight->getDirection() - Vector3(0, 0, 10)); break;
    }
    this->directionView->setValue(this->directionalLight->getDirection());
}
