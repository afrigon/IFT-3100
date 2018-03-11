//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_ELLIPSEVIEW_H_
#define COMPONENTS_VIEWS_ELLIPSEVIEW_H_

#include "BaseView.h"
#include "Ellipse.h"

namespace Components {
    namespace Views {
        class Ellipse: public Components::Views::Base {
            Components::Ellipse* ellipse = nullptr;
            Components::Views::ColorView* fillColorView;
            Components::Views::NumericView* widthView;
            Components::Views::NumericView* heightView;
            
        public:
            Ellipse(Components::Ellipse*);
            ~Ellipse();
            void layoutSubviews() override;
            void setText(int tag);

            void click(UIView & view);
            void rightclick(UIView & view);
        };
    }  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_ELLIPSEVIEW_H_



