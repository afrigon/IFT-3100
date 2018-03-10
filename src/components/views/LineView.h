//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_LINEVIEW_H_
#define COMPONENTS_VIEWS_LINEVIEW_H_

#include "BaseView.h"
#include "Line.h"

namespace Components {
namespace Views {
class Line: public Components::Views::Base {
    Components::Line* line = nullptr;
    Components::Views::ColorView* colorView;
    Components::Views::NumericView* widthView;
    Components::Views::NumericView* lengthView;
    
public:
    Line(Components::Line*);
    void layoutSubviews() override;
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_LINEVIEW_H_


