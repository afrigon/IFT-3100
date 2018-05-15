#include "DirectionalLight.h"
#include "views/DirectionalLightView.h"

Components::DirectionalLight::DirectionalLight() {
    this->name = "DirectionalLight";
}

void Components::DirectionalLight::enable(ofShader shader) {
    if(LightSourceComponent::count < 8) {
        int color = this->color.getHex();
        std::string s = std::to_string(LightSourceComponent::count);
        shader.setUniform1i("lightCount", ++LightSourceComponent::count);
        shader.setUniform4f("lights[" + s + "].position", 0.0f, 0.0f, 0.0f, 1.0f);
        shader.setUniform3f("lights[" + s + "].direction", this->direction.getX(), this->direction.getY(), this->direction.getZ());
        shader.setUniform4f("lights[" + s + "].color", ofVec4f(((color >> 16) & 0xFF) / 255.0, ((color >> 8) & 0xFF) / 255.0, (color & 0xFF) / 255.0, 1.0));
    }
}

void Components::DirectionalLight::disable(ofShader shader) {
    if(LightSourceComponent::count > 0) {
        shader.setUniform1i("lightCount", --LightSourceComponent::count);
    }
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
}

UIKit::UIView * Components::DirectionalLight::getUIView() {
    return new Components::Views::DirectionalLight(this);
}

int Components::DirectionalLight::getUIViewHeight() {
    return 20 + 30 + 30;
}
