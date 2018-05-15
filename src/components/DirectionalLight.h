#pragma once

#include "components/LightSourceComponent.h"

namespace Components
{
    class DirectionalLight : public LightSourceComponent {
        Vector3 direction = Vector3();

        public:
        DirectionalLight();
        DirectionalLight* createInstance() override { return new DirectionalLight(); }
        void enable(ofShader shader) override;
        void disable(ofShader shader) override;
        ofColor getColor();
        Vector3 getDirection();
        void setColor(ofColor color);
        void setDirection(Vector3 direction);

        UIKit::UIView* getUIView() override;
        int getUIViewHeight() override;
    };
}
