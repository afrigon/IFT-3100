#include "PointLight.h"
#include "views/PointLightView.h"

Components::PointLight::PointLight() {
    this->name = "PointLight";
    this->setAttenuationConstant(1.0f);
}

void Components::PointLight::enable(ofShader shader) {
    if(LightSourceComponent::count < 16) {
        int color = this->color.getHex();
        std::string s = std::to_string(LightSourceComponent::count);
        shader.setUniform1i("lightCount", ++LightSourceComponent::count);
        shader.setUniform4f("lights[" + s + "].position", this->position.getX(), this->position.getY(), this->position.getZ(), 2.0);
        shader.setUniform4f("lights[" + s + "].color", ofVec4f(((color >> 16) & 0xFF) / 255.0, ((color >> 8) & 0xFF) / 255.0, (color & 0xFF) / 255.0, 1.0));
        shader.setUniform1f("lights[" + s + "].constant", this->getAttenuationConstant());
        shader.setUniform1f("lights[" + s + "].linear", this->getAttenuationLinear());
        shader.setUniform1f("lights[" + s + "].quadratic", this->getAttenuationQuadratic());
    }
}

void Components::PointLight::disable(ofShader shader) {
    if(LightSourceComponent::count > 0) {
        shader.setUniform1i("lightCount", --LightSourceComponent::count);
    }
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
    return 20 + 30 + 30 + 30 + 30;
}
