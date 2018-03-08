//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ofApp.h"

void ofApp::setup() {
    outputTime = false;
    if(outputTime)
        lastElapsed = ofGetElapsedTimeMicros();

    ofSetBackgroundColor(0);
    light = ofLight();
    light.setPosition(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 100);

    this->scene = DemoScene::generate7();
    this->scene.print();
}

void ofApp::update() {
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

    if(outputTime)
    {
        std::cout << "Elapsed Micros : " << ofGetElapsedTimeMicros() - lastElapsed << std::endl;
        lastElapsed = ofGetElapsedTimeMicros();
    }
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

void ofApp::windowResized(int w, int h) {
}

void ofApp::gotMessage(ofMessage msg) {
    cout << msg.message << endl;
}

void ofApp::dragEvent(ofDragInfo dragInfo) {
}
