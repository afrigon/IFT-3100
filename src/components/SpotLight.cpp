#include "SpotLight.h"
#include "views/SpotLightView.h"

Components::SpotLight::SpotLight() {
    this->name = "SpotLight";
}

ofColor Components::SpotLight::getColor() {
    return color;
}

Vector3 Components::SpotLight::getOrientation() {
    return orientation;
}

float Components::SpotLight::getCutOff() {
    return cutOff;
}

float Components::SpotLight::getConcentration() {
    return concentration;
}

void Components::SpotLight::setColor(ofColor color) {
    this->color = color;
}

void Components::SpotLight::setOrientation(Vector3 orientation) {
    this->orientation = orientation;
}

void Components::SpotLight::setCutOff(float value) {
    cutOff = value;
}

void Components::SpotLight::setConcentration(float value) {
    concentration = value;
}

UIKit::UIView * Components::SpotLight::getUIView() {
    return new Components::Views::SpotLight(this);
}

int Components::SpotLight::getUIViewHeight() {
    return 20 + 30 + 30 + 30 + 30 + 30 + 30 + 30;
}
