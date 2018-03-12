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
#include "ComponentList.h"

class ViewController: public UIKit::UIViewController, public UIKit::UITableViewDataSource, public UIKit::UITableViewDelegate {
    Scene* scene;
    GameObject* selectedGameObject = nullptr;
    ComponentsDataSource* componentsDataSource = new ComponentsDataSource();
    
    // UI
    UIKit::UIView* hierarchyHeader = new UIKit::UIView();
    UIKit::UILabel* hierarchyHeaderLabel = new UIKit::UILabel("Hierarchy");
    UIKit::UIButton* hierarchyHeaderButton = new UIKit::UIButton("+");
    UIKit::UITableView* hierarchyPanel = new UIKit::UITableView();
    
    UIKit::UIView* componentHeader = new UIKit::UIView();
    UIKit::UILabel* componentHeaderLabel = new UIKit::UILabel("Components");
    UIKit::UIButton* componentHeaderButton = new UIKit::UIButton("+");
    UIKit::UITableView* componentPanel = new UIKit::UITableView();
    
    Components::Views::ComponentList* componentList = new Components::Views::ComponentList();

    // viewcontroller events
    void viewDidLoad() override;
    void willLayoutSubviews() override;

    // hierarchy data source
    int numberOfRows() override;
    UIKit::UITableViewCell* cellForRow(int) override;
    int heightForRow(int) override;
    
    // hierarchy delegate
    void didSelectRow(int) override;
    void didLoseFocus() override;
    
    void selectGameObject(GameObject* go);
    void didAddComponent(GameObject &);
 public:
    ViewController(Scene* scene): scene(scene) {}
    void addGameObject(UIKit::UIView &);
    void addComponent(UIKit::UIView &);

    void onKeyPressed(ofKeyEventArgs& e);
};

#endif  // VIEWCONTROLLER_H_
