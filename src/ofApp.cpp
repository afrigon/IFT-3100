//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ofApp.h"

void ofApp::setup() {
    ofDisableArbTex();
    ofSetEscapeQuitsApp(false);
    ofSetBackgroundAuto(true);
    ofSetBackgroundColor(75);
    ofSetFrameRate(60);
    ofSetDepthTest(true);
    ofSetWindowTitle("Super Epic Game Engine");

    cam.setVFlip(true);

    outputTime = false;
    outputKey = true;      //MUST BE FALSE ON FINAL BUILD : SOME KEYS ARE CRASHING THE PRINT
    takeScreenshotOnNext = false;
    if (outputTime) lastElapsed = ofGetElapsedTimeMicros();

    light = ofLight();
    light.setPosition(0, 0, 500);

    this->scenes.push_back(DemoScene::generateEmpty());
    
    UIKit::UIWindow::shared()->setRootViewController(new ViewController(&(scenes[0])));
    UIKit::UIWindow::shared()->mainCamera = &cam;
}

void ofApp::update() {
    UIKit::UIWindow::shared()->layoutIfNeeded();
}

void ofApp::draw() {
    cam.begin();

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableDepthTest();
    //light.enable();
    ofEnableSeparateSpecularLight();

    scenes[currentScene].render();

    ofDisableDepthTest();
    light.disable();
    ofDisableLighting();
    ofDisableSeparateSpecularLight();

    cam.end();

    if (outputTime) {
        std::cout << "Elapsed Micros : " << ofGetElapsedTimeMicros() - lastElapsed << std::endl;
        lastElapsed = ofGetElapsedTimeMicros();
    }

    if (!takeScreenshotOnNext) UIKit::UIWindow::shared()->draw();
    else takeScreenshot();
}

void ofApp::keyPressed(int key) {
    if(outputKey) {
        std::cout << "Key pressed" << key << std::endl;
    }
    switch (key) {
        // ctrl + s || print screen (doesn't work on windows)
        case 19:
        case 63248: takeScreenshotOnNext = true; break;
        //Control + n
        case 14:
            scenes.push_back(Scene());
            currentScene = scenes.size() - 1;
            UIKit::UIWindow::shared()->setRootViewController(new ViewController(&(scenes[currentScene])));
            break;
        //Control + w
        case 23:
            {
                vector<Scene>::const_iterator it = scenes.cbegin();
                it += currentScene;
                scenes.erase(it);
                if(scenes.empty()) { scenes.push_back(Scene()); }
                if(--currentScene < 0) { currentScene = 0; }
                UIKit::UIWindow::shared()->setRootViewController(new ViewController(&(scenes[currentScene])));
                break;
            }
        //Tab (and then look for control
        case 9:
            if(ofGetKeyPressed(OF_KEY_CONTROL)) {
                if(ofGetKeyPressed(OF_KEY_LEFT_SHIFT) || ofGetKeyPressed(OF_KEY_RIGHT_SHIFT)) {
                    if(--currentScene < 0) currentScene = scenes.size() - 1;
                } else
                    if(++currentScene == scenes.size()) { currentScene = 0; }
                UIKit::UIWindow::shared()->setRootViewController(new ViewController(&(scenes[currentScene])));
            }
    }
}

void ofApp::keyReleased(int key) {
}

void ofApp::mouseMoved(int x, int y) {
}

void ofApp::mouseDragged(int x, int y, int button) {
}

void ofApp::mouseEntered(int x, int y) {
}

void ofApp::mouseExited(int x, int y) {
}

void ofApp::dragEvent(ofDragInfo dragInfo) {
}

void ofApp::takeScreenshot() {
    takeScreenshotOnNext = false;
    ofImage screenshot = ofImage();
    screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    ofFileDialogResult result = ofSystemSaveDialog(ofGetTimestampString() + ".png", "Select a location to save the image.");
    if (result.bSuccess) screenshot.save(result.filePath);
}
