//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ofApp.h"

void ofApp::setup() {
    ofDisableArbTex();
    ofSetBackgroundAuto(true);
    ofSetBackgroundColor(75);
    ofSetFrameRate(60);
    ofSetDepthTest(true);
    ofSetWindowTitle("Super Epic Game Engine");

    cam.setVFlip(true);

    outputTime = false;
    takeScreenshotOnNext = false;
    if (outputTime) lastElapsed = ofGetElapsedTimeMicros();

    light = ofLight();
    light.setPosition(0, 0, 500);

    this->scene = DemoScene::generate9();
    
    UIKit::UIWindow::shared()->setRootViewController(new ViewController(&scene));
    UIKit::UIWindow::shared()->mainCamera = &cam;
}

void ofApp::update() {
    UIKit::UIWindow::shared()->layoutIfNeeded();
}

void ofApp::draw() {
    cam.begin();

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableDepthTest();
    light.enable();
    ofEnableSeparateSpecularLight();

    scene.render();

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
    switch (key) {
        // ctrl + s || print screen
        case 19:
        case 63248: takeScreenshotOnNext = true; break;
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
