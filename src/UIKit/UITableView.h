//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UITABLEVIEW_H_
#define UIKIT_UITABLEVIEW_H_

#include <list>

#include "UIView.h"
#include "UILabel.h"

namespace UIKit {
class UITableViewCell: public UIView {
    bool isSelected = false;
    
 public:
    ofColor textColor = ofColor(20);
    ofColor backgroundColor = ofColor(175);
    
    ofColor selectedTextColor = ofColor(255);
    ofColor selectedBackgroundColor = ofColor(66, 134, 244);
    
    UILabel* label = new UILabel("TableViewCellLabel");
    list<UIKit::UIView*> subviews = { label };

    void layoutSubviews() override;
    void draw(UIKit::CGRect) override;
};

struct UITableViewDataSource {
    virtual int numberOfRows() {}
    virtual UITableViewCell cellForRow(int index) {}
    virtual int heightForRow() { return 10; }
};

class UITableView: public UIView {
 public:
    UITableViewDataSource* dataSource;
    // UITableViewDelegate* delegate;

    void draw(UIKit::CGRect) override;
};
}  // namespace UIKit

#endif  // UIKIT_UITABLEVIEW_H_
