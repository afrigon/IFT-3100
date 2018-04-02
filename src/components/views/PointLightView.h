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
            Components::Views::NumericView* constantView;
            Components::Views::NumericView* linearView;
            Components::Views::NumericView* quadraticView;

            public:
            PointLight(Components::PointLight*);
            ~PointLight();
            void layoutSubviews() override;
            void setText(int tag);

            void click(UIView &);
            void rightclick(UIView &);
        };
    }
}
