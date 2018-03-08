//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "GameObject.h"

GameObject::GameObject()
{
    transform = new Component::Transform();
}

GameObject::~GameObject()
{
    delete transform;
    for(auto it = childs.begin(); it != childs.end(); ++it)
    {
        (*it)->~GameObject();
        delete *it;
    }
    for(auto it = components.begin(); it != components.end(); ++it)
    {
        delete *it;
    }
}

bool GameObject::operator==(const GameObject &o) const {
    return this->getID() == o.getID();
}

bool GameObject::operator!=(const GameObject &o) const {
    return this->getID() != o.getID();
}

void GameObject::update()
{

}

void GameObject::draw()
{
    ofPushMatrix(); //Push the matrix and remove after the childs
    
    //Move the matrix using the transform
    ofTranslate(transform->position.getX(), transform->position.getY(), transform->position.getZ());
    ofRotateX(transform->rotation.getX());
    ofRotateY(transform->rotation.getY());
    ofRotateZ(transform->rotation.getZ());
    ofScale(transform->scale.getX(), transform->scale.getY(), transform->scale.getZ());

    //Get all the renderable objects and render them
    vector<Renderable*> renderers = getComponents<Renderable>();
    for(auto it = renderers.begin(); it != renderers.end(); ++it)
    {
        (*it)->render();
    }
    //Draw all the childs
    for(auto it = childs.begin(); it != childs.end(); ++it)
    {
        (*it)->draw();
    }

    ofPopMatrix(); //Remove matrix before leaving to next object
}

unsigned long GameObject::getID() const {
    return (unsigned long)this;
}

#pragma region ChildsFunction

list<GameObject*>& GameObject::getChilds()
{
    return childs;
}

list<GameObject*>::iterator GameObject::addChild(GameObject* gameObject)
{
    return childs.insert(childs.cend(), gameObject);
}

list<GameObject*>::iterator GameObject::addChild(GameObject* gameObject, list<GameObject*>::const_iterator itPosition)
{
    return childs.insert(itPosition, gameObject);
}

list<GameObject*>::iterator GameObject::removeChild(list<GameObject*>::const_iterator itPosition)
{
    delete *itPosition;
    return childs.erase(itPosition);;
}

list<GameObject*>::iterator GameObject::removeChild(GameObject* objectToRemove)
{
    for(auto it = childs.cbegin(); it != childs.cend(); ++it)
    {
        if(*it == objectToRemove)
        {
            delete *it;
            return childs.erase(it);
        }
    }
    return childs.end();
}

list<GameObject*>::iterator GameObject::moveChild(list<GameObject*>::const_iterator itChild, list<GameObject*>::const_iterator itPosition)
{
    GameObject* movingObject = *itChild;
    childs.erase(itChild);
    return childs.insert(itPosition, movingObject);
}

#pragma endregion
