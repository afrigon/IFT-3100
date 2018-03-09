//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ofApp.h"

void ofApp::setup() {
    ofSetBackgroundAuto(true);
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
    ofSetDepthTest(true);
    ofSetWindowTitle("Super Epic Game Engine");

    outputTime = false;
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

    this->window.draw();
}

void ofApp::keyPressed(int key) {
}

void ofApp::keyReleased(int key) {
}

void ofApp::mouseMoved(int x, int y) {
}

void ofApp::mouseDragged(int x, int y, int button) {
}

void ofApp::mousePressed(int x, int y, int button) {
}

void ofApp::mouseReleased(int x, int y, int button) {
}

void ofApp::mouseEntered(int x, int y) {
}

void ofApp::mouseExited(int x, int y) {
}

void ofApp::gotMessage(ofMessage msg) {
    cout << msg.message << endl;
}

void ofApp::dragEvent(ofDragInfo dragInfo) {
}
