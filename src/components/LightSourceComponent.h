#pragma once

#include "components/AbstractComponent.h"
#include "ofMain.h"
#include "math/Vector3.h"

class LightSourceComponent : public AbstractComponent {
    protected:
    ofLight light;
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
};

