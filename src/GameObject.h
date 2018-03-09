//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <vector>
#include <list>
#include <string>
using std::vector;
using std::list;
using std::string;

#include "components/AbstractComponent.h"
#include "components/Transform.h"
#include "components/RenderableComponent.h"

class GameObject {
    Components::Transform* transform;
    vector<AbstractComponent*> components;
    list<GameObject*> children;

 public:
    string name = "GameObject";
    
    GameObject();
    ~GameObject();

    bool operator==(const GameObject &) const;
    bool operator!=(const GameObject &) const;

    void update();
    void draw();

    uint64_t getID() const;

    // Returns a reference on the transform pointer
    Components::Transform*& getTransform() { return transform; }
    // Returns a reference on the list
    list<GameObject*>& getChildren();
    // Add a child to the end of the list
    // Returns an iterator on his position
    list<GameObject*>::iterator addChild(GameObject* gameObject);
    // Add a child to the specified position
    // Returns an iterator on his position (in a nutshell, returns itPosition...)
    list<GameObject*>::iterator addChild(GameObject* gameObject, list<GameObject*>::const_iterator itPosition);
    // Remove the child at the specified position
    // Returns an iterator on the next child
    list<GameObject*>::iterator removeChild(list<GameObject*>::const_iterator itPosition);
    // Remove the child using the gameobject directly
    // Returns an iterator on the next child or end() if not found
    list<GameObject*>::iterator removeChild(GameObject* objectToRemove);
    // Move itChild to itPosition in the list
    // Returns the new positon of the child
    list<GameObject*>::iterator moveChild(list<GameObject*>::const_iterator itChild, list<GameObject*>::const_iterator itPosition);
    // Returns the number of object below him and include himself
    unsigned int getGameObjectCount();
    // Returns the gameobject the index value
    GameObject* getGameObjectAt(unsigned int index);

    template <class T>
    T* addComponent(T* component) {
        this->components.push_back(component);
        return component;
    }

    template <class T>
    vector<T*> getComponents() {
        vector<T*> matchingComponents;
        for (vector<AbstractComponent*>::iterator it = this->components.begin(); it != this->components.end(); ++it) {
            if (T* t = dynamic_cast<T*>(*it)) {
                matchingComponents.push_back(t);
            }
        }
        return matchingComponents;
    }
};

#endif  // GAMEOBJECT_H_
