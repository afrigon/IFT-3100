//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef UIKIT_UITABLEVIEW_H_
#define UIKIT_UITABLEVIEW_H_

#include "UIView.h"
#include "UILabel.h"

namespace UIKit {
    struct UITableViewCell: public UIView {
        ofColor backgroundColor = ofColor(255, 255, 255);
        ofColor selectedBackgroundColor = this->backgroundColor;
        UILabel* label = new UILabel("TableViewCellLabel");
        list<UIKit::UIView*> subviews = { label };
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
}

#endif  // UIKIT_UITABLEVIEW_H_
