//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <vector>
using std::vector;

#include "components/AbstractComponent.h"

class GameObject {
    vector<AbstractComponent> components;
    
public:
    bool operator==(const GameObject &) const;
    bool operator!=(const GameObject &) const;
    unsigned long getID() const;
    
    template <class T>
    T& addComponent(T& component) {
        this->components.push_back(component);
        return component;
    }
    
    template <class T>
    vector<T&> getComponents() {
        vector<T&> matchingComponents;
        for (vector<AbstractComponent>::iterator it = this->components.begin(); it != this->components.end(); ++it) {
            if (typeid(T) == typeid(decltype(*it))) {
                matchingComponents.push_back(*it);
            }
        }
        return matchingComponents;
    }
};

#endif  // GAMEOBJECT_H_
