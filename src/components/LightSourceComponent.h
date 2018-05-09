#pragma once

#include "components/AbstractComponent.h"
#include "ofMain.h"
#include "math/Vector3.h"

class LightSourceComponent : public AbstractComponent {
    protected:
    Vector3 position;
    Vector3 attenuation;
    static char count;

    public:
    ofColor color;
    void setPosition(Vector3 value) {
        position = value;
    }
    virtual void enable(ofShader) {}
    virtual void disable(ofShader) {}

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
    }

    void setAttenuationLinear(float value) {
        attenuation = Vector3(0, value, 0);
    }

    void setAttenuationQuadratic(float value) {
        attenuation = Vector3(0, 0, value);
    }
};

