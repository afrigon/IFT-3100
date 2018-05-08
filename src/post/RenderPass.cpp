//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "RenderPass.h"

void RenderPass::texturedQuad(float width, float height) {
    ofMesh m = ofMesh();
    m.setMode(ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_FAN);
    
    
    float offset = (height - height * ofGetHeight() / ofGetWidth()) / 2 / height;
    
    m.addVertex(ofVec3f(-1, -1, 0));
    m.addTexCoord(ofVec2f(0, 0));
    
    m.addVertex(ofVec3f(1, -1, 0));
    m.addTexCoord(ofVec2f(1, 0));
    
    m.addVertex(ofVec3f(1, 1, 0));
    m.addTexCoord(ofVec2f(1, 1));
    
    m.addVertex(ofVec3f(-1, 1, 0));
    m.addTexCoord(ofVec2f(0, 1));
    
    m.draw();
}
