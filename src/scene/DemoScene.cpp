//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "DemoScene.h"

Scene DemoScene::generate() {
    Scene temp = Scene();

    GameObject* o1 = new GameObject();
    GameObject* o2 = new GameObject();
    GameObject* o3 = new GameObject();
    Transform* t1 = o1->getTransform();
    Transform* t2 = o2->getTransform();
    Transform* t3 = o3->getTransform();
    t1->position = Vector3(0, 0, 0);
    t2->position = Vector3(0, 200, 0);
    t3->position = Vector3(-200, -150, 0);
    t3->rotation = Vector3(60, 60, 45);

    PrimitiveShape* p = o1->addComponent<PrimitiveShape>(new PrimitiveShape());
    p->setPointSize(4);
    p->setPoint(0, Vector3(100, 100, 0));
    p->setPoint(1, Vector3(0, 100, 0));
    p->setPoint(2, Vector3(0, 0, 0));
    p->setPoint(3, Vector3(100, 0, 0));

    p = o2->addComponent<PrimitiveShape>(new PrimitiveShape());
    p->setPointSize(4);
    p->setPoint(0, Vector3(100, 100, 0));
    p->setPoint(1, Vector3(0, 100, 0));
    p->setPoint(2, Vector3(0, 0, 0));
    p->setPoint(3, Vector3(100, 0, 0));
    p->setFillColor(ofColor(60, 120, 0));

    p = o3->addComponent<PrimitiveShape>(new PrimitiveShape());
    p->setPointSize(4);
    p->setPoint(0, Vector3(100, 100, 0));
    p->setPoint(1, Vector3(0, 100, 0));
    p->setPoint(2, Vector3(0, 0, 0));
    p->setPoint(3, Vector3(100, 0, 0));
    p->setDrawColor(ofColor(120, 0, 60));
    
    o1->addChild(o2);
    temp.addObject(o1);

    return temp.addObject(o3);
}

