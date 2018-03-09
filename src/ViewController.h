//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef VIEWCONTROLLER_H_
#define VIEWCONTROLLER_H_

#include "UIKit/UIKit.h"
#include "scene/Scene.h"

class ViewController: public UIKit::UIViewController, public UIKit::UITableViewDataSource {
    Scene* scene;
    UIKit::UITableView* hierarchy = new UIKit::UITableView();

    void viewDidLoad() override;
    void willLayoutSubviews() override;

    int numberOfRows() override;
    UIKit::UITableViewCell cellForRow(int index) override;
    int heightForRow() override;
    
 public:
    ViewController(Scene* scene): scene(scene) {}
};

#endif  // VIEWCONTROLLER_H_
