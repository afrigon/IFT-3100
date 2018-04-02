#pragma once

#include "components/LightSourceComponent.h"

namespace Components
{
    class PointLight : public LightSourceComponent {
        public:
        PointLight();
        PointLight* createInstance() override { return new PointLight(); }
        ofColor getColor();
        void setColor(ofColor color);

        UIKit::UIView* getUIView() override;
        int getUIViewHeight() override;
    };
}
