#pragma once

#include "components/LightSourceComponent.h"

namespace Components
{
    class AmbientLight : public LightSourceComponent {
        public:
        AmbientLight();
        AmbientLight* createInstance() override { return new AmbientLight(); }
        void setupColor() override;
        ofColor getColor();
        void setColor(ofColor color);

        UIKit::UIView* getUIView() override;
        int getUIViewHeight() override;
    };
}
