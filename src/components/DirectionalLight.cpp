#include "DirectionalLight.h"
#include "views/DirectionalLightView.h"

Components::DirectionalLight::DirectionalLight() {
    this->name = "DirectionalLight";
    light.setDirectional();
}

ofColor Components::DirectionalLight::getColor() {
    return color;
}

Vector3 Components::DirectionalLight::getDirection() {
    return direction;
}

void Components::DirectionalLight::setColor(ofColor color) {
    this->color = color;
}

void Components::DirectionalLight::setDirection(Vector3 direction) {
    this->direction = direction;
    light.setOrientation(ofVec3f(direction.getX(), direction.getY(), direction.getZ()));
}

UIKit::UIView * Components::DirectionalLight::getUIView() {
    return new Components::Views::DirectionalLight(this);
}

int Components::DirectionalLight::getUIViewHeight() {
    return 20 + 30 + 30;
}
