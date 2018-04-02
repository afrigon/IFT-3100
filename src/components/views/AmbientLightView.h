#pragma once

#include "BaseView.h"
#include "AmbientLight.h"

namespace Components
{
    namespace Views
    {
        class AmbientLight : public Components::Views::Base {
            Components::AmbientLight* ambientLight = nullptr;
            Components::Views::ColorView* colorView;

            public:
            AmbientLight(Components::AmbientLight*);
            void layoutSubviews() override;
        };
    }
}
