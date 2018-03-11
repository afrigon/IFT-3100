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

enum class ColorMode { RGB, HSB };

class ColorView: public LabeledView {
    bool showAlpha = true;
    ofColor* color;
    ColorMode mode = ColorMode::RGB;
    
    void editColor(int, int);
    void switchMode(UIView&);
    void click(UIView&);
    void rightclick(UIView&);
    
 public:
    const double spacing = 40;
    
    UIKit::UILabel* valueLabels [4];
    UIKit::UILabel* modeLabel = new UIKit::UILabel("RGB");
    UIKit::UIView* colorView = new UIKit::UIView();
    
    ColorView(ofColor*);
    ~ColorView();
    void setValue();
    void setShowAlpha(bool);
};

struct NumericView: public LabeledView {
    UIKit::UILabel* valueLabel = new UIKit::UILabel("0");
    
    NumericView();
    void setValue(double);
};

struct Generator {
    static Vector3View* vector3(string, Vector3);
    static ColorView* color(string, ofColor*);
    static NumericView* numeric(string, double);
    static string numericToString(double);
    static string numericToIntString(double);
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_GENERATOR_H_
