//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ViewController.h"

void ViewController::viewDidLoad() {
    this->hierarchy->dataSource = this;
    this->hierarchy->backgroundColor = ofColor(180);
    this->view->addSubview(this->hierarchy);
}

void ViewController::willLayoutSubviews() {
    this->hierarchy->frame = UIKit::CGRect(0, 0, 200, this->view->frame.size.height);
}

int ViewController::numberOfRows() {
    return this->scene->getGameObjectCount();
}

UIKit::UITableViewCell ViewController::cellForRow(int index) {
    UIKit::UITableViewCell cell;
    cell.label->setFontSize(8);
    GameObject* go = this->scene->getGameObjectAt(index);
    // cell.label->padding = go->getDepth() * 20;
    cell.label->padding = 30;
    cell.backgroundColor = ofColor(0, 0);
    cell.label->text = go->name;
    return cell;
}

int ViewController::heightForRow() {
    return 20;
}
