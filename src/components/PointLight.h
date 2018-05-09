#pragma once

#include "components/LightSourceComponent.h"

namespace Components
{
    class PointLight : public LightSourceComponent {
        public:
        PointLight();
        PointLight* createInstance() override { return new PointLight(); }
        void enable(ofShader shader) override;
        void disable(ofShader shader) override;
        ofColor getColor();
        void setColor(ofColor color);

        UIKit::UIView* getUIView() override;
        int getUIViewHeight() override;
    };
}
