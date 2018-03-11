//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "scene/DemoScene.h"
using namespace Components;

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

Scene DemoScene::generate2() {
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

    Line* l1 = o1->addComponent<Line>(new Line());
    l1->setStrokeWidth(5);

    Line* l2 = o2->addComponent<Line>(new Line());
    l2->strokeColor = ofColor(200, 0, 0);

    Line* l3 = o3->addComponent<Line>(new Line());
    l3->setLineLength(300);

    o1->addChild(o2);

    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate3() {
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

    Components::Rectangle* r1 = o1->addComponent<Components::Rectangle>(new Components::Rectangle());
    r1->setHeight(150);
    r1->setBorderWidth(5);
    r1->strokeColor = ofColor(200, 0, 0);

    Components::Rectangle* r2 = o2->addComponent<Components::Rectangle>(new Components::Rectangle());
    r2->setWidth(150);
    r2->strokeColor = ofColor(200, 0, 0);

    o3->addComponent<Components::Rectangle>(new Components::Rectangle());

    o1->addChild(o2);

    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate4() {
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

    Components::Ellipse* e1 = o1->addComponent<Components::Ellipse>(new Components::Ellipse());
    e1->setHeight(150);

    Components::Ellipse* e2 = o2->addComponent<Components::Ellipse>(new Components::Ellipse());
    e2->setWidth(150);

    Components::Ellipse* e3 = o3->addComponent<Components::Ellipse>(new Components::Ellipse());
    e3->setHeight(300);
    e3->setWidth(300);

    o1->addChild(o2);

    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate5() {
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

    Cube* c1 = o1->addComponent<Cube>(new Cube());
    c1->color = ofColor(200, 0, 0);

    Cube* c2 = o2->addComponent<Cube>(new Cube());

    Cube* c3 = o3->addComponent<Cube>(new Cube());
    c3->size = Vector3(200, 300, 100);

    o1->addChild(o2);

    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate6() {
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

    Sphere* s1 = o1->addComponent<Sphere>(new Sphere());
    s1->color = ofColor(200, 0, 0);

    Sphere* s2 = o2->addComponent<Sphere>(new Sphere());

    Sphere* s3 = o3->addComponent<Sphere>(new Sphere());
    s3->radius = 150;

    o1->addChild(o2);

    temp.addObject(o1);

    return temp.addObject(o3);
}

Scene DemoScene::generate7() {
    Scene temp = Scene();

    GameObject* o1 = new GameObject();
    Transform* t1 = o1->getTransform();
    t1->position = Vector3(0, 200, 0);

    Model* p1 = o1->addComponent<Model>(new Model());
    p1->loadModel("~/Documents/University/IFT-3100/labo/labo/labo5/bin/data/charlie.obj");

    return temp.addObject(o1);
}

Scene DemoScene::generate8() {
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

    Components::Rectangle* c1 = o1->addComponent<Components::Rectangle>(new Components::Rectangle());
    c1->fillColor = ofColor(200, 0, 0);

    PrimitiveShape* c2 = o2->addComponent<PrimitiveShape>(new PrimitiveShape());
    c2->setPointSize(4);
    c2->setPoint(0, Vector3(-50, -25, 0));
    c2->setPoint(1, Vector3(50, -25, 0));
    c2->setPoint(2, Vector3(25, 25, 0));
    c2->setPoint(3, Vector3(-25, 25, 0));

    Line* c3 = o3->addComponent<Line>(new Line());

    Components::Ellipse* c4 = o4->addComponent<Components::Ellipse>(new Components::Ellipse());
    c4->setWidth(50);

    Sphere* c5 = o5->addComponent<Sphere>(new Sphere());

    Cube* c6 = o6->addComponent<Cube>(new Cube());

    Model* c7 = o7->addComponent<Model>(new Model());
    c7->loadModel("/Users/frigon/Documents/University/IFT-3100/labo/labo/labo5/bin/data/charlie.obj");

    temp.addObject(o1);
    temp.addObject(o2);
    temp.addObject(o3);
    temp.addObject(o4);
    temp.addObject(o5);
    temp.addObject(o6);
    return temp.addObject(o7);
}

Scene DemoScene::generate9() {
    Scene temp = Scene();

    GameObject* o1 = new GameObject();
    GameObject* o2 = new GameObject();
    GameObject* o3 = new GameObject();
    GameObject* o4 = new GameObject();
    GameObject* o5 = new GameObject();
    GameObject* o6 = new GameObject();
    GameObject* o7 = new GameObject();
    GameObject* o01 = new GameObject();
    Transform* t1 = o1->getTransform();
    Transform* t2 = o2->getTransform();
    Transform* t3 = o3->getTransform();
    Transform* t4 = o4->getTransform();
    Transform* t5 = o5->getTransform();
    Transform* t6 = o6->getTransform();
    Transform* t7 = o7->getTransform();
    t1->position = Vector3(-100, -200, 0);
    t2->position = Vector3(0, 200, 0);
    t3->position = Vector3(0, 400, 0);
    t4->position = Vector3(200, -200, 0);
    t5->position = Vector3(0, 200, 0);
    t6->position = Vector3(0, 400, 0);
    t6->rotation = Vector3(0, 200, 45);
    t7->position = Vector3(200, 200, 0);
    t7->scale = Vector3(1, 1, 0.5);

    Components::Cubemap* c01 = o01->addComponent<Components::Cubemap>(new Components::Cubemap());
    o01->name = "Skybox";
    c01->loadMap("cm.png");
    c01->distance = 2000;

    Components::Rectangle* c1 = o1->addComponent<Components::Rectangle>(new Components::Rectangle());
    o1->name = "Rectangle";
    c1->fillColor = ofColor(200, 0, 0);

    PrimitiveShape* c2 = o2->addComponent<PrimitiveShape>(new PrimitiveShape());
    o2->name = "Primitive";
    c2->setPointSize(4);
    c2->setPoint(0, Vector3(-50, -25, 0));
    c2->setPoint(1, Vector3(50, -25, 0));
    c2->setPoint(2, Vector3(25, 25, 0));
    c2->setPoint(3, Vector3(-25, 25, 0));

    Line* c3 = o3->addComponent<Line>(new Line());
    o3->name = "Line";

    Components::Ellipse* c4 = o4->addComponent<Components::Ellipse>(new Components::Ellipse());
    o4->name = "Ellipse";
    c4->setWidth(50);

    Sphere* c5 = o5->addComponent<Sphere>(new Sphere());
    o5->name = "Sphere";

    Cube* c6 = o6->addComponent<Cube>(new Cube());
    o6->name = "Cube";

    Model* c7 = o7->addComponent<Model>(new Model());
    o7->name = "Charlie";
    c7->loadModel("charlie.obj");

    //Components::Texture* t06 = o6->addComponent<Components::Texture>(new Components::Texture());
    //t06->loadTexture("card.jpg");

    temp.addObject(o01);
    temp.addObject(o1);
    o1->addChild(o2);
    o1->addChild(o3);
    o2->addChild(o4);
    o4->addChild(o5);
    o4->addChild(o6);
    o4->addChild(o7);
    return temp;
}

