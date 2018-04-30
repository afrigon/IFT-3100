//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef OFAPP_H_
#define OFAPP_H_

#include "ofMain.h"
#include "post/PostProcessing.h"
#include "scene/Scene.h"
#include "scene/DemoScene.h"
#include "UIKit/UIKit.h"
#include "ViewController.h"

class ofApp: public ofBaseApp {
    vector<Scene> scenes;
    int currentScene = 0;
    bool outputTime;
    bool outputKey;
    bool takeScreenshotOnNext;
    uint64_t lastElapsed;
    PostProcessing post;
    bool enablePost = true;

 public:
    ofShader shader = ofShader();
    
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
