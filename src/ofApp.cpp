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
    ofSetWindowTitle("Super Epic Not Game Engine");
    
    post.createPass<BloomPass>();
    post.createPass<BrightPass>();
    post.createPass<InversionPass>();
    post.createPass<StaticWavePass>();
    
    outputTime = false;
    outputKey = true;      //MUST BE FALSE ON FINAL BUILD : SOME KEYS ARE CRASHING THE PRINT
    takeScreenshotOnNext = false;
    if (outputTime) lastElapsed = ofGetElapsedTimeMicros();

    this->scenes.push_back(DemoScene::generateEmpty());
    
    UIKit::UIWindow::shared()->setRootViewController(new ViewController(&(scenes[0])));
    UIKit::UIWindow::shared()->mainCamera = &(scenes[0].getCamera());
    
    this->shader.load("shader");
}

void ofApp::update() {
    UIKit::UIWindow::shared()->layoutIfNeeded();
}

void ofApp::draw() {
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableDepthTest();
    ofEnableSeparateSpecularLight();

    if (this->enablePost) post.begin();
    scenes[currentScene].render(this->shader);
    
    ofDisableDepthTest();
    ofDisableLighting();
    ofDisableSeparateSpecularLight();
    
    if (this->enablePost) post.end();

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
    //Checking the ctrl key because ctrl + key sends a int ranging from 8-ish to 30-ish
    // (include the tab (9) and the backspace(8))
    switch(key) {
            //ctrl + s || print screen (doesn't work on windows)
        case 19: if(!ofGetKeyPressed(OF_KEY_CONTROL)) { return; }
        case 63248: takeScreenshotOnNext = true; break;

            //Control + e
        case 5:
            if(ofGetKeyPressed(OF_KEY_CONTROL)) {
                ofEasyCam* cam = &(scenes[currentScene].getCamera());
                if(cam->getOrtho()) { cam->disableOrtho(); } else { cam->enableOrtho(); }
            }
            break;

            //Control + g
        case 7:
            if(ofGetKeyPressed(OF_KEY_CONTROL)) {
                scenes[currentScene].setGridEnabled(!scenes[currentScene].getGridEnabled());
            }
            break;

            //Control + n
        case 14:
            if(ofGetKeyPressed(OF_KEY_CONTROL)) {
                scenes[currentScene].disableCam();
                scenes.push_back(Scene());
                currentScene = scenes.size() - 1;
                UIKit::UIWindow::shared()->setRootViewController(new ViewController(&(scenes[currentScene])));
                scenes[currentScene].enableCam();
                UIKit::UIWindow::shared()->mainCamera = &(scenes[currentScene].getCamera());
            }
            break;

            //Control + w
        case 23:
            if(ofGetKeyPressed(OF_KEY_CONTROL)) {
                vector<Scene>::const_iterator it = scenes.cbegin();
                it += currentScene;
                scenes[currentScene].disableCam();
                scenes.erase(it);
                if(scenes.empty()) { scenes.push_back(Scene()); }
                if(--currentScene < 0) { currentScene = 0; }
                UIKit::UIWindow::shared()->setRootViewController(new ViewController(&(scenes[currentScene])));
                scenes[currentScene].enableCam();
                UIKit::UIWindow::shared()->mainCamera = &(scenes[currentScene].getCamera());
            }
            break;
            //[]
        case 91:
            scenes[currentScene].disableCam();
            if(--currentScene < 0) currentScene = scenes.size() - 1;
            UIKit::UIWindow::shared()->setRootViewController(new ViewController(&(scenes[currentScene])));
            scenes[currentScene].enableCam();
            UIKit::UIWindow::shared()->mainCamera = &(scenes[currentScene].getCamera());
            break;
        case 93:
            scenes[currentScene].disableCam();
            if(++currentScene == scenes.size()) { currentScene = 0; }
            UIKit::UIWindow::shared()->setRootViewController(new ViewController(&(scenes[currentScene])));
            scenes[currentScene].enableCam();
            UIKit::UIWindow::shared()->mainCamera = &(scenes[currentScene].getCamera());
            break;
        //Control + p
        case 16:
            this->enablePost = !this->enablePost;
            break;
        case 49:
            this->post.activeEffect ^= 1; break;
        case 50:
            this->post.activeEffect ^= 2; break;
        case 51:
            this->post.activeEffect ^= 4; break;
        case 52:
            this->post.activeEffect ^= 8; break;
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
