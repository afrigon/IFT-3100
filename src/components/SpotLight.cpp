#include "SpotLight.h"
#include "views/SpotLightView.h"

Components::SpotLight::SpotLight() {
    this->name = "SpotLight";
    light.setSpotlight();
}

ofColor Components::SpotLight::getColor() {
    return color;
}

Vector3 Components::SpotLight::getOrientation() {
    return orientation;
}

float Components::SpotLight::getCutOff() {
    return light.getSpotlightCutOff();
}

float Components::SpotLight::getConcentration() {
    return light.getSpotConcentration();
}

void Components::SpotLight::setColor(ofColor color) {
    this->color = color;
}

void Components::SpotLight::setOrientation(Vector3 orientation) {
    this->orientation = orientation;
    light.setOrientation(ofVec3f(orientation.getX(), orientation.getY(), orientation.getZ()));
}

void Components::SpotLight::setCutOff(float value) {
    light.setSpotlightCutOff(value);
}

void Components::SpotLight::setConcentration(float value) {
    light.setSpotConcentration(value);
}

UIKit::UIView * Components::SpotLight::getUIView() {
    return new Components::Views::SpotLight(this);
}

int Components::SpotLight::getUIViewHeight() {
    return 20 + 30 + 30 + 30 + 30 + 30 + 30 + 30;
}
