//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "DemoScene.h"

using namespace Component;

Scene DemoScene::generate1() {
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

    PrimitiveShape* p1 = o1->addComponent<PrimitiveShape>(new PrimitiveShape());
    p1->setPointSize(4);
    p1->setPoint(0, Vector3(100, 100, 0));
    p1->setPoint(1, Vector3(0, 100, 0));
    p1->setPoint(2, Vector3(0, 0, 0));
    p1->setPoint(3, Vector3(100, 0, 0));

    PrimitiveShape* p2 = o2->addComponent<PrimitiveShape>(new PrimitiveShape());
    p2->setPointSize(4);
    p2->setPoint(0, Vector3(100, 100, 0));
    p2->setPoint(1, Vector3(0, 100, 0));
    p2->setPoint(2, Vector3(0, 0, 0));
    p2->setPoint(3, Vector3(100, 0, 0));
    p2->setFillColor(ofColor(60, 120, 0));

    PrimitiveShape* p3 = o3->addComponent<PrimitiveShape>(new PrimitiveShape());
    p3->setPointSize(4);
    p3->setPoint(0, Vector3(100, 100, 0));
    p3->setPoint(1, Vector3(0, 100, 0));
    p3->setPoint(2, Vector3(0, 0, 0));
    p3->setPoint(3, Vector3(100, 0, 0));
    p3->setDrawColor(ofColor(120, 0, 60));
    
    o1->addChild(o2);
    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate2()
{
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

    Ligne* l1 = o1->addComponent<Ligne>(new Ligne());
    l1->setLineWidth(5);

    Ligne* l2 = o2->addComponent<Ligne>(new Ligne());
    l2->setLineColor(ofColor(200, 0, 0));

    Ligne* l3 = o3->addComponent<Ligne>(new Ligne());
    l3->setLineLength(300);

    o1->addChild(o2);
    
    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate3()
{
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

    Component::Rectangle* r1 = o1->addComponent<Component::Rectangle>(new Component::Rectangle());
    r1->setHeight(150);
    r1->setBorderWidth(5);
    r1->setDrawColor(ofColor(200, 0, 0));

    Component::Rectangle* r2 = o2->addComponent<Component::Rectangle>(new Component::Rectangle());
    r2->setWidth(150);
    r2->setDrawColor(ofColor(200, 0, 0));

    o3->addComponent<Component::Rectangle>(new Component::Rectangle());

    o1->addChild(o2);

    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate4()
{
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

    Component::Ellipse* e1 = o1->addComponent<Component::Ellipse>(new Component::Ellipse());
    e1->setHeight(150);
    e1->setBorderWidth(5);
    e1->setDrawColor(ofColor(200, 0, 0));

    Component::Ellipse* e2 = o2->addComponent<Component::Ellipse>(new Component::Ellipse());
    e2->setWidth(150);
    e2->setDrawColor(ofColor(200, 0, 0));

    Component::Ellipse* e3 = o3->addComponent<Component::Ellipse>(new Component::Ellipse());
    e3->setHeight(300);
    e3->setWidth(300);

    o1->addChild(o2);

    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate5()
{
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

    Component::Cube* c1 = o1->addComponent<Component::Cube>(new Component::Cube());
    c1->setColor(ofColor(200, 0, 0));

    Component::Cube* c2 = o2->addComponent<Component::Cube>(new Component::Cube());

    Component::Cube* c3 = o3->addComponent<Component::Cube>(new Component::Cube());
    c3->setSize(Vector3(200, 300, 100));

    o1->addChild(o2);

    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate6()
{
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

    Component::Sphere* s1 = o1->addComponent<Component::Sphere>(new Component::Sphere());
    s1->setColor(ofColor(200, 0, 0));

    Component::Sphere* s2 = o2->addComponent<Component::Sphere>(new Component::Sphere());

    Component::Sphere* s3 = o3->addComponent<Component::Sphere>(new Component::Sphere());
    s3->setRadius(150);

    o1->addChild(o2);

    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate7()
{
    Scene temp = Scene();

    GameObject* o1 = new GameObject();
    Transform* t1 = o1->getTransform();
    t1->position = Vector3(0, 200, 0);

    Component::Model* p1 = o1->addComponent<Component::Model>(new Component::Model());
    p1->loadModel("C:/Users/Alexandre/Documents/openframeworks/examples/addons/assimpExample/bin/data/astroBoy_walk.dae");

    return temp.addObject(o1);
}

Scene DemoScene::generate8()
{
    Scene temp = Scene();

    GameObject* o1 = new GameObject();
    GameObject* o2 = new GameObject();
    GameObject* o3 = new GameObject();
    GameObject* o4 = new GameObject();
    GameObject* o5 = new GameObject();
    GameObject* o6 = new GameObject();
    GameObject* o7 = new GameObject();
    Transform* t1 = o1->getTransform();
    Transform* t2 = o2->getTransform();
    Transform* t3 = o3->getTransform();
    Transform* t4 = o4->getTransform();
    Transform* t5 = o5->getTransform();
    Transform* t6 = o6->getTransform();
    Transform* t7 = o7->getTransform();
    t1->position = Vector3(-100, -200, 0);
    t2->position = Vector3(-100, 0, 0);
    t3->position = Vector3(-100, 200, 0);
    t4->position = Vector3(100, -200, 0);
    t5->position = Vector3(100, 0, 0);
    t6->position = Vector3(100, 200, 0);
    t6->rotation = Vector3(0, 0, 45);
    t7->position = Vector3(300, 200, 0);
    t7->scale = Vector3(1, 1, 0.5);

    Component::Rectangle* c1 = o1->addComponent<Component::Rectangle>(new Component::Rectangle());
    c1->setFillColor(ofColor(200, 0, 0));

    Component::PrimitiveShape* c2 = o2->addComponent<Component::PrimitiveShape>(new Component::PrimitiveShape());
    c2->setPointSize(4);
    c2->setPoint(0, Vector3(-50, -25, 0));
    c2->setPoint(1, Vector3(50, -25, 0));
    c2->setPoint(2, Vector3(25, 25, 0));
    c2->setPoint(3, Vector3(-25, 25, 0));

    Component::Ligne* c3 = o3->addComponent<Component::Ligne>(new Component::Ligne());

    Component::Ellipse* c4 = o4->addComponent<Component::Ellipse>(new Component::Ellipse());
    c4->setWidth(50);

    Component::Sphere* c5 = o5->addComponent<Component::Sphere>(new Component::Sphere());

    Component::Cube* c6 = o6->addComponent<Component::Cube>(new Component::Cube());

    Component::Model* c7 = o7->addComponent<Component::Model>(new Component::Model());
    c7->loadModel("C:/Users/Alexandre/Documents/openframeworks/examples/addons/assimpExample/bin/data/astroBoy_walk.dae");

    temp.addObject(o1);
    temp.addObject(o2);
    temp.addObject(o3);
    temp.addObject(o4);
    temp.addObject(o5);
    temp.addObject(o6);
    return temp.addObject(o7);
}

