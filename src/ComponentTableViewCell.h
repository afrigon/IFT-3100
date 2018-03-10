//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTTABLEVIEWCELL_H_
#define COMPONENTTABLEVIEWCELL_H_

#include "UIKit.h"

class ComponentTableViewCell: public UIKit::UITableViewCell {
    UIView* view = nullptr;
    
 public:
    ofColor selectedBackgroundColor = this->backgroundColor;
    
    ComponentTableViewCell() {}
    ComponentTableViewCell(UIView*);
    
    void layoutSubviews() override;
};

#endif  // COMPONENTTABLEVIEWCELL_H_
