//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef OFAPP_H_
#define OFAPP_H_

#include "ofMain.h"
#include "scene/Scene.h"
#include "scene/DemoScene.h"
#include "UIKit/UIKit.h"
#include "ViewController.h"

class ofApp: public ofBaseApp {
    Scene scene;
    bool outputTime;
    bool takeScreenshotOnNext;
    uint64_t lastElapsed;
    UIKit::UIWindow window;

    ofEasyCam cam;

 public:
    ofLight	light;

    void setup();
    void update();
    void draw();

    // events
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void dragEvent(ofDragInfo dragInfo);

    void takeScreenshot();
};

#endif  // OFAPP_H_
