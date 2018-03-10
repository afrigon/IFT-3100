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
            Components::Views::ColorView* strokeColorView;
            Components::Views::NumericView* borderWidthView;
            Components::Views::NumericView* widthView;
            Components::Views::NumericView* heightView;
            
        public:
            Ellipse(Components::Ellipse*);
            void layoutSubviews() override;
        };
    }  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_ELLIPSEVIEW_H_



