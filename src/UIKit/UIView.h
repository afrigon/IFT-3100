//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UIVIEW_H_
#define UIKIT_UIVIEW_H_

#include <list>
#include "ofMain.h"

namespace UIKit {
struct CGPoint {
    double x;
    double y;
    CGPoint(): x(0), y(0) {}
    CGPoint(double x, double y): x(x), y(y) {}
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
    CGRect operator+(const CGRect & o) {
        return UIKit::CGRect(this->origin.x + o.origin.x, this->origin.y + o.origin.y, this->size.width + o.size.width, this->size.height + o.size.width);
    }
    CGRect& operator+=(const CGRect & o ) {
        this->origin.x += o.origin.x;
        this->origin.y += o.origin.y;
        this->size.width += o.size.width;
        this->size.height += o.size.height;
        return *this;
    }
    CGRect operator+(const CGPoint & o) {
        return UIKit::CGRect(this->origin.x + o.x, this->origin.y + o.y, this->size.width, this->size.height);
    }
    CGRect& operator+=(const CGPoint & o ) {
        this->origin.x += o.x;
        this->origin.y += o.y;
        return *this;
    }
    CGRect operator+(const CGSize & o) {
        return UIKit::CGRect(this->origin.x, this->origin.y, this->size.width + o.width, this->size.height + o.width);
    }
    CGRect& operator+=(const CGSize & o ) {
        this->size.width += o.width;
        this->size.height += o.height;
        return *this;
    }
};

class UIView {
 protected:
    UIView* superview;
    std::list<UIView*> subviews;

 public:
    CGRect frame;
    bool isHidden = false;
    ofColor backgroundColor;
    ofColor tintColor;

    UIView* hitTest();  // TODO(afrigon) or something like that, still
    void addSubview(UIView*);
    void removeFromSuperView();
    virtual void layoutSubviews();
    virtual void draw(CGRect);
};
}  // namespace UIKit

#endif  // UIKIT_UIVIEW_H_
