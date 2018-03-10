//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef VIEWCONTROLLER_H_
#define VIEWCONTROLLER_H_

#include <list>

#include "UIKit/UIKit.h"
#include "scene/Scene.h"
#include "GameObject.h"
#include "ComponentsDataSource.h"

class ViewController: public UIKit::UIViewController, public UIKit::UITableViewDataSource, public UIKit::UITableViewDelegate {
    Scene* scene;
    GameObject* selectedGameObject = nullptr;
    ComponentsDataSource* componentsDataSource = new ComponentsDataSource();
    
    // UI
    UIKit::UIView* hierarchyHeader = new UIKit::UIView();
    UIKit::UILabel* hierarchyHeaderLabel = new UIKit::UILabel("Hierarchy");
    UIKit::UILabel* hierarchyHeaderButton = new UIKit::UILabel("+");
    UIKit::UITableView* hierarchyPanel = new UIKit::UITableView();
    
    UIKit::UIView* componentHeader = new UIKit::UIView();
    UIKit::UILabel* componentHeaderLabel = new UIKit::UILabel("Components");
    UIKit::UITableView* componentPanel = new UIKit::UITableView();

    // viewcontroller events
    void viewDidLoad() override;
    void willLayoutSubviews() override;

    // hierarchy data source
    int numberOfRows() override;
    UIKit::UITableViewCell* cellForRow(int index) override;
    int heightForRow(int index) override;
    
    // hierarchy delegate
    void didSelectRow(int index) override;
    void didLoseFocus() override;
    
    void selectGameObject(GameObject* go);
 public:
    ViewController(Scene* scene): scene(scene) {}
    void addGameObject(UIKit::UIView & test);
};

#endif  // VIEWCONTROLLER_H_
