//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ComponentList.h"
#include "ComponentTypes.h"

Components::Views::ComponentList::ComponentList() {
    this->backgroundColor = ofColor(0, 130);
    this->isHidden = true;
    this->isUserInteractionEnabled = true;
    
    this->wrapperView->backgroundColor = ofColor(220);
    this->wrapperView->cornerRadius = 7;
    this->addSubview(this->wrapperView);
    
    this->tableView->setDelegate(this);
    this->tableView->setDataSource(this);
    this->tableView->cellSpacing = 10;
    this->wrapperView->addSubview(this->tableView);
    
    this->titleLabel->textAlignment = UIKit::TextAlignment::center;
    this->titleLabel->padding = 20;
    this->wrapperView->addSubview(this->titleLabel);
    
    this->closeButton->textAlignment = UIKit::TextAlignment::center;
    this->closeButton->textColor = ofColor(244, 67, 54);
    this->closeButton->setFontSize(16);
    this->titleLabel->addSubview(this->closeButton);
    
    ofAddListener(this->closeButton->onclick, this, &Components::Views::ComponentList::hide);
}

Components::Views::ComponentList::~ComponentList() {
    ofRemoveListener(this->closeButton->onclick, this, &Components::Views::ComponentList::hide);
}

void Components::Views::ComponentList::layoutSubviews() {
    double width = this->superview->frame.size.width * 0.5;
    double height = this->superview->frame.size.height * 0.8;
    this->frame = this->superview->frame;
    this->wrapperView->frame = UIKit::CGRect(this->superview->frame.size.width / 2 - width / 2, this->superview->frame.size.height / 2 - height / 2, width, height);
    this->tableView->frame = UIKit::CGRect(0, 40, width, height - 40);
    this->titleLabel->frame = UIKit::CGRect(0, 0, width, 40);
    this->closeButton->frame = UIKit::CGRect(width - 50, 0, 50, 40);
    UIKit::UIView::layoutSubviews();
}

int Components::Views::ComponentList::numberOfRows() {
    return static_cast<int>(Components::ComponentTypes::LAST);
}

UIKit::UITableViewCell* Components::Views::ComponentList::cellForRow(int index) {
    UIKit::UITableViewCell* cell = new UIKit::UITableViewCell();
    cell->label->setFontSize(10);
    cell->label->padding = 20;
    cell->backgroundColor = ofColor(0, 0);
    AbstractComponent* temp = Components::ComponentStore::generate(static_cast<Components::ComponentTypes>(index));
    cell->label->text = temp->name;
    delete temp;
    return cell;
}

int Components::Views::ComponentList::heightForRow(int index) {
    return 30;
}

void Components::Views::ComponentList::didSelectRow(int index) {
    this->target->addComponent(Components::ComponentStore::generate(static_cast<Components::ComponentTypes>(index)));
    ofNotifyEvent(this->target->onaddcomponent, *this->target);
    this->tableView->unselectAll();
    this->isHidden = true;
    this->target = nullptr;
}

void Components::Views::ComponentList::show(GameObject* target) {
    this->target = target;
    this->isHidden = false;
}

void Components::Views::ComponentList::hide(UIView & view) {
    this->isHidden = true;
    this->target = nullptr;
}
