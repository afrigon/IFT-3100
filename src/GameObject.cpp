//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "GameObject.h"

bool GameObject::operator==(const GameObject &o) const {
    return this->getID() == o.getID();
}

bool GameObject::operator!=(const GameObject &o) const {
    return this->getID() != o.getID();
}

unsigned long GameObject::getID() const {
    return (unsigned long)this;
}

template <class T>
T& GameObject::addComponent(T component) {
    this->components.push_back(component);
    return component;
}

template <class T>
vector<T&> GameObject::getComponents() {
    vector<T&> matchingComponents;
    for (vector<AbstractComponent>::iterator it = this->components.begin(); it != this->components.end(); ++it) {
        if (typeid(T) == typeid(decltype(*it))) {
            matchingComponents.push_back(*it);
        }
    }
    return matchingComponents;
}
