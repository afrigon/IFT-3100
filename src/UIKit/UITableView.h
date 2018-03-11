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
    friend class UITableView;
    bool isSelected = false;
    
 public:
    UITableViewCell();
    
    ofColor textColor = ofColor(20);
    ofColor backgroundColor = ofColor(175);
    
    ofColor selectedTextColor = ofColor(255);
    ofColor selectedBackgroundColor = ofColor(66, 134, 244);
    
    UILabel* label = new UILabel("TableViewCellLabel");

    virtual void select();
    void layoutSubviews() override;
    void draw(UIKit::CGRect) override;
};

struct UITableViewDataSource {
    virtual int numberOfRows() { return 0; }
    virtual UITableViewCell* cellForRow(int index) { return new UITableViewCell(); }
    virtual int heightForRow(int index) { return 10; }
};
    
struct UITableViewDelegate {
    virtual void didSelectRow(int index) {}
    virtual void willLoseFocus() {}
    virtual void didLoseFocus() {}
};

class UITableView: public UIView {
    UITableViewDataSource* dataSource = nullptr;
    UITableViewDelegate* delegate = nullptr;

    void didSelectCell(UIView &);
    void onBlur(UIView &);

 public:
    double cellSpacing = 0;
    
    UITableView();
    ~UITableView();
    void unselectAll();
    virtual void reloadData();
    void setDataSource(UITableViewDataSource*);
    void setDelegate(UITableViewDelegate*);
    void draw(UIKit::CGRect) override;
};
}  // namespace UIKit

#endif  // UIKIT_UITABLEVIEW_H_
