//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "GameObject.h"

GameObject::GameObject() {
    transform = new Components::Transform();
    parent = nullptr;
}

GameObject::~GameObject() {
    delete transform;
    for (auto it = children.begin(); it != children.end(); ++it) {
        (*it)->~GameObject();
        delete *it;
    }

    for (auto it = components.begin(); it != components.end(); ++it) {
        delete *it;
    }
    parent->removeChild(this);
}

bool GameObject::operator==(const GameObject &o) const {
    return this->getID() == o.getID();
}

bool GameObject::operator!=(const GameObject &o) const {
    return this->getID() != o.getID();
}

uint64_t GameObject::getID() const {
    return (uint64_t)this;
}

void GameObject::update() {}

void GameObject::draw() {
    ofPushMatrix();  // Push the matrix and remove after the childs

    // Move the matrix using the transform
    ofTranslate(transform->position.getX(), -transform->position.getY(), -transform->position.getZ());
    ofRotateX(transform->rotation.getX());
    ofRotateY(transform->rotation.getY());
    ofRotateZ(transform->rotation.getZ());
    ofScale(transform->scale.getX(), transform->scale.getY(), transform->scale.getZ());

    //Apply the textures
    std::vector<Components::Texture*> textures = getComponents<Components::Texture>();
    bool useTexture = !textures.empty();
    for(int i = 0; i < textures.size(); ++i) {
        textures[i]->bindTexture(i);
    }

    // Get all the renderable objects and render them
    std::vector<RenderableComponent*> renderers = getComponents<RenderableComponent>();
    for (auto it = renderers.begin(); it != renderers.end(); ++it) {
        (*it)->render(useTexture);
    }

    //Remove the textures
    for(int i = 0; i < textures.size(); ++i) {
        textures[i]->unbindTexture(i);
    }

    // Draw all the childs
    for (auto it = children.begin(); it != children.end(); ++it) {
        (*it)->draw();
    }

    ofPopMatrix();  // Remove matrix before leaving to next object
}

#pragma region ChildsFunction

list<GameObject*>& GameObject::getChildren() {
    return children;
}

GameObject *& GameObject::getParent() {
    return parent;
}

void GameObject::setParent(GameObject * parent) {
    this->parent = parent;
}

list<GameObject*>::iterator GameObject::addChild(GameObject* gameObject) {
    gameObject->setParent(this);
    return children.insert(children.cend(), gameObject);
}

list<GameObject*>::iterator GameObject::addChild(GameObject* gameObject, list<GameObject*>::const_iterator itPosition) {
    gameObject->setParent(this);
    return children.insert(itPosition, gameObject);
}

list<GameObject*>::iterator GameObject::removeChild(list<GameObject*>::const_iterator& itPosition) {
    delete *itPosition;
    return children.erase(itPosition);;
}

list<GameObject*>::iterator GameObject::removeChild(GameObject* objectToRemove) {
    for (auto it = children.cbegin(); it != children.cend(); ++it) {
        if (*it == objectToRemove) {
            return children.erase(it);
        }
    }
    return children.end();
}

list<GameObject*>::iterator GameObject::moveChild(list<GameObject*>::const_iterator& itChild, list<GameObject*>::const_iterator& itPosition) {
    GameObject* movingObject = *itChild;
    children.erase(itChild);
    return children.insert(itPosition, movingObject);
}

unsigned int GameObject::getGameObjectCount() {
    unsigned int compteur = 0;
    for(auto it = children.cbegin(); it != children.cend(); ++it) {
        compteur += (*it)->getGameObjectCount();
    }
    return compteur + 1;
}

GameObject * GameObject::getGameObjectAt(unsigned int index) {
    if(!children.empty()) {
        int i = 0;
        for(auto it = children.cbegin(); it != children.cend(); ++it) {
            if(i == index) {
                return *it;
            } else {
                unsigned int count = (*it)->getGameObjectCount();
                i += count;
                if(i > index) {
                    return (*it)->getGameObjectAt(index + count - i - 1);
                }
            }
        }
    }
    return nullptr;
}

unsigned int GameObject::getDepth() {
    unsigned int i = 0;
    GameObject* p = parent;
    while(p != nullptr) {
        ++i;
        p = p->getParent();
    }
    return i;
}

int GameObject::getComponentsCount() {
    return this->components.size() + 1;
}

vector<AbstractComponent*> GameObject::getComponents() {
    vector<AbstractComponent*> temp = this->components;
    temp.insert(temp.begin(), this->transform);
    return temp;
}

AbstractComponent* GameObject::getComponentAt(int index) {
    if (index == 0) return this->transform;
    return this->components.at(index - 1);
}

#pragma endregion
