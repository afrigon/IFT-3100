//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ViewController.h"

void ViewController::viewDidLoad() {
    // hierarchy
    this->hierarchyHeader->isUserInteractionEnabled = true;
    this->hierarchyHeader->backgroundColor = ofColor(220);
    this->view->addSubview(this->hierarchyHeader);
    
    this->hierarchyHeaderLabel->padding = 10;
    this->hierarchyHeader->addSubview(this->hierarchyHeaderLabel);
    
    this->hierarchyHeaderButton->textColor = ofColor(20);
    this->hierarchyHeader->addSubview(this->hierarchyHeaderButton);
    ofAddListener(this->hierarchyHeaderButton->onclick, this, &ViewController::addGameObject);
    
    this->hierarchyPanel->setDataSource(this);
    this->hierarchyPanel->setDelegate(this);
    this->hierarchyPanel->isUserInteractionEnabled = true;
    this->hierarchyPanel->backgroundColor = ofColor(180);
    this->view->addSubview(this->hierarchyPanel);
    
    // components
    this->componentHeader->backgroundColor = ofColor(220);
    this->componentHeader->isUserInteractionEnabled = true;
    this->view->addSubview(this->componentHeader);
    
    this->componentHeaderLabel->padding = 10;
    this->componentHeader->addSubview(this->componentHeaderLabel);
    
    this->componentHeaderButton->textColor = ofColor(20);
    this->componentHeader->addSubview(this->componentHeaderButton);
    ofAddListener(this->componentHeaderButton->onclick, this, &ViewController::addComponent);
    
    this->componentPanel->setDataSource(this->componentsDataSource);
    this->componentPanel->cellSpacing = 10;
    this->componentPanel->isUserInteractionEnabled = true;
    this->componentPanel->backgroundColor = ofColor(180);
    this->view->addSubview(this->componentPanel);
    
    // component list
    this->view->addSubview(this->componentList);
}

void ViewController::willLayoutSubviews() {
    this->hierarchyHeader->frame = UIKit::CGRect(0, 0, 200, 30);
    this->hierarchyHeaderLabel->frame = UIKit::CGRect(0, 0, 150, 30);
    this->hierarchyHeaderButton->frame = UIKit::CGRect(200-30, 2, 30, 30);
    this->hierarchyPanel->frame = UIKit::CGRect(0, 30, 200, this->view->frame.size.height);
    
    int componentPannelX = (this->selectedGameObject ? this->view->frame.size.width - 300 : this->view->frame.size.width);
    this->componentHeader->frame = UIKit::CGRect(componentPannelX, 0, 300, 30);
    this->componentHeaderLabel->frame = UIKit::CGRect(0, 0, 150, 30);
    this->componentHeaderButton->frame = UIKit::CGRect(300-30, 2, 30, 30);
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
    if (this->selectedGameObject) {
        ofRemoveListener(this->selectedGameObject->onaddcomponent, this, &ViewController::didAddComponent);
    }
    
    if (go) {
        ofAddListener(go->onaddcomponent, this, &ViewController::didAddComponent);
    }
    
    this->selectedGameObject = go;
    this->componentsDataSource->go = this->selectedGameObject;
    this->componentPanel->reloadData();
}

void ViewController::didAddComponent(GameObject & go) {
    this->componentPanel->reloadData();
}

void ViewController::addGameObject(UIKit::UIView & view) {
    this->scene->addObject(new GameObject());
    this->hierarchyPanel->reloadData();
}

void ViewController::addComponent(UIKit::UIView & view) {
    if (!this->selectedGameObject) return; // show error
    this->componentList->show(this->selectedGameObject);
}

void ViewController::onKeyPressed(ofKeyEventArgs & e) {
    switch(e.key) {
        case 356: //LEFT 
            if(selectedGameObject)
                if(selectedGameObject->getParent()) {
                    selectedGameObject->getParent()->removeChild(selectedGameObject);
                    if(selectedGameObject->getParent()->getParent()) {
                        selectedGameObject->getParent()->getParent()->addChild(selectedGameObject);
                    } else {
                        scene->addObject(selectedGameObject);
                    }
                    this->hierarchyPanel->reloadData();
                }
            break;
        case 357: //UP 
                  //Terrorist style because no more time 
            if(selectedGameObject) {
                if(selectedGameObject->getParent()) {
                    list<GameObject*>::const_iterator hisIt = selectedGameObject->getParent()->getChildren().cend();
                    for(auto it = selectedGameObject->getParent()->getChildren().cbegin(); it != selectedGameObject->getParent()->getChildren().cend(); ++it) {
                        if((*it)->getID() == selectedGameObject->getID()) {
                            if(hisIt != selectedGameObject->getParent()->getChildren().cend()) {
                                list<GameObject*>::const_iterator myIt = hisIt; ++myIt;
                                selectedGameObject->getParent()->moveChild(myIt, hisIt);
                            }
                            this->hierarchyPanel->reloadData();
                            break;
                        }
                        hisIt = it;
                    }
                } else {
                    list<GameObject*>::const_iterator hisIt = scene->getGameObjects().cend();
                    for(auto it = scene->getGameObjects().cbegin(); it != scene->getGameObjects().cend(); ++it) {
                        if((*it)->getID() == selectedGameObject->getID()) {
                            if(hisIt != scene->getGameObjects().cend()) {
                                list<GameObject*>::const_iterator myIt = hisIt; ++myIt;
                                scene->getGameObjects().erase(myIt);
                                scene->getGameObjects().insert(hisIt, selectedGameObject);
                            }
                            this->hierarchyPanel->reloadData();
                            break;
                        }
                        hisIt = it;
                    }
                }
            }
            break;
        case 358: //RIGHT 
            if(selectedGameObject) {
                GameObject* newParent = nullptr;
                if(selectedGameObject->getParent()) {
                    for(auto it = selectedGameObject->getParent()->getChildren().begin(); it != selectedGameObject->getParent()->getChildren().end(); ++it) {
                        if((*it)->getID() == selectedGameObject->getID()) break;
                        newParent = (*it);
                    }
                } else {
                    list<GameObject*> tmp = scene->getGameObjects();
                    for(list<GameObject*>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
                        if((*it)->getID() == selectedGameObject->getID()) break;
                        newParent = (*it);
                    }
                }
                if(newParent) {
                    if(selectedGameObject->getParent()) {
                        selectedGameObject->getParent()->removeChild(selectedGameObject);
                    } else {
                        scene->remove(selectedGameObject);
                    }
                    newParent->addChild(selectedGameObject, newParent->getChildren().cbegin());
                    this->hierarchyPanel->reloadData();
                }
            }
            break;
        case 359: //DOWN 
                  //Terrorist style because no more time 
            if(selectedGameObject) {
                if(selectedGameObject->getParent()) {
                    list<GameObject*>::const_iterator hisIt = selectedGameObject->getParent()->getChildren().cend();
                    for(auto it = selectedGameObject->getParent()->getChildren().cend(); it != selectedGameObject->getParent()->getChildren().cbegin();) {
                        --it;
                        if((*it)->getID() == selectedGameObject->getID()) {
                            if(hisIt != selectedGameObject->getParent()->getChildren().cend()) {
                                list<GameObject*>::const_iterator myIt = hisIt++; --myIt;
                                selectedGameObject->getParent()->moveChild(myIt, hisIt);
                            }
                            this->hierarchyPanel->reloadData();
                            break;
                        }
                        hisIt = it;
                    }
                } else {
                    list<GameObject*>::const_iterator hisIt = scene->getGameObjects().cend();
                    for(auto it = scene->getGameObjects().cend(); it != scene->getGameObjects().cbegin();) {
                        --it;
                        if((*it)->getID() == selectedGameObject->getID()) {
                            if(hisIt != scene->getGameObjects().cend()) {
                                list<GameObject*>::const_iterator myIt = hisIt++; --myIt;
                                scene->getGameObjects().erase(myIt);
                                scene->getGameObjects().insert(hisIt, selectedGameObject);
                            }
                            this->hierarchyPanel->reloadData();
                            break;
                        }
                        hisIt = it;
                    }
                }
            }
            break;
        default: break;
    }
}

int ViewController::heightForRow(int index) {
    return 20;
}
