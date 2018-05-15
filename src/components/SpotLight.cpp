#include "SpotLight.h"
#include "views/SpotLightView.h"

Components::SpotLight::SpotLight() {
    this->name = "SpotLight";
}

void Components::SpotLight::enable(ofShader shader) {
    if(LightSourceComponent::count < 16) {
        int color = this->color.getHex();
        std::string s = std::to_string(LightSourceComponent::count);
        shader.setUniform1i("lightCount", ++LightSourceComponent::count);
        shader.setUniform4f("lights[" + s + "].position", this->position.getX(), this->position.getY(), this->position.getZ(), 3.0);
        shader.setUniform3f("lights[" + s + "].direction", this->orientation.getX(), this->orientation.getY(), this->orientation.getZ());
        shader.setUniform1f("lights[" + s + "].cutOff", cos(ofDegToRad(this->getCutOff())));
        shader.setUniform1f("lights[" + s + "].outerCutOff", cos(ofDegToRad(this->getOuterCutOff())));
        shader.setUniform4f("lights[" + s + "].color", ofVec4f(((color >> 16) & 0xFF) / 255.0, ((color >> 8) & 0xFF) / 255.0, (color & 0xFF) / 255.0, 1.0));
        shader.setUniform1f("lights[" + s + "].constant", this->getAttenuationConstant());
        shader.setUniform1f("lights[" + s + "].linear", this->getAttenuationLinear());
        shader.setUniform1f("lights[" + s + "].quadratic", this->getAttenuationQuadratic());
    }
}

void Components::SpotLight::disable(ofShader shader) {
    if(LightSourceComponent::count > 0) {
        shader.setUniform1i("lightCount", --LightSourceComponent::count);
    }
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

float Components::SpotLight::getOuterCutOff() {
    return outerCutOff;
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

void Components::SpotLight::setOuterCutOff(float value) {
    outerCutOff = value;
}

UIKit::UIView * Components::SpotLight::getUIView() {
    return new Components::Views::SpotLight(this);
}

int Components::SpotLight::getUIViewHeight() {
    return 20 + 30 + 30 + 30 + 30 + 30 + 30 + 30;
}
