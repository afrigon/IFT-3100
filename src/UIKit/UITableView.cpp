//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIKit/UITableView.h"

void UIKit::UITableViewCell::layoutSubviews() {
    this->label->frame = this->frame;
    this->label->textColor = this->isSelected ? this->selectedTextColor : this->textColor;
    UIKit::UIView::layoutSubviews();
}

void UIKit::UITableViewCell::draw(UIKit::CGRect rect) {
    if (this->isHidden) return;
    ofSetColor(this->isSelected ? this->selectedBackgroundColor : this->backgroundColor);
    ofDrawRectangle(rect.origin.x, rect.origin.y, this->frame.size.width, this->frame.size.height);
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->draw(this->frame + rect.origin);
    }
}

void UIKit::UITableView::draw(UIKit::CGRect rect) {
    if (this->isHidden) return;
    if (this->dataSource == nullptr) {
        std::cout << "UITableView MUST have a dataSource of type UITableViewDataSource" << std::endl;
        return;
    }

    ofDrawRectangle(this->frame.origin.x + rect.origin.x,
                    this->frame.origin.y + rect.origin.y,
                    this->frame.size.width,
                    this->frame.size.height);
    UIKit::CGRect cellRect = this->frame;
    cellRect += rect.origin;
    for (int i = 0; i < this->dataSource->numberOfRows(); ++i) {
        cellRect.origin.y = i * this->dataSource->heightForRow();
        UITableViewCell cell = this->dataSource->cellForRow(i);
        cell.frame.size = UIKit::CGSize(this->frame.size.width, this->dataSource->heightForRow());
        cell.layoutSubviews();
        cell.draw(cellRect);
    }
}
