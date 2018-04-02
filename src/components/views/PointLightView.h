#pragma once

#include "BaseView.h"
#include "PointLight.h"

namespace Components
{
    namespace Views
    {
        class PointLight : public Components::Views::Base {
            Components::PointLight* pointLight = nullptr;
            Components::Views::ColorView* colorView;

            public:
            PointLight(Components::PointLight*);
            void layoutSubviews() override;
        };
    }
}
