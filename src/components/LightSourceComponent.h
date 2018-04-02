#pragma once

#include "components/AbstractComponent.h"
#include "ofMain.h"
#include "math/Vector3.h"

class LightSourceComponent : public AbstractComponent {
    protected:
    ofLight light;
    Vector3 attenuation;
    virtual void setupColor() {
        light.setDiffuseColor(color);
    }

    public:
    ofColor color;
    void setPosition(Vector3 position) {
        light.setPosition(ofVec3f(position.getX(), position.getY(), position.getZ()));
    }
    void enable() {
        setupColor();
        light.enable();
    }
    void disable() {
        light.disable();
    }

    float getAttenuationConstant() {
        return attenuation.getX();
    }

    float getAttenuationLinear() {
        return attenuation.getY();
    }

    float getAttenuationQuadratic() {
        return attenuation.getZ();
    }

    void setAttenuationConstant(float value) {
        attenuation = Vector3(value, 0, 0);
        light.setAttenuation(attenuation.getX(), attenuation.getY(), attenuation.getZ());
    }

    void setAttenuationLinear(float value) {
        attenuation = Vector3(0, value, 0);
        light.setAttenuation(attenuation.getX(), attenuation.getY(), attenuation.getZ());
    }

    void setAttenuationQuadratic(float value) {
        attenuation = Vector3(0, 0, value);
        light.setAttenuation(attenuation.getX(), attenuation.getY(), attenuation.getZ());
    }
};

