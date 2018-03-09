//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef VIEWCONTROLLER_H_
#define VIEWCONTROLLER_H_

#include "UIKit/UIKit.h"

class ViewController: public UIKit::UIViewController, public UIKit::UITableViewDataSource {
    UIKit::UITableView* hierarchy = new UIKit::UITableView();

    void viewDidLoad() override;
    void willLayoutSubviews() override;

    int numberOfRows() override;
    UIKit::UITableViewCell cellForRow(int index) override;
    int heightForRow() override;
};

#endif  // VIEWCONTROLLER_H_
