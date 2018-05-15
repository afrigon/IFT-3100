#pragma once

#include "components/LightSourceComponent.h"

namespace Components
{
    class SpotLight : public LightSourceComponent {
        Vector3 orientation = Vector3();
        float cutOff = 45;
        float outerCutOff = 50;

        public:
        SpotLight();
        SpotLight* createInstance() override { return new SpotLight(); }
        void enable(ofShader shader) override;
        void disable(ofShader shader) override;
        ofColor getColor();
        Vector3 getOrientation();
        float getCutOff();
        float getOuterCutOff();
        void setColor(ofColor color);
        void setOrientation(Vector3 orientation);
        void setCutOff(float value);
        void setOuterCutOff(float value);

        UIKit::UIView* getUIView() override;
        int getUIViewHeight() override;
    };
}
