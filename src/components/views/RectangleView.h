//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_RECTANGLEVIEW_H_
#define COMPONENTS_VIEWS_RECTANGLEVIEW_H_

#include "BaseView.h"
#include "Rectangle.h"

namespace Components {
namespace Views {
class Rectangle: public Components::Views::Base {
    Components::Rectangle* rectangle = nullptr;
    Components::Views::ColorView* fillColorView;
    Components::Views::ColorView* strokeColorView;
    Components::Views::NumericView* borderWidthView;
    Components::Views::NumericView* widthView;
    Components::Views::NumericView* heightView;

public:
    Rectangle(Components::Rectangle*);
    ~Rectangle();
    void layoutSubviews() override;
    void setText(int tag);

    void click(UIView & view);
    void rightclick(UIView & view);
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_RECTANGLEVIEW_H_


