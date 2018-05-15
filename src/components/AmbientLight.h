#pragma once

#include "components/LightSourceComponent.h"

namespace Components
{
    class AmbientLight : public LightSourceComponent {
        static char count;

        public:
        AmbientLight();
        AmbientLight* createInstance() override { return new AmbientLight(); }
        void enable(ofShader shader) override;
        void disable(ofShader shader) override;
        ofColor getColor();
        void setColor(ofColor color);

        UIKit::UIView* getUIView() override;
        int getUIViewHeight() override;
    };
}
