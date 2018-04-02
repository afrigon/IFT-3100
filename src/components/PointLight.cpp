#include "PointLight.h"
#include "views/PointLightView.h"

Components::PointLight::PointLight() {
    this->name = "PointLight";
    light.setPointLight();
}

ofColor Components::PointLight::getColor() {
    return color;
}

void Components::PointLight::setColor(ofColor color) {
    this->color = color;
}

UIKit::UIView * Components::PointLight::getUIView() {
    return new Components::Views::PointLight(this);
}

int Components::PointLight::getUIViewHeight() {
    return 20 + 30;
}
