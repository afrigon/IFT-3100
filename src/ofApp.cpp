//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ofApp.h"

void ofApp::setup() {
    // this->scene = DemoScene::generate();
    // this->scene.print();
    ofSetBackgroundAuto(true);
    ofSetBackgroundColor(0, 0, 0);
    ofSetFrameRate(60);
    ofSetDepthTest(true);
    ofSetWindowTitle("Super Epic Game Engine");
    this->window.setRootViewController(new ViewController());
}

void ofApp::update() {
    this->window.layoutSubviews();
}

void ofApp::draw() {
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
