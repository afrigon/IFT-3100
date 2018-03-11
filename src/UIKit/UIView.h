//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UIVIEW_H_
#define UIKIT_UIVIEW_H_

#include <list>
#include <cmath>

#include "UIEvent.h"
#include "ofMain.h"

namespace UIKit {
struct CGPoint {
    double x;
    double y;
    CGPoint(): x(0), y(0) {}
    CGPoint(double x, double y): x(x), y(y) {}
    UIKit::CGPoint operator+(const UIKit::CGPoint &);
    UIKit::CGPoint& operator+=(const UIKit::CGPoint &);
};

struct CGSize {
    double width;
    double height;
    CGSize(): width(0), height(0) {}
    CGSize(double width, double height): width(width), height(height) {}
};

struct CGRect {
    CGPoint origin;
    CGSize size;
    CGRect(): origin(CGPoint()), size(CGSize()) {}
    CGRect(CGPoint origin, CGSize size): origin(origin), size(size) {}
    CGRect(double x, double y, double width, double height): origin(CGPoint(x, y)), size(CGSize(width, height)) {}
    CGRect operator+(const CGRect &);
    CGRect& operator+=(const CGRect &);
    CGRect operator+(const CGPoint &);
    CGRect& operator+=(const CGPoint &);
    CGRect operator+(const CGSize &);
    CGRect& operator+=(const CGSize &);
    bool contains(const CGPoint &);
};

class UIView {
    bool focus = false;
    bool isUserInteractionEnabled = false;
    
 protected:
    UIView* superview;
    std::list<UIView*> subviews;

 public:
    int tag = -1;
    CGRect frame;
    bool isHidden = false;
    ofColor backgroundColor = ofColor(0, 0);
    ofColor tintColor;
    int cornerRadius = 0;
    bool shouldBubble = true;
    ofEvent<UIView> onclick;
    ofEvent<UIView> onmousedown;
    ofEvent<UIView> onmouseup;
    ofEvent<UIView> onrightclick;
    ofEvent<UIView> onfocus;
    ofEvent<UIView> onblur;

    UIView() {}
    ~UIView();
    bool operator==(const UIView &) const;
    bool operator!=(const UIView &) const;
    uint64_t getID() const;
    
    virtual void didAddSubview(UIView*) {}
    virtual void willRemoveSubview(UIView*) {}
    
    void addSubview(UIView*);
    void removeFromSuperView();
    virtual void layoutSubviews();
    virtual void draw(CGRect);
    bool hitTest(UIKit::CGPoint, UIKit::CGPoint, UIKit::UIEvent);
    bool isFocused();
    double getHeight();
};
}  // namespace UIKit

#endif  // UIKIT_UIVIEW_H_
