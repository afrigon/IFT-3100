#pragma once

#include "BaseView.h"
#include "DirectionalLight.h"

namespace Components
{
    namespace Views
    {
        class DirectionalLight : public Components::Views::Base {
            Components::DirectionalLight* directionalLight = nullptr;
            Components::Views::ColorView* colorView;
            Components::Views::Vector3View* directionView;

            public:
            DirectionalLight(Components::DirectionalLight*);
            ~DirectionalLight();
            void layoutSubviews() override;

            void click(UIView &);
            void rightclick(UIView &);
        };
    }
}
