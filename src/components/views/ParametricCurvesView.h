#pragma once

#include "BaseView.h"
#include "ParametricCurves.h"

namespace Components
{
    namespace Views
    {
        class ParametricCurves : public Components::Views::Base {
            Components::ParametricCurves* parametricCurves = nullptr;
            Components::Views::SwitchView* switchView;
            Components::Views::ColorView* colorView;
            Components::Views::NumericView* widthView;
            Components::Views::NumericView* pointCount;
            vector<Components::Views::Vector3View*> points;

            void setText(int);
            void addPoint();
            void removePoint();

            public:
            ParametricCurves(Components::ParametricCurves*);
            ~ParametricCurves();
            void layoutSubviews() override;
            void click(UIView &);
            void rightclick(UIView &);
        };
    }
}
