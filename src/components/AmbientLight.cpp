#include "AmbientLight.h"
#include "views/AmbientLightView.h"

Components::AmbientLight::AmbientLight() {
    this->name = "AmbientLight";
}

char Components::AmbientLight::count = 0;

void Components::AmbientLight::enable(ofShader shader) {
    if(LightSourceComponent::count < 8) {
        int color = this->color.getHex();
        std::string s = std::to_string(LightSourceComponent::count);
        shader.setUniform1i("lightCount", ++LightSourceComponent::count);
        shader.setUniform1i("ambCount", ++Components::AmbientLight::count);
        shader.setUniform4f("lights[" + s + "].position", this->position.getX(), this->position.getY(), this->position.getZ(), 0.0);
        shader.setUniform4f("lights[" + s + "].color", ofVec4f(((color >> 16) & 0xFF) / 255.0, ((color >> 8) & 0xFF) / 255.0, (color & 0xFF) / 255.0, 1.0));
    }
}

void Components::AmbientLight::disable(ofShader shader) {
    if(LightSourceComponent::count > 0) {
        shader.setUniform1i("lightCount", --LightSourceComponent::count);
        shader.setUniform1i("ambCount", --Components::AmbientLight::count);
    }
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
