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
#include <vector>
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

struct TextView : public LabeledView {
    UIKit::UITextfield* value;

    TextView(std::string text = "");
    void setValue(std::string);
};

struct Vector3View: public LabeledView {
    const double spacing = 50;
    UIKit::UIButton* valueLabels [3];
    
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
    const double spacing = 35;
    
    UIKit::UIButton* valueLabels [4];
    UIKit::UIButton* modeLabel = new UIKit::UIButton("RGB");
    UIKit::UIView* colorView = new UIKit::UIView();
    
    ColorView(ofColor*);
    ~ColorView();
    void setValue();
    void setShowAlpha(bool);
};

struct NumericView: public LabeledView {
    int decimalCount = 2;
    UIKit::UIButton* valueLabel = new UIKit::UIButton("0");
    
    NumericView();
    void setValue(double);
};
    
struct SwitchView: public LabeledView {
    UIKit::UIButton* valueLabel = new UIKit::UIButton("");
    vector<string> choices;
    int selectedIndex = -1;
    
    SwitchView();
    void setValue(int);
};

struct FilePickerDelegate {
    virtual void didPickFile(string path) {}
};

struct FilePickerView: public LabeledView {
    FilePickerDelegate* delegate = nullptr;
    UIKit::UILabel* pathLabel = new UIKit::UILabel("");
    UIKit::UIButton* button = new UIKit::UIButton("open");
    
    FilePickerView();
    ~FilePickerView();
    void setValue(string);
    void buttonclick(UIView &);
};

struct Generator {
    static Vector3View* vector3(string, Vector3);
    static ColorView* color(string, ofColor*);
    static NumericView* numeric(string, double);
    static SwitchView* switchView(string, vector<string>, int);
    static TextView* text(string, string);
    static FilePickerView* file(string, string);
    static string numericToString(double, int = 2);
    static string numericToIntString(double);
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_GENERATOR_H_
