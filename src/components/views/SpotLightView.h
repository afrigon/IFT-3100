#pragma once

#include "BaseView.h"
#include "SpotLight.h"

namespace Components
{
    namespace Views
    {
        class SpotLight : public Components::Views::Base {
            Components::SpotLight* spotLight = nullptr;
            Components::Views::ColorView* colorView;
            Components::Views::Vector3View* orientationView;
            Components::Views::NumericView* cutoffView;
            Components::Views::NumericView* outerCutOff;
            Components::Views::NumericView* constantView;
            Components::Views::NumericView* linearView;
            Components::Views::NumericView* quadraticView;

            public:
            SpotLight(Components::SpotLight*);
            ~SpotLight();
            void layoutSubviews() override;
            void setText(int tag);

            void click(UIView &);
            void rightclick(UIView &);
        };
    }
}
