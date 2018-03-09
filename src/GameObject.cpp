//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "GameObject.h"

GameObject::GameObject() {
    transform = new Components::Transform();
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
}

bool GameObject::operator==(const GameObject &o) const {
    return this->getID() == o.getID();
}

bool GameObject::operator!=(const GameObject &o) const {
    return this->getID() != o.getID();
}

void GameObject::update() {}

void GameObject::draw() {
    ofPushMatrix();  // Push the matrix and remove after the childs

    // Move the matrix using the transform
    ofTranslate(transform->position.getX(), transform->position.getY(), transform->position.getZ());
    ofRotateX(transform->rotation.getX());
    ofRotateY(transform->rotation.getY());
    ofRotateZ(transform->rotation.getZ());
    ofScale(transform->scale.getX(), transform->scale.getY(), transform->scale.getZ());

    // Get all the renderable objects and render them
    std::vector<RenderableComponent*> renderers = getComponents<RenderableComponent>();
    for (auto it = renderers.begin(); it != renderers.end(); ++it) {
        (*it)->render();
    }
    // Draw all the childs
    for (auto it = children.begin(); it != children.end(); ++it) {
        (*it)->draw();
    }

    ofPopMatrix();  // Remove matrix before leaving to next object
}

uint64_t GameObject::getID() const {
    return (uint64_t)this;
}

#pragma region ChildsFunction

list<GameObject*>& GameObject::getChildren() {
    return children;
}

list<GameObject*>::iterator GameObject::addChild(GameObject* gameObject) {
    return children.insert(children.cend(), gameObject);
}

list<GameObject*>::iterator GameObject::addChild(GameObject* gameObject, list<GameObject*>::const_iterator itPosition) {
    return children.insert(itPosition, gameObject);
}

list<GameObject*>::iterator GameObject::removeChild(list<GameObject*>::const_iterator itPosition) {
    delete *itPosition;
    return children.erase(itPosition);;
}

list<GameObject*>::iterator GameObject::removeChild(GameObject* objectToRemove) {
    for (auto it = children.cbegin(); it != children.cend(); ++it) {
        if (*it == objectToRemove) {
            delete *it;
            return children.erase(it);
        }
    }
    return children.end();
}

list<GameObject*>::iterator GameObject::moveChild(list<GameObject*>::const_iterator itChild, list<GameObject*>::const_iterator itPosition) {
    GameObject* movingObject = *itChild;
    children.erase(itChild);
    return children.insert(itPosition, movingObject);
}

#pragma endregion
