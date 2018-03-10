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

    outputTime = false;
    takeScreenshotOnNext = false;
    if (outputTime) lastElapsed = ofGetElapsedTimeMicros();

    light = ofLight();
    light.setPosition(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 100);

    this->scene = DemoScene::generate9();
    this->scene.print();
    
    this->window.setRootViewController(new ViewController(&scene));
}

void ofApp::update() {
    this->window.layoutSubviews();
}

void ofApp::draw() {
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableDepthTest();
    light.enable();
    ofEnableSeparateSpecularLight();

    scene.render();

    ofDisableDepthTest();
    light.disable();
    ofDisableLighting();
    ofDisableSeparateSpecularLight();

    if (outputTime) {
        std::cout << "Elapsed Micros : " << ofGetElapsedTimeMicros() - lastElapsed << std::endl;
        lastElapsed = ofGetElapsedTimeMicros();
    }

    if (!takeScreenshotOnNext) this->window.draw();
    else takeScreenshot();
}

void ofApp::keyPressed(int key) {
    // ctrl + s || print screen
    if (key == 19 || key == 63248) takeScreenshotOnNext = true;
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
