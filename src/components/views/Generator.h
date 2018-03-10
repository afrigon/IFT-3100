//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_VIEWS_GENERATOR_H_
#define COMPONENTS_VIEWS_GENERATOR_H_

#include <cmath>
#include <string>
using std::string;

#include "UIKit.h"
#include "Vector3.h"

namespace Components {
namespace Views {
    struct LabeledView: public UIKit::UIView {
        const double height = 30;
        UIKit::UILabel* label = new UIKit::UILabel();
        LabeledView();
        void setName(string name);
    };
    
    struct Vector3View: public LabeledView {
        const double spacing = 50;
        UIKit::UILabel* valueLabels [3];
        Vector3View();
        void setValue(Vector3);
    };
    
    struct ColorView: public LabeledView {
        UIKit::UIView* colorView = new UIKit::UIView();
        ColorView();
        void setValue(ofColor);
    };
    
    struct NumericView: public LabeledView {
        UIKit::UILabel* valueLabel = new UIKit::UILabel("0");
        NumericView();
        void setValue(double);
    };
    
    struct Generator {
        static Vector3View* vector3(string, Vector3);
        static ColorView* color(string, ofColor);
        static NumericView* numeric(string, double);
        static string numericToString(double);
    };
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_GENERATOR_H_
