//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ViewController.h"

void ViewController::viewDidLoad() {
    // hierarchy
    this->view->addSubview(this->hierarchyHeader);
    this->hierarchyHeader->addSubview(this->hierarchyHeaderLabel);
    this->hierarchyHeader->addSubview(this->hierarchyHeaderButton);
    this->hierarchyHeader->backgroundColor = ofColor(220);
    this->hierarchyHeaderLabel->padding = 10;
    
    this->hierarchyPanel->setDataSource(this);
    this->hierarchyPanel->setDelegate(this);
    this->hierarchyPanel->backgroundColor = ofColor(180);
    this->view->addSubview(this->hierarchyPanel);
    ofAddListener(this->hierarchyHeaderButton->onclick, this, &ViewController::addGameObject);
    
    // components
    this->view->addSubview(this->componentHeader);
    this->componentHeader->addSubview(this->componentHeaderLabel);
    this->componentHeader->backgroundColor = ofColor(220);
    this->componentHeaderLabel->padding = 10;
    
    this->componentPanel->setDataSource(this->componentsDataSource);
    this->componentPanel->cellSpacing = 10;
    this->componentPanel->backgroundColor = ofColor(180);
    this->view->addSubview(this->componentPanel);
}

void ViewController::willLayoutSubviews() {
    this->hierarchyHeader->frame = UIKit::CGRect(0, 0, 200, 30);
    this->hierarchyHeaderLabel->frame = UIKit::CGRect(0, 0, 150, 30);
    this->hierarchyHeaderButton->frame = UIKit::CGRect(160, 0, 30, 30);
    this->hierarchyPanel->frame = UIKit::CGRect(0, 30, 200, this->view->frame.size.height);
    
    int componentPannelX = (this->selectedGameObject ? this->view->frame.size.width - 300 : this->view->frame.size.width);
    this->componentHeader->frame = UIKit::CGRect(componentPannelX, 0, 300, 30);
    this->componentHeaderLabel->frame = UIKit::CGRect(0, 0, 150, 30);
    this->componentPanel->frame = UIKit::CGRect(componentPannelX, 30, 300, this->view->frame.size.height);
}

int ViewController::numberOfRows() {
    return this->scene->getGameObjectCount();
}

UIKit::UITableViewCell* ViewController::cellForRow(int index) {
    UIKit::UITableViewCell* cell = new UIKit::UITableViewCell();
    cell->label->setFontSize(8);
    GameObject* go = this->scene->getGameObjectAt(index);
    cell->label->padding = (go->getDepth() + 1) * 15;
    cell->backgroundColor = ofColor(0, 0);
    cell->label->text = go->name;
    return cell;
}

void ViewController::didSelectRow(int index) {
    this->selectGameObject(this->scene->getGameObjectAt(index));
}

void ViewController::didLoseFocus() {
    this->selectGameObject(nullptr);
}

void ViewController::selectGameObject(GameObject* go) {
    this->selectedGameObject = go;
    this->componentsDataSource->go = this->selectedGameObject;
    this->componentPanel->reloadData();
}

void ViewController::addGameObject(UIKit::UIView & test) {
    // cout << "test" << endl;
    this->scene->addObject(new GameObject());
    this->hierarchyPanel->reloadData();
}

int ViewController::heightForRow(int index) {
    return 20;
}
