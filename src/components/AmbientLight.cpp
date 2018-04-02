#include "AmbientLight.h"
#include "views/AmbientLightView.h"

Components::AmbientLight::AmbientLight() {
    this->name = "AmbientLight";
    light.setAmbientColor(ofFloatColor::white);
    light.setDiffuseColor(ofFloatColor::black);
}

void Components::AmbientLight::setupColor() {
    light.setAmbientColor(color);
}

ofColor Components::AmbientLight::getColor() {
    return color;
}

void Components::AmbientLight::setColor(ofColor color) {
    this->color = color;
}

UIKit::UIView * Components::AmbientLight::getUIView() {
    return new Components::Views::AmbientLight(this);
}

int Components::AmbientLight::getUIViewHeight() {
    return 20 + 30;
}
