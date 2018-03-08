//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UITableView.h"

void UIKit::UITableViewCell::draw(UIKit::CGRect rect) {
    if (isHidden) return;
    ofSetColor(this->backgroundColor);
    ofDrawRectangle(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->draw(rect);
    }
}

void UIKit::UITableView::draw(UIKit::CGRect rect) {
    if (isHidden) return;
    if (this->dataSource == nullptr) {
        return (std::cout << "UITableView MUST have a dataSource of type UITableViewDataSource" << std::endl);
    }
    
    ofSetColor(this->backgroundColor);
    ofDrawRectangle(this->frame.origin.x + rect.origin.x, this->frame.origin.y + rect.origin.y, this->frame.size.width, this->frame.size.height);
    UIKit::CGRect cellRect = rect + this->frame;
    cellRect.size = CGSize(this->frame.size.width, this->dataSource->heightForRow());
    for (int i = 0; i < this->dataSource->numberOfRows(); ++i) {
        cellRect.origin = UIKit::CGPoint(0, i * this->dataSource->heightForRow());
        this->dataSource->cellForRow(i).draw(cellRect);
    }
}
