//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "UIKit/UITableView.h"

UIKit::UITableViewCell::UITableViewCell() {
    this->isUserInteractionEnabled = true;
    this->addSubview(this->label);
}

void UIKit::UITableViewCell::select() {
    this->isSelected = true;
}

void UIKit::UITableViewCell::layoutSubviews() {
    this->frame.size.width = this->superview->frame.size.width;
    this->label->frame = CGRect(UIKit::CGPoint(), this->frame.size);
    this->label->textColor = this->isSelected ? this->selectedTextColor : this->textColor;
    UIKit::UIView::layoutSubviews();
}

void UIKit::UITableViewCell::draw(UIKit::CGRect rect) {
    if (this->isHidden) return;
    ofSetColor(this->isSelected ? this->selectedBackgroundColor : this->backgroundColor);
    ofDrawRectangle(this->frame.origin.x + rect.origin.x, this->frame.origin.y + rect.origin.y, this->frame.size.width, this->frame.size.height);
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        (*it)->draw(this->frame + rect.origin);
    }
}

UIKit::UITableView::UITableView() {
    ofAddListener(this->onblur, this, &UITableView::onBlur);
}

UIKit::UITableView::~UITableView() {
    ofRemoveListener(this->onblur, this, &UITableView::onBlur);
}

void UIKit::UITableView::didSelectCell(UIView & view) {
    this->unselectAll();
    if (!this->delegate) return;
    int i = 0;
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it, ++i) {
        if (view == **it) {
            static_cast<UITableViewCell*>(*it)->select();
            this->delegate->didSelectRow(i);
        }
    }
}

void UIKit::UITableView::onBlur(UIView & view) {
    //if (this->delegate) this->delegate->willLoseFocus();
    //this->unselectAll();
    //if (this->delegate) this->delegate->didLoseFocus();
}

void UIKit::UITableView::unselectAll() {
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it) {
        static_cast<UITableViewCell*>(*it)->isSelected = false;
    }
}

void UIKit::UITableView::reloadData() {
    while(!this->subviews.empty()) {
        ofRemoveListener(this->subviews.front()->onmousedown, this, &UIKit::UITableView::didSelectCell);
        delete this->subviews.front();
        this->subviews.pop_front();
    }
    
    if (!this->dataSource) {
        std::cout << "UITableView MUST have a dataSource of type UITableViewDataSource" << std::endl;
        return;
    }
    double x = 0;
    for (int i = 0; i < this->dataSource->numberOfRows(); ++i) {
        UITableViewCell* cell = this->dataSource->cellForRow(i);
        if (!cell) continue;
        ofAddListener(cell->onmousedown, this, &UIKit::UITableView::didSelectCell);
        cell->frame = UIKit::CGRect(UIKit::CGPoint(0, x),
                                    UIKit::CGSize(this->frame.size.width, this->dataSource->heightForRow(i)));
        x += this->dataSource->heightForRow(i) + this->cellSpacing;
        this->addSubview(cell);
    }
}

void UIKit::UITableView::setDataSource(UITableViewDataSource* dataSource) {
    this->dataSource = dataSource;
    this->reloadData();
}

void UIKit::UITableView::setDelegate(UITableViewDelegate* delegate) {
    this->delegate = delegate;
}

void UIKit::UITableView::draw(UIKit::CGRect rect) {
    if (this->isHidden) return;
    ofSetColor(this->backgroundColor);
    ofDrawRectangle(this->frame.origin.x + rect.origin.x,
                    this->frame.origin.y + rect.origin.y,
                    this->frame.size.width,
                    this->frame.size.height);
    int i = 0;
    for (list<UIView*>::iterator it = this->subviews.begin(); it != this->subviews.end(); ++it, ++i) {
        (*it)->draw(this->frame + rect.origin);
    }
}
