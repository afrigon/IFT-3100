#pragma once

#include "components/LightSourceComponent.h"

namespace Components
{
    class SpotLight : public LightSourceComponent {
        Vector3 orientation = Vector3();
        float cutOff = 45;
        float concentration = 1;

        public:
        SpotLight();
        SpotLight* createInstance() override { return new SpotLight(); }
        ofColor getColor();
        Vector3 getOrientation();
        float getCutOff();
        float getConcentration();
        void setColor(ofColor color);
        void setOrientation(Vector3 orientation);
        void setCutOff(float value);
        void setConcentration(float value);

        UIKit::UIView* getUIView() override;
        int getUIViewHeight() override;
    };
}
