//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_VIEWS_COMPONENTLIST_H_
#define COMPONENTS_VIEWS_COMPONENTLIST_H_

#include "UIKit.h"
#include "GameObject.h"

namespace Components {
namespace Views {
class ComponentList: public UIKit::UIView, public UIKit::UITableViewDataSource, public UIKit::UITableViewDelegate {
    GameObject* target = nullptr;
    UIKit::UIView* wrapperView = new UIKit::UIView();
    UIKit::UITableView* tableView = new UIKit::UITableView();
    UIKit::UILabel* titleLabel = new UIKit::UILabel("New Components");
    UIKit::UIButton* closeButton = new UIKit::UIButton("X");
    
    int numberOfRows() override;
    UIKit::UITableViewCell* cellForRow(int) override;
    int heightForRow(int) override;
    void didSelectRow(int) override;

 public:
    ComponentList();
    ~ComponentList();
    void show(GameObject*);
    void hide(UIView &);
    void layoutSubviews() override;
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_COMPONENTLIST_H_
