//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "PostProcessing.h"

PostProcessing::PostProcessing() {
    ofAddListener(ofEvents().windowResized, this, &PostProcessing::resize);
    this->setup();
}

PostProcessing::~PostProcessing() {
    ofRemoveListener(ofEvents().windowResized, this, &PostProcessing::resize);
}

void PostProcessing::resize(ofResizeEventArgs& args) {
    this->setup();
}

void PostProcessing::setup() {
    ofFbo::Settings s;
    
    s.width = ofNextPow2(ofGetWidth());
    s.height = ofNextPow2(ofGetHeight());
    s.textureTarget = GL_TEXTURE_2D;    
    this->pingPong[0].allocate(s);
    this->pingPong[1].allocate(s);
    
    s.useDepth = true;
    s.depthStencilInternalFormat = GL_DEPTH_COMPONENT24;
    s.depthStencilAsTexture = true;
    this->raw.allocate(s);
}

void PostProcessing::begin() {
    raw.begin(false);
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    glViewport(0, 0, this->raw.getWidth(), this->raw.getHeight());
    
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    
    ofPushStyle();
    glPushAttrib(GL_ENABLE_BIT);
}

void PostProcessing::end() {
    glPopAttrib();
    ofPopStyle();
    
    glViewport(0, 0, ofGetWidth(), ofGetHeight());
    
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    this->raw.end();
    
    ofPushStyle();
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING);
    ofSetColor(255, 255, 255);
    this->process();
    glPopAttrib();
    ofPopStyle();
}

void PostProcessing::process() {
    int processedCount = 0;
    int currentReadFbo = 0;
    for (int i = 0; i < passes.size(); ++i) {
        if ((this->activeEffect & static_cast<int>(pow(2, i))) != 0) {
            if (i == 0) passes[i]->render(raw, pingPong[1 - currentReadFbo]);
            else passes[i]->render(pingPong[currentReadFbo], pingPong[1 - currentReadFbo]);
            currentReadFbo = 1 - currentReadFbo;
            processedCount++;
        }
    }

    //fliped for ofEasyCam
    glPushMatrix();
    int w = ofGetWidth();
    int h = ofGetHeight();
    glTranslatef(0, h, 0);
    glScalef(1, -1, 1);
    
    if (processedCount == 0) raw.draw(0, 0, w, h);
    else pingPong[currentReadFbo].draw(0, 0, w, h);
    
    glPopMatrix();
}
