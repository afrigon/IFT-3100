//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ViewController.h"

void ViewController::viewDidLoad() {
    this->hierarchy->dataSource = this;
    this->hierarchy->backgroundColor = ofColor(96, 96, 96);
    this->view->addSubview(this->hierarchy);
}

void ViewController::willLayoutSubviews() {
    this->hierarchy->frame = UIKit::CGRect(0, 0, 200, this->view->frame.size.height);
}

int ViewController::numberOfRows() {
    return 10;
}

UIKit::UITableViewCell ViewController::cellForRow(int index) {
    UIKit::UITableViewCell cell;
    cell.backgroundColor = ofColor(255, 0, 0);
    return cell;
}

int ViewController::heightForRow() {
    return 20;
}
